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
//  myDFPlayer.readState(); //đọc trạng thái mp3 hiện tại
//  myDFPlayer.readVolume(); //đọc giá trị volume hiện tại
//  myDFPlayer.readEQ(); //đọc cài đặt EQ
//  myDFPlayer.readFileCounts(); //Đọc tất cả các file có trong thẻ nhớ
//  myDFPlayer.readCurrentFileNumber(); //Đọc sô file phát hiện tại
//  myDFPlayer.readFileCountsInFolder(3); //Đọc số file trong folder SD:/03

//#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(5, 6); 
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
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
  myDFPlayer.playFolder(01, 001); //folder: 01 ; file 001cochay
  delay(1000);
  myDFPlayer.playFolder(01, 002); //folder: 01 ; file 002cotrom
  delay(1000);
  myDFPlayer.playFolder(01, 003); //folder: 01 ; file 003baodong
  delay(1000);
  myDFPlayer.playFolder(01, 004); //folder: 01 ; file 004cororikhigas
  delay(2000);
  
  myDFPlayer.playFolder(02, 001); //folder: 02 ; file 001cokhoi
  delay(1000); 
  myDFPlayer.playFolder(02, 002); //folder: 02 ; file 002cokhach
  delay(1000);
  myDFPlayer.playFolder(02, 003); //folder: 02 ; file 003conguoivaonha
  delay(5000);
  
}
