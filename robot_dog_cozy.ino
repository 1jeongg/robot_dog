// 전체 핀들 요약
// servoPin: 8,9번   피에조부저: 12번    lcd1: 44, 45, 46, 47, 48, 49) lcd2: (36, 37, 38, 39, 40, 41)
// 무게핀: 2,3번      조도센서(머리): A1, 조도센서(손): A0  버튼: 14번

// 사용한 센서: 가속도 센서, 무게 센서, 조도센서(손), 조도센서(머리), 버튼 
// 사용한 출력 모듈: 피에조 부저(126-199줄), lcd 2개(206-476줄), 서보모터 2개(코드 41-118줄)

/*
<전체 코드 간단한 설명>
스케치 파일을 업로드 했을 때 효과음(도미솔도)와 함께 강아지 인형의 기본 눈 동작이 출력됨

case1(코드 585-594줄): 박스를 두 번 두들겼을 때(가속도 센서)  => 화난 표정(lcd) + 마리오 음악(피에조부저) + 강아지 귀 두 번 움직임(서보모터)
                      (double_tap==1                   => angry_left_eye(), angry_right_eye(), mario_music(), servo_function()*2)
       
case2(코드 597-607줄): 강아지 손을 잡았을 때(조도센서)       => 기쁜 표정(lcd) + 학교종 음악(피에조 부저) + 귀가 천천히 한 번 움직임(서보모터)
                      (hand_bright>=1000               => happy_left_eye(), happy_right_eye(), school_bell_music(), servo_slow_function())
       
case3(코드 609-617줄): 밥그릇에 과자를 올렸을 때(무게 센서)   => 기쁜 표정(lcd) + 엘리제 음악(피에조 부저) + 양쪽 귀가 반대로 움직임(서보모터)
                      (weight < -220000                 => happy_left_eye(), happy_right_eye(), eliz_music(), servo_cute_function()))
      
case4(코드 619-628줄): 방의 밝기가 어두어지면(조도센서)      => 졸리는 표정(lcd) + 귀가 엄청 천천히 움직임(서보모터)
                      (head_bright>=1000               => sleepy_left_eye(), sleepy_right_eye(), servo_very_slow_function())

버튼을 누르면 효과음(도솔미도)와 함께 강아지 인형의 눈이 꺼짐
다시 버튼을 누르면 처음 상태로 돌아감
*/

#include <LiquidCrystal.h>
#include "HX711.h"
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 scale;

// Servo Motor Function
// servo_function(servoPin, servoPin2) : double_tap에 반응하는 함수, delay=3
// servo_very_slow_function(servoPin, servoPin2) : 머리 위 조도센서를 어둡게 했을 때 반응하는 함수, delay=10
// servo_slow_function(servoPin, servoPin2) : 손에 있는 조도센서를 어둡게 했을 때 반응하는 함수, delay=6
// servo_cute_function(servoPin, servoPin2) : 무게 센서에 반응하는 함수, 귀가 좌우로 움직임, delay=3

#include <Servo.h> 
int servoPin = 8;
int servoPin2 = 9;
Servo servo;
Servo servo2; 
int angle = 0; // servo position in degrees 

void servo_function(int servoPin, int servoPin2){
  servo.attach(servoPin);
  servo2.attach(servoPin2); 
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(3); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(3); 
  }
}

void servo_very_slow_function(int servoPin, int servoPin2){
  servo.attach(servoPin);
  servo2.attach(servoPin2); 
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(10); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(10); 
  }
}

void servo_cute_function(int servoPin, int servoPin2){
  servo.attach(servoPin);
  servo2.attach(servoPin2); 
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle);
    servo2.write(180-angle); 
    delay(3); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle);
    servo2.write(180-angle); 
    delay(3); 
  }
}

void servo_slow_function(int servoPin, int servoPin2){
  servo.attach(servoPin);
  servo2.attach(servoPin2); 
  for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(6); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle);
    servo2.write(angle); 
    delay(6); 
  }
}
/////////////////////////////////////////////////////////////////

// sound function
// school_bell_music(piezoPin): 손에 있는 조도센서를 어둡게 했을 때 반응하는 함수
// eliz_music(piezoPin): 무게 센서에 반응하는 함수
// mario_music(piezoPin) : double_tap시 반응하는 함수

#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 
#define B0 246 // 시 
#define D1 311// 시
#define A0 220// 시
#define NOTE_C5  523
#define NOTE_C4  262
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_A3  220
#define NOTE_AS3 233

int piezoPin = 12; // 부저의 ⊕극을 오렌지 보드 8번에 연결 
int tempo = 200; // duration 옵션 값 설정 
int notes[25] = { G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C }; 
int eli[25] = { E, D1, E, D1, E, B0, D, C, A0 }; 
int mario[6] = {NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,  NOTE_AS3, NOTE_AS4};

void school_bell_music(int piezoPin)
{
   for (int i = 0; i < 7; i++) { 
    tone (piezoPin, notes[ i ], tempo); 
    delay (200); 
  } 
}

void eliz_music(int piezoPin)
{
   for (int i = 0; i < 9; i++) { 
    tone (piezoPin, eli[ i ], tempo); 
    delay (200); 
  } 
}

void mario_music(int pizeoPin) {
  // put your main code here, to run repeatedly:
   for (int i = 0; i < 6; i++) { 
    tone (piezoPin, mario[ i ], tempo); 
    delay (200); 
  } 
}
// 버튼 껐을 때 사운드 재생
void on() {
  tone(12, 262, 1000);
  delay(300);

  tone(12, 330, 1000);
  delay(300);
  
  tone(12, 392, 1000);
  delay(300);

  tone(12, 523, 300);
  delay(300);
}
// 버튼 껐을 때 사운드 재생
void off() {
  tone(12, 523, 1000);
  delay(300);
  
  tone(12, 392, 1000);
  delay(300);

  tone(12, 330, 1000);
  delay(300);

  tone(12, 262, 300);
  delay(300);
}
/////////////////////////////////////////////////////////////////////////
//Face Functon
// left_eye(lcd), right_eye(lcd), happy_left_eye(lcd), happy_right_eye(lcd)
// angry_left_eye(lcd), angry_right_eye(lcd), sleepy_left_eye(lcd), sleepy_right_eye(lcd)

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd1(44, 45, 46, 47, 48, 49); // 왼쪽 LCD 연결
LiquidCrystal lcd2(36, 37, 38, 39, 40, 41); // 오른쪽 LCD 연결

// 사용자 정의 문자 데이터
byte user1[8] = { // 모두 채움
  B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111
};

byte user2[8] = { //왼쪽 위 채움
   B10000, B11000, B11000, B11100, B11100, B11110, B11110, B11111
};
byte user3[8] = { //오른쪽 위 채움
   B11111, B11110, B11110, B11100, B11100, B11000, B11000, B10000
};
byte user4[8] = { //왼쪽 아래 채움
   B00001, B00011, B00011, B00111, B00111, B01111, B01111, B11111
};
byte user5[8] = { //오른쪽 아래 채움
   B11111, B01111, B01111, B00111, B00111, B00011, B00011, B00001
};
byte user6[8] = { //왼쪽 하트1
   B00001, B00011, B00111, B01111, B11111, B01111, B00111, B00011
};
byte user7[8] = { //왼쪽 하트2
   B11111, B11111, B11111, B11111, B11110, B11100, B11000, B10000
};
byte user8[8] = { //왼쪽 하트3
   B11100, B11000, B10000, B00000, B00000, B00000, B00000, B00000
};
byte user9[8] = { //오른쪽 하트1
   B00011, B00111, B01111, B11111, B01111, B00111, B00011, B00001
};
byte user10[8] = { //오른쪽 하트2
   B10000, B11000, B11100, B11110, B11111, B11111, B11111, B11111
};
byte user11[8] = { //오른쪽 하트3
   B00000, B00000, B00000, B00000, B00000, B10000, B11000, B11100
};

void left_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.createChar(1, user2); // 사용자 정의 문자 2 생성
  lcd.createChar(2, user3); // 사용자 정의 문자 3 생성  
  lcd.createChar(3, user4); // 사용자 정의 문자 2 생성
  lcd.createChar(4, user5); // 사용자 정의 문자 3 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기
  
    lcd.setCursor(6, 0); 
    lcd.write(byte(4));
    lcd.setCursor(7, 1); 
    lcd.write(byte(4)); 
    lcd.setCursor(7, 0); 
    lcd.write(byte(1));
    lcd.setCursor(8, 1); 
    lcd.write(byte(1)); 
    lcd.setCursor(11, 0); 
    lcd.write(byte(0));
    lcd.setCursor(12, 0); 
    lcd.write(byte(0)); 
    lcd.setCursor(13, 0); 
    lcd.write(byte(0));
    lcd.setCursor(14, 0); 
    lcd.write(byte(0)); 
    lcd.setCursor(15, 0); 
    lcd.write(byte(0));
    
  //lcd.clear(); // LCD 화면 지우기
}

void right_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.createChar(1, user2); // 사용자 정의 문자 2 생성
  lcd.createChar(2, user3); // 사용자 정의 문자 3 생성  
  lcd.createChar(3, user4); // 사용자 정의 문자 2 생성
  lcd.createChar(4, user5); // 사용자 정의 문자 3 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(6, 1); 
  lcd.write(byte(3));
  lcd.setCursor(7, 1); 
  lcd.write(byte(2)); 
  lcd.setCursor(7, 0); 
  lcd.write(byte(3));
  lcd.setCursor(8, 0); 
  lcd.write(byte(2)); 
  lcd.setCursor(11, 1); 
  lcd.write(byte(0));
  lcd.setCursor(12, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(13, 1); 
  lcd.write(byte(0));
  lcd.setCursor(14, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(15, 1); 
  lcd.write(byte(0)); 
}


void happy_right_eye(LiquidCrystal lcd){
  lcd.createChar(0, user4); 
  lcd.createChar(1, user3); 
  lcd.createChar(2, user6);  
  lcd.createChar(3, user7); 
  lcd.createChar(4, user8); 
  lcd.createChar(5, user9); 
  lcd.createChar(6, user10); 
  lcd.createChar(7, user11); 

  
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(6, 1); 
  lcd.write(byte(0));
  lcd.setCursor(7, 1); 
  lcd.write(byte(1)); 
  lcd.setCursor(7, 0); 
  lcd.write(byte(0));
  lcd.setCursor(8, 0); 
  lcd.write(byte(1)); 
  
  lcd.setCursor(11, 1); 
  lcd.write(byte(2));
  lcd.setCursor(12, 1); 
  lcd.write(byte(3)); 
  lcd.setCursor(13, 1); 
  lcd.write(byte(4));
  
  lcd.setCursor(11, 0); 
  lcd.write(byte(5)); 
  lcd.setCursor(12, 0); 
  lcd.write(byte(6)); 
  lcd.setCursor(13, 0); 
  lcd.write(byte(7)); 
}

void happy_left_eye(LiquidCrystal lcd){
  lcd.createChar(0, user5); 
  lcd.createChar(1, user2); 
  lcd.createChar(2, user6);  
  lcd.createChar(3, user7); 
  lcd.createChar(4, user8); 
  lcd.createChar(5, user9); 
  lcd.createChar(6, user10); 
  lcd.createChar(7, user11); 

  
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(6, 0); 
  lcd.write(byte(0));
  lcd.setCursor(7, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(7, 0); 
  lcd.write(byte(1));
  lcd.setCursor(8, 1); 
  lcd.write(byte(1)); 
  
  lcd.setCursor(11, 1); 
  lcd.write(byte(2));
  lcd.setCursor(12, 1); 
  lcd.write(byte(3)); 
  lcd.setCursor(13, 1); 
  lcd.write(byte(4));
  
  lcd.setCursor(11, 0); 
  lcd.write(byte(5)); 
  lcd.setCursor(12, 0); 
  lcd.write(byte(6)); 
  lcd.setCursor(13, 0); 
  lcd.write(byte(7)); 
}

void angry_left_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.createChar(1, user3); // 사용자 정의 문자 2 생성
  lcd.createChar(2, user3); // 사용자 정의 문자 3 생성  
  lcd.createChar(3, user4); // 사용자 정의 문자 2 생성
  lcd.createChar(4, user4); // 사용자 정의 문자 3 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기
  lcd.setCursor(6, 0); 
  lcd.write(byte(4));
  lcd.setCursor(5, 1); 
  lcd.write(byte(4)); 
  lcd.setCursor(7, 0); 
  lcd.write(byte(1));
  lcd.setCursor(6, 1); 
  lcd.write(byte(1)); 
  lcd.setCursor(11, 0); 
  lcd.write(byte(0));
  lcd.setCursor(12, 0); 
  lcd.write(byte(0)); 
  lcd.setCursor(13, 0); 
  lcd.write(byte(0));
  lcd.setCursor(14, 0); 
  lcd.write(byte(0)); 
  lcd.setCursor(15, 0); 
  lcd.write(byte(0)); 
  
}
void angry_right_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.createChar(1, user2); // 사용자 정의 문자 2 생성
  lcd.createChar(2, user3); // 사용자 정의 문자 3 생성  
  lcd.createChar(3, user4); // 사용자 정의 문자 2 생성
  lcd.createChar(4, user5); // 사용자 정의 문자 3 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(5, 0); 
  lcd.write(byte(4));
  lcd.setCursor(6, 1); 
  lcd.write(byte(4)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(1));
  lcd.setCursor(7, 1); 
  lcd.write(byte(1)); 
  lcd.setCursor(11, 1); 
  lcd.write(byte(0));
  lcd.setCursor(12, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(13, 1); 
  lcd.write(byte(0));
  lcd.setCursor(14, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(15, 1); 
  lcd.write(byte(0)); 

}
void sleepy_left_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(11, 0); 
  lcd.write(byte(0));
  lcd.setCursor(11, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(12, 0); 
  lcd.write(byte(0));
  lcd.setCursor(12, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(14, 0); 
  lcd.write(byte(0));
  lcd.setCursor(15, 0); 
  lcd.write(byte(0)); 
}

void sleepy_right_eye(LiquidCrystal lcd){
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(11, 0); 
  lcd.write(byte(0));
  lcd.setCursor(11, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(12, 0); 
  lcd.write(byte(0));
  lcd.setCursor(12, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(14, 1); 
  lcd.write(byte(0));
  lcd.setCursor(15, 1); 
  lcd.write(byte(0)); 

}

////////////////////////////////////////////////////////////////

#include <Wire.h>
#include <ADXL345.h>
ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

int pin_button = 14; // 버튼 연결 핀
boolean state_previous = false; // 버튼의 이전 상태
boolean state_current; // 버튼의 현재 상태
int count = 0; // 버튼을 누른 횟수

void setup(){
  Serial.begin(9600);
  pinMode (piezoPin, OUTPUT); 
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  pinMode(pin_button, INPUT);
  
  // 가속도 센서 setup
  adxl.powerOn();

  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment
  adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?
 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
  
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);
 
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);
 
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625us per increment
  adxl.setDoubleTapLatency(80); //1.25ms per increment
  adxl.setDoubleTapWindow(200); //1.25ms per increment

  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment

  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,    ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,   ADXL345_INT1_PIN );
 
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
  adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);
}

int hand_bright, head_bright;
int flag = 1;

void loop(){
  
  //read interrupts source and look for triggerd actions
  byte interrupts = adxl.getInterruptSource(); 
  int  double_tap=0;
  long weight;
  
  // 무게 감지
  if (scale.is_ready()) {
    weight = scale.read();
  }
  
  state_current = digitalRead(pin_button); // 버튼 상태 읽기
  if (state_current) { // 버튼을 누른 경우
    if (state_previous == false) { // 이전 상태와 비교
      count++; // 상태가 바뀐 경우에만 횟수 증가
      state_previous = true;
      Serial.println(count); // 버튼이 눌러진 횟수 출력
      flag = 1;
    }
    delay(50); // 디바운싱
  }
  else {
    state_previous = false;
  }
  
  if (count%2 == 1) {
    if (flag) {
        off(); // 버튼이 꺼지면 재생음(도솔미도) 출력
        lcd1.clear(); // lcd 지움
        lcd2.clear();
        flag = 0;
      }
  }
  if (count%2 == 0){
      left_eye(lcd1);
      right_eye(lcd2);
      if (flag) { //제일 처음, 또는 버튼이 켜지면 재생음(도미솔도) 출력
        on();
        flag = 0;
      }
      //double tap
      if(adxl.triggered(interrupts, ADXL345_DOUBLE_TAP)){
        //Serial.println("double tap"); 
        double_tap = 1;
      }
      ///////////////////////////////////////////////////////
      // accelrator sensor -> happy
      // 화난 표정 + 마리오 음악 + 서보모터 귀 두 번 움직임(delay=3)
      if (double_tap == 1){ // double tap -> angry
        angry_left_eye(lcd1);
        angry_right_eye(lcd2);
        Serial.println("angry"); 
        mario_music(piezoPin);
        servo_function(servoPin, servoPin2);
        servo_function(servoPin, servoPin2);
      }
      
      ////////////////////////////////////////////////////////
      // illuminance sensor (hand) -> very happy
      // 기쁜 표정 + 학교종 음악 + 서보모터 천천히 움직임(delay=6)
      hand_bright = analogRead(A3);
      //Serial.println(hand_bright);
      if (hand_bright >= 1000){
        happy_left_eye(lcd1);
        happy_right_eye(lcd2);
        Serial.println("very happy"); 
        school_bell_music(piezoPin);
        servo_slow_function(servoPin, servoPin2);
      }
      ///////////////////////////////////////////////////////
      // weight sensor -> happy
      // 기쁜 표정 + 엘리제 음악 + 서보모터 반대로 움직임(delay=3)
      if (weight < -220000){
        happy_left_eye(lcd1);
        happy_right_eye(lcd2);
        Serial.println("happy");
        eliz_music(piezoPin);
        servo_cute_function(servoPin, servoPin2);
      }
      ///////////////////////////////////////////////////////
      // illuminance sensor (head) -> sleepy
      // 졸리는 표정 + 서보모터 엄청 천천히 움직임(delay=10)
      head_bright = analogRead(A5);
      //Serial.println(head_bright);
      if (head_bright >= 1000){
        sleepy_left_eye(lcd1);
        sleepy_right_eye(lcd2);
        servo_very_slow_function(servoPin, servoPin2);
        Serial.println("sleepy"); 
      }
      ///////////////////////////////////////////////////////
      
      delay(3000);
  }
}
