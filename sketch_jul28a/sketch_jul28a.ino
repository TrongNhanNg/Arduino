  //----Set volume----
//  myDFPlayer.volume(10);  //Set volume value (0~30).
//  myDFPlayer.volumeUp(); //Volume Up
//  myDFPlayer.volumeDown(); //Volume Down
  
  //----Set different EQ----
//  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
//  myDFPlayer.EQ(DFPLAYER_EQ_POP);
//  myDFPlayer.EQ(DFPLAYER_EQ_ROCK);
//  myDFPlayer.EQ(DFPLAYER_EQ_JAZZ);
//  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
//  myDFPlayer.EQ(DFPLAYER_EQ_BASS);
  
  //----Thiết lặp sử dụng thẻ SD----
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_U_DISK);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_AUX);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SLEEP);
//  myDFPlayer.outputDevice(DFPLAYER_DEVICE_FLASH);
  
  //----Mp3 control----
//  myDFPlayer.sleep();     //sleep
//  myDFPlayer.reset();     //Reset the module
//  myDFPlayer.enableDAC();  //Kích hoạt On-chip DAC
//  myDFPlayer.disableDAC();  //Tắt On-chip DAC
//  myDFPlayer.outputSetting(true, 15); //Cài đặt output, kích hoạt output và cài đặt mức đầu ra là 15
  
  //----Mp3 play----
//  myDFPlayer.next();  //Mở bài mp3 tiếp theo
//
//  myDFPlayer.previous();  //Mở bài mp3 trước
//
//  myDFPlayer.play(1);  //Mở bài mp3 đầu tiên
//
//  myDFPlayer.loop(1);  //Dừng bài mp3 đầu tiên
//
//  myDFPlayer.pause();  //tạm dừng mp3
//
//  myDFPlayer.start();  //Bắt đầu mp3 từ trạng thái tạm dừng
//
//  myDFPlayer.playFolder(15, 4);  //Mở 1 bài mp3 cụ thể trong SD:/15/004.mp3; tên Folder (1~99); tên File (1~255)
//
//  myDFPlayer.enableLoopAll(); //Lặp lại tất cả các file mp3
//
//  myDFPlayer.disableLoopAll(); //Dừng tất cả các file mp3
//
//  myDFPlayer.playMp3Folder(4); //Mở 1 bài mp3 cụ thể trong folder mp3 trong thẻ SD:/MP3/0004.mp3; Tên File(0~65535)
//
//  myDFPlayer.advertise(3); //Giới thiệu 1 bài mp3 cụ thể trong SD:/ADVERT/0003.mp3; Tên File (0~65535)
//
//  myDFPlayer.stopAdvertise(); //Dừng giới thiệu
//
//  myDFPlayer.playLargeFolder(2, 999); //Mở 1 bài mp3 cụ thể trong thẻ SD:/02/004.mp3; Tên Folder (1~10); tên File (1~1000)
//
//  myDFPlayer.loopFolder(5); //Lặp tất cả các file mp3 tron thư mục SD:/05.
//
//  myDFPlayer.randomAll(); //Random tất cả các bài mp3
//
//  myDFPlayer.enableLoop(); //bật vòng loop
//
//  myDFPlayer.disableLoop(); //tắt loop
//
//  //----Read imformation----
//  Serial.println(myDFPlayer.readState()); //đọc trạng thái mp3 hiện tại
//  Serial.println(myDFPlayer.readVolume()); //đọc giá trị volume hiện tại
//  Serial.println(myDFPlayer.readEQ()); //đọc cài đặt EQ
//  Serial.println(myDFPlayer.readFileCounts()); //Đọc tất cả các file có trong thẻ nhớ
//  Serial.println(myDFPlayer.readCurrentFileNumber()); //Đọc sô các file phát hiện tại
//  Serial.println(myDFPlayer.readFileCountsInFolder(3)); //Đọc số file trong folder SD:/03

//#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(12, 11); // TX-10; RX-11
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int pirPin = 10;
int buzzerPin = 2;
int wakeledPin = 3;

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(wakeledPin, OUTPUT);
  
  if (!myDFPlayer.begin(mySoftwareSerial)) 
  {  
    Serial.println(F("Không thể khởi động:"));
    Serial.println(F("1.Kiểm tra lại kết nối"));
    Serial.println(F("2.Lắp lại thẻ nhớ"));
      while(true)
      {
        delay(0);
      }
  }
  Serial.println(F("DFPlayer Mini đang hoạt động"));
  
  myDFPlayer.volume(30);  //cài đặt volume từ 0 đến 30
  
}

void loop() 
{

  digitalWrite(wakeledPin, HIGH);
  delay(100);
  digitalWrite(wakeledPin, LOW);
  delay(5000);
  int pirState = digitalRead(pirPin);
  if (pirState == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);
    myDFPlayer.play(1);
    delay(5000);  
    
    
    
  }
  if (pirState == LOW)
  {
    digitalWrite(buzzerPin, LOW);
    myDFPlayer.pause();
  }
  
  

}
