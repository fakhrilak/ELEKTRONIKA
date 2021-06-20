int aa = 0;
void setup() {
  // put your setup code here, to run once:
  for(int a = 10;a<=13;a++){
    pinMode(a,OUTPUT);
  }
  
}

void loop() {
  aa= aa+1;
  // put your main code here, to run repeatedly:
  for(int a =10;a<=13;a++){
    digitalWrite(a,aa%2);
    delay(500);
  }

}
