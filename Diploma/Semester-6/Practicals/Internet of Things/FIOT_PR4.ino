const int ledPin1 =8 ;
     // Pin connected to the LED
const int switchPin1 = 1;  // Pin connected to the switch
int switchState1 = 0;      // Variable to store the state of the switch
const int ledPin2 =10 ;
     // Pin connected to the LED
const int switchPin2 = 3;  // Pin connected to the switch
int switchState2 = 0;      // Variable to store the state of the switch
const int ledPin3 =12 ;
     // Pin connected to the LED
const int switchPin3 = 5;  // Pin connected to the switch
int switchState3 = 0;      // Variable to store the state of the switch

void setup() {
  pinMode(ledPin1, OUTPUT);       // Set the LED pin as an output
  pinMode(switchPin1, INPUT_PULLUP); // Use internal pull-up resistor for the switch
 pinMode(ledPin2, OUTPUT);       // Set the LED pin as an output
  pinMode(switchPin2, INPUT_PULLUP); // Use internal pull-up resistor for the switch
 pinMode(ledPin3, OUTPUT);       // Set the LED pin as an output
  pinMode(switchPin3, INPUT_PULLUP); // Use internal pull-up resistor for the switch
}

void loop() {
  switchState1 = digitalRead(switchPin1);  // Read the state of the switch

             // If the switch is pressed
    digitalWrite(ledPin1, !switchState1 ? HIGH :LOW);         // Turn the LED on
  switchState2 = digitalRead(switchPin2);  // Read the state of the switch

             // If the switch is pressed
    digitalWrite(ledPin2, !switchState2 ? HIGH :LOW);         // Turn the LED on
  switchState3 = digitalRead(switchPin3);  // Read the state of the switch

             // If the switch is pressed
    digitalWrite(ledPin3, !switchState3 ? HIGH :LOW);         // Turn the LED on
  }