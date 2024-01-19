#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 
SoftwareSerial mySoftwareSerial(4, 5);
DFRobotDFPlayerMini myDFPlayer;
int led = 2;
int buzzer = 3;
int pirPin = 8;

void setup() {                
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(led, OUTPUT);    
  pinMode(buzzer, OUTPUT); 
  pinMode(pirPin, INPUT);
  myDFPlayer.volume(30);
}
 
// Hàm loop chạy mãi mãi sau khi kết thúc hàm setup()
void loop() {
  digitalWrite(led, HIGH);
  int pirState = digitalRead(pirPin);
  if (pirState == HIGH)
  {
    myDFPlayer.play(1);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, LOW);
    delay(1000);
  }
  if (pirState == LOW)
  {
    digitalWrite(buzzer, LOW);
    
    myDFPlayer.pause();
  }
              
}
