#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int rawValue; // A/D readings
int pb11;
int pb22;
int x = 0;
int offset = 102;
int res  = 3;
int pb1 = 4;
int pb2 = 2;
int menu = 0;
int gendre = 0;
int umur = 20;
int tinggi_badan = 140;
double volt = 0,as = 0,V1=0;
double tampil_V = 0,tampil_V1=0,akar= 0,q = 0,pascals=0,V=0;
float lempar  = 0;
int nilai,reset = 0;
void setup() {
  Serial.begin(9600);
  pinMode(res,INPUT);
  lcd.begin();
  lcd.setCursor(3,0);
  lcd.print("Prototype");
  lcd.setCursor(3,1);
  lcd.print("Spirometer");
  delay(3000);
}

void loop() {
  x = analogRead(A0);
  int ress = digitalRead(res);
  pb11 = digitalRead(pb1);
  pb22 = digitalRead(pb2);
  Serial.print(ress);
  Serial.print(pb11);
  Serial.println(pb22);
  if (ress == 1){
    tampil_V = 0;
  }
  if(ress ==1){
    menu = menu +1;
  }
  if (menu == 0){
     clear_lcd();
     namaDewi();
  }
  if (menu == 1){
    clear_lcd();
    pengukuran_2();
  }
  else if(menu == 2){
    clear_lcd();
    penentuan_tinggi();
  }
  else if(menu == 3){
    clear_lcd();
    male_female();
  }
  else if(menu == 4){
    clear_lcd();
    umur_r();
  }
  else if(menu == 5){
    clear_lcd();
    hasil();
  }
  else if(menu == 6){
    clear_lcd();
    reset_();
  }
  if(menu == 7){
    menu = 0;
  }
  Serial.print("tampil_V ");
  Serial.println(tampil_V);
  Serial.print("V ");
  Serial.println(V);
  Serial.print("lempar ");
  Serial.println(lempar);
  delay(300);
}
