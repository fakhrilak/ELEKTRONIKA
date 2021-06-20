int menu_reset(){
  writeIntIntoEEPROM(0, 0);
  writeIntIntoEEPROM(1, 0);
  writeIntIntoEEPROM(2, 0);
  eeprom_detik=0;
  eeprom_menit=0;
  eeprom_jam =0;
  jam_local=0;
  menit_local=0;
  detik_local=0;
  reset_Lcd();
}
int detikk(){
  delay(505);
  return 1;
}
int menu_waktu(){
  if (detikk() == 1){
    int detik = readIntFromEEPROM(0);
    int detik_count = readIntFromEEPROM(0);
    if(detik >= batas_detik ){
      writeIntIntoEEPROM(0, 0);
      int menit = readIntFromEEPROM(1);
      if(menit >= batas_menit){
        writeIntIntoEEPROM(1, 0);
        int jam = readIntFromEEPROM(2);
        writeIntIntoEEPROM(2, jam);
        eeprom_jam = readIntFromEEPROM(2);
        jam = jam + 1;
        writeIntIntoEEPROM(2, jam);
        eeprom_jam = readIntFromEEPROM(2);
      }else{
        menit = menit + 1;
        writeIntIntoEEPROM(1, menit);
        eeprom_menit = readIntFromEEPROM(1);
      }
    }else if(detikk() == 1){
      detik = detik + 1;
      if(detik_local >= 1){
        detik_local = detik_local - 1;
        if(detik_local == 10){ ///locat waktu
          detik_local = detik_local - 5;
        }
      }else if(detik_local == 0){
        detik_local = batas_detik;
        if(menit_local >= 1){
          menit_local = menit_local - 1;
        }else if(menit_local == 0){
          menit_local = batas_menit;
          if(jam_local >=1){
            jam_local = jam_local - 1;
          }
        }
      }
      if(detik == 10){///locat komulatif  
        detik = detik - 5;
        int a = detik + 10;
        writeIntIntoEEPROM(0,a );
      }else{
        writeIntIntoEEPROM(0, detik);
      }
        eeprom_detik = readIntFromEEPROM(0);
      }    
    }
  }
 int sembilan(){
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
 }
int tiga(){
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
  delay(500);
  reset_Lcd();
  digitalWrite(buzzer,HIGH);
  delay(500);
  tampil_Lcd();
  digitalWrite(buzzer,LOW);
}
