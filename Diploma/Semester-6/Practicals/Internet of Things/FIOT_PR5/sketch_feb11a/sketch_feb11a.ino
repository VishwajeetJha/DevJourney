const int l1 = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  delay(10);  

  int brightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(l1, brightness);

}