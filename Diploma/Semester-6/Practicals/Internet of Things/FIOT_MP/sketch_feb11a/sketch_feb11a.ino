#define in1 A0
#define in2 A1
#define in3 A2
#define in4 A3
#define buzzer 13

#define ena 6          // PWM for Left Motors
#define enb 5          // PWM for Right Motors

// LEFT SIDE BULBS
#define fl2 2         // Front Light Right (White, No PWM)
#define backLightA 3   // Back Light Right (Red, PWM for brightness control)
#define blinkerA 8     // Right Blinker (Yellow, No PWM, ON only when turning right)
#define revLightA 7    // Back Light Right (White, No PWM)
#define blinkerC 9      //Right backside

// RIGHT SIDE BULBS
#define fl1 12          // Front Light Left (White, No PWM)
#define backLightB 11  // Back Light Left (Red, PWM for brightness control)
#define revLightB 10   // Back Light Left (White, No PWM)
#define blinkerB A4    // Left Blinker (Yellow, No PWM, ON only when turning left)
#define blinkerD 4    // Left backside

uint8_t speedValue = 255; // Default speed (0-255)
uint8_t turnSpeed = 42;   // Reduced speed for turning

bool hazardLightsOn = false;
bool frontLightsOn = false;
bool blinkRight = false;
bool blinkLeft = false;
bool revLightsOn = false;

void setup() {
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fl1, OUTPUT);
  pinMode(fl2, OUTPUT);
  pinMode(backLightA, OUTPUT);
  pinMode(backLightB, OUTPUT);
  pinMode(blinkerA, OUTPUT);
  pinMode(blinkerB, OUTPUT);
  pinMode(blinkerC, OUTPUT);
  pinMode(blinkerD, OUTPUT);
  pinMode(revLightA, OUTPUT);
  pinMode(revLightB, OUTPUT);

  digitalWrite(buzzer, HIGH);  // Start with buzzer OFF

  notify(1);
}

void loop() {
  static unsigned long lastBlinkTime = 0;
  const unsigned long blinkInterval = 500; // 500ms
  static bool blinkState = false;

  unsigned long currentMillis = millis();
  if (currentMillis - lastBlinkTime >= blinkInterval) {
    lastBlinkTime = currentMillis;
    blinkState = !blinkState;

    if (hazardLightsOn || blinkRight || blinkLeft) {
      if (hazardLightsOn || blinkRight) {
        digitalWrite(blinkerA, blinkState ? HIGH : LOW);
        digitalWrite(blinkerC, blinkState ? HIGH : LOW);
      }

      if (hazardLightsOn || blinkLeft) {
        digitalWrite(blinkerB, blinkState ? HIGH : LOW);
        digitalWrite(blinkerD, blinkState ? HIGH : LOW);
      }
    }
  }

  if (Serial.available() > 0) {
    // Reset all blinkers if not blinking
    if (!blinkLeft && !blinkRight && !hazardLightsOn) {
      turnOffBlinkers();
    }

    char inputvalue = char(Serial.read());
    Serial.println(inputvalue); // Debugging

    if (inputvalue == 'W') frontLightsOn = true;
    else if (inputvalue == 'w') frontLightsOn = false;

    if (inputvalue == 'U') revLightsOn = true;
    else if (inputvalue == 'u') revLightsOn = false;

    controlFrontLights(frontLightsOn);
    reverseLights(revLightsOn);

    switch (inputvalue) {
      case 'F': // Forward
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkLeft = false;
          blinkRight = false;
          turnOffBlinkers();
        }
        drive(HIGH, LOW, LOW, HIGH, speedValue, speedValue);
        break;

      case 'B': // Backward
        reverseLights(HIGH);
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkLeft = false;
          blinkRight = false;
          turnOffBlinkers();
        }
        drive(LOW, HIGH, HIGH, LOW, speedValue, speedValue);
        break;

      case 'R': // Right turn
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkLeft = false;
          turnOffLeftBlinkers();
          blinkRight = true;
        }
        drive(LOW, LOW, LOW, HIGH, speedValue, speedValue);
        break;

      case 'L': // Left turn
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkRight = false;
          turnOffRightBlinkers();
          blinkLeft = true;
        }
        drive(HIGH, LOW, LOW, LOW, speedValue, speedValue);
        break;

      case 'G': // Forward + Left
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkRight = false;
          turnOffRightBlinkers();
          blinkLeft = true;
        }
        drive(HIGH, LOW, LOW, HIGH, speedValue, turnSpeed);
        break;

      case 'I': // Forward + Right
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkLeft = false;
          turnOffLeftBlinkers();
          blinkRight = true;
        }
        drive(HIGH, LOW, LOW, HIGH, turnSpeed, speedValue);
        break;

      case 'H': // Backward + Left
        reverseLights(HIGH);
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkRight = false;
          turnOffRightBlinkers();
          blinkLeft = true;
        }
        drive(LOW, HIGH, HIGH, LOW, turnSpeed, speedValue);
        break;

      case 'J': // Backward + Right
        reverseLights(HIGH);
        controlBrakeLights(12);
        if (!hazardLightsOn) {
          blinkLeft = false;
          turnOffLeftBlinkers();
          blinkRight = true;
        }
        drive(LOW, HIGH, HIGH, LOW, speedValue, turnSpeed);
        break;

      case 'U':
        revLightsOn = true;
        break;

      case 'u':
        revLightsOn = false;
        break;

      case 'V': // Buzzer ON
        digitalWrite(buzzer, LOW);
        break;

      case 'v': // Buzzer OFF
        digitalWrite(buzzer, HIGH);
        break;

      case 'X': // Hazard Lights ON
        hazardLightsOn = true;
        break;

      case 'x': // Hazard Lights OFF
        hazardLightsOn = false;
        turnOffBlinkers();
        break;

      case 'S': // Stop
        controlBrakeLights(240);
        if (!revLightsOn) {
          digitalWrite(revLightA, LOW);
          digitalWrite(revLightB, LOW);
        }
        drive(LOW, LOW, LOW, LOW, 0, 0);

        if (!hazardLightsOn) {
          if (blinkLeft) {
            blinkLeft = false;
            turnOffLeftBlinkers();
          }
          if (blinkRight) {
            blinkRight = false;
            turnOffRightBlinkers();
          }
        }
        break;

      case 'D': // Bluetooth Disconnected
        // Stop the car
        drive(LOW, LOW, LOW, LOW, 0, 0);

        // Turn off all blinkers
        hazardLightsOn = false;
        blinkLeft = false;
        blinkRight = false;
        turnOffBlinkers();

        // Turn off front and reverse lights
        frontLightsOn = false;
        controlFrontLights(false);
        digitalWrite(revLightA, LOW);
        digitalWrite(revLightB, LOW);
        controlBrakeLights(0);

        // disconnect notification beep 3 times and blink 3 times
        notify(3);
        break;
    }
  }
}

void drive(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t leftSpeed, uint8_t rightSpeed) {
  digitalWrite(in1, i1);
  digitalWrite(in2, i2);
  digitalWrite(in3, i3);
  digitalWrite(in4, i4);
  analogWrite(ena, leftSpeed);
  analogWrite(enb, rightSpeed);
}

void controlFrontLights(bool state) {
  digitalWrite(fl1, state ? HIGH : LOW);
  digitalWrite(fl2, state ? HIGH : LOW);
}

void controlBrakeLights(uint8_t val) {
  analogWrite(backLightA, val);
  analogWrite(backLightB, val);
}

void reverseLights(bool state) {
  digitalWrite(revLightA, state ? HIGH : LOW);
  digitalWrite(revLightB, state ? HIGH : LOW);
}

void turnOffBlinkers() {
  digitalWrite(blinkerA, LOW);
  digitalWrite(blinkerB, LOW);
  digitalWrite(blinkerC, LOW);
  digitalWrite(blinkerD, LOW);
}

void notify(uint8_t fancyTimes) {
  for (uint8_t i = 0; i < fancyTimes; i++) {
    // Step A
    digitalWrite(blinkerA, HIGH);
    digitalWrite(buzzer, LOW);   // Buzzer ON with first light
    delay(120);
    digitalWrite(blinkerA, LOW);
    digitalWrite(buzzer, HIGH);  // Buzzer OFF

    // Step B
    digitalWrite(blinkerB, HIGH);
    delay(120);
    digitalWrite(blinkerB, LOW);

    // Step C
    digitalWrite(blinkerD, HIGH);
    delay(120);
    digitalWrite(blinkerD, LOW);
    
    // Step D
    digitalWrite(blinkerC, HIGH);
    delay(120);
    digitalWrite(blinkerC, LOW);
  }
}

void turnOffLeftBlinkers() {
  digitalWrite(blinkerB, LOW);
  digitalWrite(blinkerD, LOW);
}

void turnOffRightBlinkers() {
  digitalWrite(blinkerA, LOW);
  digitalWrite(blinkerC, LOW);
}