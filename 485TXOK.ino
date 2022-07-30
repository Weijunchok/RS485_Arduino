#define EN485 15
HardwareSerial mySerial1(1);
void setup() {
  Serial.begin(9600);
  mySerial1.begin(9600,SERIAL_8N1,33,32);
  pinMode(EN485,OUTPUT);
  
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  digitalWrite(EN485,HIGH);
  while (Serial.available()) {
    mySerial1.print(Serial.readString());
  }
  delayMicroseconds(50000); //延时要足，要不然其实还没发完就变接收模式了，没发出去
  digitalWrite(EN485,LOW);
  while (mySerial1.available()) {
    Serial.print(mySerial1.readString());
  }
  delay(20);
}
