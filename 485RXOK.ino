#define EN485 15
HardwareSerial mySerial1(1);
void setup() {
  Serial.begin(9600);
  mySerial1.begin(9600,SERIAL_8N1,33,32);
  pinMode(EN485,OUTPUT);
  digitalWrite(EN485,LOW);
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  digitalWrite(EN485,LOW);
  while (mySerial1.available()) {
    Serial.print(mySerial1.readString());
  }
  /*
  while (Serial.available()) {
    digitalWrite(EN485,HIGH);
    mySerial1.write((char)Serial.read());
  }*/
  delay(20);
}
