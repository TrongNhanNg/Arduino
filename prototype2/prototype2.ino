// Best so far
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <Wire.h> 
#include <LiquidCrystal.h>

SoftwareSerial mySoftwareSerial(4, 5); //
DFRobotDFPlayerMini myDFPlayer;
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int pirSensors[] = {8, 9, 10, 11, 12, 13};
int buzzerPin = 3;
int ledPin = 2;
int active = 1;

const char *directions[] = {"2 o'clock", "4 o'clock", "6 o'clock", "8 o'clock", "10 o'clock", "12 o'clock"};
unsigned long alarmTimer = 0;
unsigned long ledTimer = 0;
unsigned long lastMotion = 0;
int currentDirection  = 0;

void setup()
{
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);  //cài đặt volume từ 0 đến 30

  for (int i = 0; i < 6; i++) 
  {
    pinMode(pirSensors[i], INPUT);
  }
  
  pinMode(ledPin, OUTPUT);    
  pinMode(buzzerPin, OUTPUT); 
  

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("System      ");
  lcd.setCursor(0,1);
  lcd.print("initiating...     ");
}

void loop() 
{
  for (int i = 0; i < 6; i++) 
  {
    if (digitalRead(pirSensors[i]) == HIGH) 
    {
      
      if (millis() - lastMotion > 5000) // interrupt dfplayer each time motion detected
      {
        myDFPlayer.play(1);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Motion detected!");
        lcd.setCursor(0,1);
        lcd.print("At: ");
        lcd.print(directions[i]);
        digitalWrite(buzzerPin, HIGH);
        active = 1;
        currentDirection = i;
        alarmTimer = millis();
        digitalWrite(ledPin, HIGH);
      } 
      else if (i != currentDirection) 
      {
        myDFPlayer.play(1);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Motion detected!");
        lcd.setCursor(0,1);
        lcd.print("At: ");
        lcd.print(directions[i]);
        digitalWrite(buzzerPin, HIGH);
        active = 1;
        currentDirection = i;
        alarmTimer = millis();
        digitalWrite(ledPin, HIGH);
      }
    } 
    else 
    {
      if (active && (millis() - alarmTimer > 5000)) {
        digitalWrite(buzzerPin, LOW);
        myDFPlayer.pause();
        lcd.setCursor(0,0);
        lcd.print("    No sign     ");
        lcd.setCursor(0,1);
        lcd.print("  of movement    ");
        active = 0;
        digitalWrite(ledPin, LOW);
      }
    }
  }
  if (!active) {
    if (millis() - ledTimer > 2000) { 
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
    ledTimer = millis();
   }
 }
}






//for (int i = 0; i < 6; i++) 
//  {
//    if (digitalRead(pirSensors[i]) == HIGH) 
//    {
//    
//      if (!active)
//      {
//        if (millis() - lastMotion < 10000)
//        {
//          
//          lcd.setCursor(0,0);
//          lcd.print("Motion detected!      ");
//          lcd.setCursor(0,1);
//          lcd.print(directions[i]);
//          myDFPlayer.play(1);
//          digitalWrite(buzzerPin, HIGH);
//          lastMotion = millis();
//          lastDirection = i;
//          active = 1;
//        }
//        
//      }
//    }
//  
//    else 
//    {
//      if (active)
//      {
//        
//        lcd.setCursor(0,0);
//        lcd.print("No sign          ");
//        lcd.setCursor(0,1);
//        lcd.print("of movement     ");
//        myDFPlayer.pause();
//        digitalWrite(buzzerPin, LOW);
//        active = 0;
//      }
//        
//     }
// }
