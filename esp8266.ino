
#include <SoftwareSerial.h>
SoftwareSerial MODULO(8, 7); // RX || TX // TX  || RX
void setup(){
  MODULO.begin(115200);
  Serial.begin(115200);
  MODULO.println("AT+CIOBAUD=9600");
  delay(1000);
  Serial.begin(9600);
  MODULO.begin(9600);
  Serial.println("ok");
}

void loop(){
  if (Serial.available() > 0){
    MODULO.write(Serial.read());
}
  if (MODULO.available() > 0) {
    Serial.write(MODULO.read());    
}
}
