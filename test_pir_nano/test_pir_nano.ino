


  int pirSensor1 = 8;
  //int pirSensor2 = 9;
  int ledPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(pirSensor1, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  if (digitalRead(pirSensor1) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
