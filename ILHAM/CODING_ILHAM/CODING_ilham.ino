#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
int aa;
int reset = 4;
int up = 7;
int down = 5;
int start = 6;
int relay = 12;
int clockk = A0;
int buzzer =13;
int live_time;
int set_alarm = 6;
int count = 0;
int set_time = 0;

//waktu local
int jam_local = 0;
int menit_local = 0;
int detik_local = 0;

//waktu tampil
int menit_tampil = 59;
int detik_tampil = 59;

int menit_state = 0;
int detik_state = 0;

int lifetime = 7500;
//waktu read eeprom
int eeprom_detik;
int eeprom_menit;
int eeprom_jam;
int count_start = 0;


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
  lcd.setCursor(5,0);
  lcd.print("ATEM");
  lcd.setCursor(-2,1);
  lcd.print("ANDAKARA JAKARTA");
  lcd.setCursor(-4,2);
  lcd.print("ILHAM NURFAUZAN");
  lcd.setCursor(0,3);
  lcd.print("18242041");
  delay(3000);
//   writeIntIntoEEPROM(2, 12);
  reset_Lcd();
}

void loop() {
  // put your main code here, to run repeatedly:
  int Reset = digitalRead(reset);
  int Up = digitalRead(up);
  int Down = digitalRead(down);
  int Star_Stop = digitalRead(start);
  tampil_Lcd();
  if(Star_Stop == 1){
//     if(count == 0){
//      menit_state = menit_local;
//      detik_state = detik_local;
//      menit_local = 0;
//      detik_local = 0;
//     }
    if(detik_local != 0 or menit_local != 0){
        if(eeprom_menit == 125){
          lima();
        }else if(eeprom_jam != 125){
           digitalWrite(relay,0);
           menu_waktu();
        }
    }else{
      tiga();
    }
    
  }else if (count == 0&&Star_Stop ==0){
    eeprom_detik = EEPROM.read(1);
    eeprom_menit = EEPROM.read(2);
    eeprom_jam = EEPROM.read(3);
    if(eeprom_menit == lifetime){
      
    }
  }
  if(Star_Stop == 0){
    digitalWrite(relay,1);
  }
  if(Reset == 1){
    menu_reset();
  }
  if(Up == 1 && set_time == 1){
    menit_local = menit_local + 1;
  }
  if (Down == 1 && set_time == 1){
    menit_local = menit_local - 1;
  }
  if(Up == 1 && set_time == 0){
    detik_local = detik_local + 1;
  }
  if (Down == 1 && set_time == 0){
    detik_local = detik_local - 1;
  }
  
  if (Down == 1 && Up == 1){
    if(set_time==1){
      set_time = 0;
    }else if(set_time == 0){
      set_time = 1;
    }
  }
  Serial.println(count);
  Serial.print(" : ");
  Serial.print(detik_local);
  Serial.print(" : ");
  Serial.println(menit_local);
  count = count + 1; 

delay(400);
}
