
#define Versao "LabHome_200718a"

String DeviceID;
String apPass = "12345678";
uint8_t   an_pins[]={32,36,39,35,34,33};
float     wave[3][2500];
float     trafo=2000;
float     shunt=200;
float     vref=3.3;
uint8_t   w_mode=11;    // 0-parado 1-manRising 2-manFalling 3-manualChange
bool      w_run=true;  // 11-autoRising 12-autoFalling 13-autoChange
uint32_t  tr_millis;
float     v_sinc=511, v_sinc0=501, v_sinc1=521; // 0 a 1023
int8_t    tr_state=-1, prev_tr_state=-1;
uint8_t   tr_port=0;
uint16_t  w_us=50;    // min=40 (ESP32)
uint16_t  w_ini=0;
float     w_esc=1;

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
WebServer server(80);
#include <SPIFFS.h>
File fsUploadFile;
#include <analogWrite.h>

void setup() {
  Serial.begin(230400); // 230400-windows7 2000000-windows10
  Serial.println();
  SPIFFS.begin();
  DeviceID=Versao; DeviceID+="_"; DeviceID=DeviceID.substring(0,DeviceID.indexOf("_"));
  WiFi.softAP(DeviceID.c_str(), apPass.c_str());
  update_setup();
  web_setup();
  analogReadResolution(10);
  analogWriteFrequency(60);
  analogWrite(27,512,1023);
  delay(10);
  w_read();
}

void loop() {
  if(tr_millis<=millis()){
    if(w_run){
      float rv=analogRead(an_pins[tr_port]); rv=rv+32; // rv=(rv*2.48/3200.0)+0.17;
      if(rv<v_sinc0) tr_state=0;
      if(rv>v_sinc1) tr_state=1;
      bool ativar=false;
      if(w_mode%10==1 && tr_state==1 && prev_tr_state==0) ativar=true;
      if(w_mode%10==2 && tr_state==0 && prev_tr_state==1) ativar=true;
      if(w_mode%10==3 && tr_state==0 && prev_tr_state==1) ativar=true;
      if(w_mode%10==3 && tr_state==1 && prev_tr_state==0) ativar=true;
      if(ativar){
        w_read();
        tr_state=-1; prev_tr_state=-1;
        if(w_mode<10) w_run=false;
        tr_millis= millis()+500;
      }
      prev_tr_state=tr_state;
    }
  }
  server.handleClient();
}

void w_read(){
  uint32_t prev_micros=micros();
  for(uint16_t i=0;i<2000;i++){
    wave[0][i]=analogRead(an_pins[0]);
    wave[1][i]=analogRead(an_pins[1]);
    wave[2][i]=analogRead(an_pins[2]);
    while((micros()-prev_micros)<w_us) {}
    prev_micros+=w_us;
  }
  for(uint16_t i=0;i<2000;i++){
    for(uint8_t j=0;j<3;j++){
      wave[j][i]+=32;
      if(wave[j][i]>1023) wave[j][i]=1023;
    }
  }
 }
