//int pengukuran(){
//  volt = x *(1.1 / 1023.0);
//  //topascal
//  as = (x-offset)*(0.0238715278 * 100);
//  pascals=(0.977*as);
//  V = pascals*0.226865;
//  V1 = V*1.3;
//  V =  V *-7.3;
//  Serial.print("tampil_V ");
//  Serial.println(tampil_V);
//  Serial.print("V ");
//  Serial.println(V);
//  Serial.print("lempar ");
//  Serial.println(lempar);
//  if (V> 0.34 && lempar == 0){
//    lempar = 1;
//  }
//  if (lempar == 1 && V> 0.38 ){
//      Serial.print("masssssssssoooooook");
//     tampil_V = tampil_V+V;
//     delay(500);
//  }
//  lcd.setCursor(1,0);
//  lcd.print("Vital Capacity");
//  lcd.setCursor(0,1);
//  lcd.print("FVC = ");
//  lcd.setCursor(6,1);
//  lcd.print((tampil_V * 1)*(1000,3));
//  lcd.setCursor(14,1);
//  lcd.print("mL");
//}
int namaDewi(){
  lcd.setCursor(1,0);
  lcd.print("Dewi Majasari");
  lcd.setCursor(2,1);
  lcd.print("P22040118009");
}
int pengukuran_2(){
  if(reset ==1){
    reset = 0;
  }
  Serial.println(reset);
  int xx = x;
  if(xx > nilai && xx >39){
    nilai = xx;
  }
  volt =  nilai * (5.0 / 1023.0);
  pascals = (volt-0.4)/0.225;
  V = ((-2*pascals/1.2)/0.625);
  akar = sqrt(V);
  q =(0.0005*akar);
  tampil_V = akar;
//  if (V> 0.34){
//    lempar = 1;
//  }
//  if (lempar == 1 && V> 0.34 ){
//     tampil_V = q;
//  }
  if(nilai > 43){
    tampil_V1 = 4.74 - V;
    lcd.setCursor(1,0);
  lcd.print("Vital Capacity");
  lcd.setCursor(0,1);
  lcd.print("FVC = ");
  lcd.setCursor(6,1);
  lcd.print(tampil_V1*1000,3);
  lcd.setCursor(14,1);
  lcd.print("mL");
  }else{
    lcd.setCursor(1,0);
  lcd.print("Vital Capacity");
  lcd.setCursor(0,1);
  lcd.print("FVC = ");
  lcd.setCursor(6,1);
  lcd.print(0.000);
  lcd.setCursor(14,1);
  lcd.print("mL");
  }
}
int clear_lcd(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

int penentuan_tinggi(){
  if(menu == 2 && pb11 == 1){
    tinggi_badan = tinggi_badan - 1;
  }else if(menu == 2 && pb22 == 1){
    tinggi_badan = tinggi_badan + 1;
  }
  lcd.setCursor(2,0);
  lcd.print("Tinggi Badan");
  lcd.setCursor(5,1);
  lcd.print(tinggi_badan);
  lcd.setCursor(9,1);
  lcd.print("cm");
}

int male_female(){
  if(menu == 3 && pb11 == 1){
    gendre = 0;
  }else if(menu == 3 && pb22 == 1){
    gendre = 1;
  }
  lcd.setCursor(0,0);
  lcd.print("Male / Female");
  if(gendre == 1){
    lcd.setCursor(0,1);
    lcd.print("                 ");
    lcd.setCursor(0,1);
    lcd.print("Male");
  }else if(gendre == 0){
    lcd.setCursor(0,1);
    lcd.print("                 ");
    lcd.setCursor(7,1);
    lcd.print("Female");
  }
  
}

int umur_r(){
  if(menu == 4 && pb11 == 1){
    umur = umur - 1;
  }else if(menu == 4 && pb22 == 1){
    umur = umur + 1;
  }
  lcd.setCursor(6,0);
  lcd.print("Umur");
  lcd.setCursor(5,1);
  lcd.print(umur);
  lcd.setCursor(8,1);
  lcd.print("Tahun");
}

int hasil(){
  float hasil = -3.37068 + (0.02824 * umur) + (0.03583 * tinggi_badan) + (1.00051 * 1 - 0.04546 * 1 *umur)+0.30431;

//  float toleransi = hasil*100/100;
//  Serial.print("hasil ");
//  Serial.println(hasil);
//  Serial.print("toleransi ");
//  Serial.println(t);
//  Serial.print("tampil_V ");
//  Serial.println(tampil_V1);
  if(tampil_V1 < hasil){
    lcd.setCursor(3,0);
    lcd.print("TIDAK NORMAL");
  }else{
    lcd.setCursor(3,0);
  lcd.print("NORMAL");
  }
  
}

int reset_(){
  if(menu == 6 && pb11 == 1){
    reset = 0;
  }else if(menu == 6 && pb22 == 1){
    reset = 1;
  }
  if(reset == 1){
   gendre = 0;
   umur = 20;
   tinggi_badan = 140;
   volt = 0;
   as = 0;
   V1=0;
   tampil_V = 0;
   tampil_V1=0;
   akar= 0;
   q = 0;
   pascals=0;
   V=0;
   lempar  = 0;
   nilai=0;
   lcd.setCursor(3,0);
   lcd.print("Reseted");
  }
  else if(reset==0){
    lcd.setCursor(3,0);
   lcd.print("Reset ?");
  }
}
