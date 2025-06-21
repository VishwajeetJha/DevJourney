const int L1 = 2, L2 = 3, L3 = 4, L4 = 5, L5 = 6, L6 = 7, L7 = 8, L8 = 9; // LED pins

void setup()
{
  // LED pins --> output
  for (int pin = L1; pin <= L8; pin++)
  {
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  // battiyo ko ON karna
  for (int pin = L1; pin <= L8; pin++)
  {
    digitalWrite(pin, HIGH);
  }
  delay(1000); // ek second ka delay

  // battiyo ko OFF karna
  for (int pin = L1; pin <= L8; pin++)
  {
    digitalWrite(pin, LOW);
  }
  delay(1000); // ek second ka delay
}