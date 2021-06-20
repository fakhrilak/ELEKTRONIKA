#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const float SensorOffset = 102.0;
#define echoPin 6 //Echo Pin
#define trigPin 7 //Trigger Pin
int button = 3;
int relay = 2;
long duration, distance;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  pinMode(button,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float baca = (analogRead(A0)-SensorOffset)/100.0;
  int setButton = digitalRead(button);
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(setButton == 1 && distance < 4){
    digitalWrite(relay,HIGH);
//    Serial.println(distance);
  }else if(setButton == 0 && distance <= 1){
    digitalWrite(relay,HIGH);
//    Serial.println(distance);
  }else if(setButton == 0 && distance >= 0){
    digitalWrite(relay,HIGH);
//    Serial.println(distance);
  }else{
    digitalWrite(relay,LOW);
//    Serial.println(distance);
  }
  lcd.setCursor(3,0);
  lcd.print("Nilai Sensor : ");
  lcd.setCursor(3,1);
  lcd.print(baca*7.5);
  lcd.setCursor(9,1);
  lcd.print("mmHg");
  Serial.println(baca);
  delay(1000);
}
