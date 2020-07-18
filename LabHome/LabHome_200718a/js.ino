// https://lastminuteengineers.com/handling-esp32-gpio-interrupts-tutorial/
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/ledc.html
// https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-ledc.h

void handleJson(){
  String sa,sb,pg,fields;
  //
  sa="w_msd";if(server.hasArg(sa)){ w_us=server.arg(sa).toInt()*50; }
  sa="w_ini";if(server.hasArg(sa)){ w_ini=server.arg(sa).toInt(); }
  sa="w_esc";if(server.hasArg(sa)){ w_esc=server.arg(sa).toFloat(); }
  sa="w_esc";if(server.hasArg(sa)){ w_esc=server.arg(sa).toFloat(); }
  sa="tr_port";if(server.hasArg(sa)){ tr_port=server.arg(sa).toInt(); }
  sa="v_sinc";if(server.hasArg(sa)){ v_sinc=server.arg(sa).toInt();
  v_sinc0=v_sinc-10; v_sinc1=v_sinc+10; }
  
  sa="w_mode";if(server.hasArg(sa)){  w_mode=server.arg(sa).toInt(); if(w_mode>10) w_run=true; }
  //
  sa="w_us";if(server.hasArg(sa)){
    w_us=server.arg(sa).toInt();
    if(w_us>200 && w_mode>10) w_mode-=10;
  }
  if(w_us<50)   w_us=50;
  if(w_us>1000) w_us=1000;
  //
  sa="tr_port";if(server.hasArg(sa)){ tr_port=server.arg(sa).toInt(); }
  sa="v_sinc";if(server.hasArg(sa)){ v_sinc=server.arg(sa).toInt();
    v_sinc0=v_sinc-50; if(v_sinc0<0) v_sinc0=0;
    v_sinc1=v_sinc+50; if(v_sinc1>1023) v_sinc1=1023;
  }
  sa="w_run";if(server.hasArg(sa)){   w_run=(server.arg(sa)=="true"); }
  sa="fields";if(server.hasArg(sa)){  fields=","+server.arg(sa)+",";
    if(pg.length()==0) pg+="{"; else pg+=",";
    sa=",w_us,";  if(fields.indexOf(sa)>=0){ pg+="\"w_us\":";pg+=w_us;              pg+=","; }
//    sa=",w_size,";  if(fields.indexOf(sa)>=0){ pg+="\"w_size\":";pg+=w_size; pg+=","; }
    sa=",trafo,"; if(fields.indexOf(sa)>=0){ pg+="\"trafo\":";pg+=String(trafo,0);  pg+=","; }
    sa=",shunt,"; if(fields.indexOf(sa)>=0){ pg+="\"shunt\":";pg+=String(shunt,0);  pg+=","; }
    sa=",vref,";  if(fields.indexOf(sa)>=0){ pg+="\"vref\":";pg+=String(vref);      pg+=","; }
    sa=",w_mode,";if(fields.indexOf(sa)>=0){ pg+="\"w_mode\":";pg+=String(w_mode);  pg+=","; }
    sa=",w_run,";if(fields.indexOf(sa)>=0){   pg+="\"w_run\":";pg+=String(w_run); pg+=","; }
    sa=",tr_port,";if(fields.indexOf(sa)>=0){ pg+="\"tr_port\":";pg+=String(tr_port); pg+=","; }
    sa=",v_sinc,";if(fields.indexOf(sa)>=0){  pg+="\"v_sinc\":"; pg+=String(v_sinc); pg+=",";  }
    sa=",w_esc,";  if(fields.indexOf(sa)>=0){ pg+="\"w_esc\":";pg+=w_esc; pg+=","; }
    //
    if(pg.length()==1) pg="";
    if(pg.endsWith(",")); pg=pg.substring(0,pg.length()-1);
  }
  //
  sa="wa2";if(server.hasArg(sa)){
    if(pg.length()==0) pg+="{"; else pg+=",";
    pg+="\"wa\":[";
    for(uint8_t j=0;j<=2;j++){
      pg+="[";
      for(uint16_t i=0; i<=199;i++){
        uint16_t ia; if(w_esc>=1.0) ia=i*(uint16_t)w_esc; else ia=i;
        pg+=String(wave[j][ia+w_ini]*vref/1023,2);
        if(i<199) pg+=",";
      }
      pg+="]";
      if(j<2) pg+=",";
    }
    pg+="]";
  }
  //
  if(pg.length()==0) pg="{";
  pg+="}";
  server.send(200, "text/json", pg);
}
//
//String str32(uint16_t n){
//  String sa="";
//  uint16_t ia=n%32; uint16_t ib=n/32;
//  char ca;
//  if(ib<10) ca=(ib+48); else ca=(ib+55);
//  sa+=ca;
//  if(ia<10) ca=(ia+48); else ca=(ia+55);
//  sa+=ca;
//  return sa;
//}
