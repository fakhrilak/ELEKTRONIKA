int reset_Lcd(){
  lcd.setCursor(1,0);
  lcd.print("                 ");
  lcd.setCursor(4,1);
  lcd.print("            ");
  lcd.setCursor(2,2);
  lcd.print("      ");
  lcd.setCursor(-4,3);
  lcd.print("                  ");
}

int tampil_Lcd(){
  lcd.setCursor(-1,0);
  lcd.print("KOMULATIF COUNT");
  if(eeprom_jam > 9){
    lcd.setCursor(0,1);
    lcd.print(eeprom_jam);
  }else if (eeprom_jam > 100){
    lcd.setCursor(-1,1);
    lcd.print(eeprom_jam);
  }else{
    lcd.setCursor(1,1);
    lcd.print(eeprom_jam);
  }
  lcd.setCursor(4,1);
  lcd.print(":");
  if(eeprom_menit > 9){
    lcd.setCursor(7,1);
    lcd.print(eeprom_menit);
  }else{
    lcd.setCursor(7,1);
    lcd.print("   ");
    lcd.setCursor(7,1);
    lcd.print(eeprom_menit);
  }
  lcd.setCursor(10,1);
  lcd.print(":");
  if(eeprom_detik > 9){
    lcd.setCursor(12,1);
    lcd.print(eeprom_detik);
  }else{
    lcd.setCursor(12,1);
    lcd.print("  ");
    lcd.setCursor(12,1);
    lcd.print(eeprom_detik);
  }
  lcd.setCursor(1,2);
  lcd.print("WAKTU");
  if(jam_local > 9 ){
    lcd.setCursor(-3,3);
    lcd.print(jam_local);
  }else if (jam_local > 100){
    lcd.setCursor(-4,3);
    lcd.print(jam_local);
  }else{
    lcd.setCursor(-2,3);
    lcd.print(jam_local);
  }
  lcd.setCursor(0,3);
  lcd.print(":");
  if(menit_local > 9){
    lcd.setCursor(2,3);
    lcd.print(menit_local);
  }else{
    lcd.setCursor(3,3);
    lcd.print("   ");
    lcd.setCursor(3,3);
    lcd.print(menit_local);
  }
  lcd.setCursor(6,3);
  lcd.print(":");
  if(detik_local > 9){
    lcd.setCursor(8,3);
    lcd.print(detik_local);
  }else{
    lcd.setCursor(8,3);
    lcd.print("   ");
    lcd.setCursor(8,3);
    lcd.print(detik_local);
  }
}
