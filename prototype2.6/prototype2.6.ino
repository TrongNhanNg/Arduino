//Nano test
//Final fine wiring with 2 pir active
//Under dev
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <Wire.h> 
#include <LiquidCrystal.h>

SoftwareSerial mySoftwareSerial(5, 4); ///tx4 rx5 ( VCC RX TX )
DFRobotDFPlayerMini myDFPlayer;
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int pirSensors[] = {8, 9};
int buzzerPin = 3;
int ledPin = 2;

const char *directions[] = {"2 o'clock", "4 o'clock"};

int active = 0;
unsigned long alarmTimer = 0;
int currentDirection  = 0;

unsigned long currentTime;
unsigned long lastCountResetTime = 0;
unsigned long lastMotionTime = 0;
const int resetTimeout = 5000;
//.........
unsigned long previousMillis = 0;
const long interval = 500;  // Interval for LED flashing
//..........
int ledState = LOW;
int pirCount[] = {0,0};
int pirCountLimit = 3;

void setup()
{
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);  //cài đặt volume từ 0 đến 30

  for (int i = 0; i < 2; i++) 
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
//===================================================================================
void printDetection(int directionPir) 
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Motion detected!");
  lcd.setCursor(0,1);
  lcd.print("At: ");
  lcd.print(directions[directionPir]);
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  
}
void noDetection() 
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    No sign     ");
    lcd.setCursor(0,1);
    lcd.print("  of movement    ");
  }
}
//==================================================================================
void loop() 
{
  if(digitalRead(pirSensors[0]) == HIGH)
    {
      lastMotionTime = millis();
      printDetection(0);
    }
  else if(digitalRead(pirSensors[1]) == HIGH)
    {
      //pirCount[1]++;
      //lastCountResetTime = millis();
      //if(pirCount[1] > pirCountLimit)
      //{
        lastMotionTime = millis();
        printDetection(1);
      //  pirCount[1] = 0;
      //}
      //if(millis() - lastCountResetTime >=3000)
      //{
      //  pirCount[1] = 0;
      //}
    }
  else
    {
      if(millis() - lastMotionTime >= 3000)
      {
          noDetection();
      }
    }    
  
  }
    
  
    
  

 
