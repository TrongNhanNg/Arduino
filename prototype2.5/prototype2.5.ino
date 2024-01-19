//Nano test
//Final fine wiring with 2 pir active
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
const int resetTimeout = 5000;

int pirCount[] = {0,0};
int pirCountLimit = 1;

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
void DFAlarm_Off(long duration)
{
  if ((active = 1) && (millis() - alarmTimer > duration)) 
  {
//    digitalWrite(buzzerPin, LOW);
//    myDFPlayer.pause();
//    lcd.setCursor(0,0);
//    lcd.print("    No sign     ");
//    lcd.setCursor(0,1);
//    lcd.print("  of movement    ");
    active = 0;
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}

//directionPir = [0,1,2...}
void LCDAlarm_On(int directionPir)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Motion detected!");
  lcd.setCursor(0,1);
  lcd.print("At: ");
  lcd.print(directions[directionPir]);
}

void DFAlarm_On(int songNum, int directionPir)
{
  myDFPlayer.play(songNum);
  digitalWrite(buzzerPin, HIGH);
  //currentDirection = directionPir;
  active = 1;
  alarmTimer = millis();
  digitalWrite(ledPin, LOW);
}

//==================================================================================
void loop() 
{
  
  for(int i = 0; i < 2; i++)
  {
 
    if(digitalRead(pirSensors[i]) == HIGH)
    {
      lastCountResetTime = millis();
      pirCount[i]++;
      LCDAlarm_On(i);
      if (pirCount[i] >= pirCountLimit) 
      {
        DFAlarm_On(1,i);
        pirCount[i]=0;
        active = 1;
      }
      //if (millis() - lastCountResetTime >= resetTimeout)
      //{
      //  pirCount[i] = 0;
      //}
    }
    else 
    {
      DFAlarm_Off(5000);
      
    }
    
  }
}
 
