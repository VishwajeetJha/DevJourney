#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define ena 9   // PWM for Left Motors
#define enb 10  // PWM for Right Motors

int speedValue = 255; // Default speed (0-255)
int turnSpeed = 128;  // Reduced speed for turning

void setup() {
  Serial.begin(9600);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());

    switch (inputvalue) {
      case 'F': // Forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, speedValue);
        analogWrite(enb, speedValue);
        break;

      case 'B': // Backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(ena, speedValue);
        analogWrite(enb, speedValue);
        break;

      case 'R': // Right (No speed change, both sides running)
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, speedValue);
        analogWrite(enb, speedValue);
        break;

      case 'L': // Left (No speed change, both sides running)
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(ena, speedValue);
        analogWrite(enb, speedValue);
        break;

      case 'G': // Forward + Right (Reduce right side speed)
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, speedValue);  // Left side full speed
        analogWrite(enb, turnSpeed);   // Right side reduced speed
        break;

      case 'I': // Forward + Left (Reduce left side speed)
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, turnSpeed);   // Left side reduced speed
        analogWrite(enb, speedValue);  // Right side full speed
        break;

      default: // Stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(ena, 0);
        analogWrite(enb, 0);
        break;
    }
  }
}
