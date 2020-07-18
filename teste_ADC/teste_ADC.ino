uint16_t valor_minimo = 1023;
uint16_t valor_maximo = 0;

uint32_t prev_millis;

uint32_t prev_micros;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(prev_millis != millis()){
    prev_millis = millis();

    prev_micros = micros();

    uint16_t valor = analogRead(A0); //A0 = SVP GPIO36 no ESP32

    uint16_t tempo = micros() - prev_micros;
    
    if(valor<valor_minimo) valor_minimo = valor;
    if(valor>valor_maximo) valor_maximo = valor;
    
    if(prev_millis%1000 == 0){

      uint16_t valor_medio = (valor_maximo + valor_minimo)/2;
      
      Serial.print(valor_minimo);
      Serial.print(" ");
      Serial.print(valor_medio);
      Serial.print(" ");
      Serial.print(valor_maximo);
      Serial.print(" ");
      Serial.print(tempo);
      Serial.println();
      
      valor_minimo = 4095; //4095 para ESP32, 1023 para demais
      valor_maximo = 0;
    }
  }
}
