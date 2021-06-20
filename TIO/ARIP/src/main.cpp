#include<Arduino.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 4);

void writeIntIntoEEPROM(int address, int number)
{ 
  byte byte1 = number >> 8;
  byte byte2 = number & 0xFF;
  EEPROM.write(address, byte1);
  EEPROM.write(address + 1, byte2);
}

int readIntFromEEPROM(int address)
{
  byte byte1 = EEPROM.read(address);
  byte byte2 = EEPROM.read(address + 1);
  return (byte1 << 8) + byte2;
}

int aa;
int reset = 10;
int up = 12;
int down = 11;
int start = 13;
int relay = 6;
int clockk = A0;
int buzzer =5;
int live_time;
int set_alarm = 6;

//waktu local
int jam_local = 0;
int counter_A = 0;
//int menit = 0;
//int detik = 0;

//waktu read eeprom
int eeprom_detik;
int eeprom_menit;
int eeprom_jam;
int count_start = 0;


int menu_reset(){
  writeIntIntoEEPROM(0, 0);
  writeIntIntoEEPROM(1, 0);
  writeIntIntoEEPROM(2, 0);
  eeprom_detik=0;
  eeprom_menit=0;
  eeprom_jam =0;
  lcd.setCursor(-1,2);
  lcd.print(eeprom_jam);
  lcd.setCursor(3,2);
  lcd.print(":");
  lcd.setCursor(4,2);
  lcd.print(eeprom_menit);
  lcd.setCursor(7,2);
  lcd.print(":");
  lcd.setCursor(8,2);
  lcd.print(eeprom_detik);
}
int detikk(){
  delay(1);
  return 1; 
}
int menu_waktu(){
  lcd.setCursor(2,2);
  lcd.print("         ");
  lcd.setCursor(-4,3);
  lcd.print("                ");
  lcd.setCursor(-1,2);
  lcd.print(eeprom_jam);
  lcd.setCursor(3,2);
  lcd.print(":");
  lcd.setCursor(4,2);
  lcd.print(eeprom_menit);
  lcd.setCursor(7,2);
  lcd.print(":");
  lcd.setCursor(8,2);
  lcd.print(eeprom_detik);
  lcd.setCursor(-4,3);
  lcd.print(set_alarm);
  if (detikk() == 1){
    int detik = readIntFromEEPROM(0);
    
    if(detik == 15){
      writeIntIntoEEPROM(0, 0);
      int menit = readIntFromEEPROM(1);
      if(menit >= 3){
        writeIntIntoEEPROM(1, 0);
        int jam = readIntFromEEPROM(2);
        if(jam == 4){
          writeIntIntoEEPROM(2, jam);
          eeprom_jam = readIntFromEEPROM(2);
          }else if(jam == 2){
          int bb = 0;
          while(bb<=3){
            Serial.println("cok");
            analogWrite(buzzer,255);
              delay(100);
              analogWrite(buzzer,0);
              delay(100);
            bb++;
          }
          jam = jam + 1;
          writeIntIntoEEPROM(2, jam);
          eeprom_jam = readIntFromEEPROM(2);
        }else{
          jam = jam + 1;
          jam_local = jam + 1;
          writeIntIntoEEPROM(2, jam);
          eeprom_jam = readIntFromEEPROM(2);
        }
      }else if(eeprom_detik == 9){
         eeprom_jam = readIntFromEEPROM(2);
      }else{
        menit = menit + 1;
        writeIntIntoEEPROM(1, menit);
        eeprom_menit = readIntFromEEPROM(1);
      }
    }else if(detikk() == 1 && eeprom_jam != 4){
      detik = detik + 1;
      writeIntIntoEEPROM(0, detik);
      eeprom_detik = readIntFromEEPROM(0);
    }
    }
  }


void setup() {
  // put your setup code here, to run once:
  pinMode(reset,INPUT);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  pinMode(start,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(relay,OUTPUT);
  lcd.begin();
  Serial.begin(9600);
  lcd.setCursor(1,0);
  lcd.print("ARIF SETYO AJI");
  lcd.setCursor(4,1);
  lcd.print("18242032");
  lcd.setCursor(2,2);
  lcd.print("ATEM");
  lcd.setCursor(-4,3);
  lcd.print("ANDAKARA JAKARTA");
  delay(3000);
  lcd.setCursor(2,2);
  lcd.print("         ");
  lcd.setCursor(-4,3);
  lcd.print("                ");
//  writeIntIntoEEPROM(0, 0);
//  eeprom_detik = readIntFromEEPROM(0);
//  eeprom_menit = readIntFromEEPROM(1);
//  writeIntIntoEEPROM(1, 0);
//  writeIntIntoEEPROM(2, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Reset = digitalRead(reset);
  int Up = digitalRead(up);
  int Down = digitalRead(down);
  int Star_Stop = digitalRead(start);
  lcd.setCursor(-1,2);
  lcd.print(eeprom_jam);
  lcd.setCursor(3,2);
  lcd.print(":");
  lcd.setCursor(4,2);
  lcd.print(eeprom_menit);
  lcd.setCursor(7,2);
  lcd.print(":");
  lcd.setCursor(8,2);
  lcd.print(eeprom_detik);
  lcd.setCursor(-4,3);
  lcd.print(set_alarm);
    
//  digitalWrite(buzzer,HIGH);
  if(Star_Stop == 1 && jam_local != set_alarm){
     menu_waktu();
    digitalWrite(relay,LOW); 
  }else if(Star_Stop == 1 && jam_local == set_alarm){
    counter_A = counter_A +1;
      if(counter_A < 2){
        int bb = 0;
        while(bb<=9){
          analogWrite(buzzer,200);
          delay(100);
          digitalWrite(buzzer,LOW);
          delay(100);
          bb++;
        }
      Star_Stop =0;
        digitalWrite(relay,HIGH);
      }else{
        Star_Stop =0;
        digitalWrite(relay,HIGH);
      } 
  }else if(Star_Stop == 0){
    counter_A = 0;
    digitalWrite(relay,HIGH);
    jam_local = 0;
  }

  if(Reset == 1){ 
    menu_reset();
  }
  if(Up == 1){
    set_alarm = set_alarm + 1;
  }
  if(Down==1){
    set_alarm = set_alarm - 1;
  }
  if(eeprom_jam == 4){
    int cc = 0;
    while(cc<=12){
       Serial.println("cek");
       analogWrite(buzzer,200);
       delay(100);
       analogWrite(buzzer,0);
       delay(100);
       cc++;
  }
  }

delay(200);
}

