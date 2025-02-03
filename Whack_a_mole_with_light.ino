#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial MP3Module(A10, A11);
DFRobotDFPlayerMini MP3Player;
LiquidCrystal_I2C lcd(0x27,16,2); 
int cds1 = A2;
int cds2 = A3;
int cds3 = A4;
int cds4 = A5;
int cds5 = A6;
int cds6 = A7;
int cds7 = A8;
int LED = 9;
long randNumber;
long prerand;
int score=0;
int scorebk=0;
int pass=700;   // 점수 흭득 광량
int wait=20; //대기시간 
float a=0,b=60;
long pretime = millis() ;
long curtime;
int count =0;
int start = 0;
int sptime = 80;
void setup() {
    lcd.init();  // LCD초기 설정             
  lcd.backlight(); // LCD초기 설정  
  // Set Arduino pins as outputs

// Table to convert a hex digit into the matching 7-seg display segments
//
//
    Serial.begin(9600); // Serial 통신을 초기화 합니다.
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
       pinMode(8, OUTPUT); //신부님
    pinMode(10, OUTPUT); //스피커핀
    pinMode(cds1,INPUT);
    pinMode(cds2,INPUT);
    pinMode(cds3,INPUT);
    pinMode(cds4,INPUT);
    pinMode(cds5,INPUT);
    pinMode(cds6,INPUT);
     pinMode(cds7,INPUT);
  MP3Module.begin(9600);
  
  if (!MP3Player.begin(MP3Module)) { // MP3 모듈을 초기화합니다. 초기화에 실패하면 오류를 발생시킵니다.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  delay(1);
  MP3Player.volume(20);  // 볼륨을 조절합니다. 0~30까지 설정이 가능합니다.

}

void loop() {
  if(start == 0){
     MP3Player.play(5); //시작음
     delay(1000);
    lcd.setCursor(0,0);
    lcd.print(" 3");
    delay(1000);
    lcd.print("    2");
    delay(1000);
    lcd.print("    1");
    delay(1000);
    start++;
     lcd.clear();
    lcd.print("       START!!!");
    delay(500);
     lcd.clear();
     delay(1000);
  }

  lcd.setCursor(0,0); //텍스트가 LCD에 나타날 위치
     a=(a*1000+count*100+180)/1000;
     if(a>=40 && start==1){
      MP3Player.play(6);
      wait=10;
      start++;
     }
     else if(a>=60){
      end(score);
     }
     lcd.print("Time : ");
     lcd.print(a);
 lcd.setCursor(0,1); //텍스트가 LCD에 나타날 위치
 lcd.print("Score : ");
  lcd.print(scorebk); 
 count=0; 

 
randNumber = random(1,8);             //1~7사이 랜덤 
  Serial.println("rand= " );
Serial.println(randNumber );

while(prerand == randNumber){
  randNumber = random(1,8);             //1~7사이 랜덤 
  Serial.println("zaprand= " );
Serial.println(randNumber );
}

prerand = randNumber;

Serial.println("score= " );
Serial.println(scorebk );
tone(10,262);
delay(sptime);
noTone(10);
if(randNumber == 1){
  for ( count=0; count < wait; count++) { //1번 악당이 나타난 후  신호 대기
  digitalWrite(2, HIGH);
    cds1 = analogRead(A2); // A2로 받은 아날로그 값을 cds변수로 넘겨줍니다.
    if(cds1>pass){        //pass이상의 광량을 식별시, 점수 흭득 후 다음 목표 진행
    tone(10,392);
delay(sptime);
noTone(10);
      digitalWrite(2, LOW);
      score++;
      break;
    }
     Serial.println(cds1 ); // Serial 모니터에 cds 값을 찍어주고 한줄 내려줍니다.
         delay(100);
       digitalWrite(2, LOW); // 3초가 지나면 다음 악당 출현
}
}
else if(randNumber == 2){
  for (count=0; count < wait; count++) { 
  digitalWrite(3, HIGH);
    cds2 = analogRead(A3);
    if(cds2>pass){
         tone(10,392);
delay(sptime);
noTone(10);
      digitalWrite(3, LOW);
      score++;
      break;
    }
     Serial.println(cds2 ); 
         delay(100);
       digitalWrite(3, LOW);
}
}
else if(randNumber == 3){
  for ( count=0; count < wait; count++) { 
  digitalWrite(4, HIGH);
    cds3 = analogRead(A4); 
    if(cds3>pass){
        tone(10,392);
delay(sptime);
noTone(10);
      digitalWrite(4, LOW);
      score++;
      break;
    }
     Serial.println(cds3 ); 
         delay(100);
       digitalWrite(4, LOW);
}
}
else if(randNumber == 4){
  for ( count=0; count < wait; count++) { 
  digitalWrite(5, HIGH);
    cds4 = analogRead(A5); 
    if(cds4>pass){
           tone(10,392);
delay(sptime);
noTone(10);
       digitalWrite(5, LOW);
      score++;
      break;
    }
     Serial.println(cds3 );
         delay(100);
       digitalWrite(5, LOW);
}
}
else if(randNumber == 5){
  for ( count=0; count < wait; count++) { 
  digitalWrite(6, HIGH);
    cds5 = analogRead(A6); 
    if(cds5>pass){
          tone(10,392);
delay(sptime);
noTone(10);
      digitalWrite(6, LOW);
      score++;
      break;
    }
     Serial.println(cds5 ); 
         delay(100);
       digitalWrite(6, LOW);
}
}
else if(randNumber == 6){
  for (count=0; count < wait; count++) { 
  digitalWrite(7, HIGH);
    cds6 = analogRead(A7); 
    if(cds6>pass){
           tone(10,392);
delay(sptime);
noTone(10);
       digitalWrite(7, LOW);
      score++;
      break;
    }
     Serial.println(cds6 ); 
         delay(100);
       digitalWrite(7, LOW);
}
}
else if(randNumber == 7){
  for (count=0; count < wait; count++) { 
  digitalWrite(8, HIGH);
    cds7 = analogRead(A8); 
    if(cds7>pass){
           tone(10,392);
delay(sptime);
noTone(10);
       digitalWrite(8, LOW);
      score=score+3;
      break;
    }
     Serial.println(cds6 ); 
         delay(100);
       digitalWrite(8, LOW);
}
}
else{ 
  Serial.println("waiting");
  delay(2000);
}
    scorebk=score;           
}
void end(int score){
     MP3Player.play(2); // 종료
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("====finish!!=======");
   lcd.setCursor(0,1); //텍스트가 LCD에 나타날 위치
 lcd.print("Score : ");
   lcd.print(score); 
   exit(0);
}
