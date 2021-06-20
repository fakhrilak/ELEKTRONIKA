#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(A0, A1, A2);
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
int count = 0;

//waktu local
int jam_local = 0;
int menit_local = 0;
int detik_local = 0;

//batas waktu
int batas_jam = 4;
int batas_menit = 59;
int batas_detik = 59;

//setjam
int set_jam = 0;

int set_batas_jam_eeprom = 950;
int count_9 = 0;
int count_3 = 0;
int count_6 = 1;

int count_click = 0;

//waktu tampil
int menit_tampil = 59;
int detik_tampil = 59;

//waktu read eeprom
int eeprom_detik;
int eeprom_menit;
int eeprom_jam;
int count_start = 0;
int delayy = 300;
int triger = 0;

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
  //writeIntIntoEEPROM(2, 0);
  reset_Lcd();
}

void loop() {
  // put your main code here, to run repeatedly:
  int Reset = digitalRead(reset);
  int Up = digitalRead(up);
  int Down = digitalRead(down);
  int Star_Stop = digitalRead(start);
  triger = Star_Stop;
  tampil_Lcd();
      if(Star_Stop == 1){
        delayy = 0;
         if(count_click == 0){
          //oper jam_local to setjam
          set_jam = jam_local;
          set_jam = set_jam -1;
          jam_local = set_jam;
          if (jam_local < 0){
            jam_local = 0;
            menit_local = 0;
            detik_local = 0;
          }else{
            menit_local = 58;
            detik_local = 59;
          }
          count_click = 1;
         }  
         // jika jam sudah mencapai batas beep 9x
         else if(jam_local == 0 and menit_local == 0 and detik_local == 0 && count_9 ==0){
            digitalWrite(relay,LOW);
            sembilan();
            count_9 = count_9 + 1;
         }else if(jam_local != 0 or menit_local != 0 or detik_local != 0){
             digitalWrite(relay,HIGH);
             delayy = 0;
             menu_waktu();
          }
     }
     else if (Star_Stop ==0){
          delayy = 300;
          if(count != 0){
              digitalWrite(relay,LOW);
              if(Star_Stop==0 && Up == 1 && eeprom_jam != 1000){
              jam_local = jam_local + 1;
              }
              else if(Star_Stop==0 && Down == 1 && eeprom_jam != 1000){
              jam_local = jam_local - 1;
              }
          }else if(count == 0){
            eeprom_detik = EEPROM.read(1);
            if(eeprom_detik <= 56){
               writeIntIntoEEPROM(0, eeprom_detik + 3);
               eeprom_detik = EEPROM.read(1);
            }else if(eeprom_detik >=57){
              eeprom_detik = eeprom_detik + 3;
              if(eeprom_detik >= 59){
                eeprom_detik = eeprom_detik - 59;
                writeIntIntoEEPROM(0, eeprom_detik);
                eeprom_detik = EEPROM.read(1);
              }
            }
            eeprom_menit = EEPROM.read(2);
            eeprom_jam = EEPROM.read(3);
    
                //jika jam eeprom sudah mencapai 950 beep 3x
                if(eeprom_jam >= set_batas_jam_eeprom && count_3 == 0){
                tiga();
                count_3 = count_3 + 1;
                }
          }          
      }
//  jika jam eeprom sudah mencapai 1000
  if(Reset == 1){
    menu_reset();
  }
  Serial.print(delayy);
  Serial.print(" : ");
  Serial.print(jam_local);
  Serial.print(" : ");
  Serial.print(menit_local);
  Serial.print(" : ");
  Serial.println(detik_local);
  count = count + 1;
  delay(delayy);
}
