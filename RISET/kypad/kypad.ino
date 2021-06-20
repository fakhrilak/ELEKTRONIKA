#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
//  lcd.setCursor(3,0);
//  lcd.print("Prototype");
//  lcd.setCursor(3,1);
//  lcd.print("Spirometer");
  for(int a = 8;a<=10;a++){
    pinMode(a,OUTPUT);
    digitalWrite(a,HIGH);
  }
  for(int b = 5;b<=7;b++){
    pinMode(b,INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int a = 8;a<=10;a++){
    digitalWrite(a,LOW);
    delay(50);
    if (9==LOW&&7==LOW){
      lcd.setCursor(1,0);
      lcd.print("haha");
    }
    digitalWrite(a,HIGH);
    delay(50);
  }
  int aa = digitalRead(5);
  int bb = digitalRead(6);
  int cc = digitalRead(7);
}
