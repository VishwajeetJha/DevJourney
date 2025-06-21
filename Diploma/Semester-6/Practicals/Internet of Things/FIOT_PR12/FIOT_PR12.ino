const int trigPin = 9;
const int echoPin = 10;
const int relPin = 12;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(relPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(ledPin, LOW);
  digitalWrite(relPin, LOW);

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 10){
    digitalWrite(relPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("Relay Triggered!");
  }
  else{
    digitalWrite(relPin, LOW);
  }
  delay(1000);
}