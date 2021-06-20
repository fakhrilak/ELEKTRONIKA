void setup() {
  // put your setup code here, to run once:
  for(int b=10;b<=13;b++){
    pinMode(b,OUTPUT);
  }
//  pinMode(13,OUTPUT);
//  pinMode(12,OUTPUT);
//  pinMode(11,OUTPUT);
//  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int a = 10;a<=13;a++){
    digitalWrite(a,HIGH);
    delay(1000);
  }
  for(int a = 10;a<=13;a++){
    digitalWrite(a,0);
  }
  delay(1000);
//  digitalWrite(10,HIGH);
//  delay(1000);
//  digitalWrite(11,HIGH);
//  delay(1000);
//  digitalWrite(12,HIGH);
//  delay(1000);
//  digitalWrite(13,HIGH);
//  delay(1000);
//  digitalWrite(13,LOW);
//  digitalWrite(10,LOW);
//  digitalWrite(11,LOW);
//  digitalWrite(12,LOW);
//  delay(1000);
}
