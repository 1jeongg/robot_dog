// 강아지 눈 함수 최종본(기본, 행복, 분노, 졸림 LCD 표현)
// main함수에서는 delay로 인한 오류 때문에 눈썹의 움직임 구현 실패함

#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd1(44, 45, 46, 47, 48, 49); // 왼쪽 LCD 연결
LiquidCrystal lcd2(36, 37, 38, 39, 40, 41); // 오른쪽 LCD 연결
LiquidCrystal lcd3(30, 31, 32, 33, 34, 35); // 오른쪽 LCD 연결
// 사용자 정의 문자 데이터
byte user1[8] = {
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

void both_high_eye(LiquidCrystal lcd,LiquidCrystal lcd2){
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

  lcd2.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd2.createChar(1, user2); // 사용자 정의 문자 2 생성
  lcd2.createChar(2, user3); // 사용자 정의 문자 3 생성  
  lcd2.createChar(3, user4); // 사용자 정의 문자 2 생성
  lcd2.createChar(4, user5); // 사용자 정의 문자 3 생성
  lcd2.begin(16, 2); // LCD 크기 설정
  lcd2.clear(); // LCD 화면 지우기

  lcd2.setCursor(6, 1); 
  lcd2.write(byte(3));
  lcd2.setCursor(7, 1); 
  lcd2.write(byte(2)); 
  lcd2.setCursor(7, 0); 
  lcd2.write(byte(3));
  lcd2.setCursor(8, 0); 
  lcd2.write(byte(2)); 
  lcd2.setCursor(11, 1); 
  lcd2.write(byte(0));
  lcd2.setCursor(12, 1); 
  lcd2.write(byte(0)); 
  lcd2.setCursor(13, 1); 
  lcd2.write(byte(0));
  lcd2.setCursor(14, 1); 
  lcd2.write(byte(0)); 
  lcd2.setCursor(15, 1); 
  lcd2.write(byte(0)); 
  
}

void both_low_eye(LiquidCrystal lcd1,LiquidCrystal lcd2){

  
}
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
  
  delay(2000);
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(5, 0); 
  lcd.write(byte(4));
  lcd.setCursor(6, 1); 
  lcd.write(byte(4)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(1));
  lcd.setCursor(7, 1); 
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
  
  delay(2000);
  lcd.clear();
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
  
  delay(2000);
  lcd.clear(); // LCD 화면 지우기
  
   lcd.setCursor(5, 1); 
  lcd.write(byte(3));
  lcd.setCursor(6, 1); 
  lcd.write(byte(2)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(3));
  lcd.setCursor(7, 0); 
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
  
  delay(2000);
  lcd.clear();
  
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

  
  delay(1000);
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(5, 1); 
  lcd.write(byte(0));
  lcd.setCursor(6, 1); 
  lcd.write(byte(1)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(0));
  lcd.setCursor(7, 0); 
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
  
  delay(1000);
  lcd.clear();
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

  
  delay(1000);
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(5, 0); 
  lcd.write(byte(0));
  lcd.setCursor(6, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(1));
  lcd.setCursor(7, 1); 
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
  
  delay(1000);
  lcd.clear();
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
  
  delay(1000);
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(5, 0); 
  lcd.write(byte(4));
  lcd.setCursor(4, 1); 
  lcd.write(byte(4)); 
  lcd.setCursor(6, 0); 
  lcd.write(byte(1));
  lcd.setCursor(5, 1); 
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
  
  delay(1000);
  lcd.clear();
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
  
  delay(1000);
  lcd.clear(); // LCD 화면 지우기
  
  lcd.setCursor(4, 0); 
  lcd.write(byte(4));
  lcd.setCursor(5, 1); 
  lcd.write(byte(4)); 
  lcd.setCursor(5, 0); 
  lcd.write(byte(1));
  lcd.setCursor(6, 1); 
  lcd.write(byte(1)); 
  lcd.setCursor(11, 1); 
  lcd.write(byte(0));
  lcd.setCursor(12,1); 
  lcd.write(byte(0)); 
  lcd.setCursor(13, 1); 
  lcd.write(byte(0));
  lcd.setCursor(14, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(15, 1); 
  lcd.write(byte(0)); 
  
  delay(1000);
  lcd.clear();
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

  delay(5000);
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(10, 0); 
  lcd.write(byte(0));
  lcd.setCursor(10, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(11, 0); 
  lcd.write(byte(0));
  lcd.setCursor(11, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(14, 0); 
  lcd.write(byte(0));
  lcd.setCursor(15, 0); 
  lcd.write(byte(0)); 

  delay(5000);
  lcd.clear(); // LCD 화면 지우기
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

  delay(5000);
  lcd.clear(); // LCD 화면 지우기

  lcd.setCursor(10, 0); 
  lcd.write(byte(0));
  lcd.setCursor(10, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(11, 0); 
  lcd.write(byte(0));
  lcd.setCursor(11, 1); 
  lcd.write(byte(0)); 
  lcd.setCursor(14, 1); 
  lcd.write(byte(0));
  lcd.setCursor(15, 1); 
  lcd.write(byte(0)); 

  delay(5000);
  lcd.clear(); // LCD 화면 지우기
}

void setup() {
 
}

void loop(){
  both_high_eye(lcd1,lcd2);
  delay(1000);
  /*delay(1000);
  both_low_eye(lcd1,lcd2);
  //left_eye(lcd1);
  right_eye(lcd2);
 */ 
  
  /*
  delay(1000);
  happy_left_eye(lcd);
  delay(1000);
  happy_right_eye(lcd);
  delay(1000);
  angry_left_eye(lcd);
  delay(1000);
  angry_right_eye(lcd);
  delay(1000);
  sleepy_left_eye(lcd);
  delay(1000);
  sleepy_right_eye(lcd);
  delay(1000);
  */
}
