#include <Arduino.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

int buzzer = 13;
int relay =  12;
int reset = 4;
int down = 5;
int start = 6;
int up = 7;


int jam_local = 0;
int menit_local = 0;
int detik_local = 0;
int counter_A = 0;

int setAlarm = 0;


int eeprom_detik;
int eeprom_menit;
int eeprom_jam;
int count_start = 0;


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
  Serial.print("eeprom = ");
  Serial.print(eeprom_jam);
  Serial.print(" : ");
  Serial.print(eeprom_menit);
  Serial.print(" : ");
  Serial.println(eeprom_detik);
  Serial.print("local = ");
  Serial.print(jam_local);
  Serial.print(" : ");
  Serial.print(menit_local);
  Serial.print(" : ");
  Serial.println(detik_local);
}
int detikk(){
  delay(100);
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
  // lcd.setCursor(-4,3);
  // lcd.print(set_alarm);
  Serial.print("eeprom = ");
  Serial.print(eeprom_jam);
  Serial.print(" : ");
  Serial.print(eeprom_menit);
  Serial.print(" : ");
  Serial.println(eeprom_detik);
  Serial.print("local = ");
  Serial.print(jam_local);
  Serial.print(" : ");
  Serial.print(menit_local);
  Serial.print(" : ");
  Serial.println(detik_local);
  if (detikk() == 1){
    int detik = readIntFromEEPROM(0);
    
    if(detik == 15){
      writeIntIntoEEPROM(0, 0);
      detik_local = 0;
      int menit = readIntFromEEPROM(1);
      
      if(menit >= 3){
        writeIntIntoEEPROM(1, 0);
        menit_local = 0;
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
        menit_local = menit_local + 1;
        writeIntIntoEEPROM(1, menit);
        eeprom_menit = readIntFromEEPROM(1);
      }
    }else if(detikk() == 1 && eeprom_jam != 4){
      detik = detik + 1;
      detik_local = detik_local + 1;
      writeIntIntoEEPROM(0, detik);
      eeprom_detik = readIntFromEEPROM(0);
    }
    }
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
  pinMode(reset,INPUT);
  pinMode(down,INPUT);
  pinMode(start,INPUT);
  pinMode(up,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Reset = digitalRead(reset);
  int Down = digitalRead(down);
  int UP = digitalRead(up);
  int Start = digitalRead(start);

  if(Start == 1){
    menu_waktu();
  }
  if(Reset == 1){
    menu_reset();
  }

  if(UP == 1){
    setAlarm = setAlarm + 1;
  }
  if(Down == 1){
    setAlarm = setAlarm - 1;
  }
  lcd.print(eeprom_detik);
  Serial.print("eeprom = ");
  Serial.print(eeprom_jam);
  Serial.print(" : ");
  Serial.print(eeprom_menit);
  Serial.print(" : ");
  Serial.println(eeprom_detik);
  Serial.print("local = ");
  Serial.print(jam_local);
  Serial.print(" : ");
  Serial.print(menit_local);
  Serial.print(" : ");
  Serial.println(detik_local);
  if(jam_local == setAlarm){
    counter_A =  counter_A + 1;
    if(counter_A <= 1){
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
      delay(1000);
    }
  }

}