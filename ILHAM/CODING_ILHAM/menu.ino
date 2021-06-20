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
  delay(100);
  return 1;
}
int menu_waktu(){
  if (detikk() == 1){
    int detik = readIntFromEEPROM(0);
    if(detik >= 59 ){
      writeIntIntoEEPROM(0, 0);
      int menit = readIntFromEEPROM(1);
      if(menit >= 59){
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
      }else if(detik_local == 0){
        detik_local = 59;
        menit_local = menit_local - 1;
      }
      writeIntIntoEEPROM(0, detik);
      eeprom_detik = readIntFromEEPROM(0);
      }    
    }
  }

int lima(){
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
}
int tiga(){
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
      digitalWrite(buzzer,HIGH);
      delay(300);
      digitalWrite(buzzer,LOW);
      delay(300);
}
