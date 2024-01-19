


  int pirSensors = 5;
  int ledPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(pirSensors, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  if (digitalRead(pirSensors) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
