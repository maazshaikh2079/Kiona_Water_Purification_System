#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
#define Buzzer 2
#define RED 3
#define GREEN 5

void setup() {
   lcd.init();
  lcd.clear();
  lcd.backlight(); // Turns on backlight
  pinMode(A1, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin(16,2);
}

void loop() {
 int gas= analogRead(A1);
 Serial.println(gas);
 //Serial.print("GAS");
 lcd.setCursor(0,0);
 //lcd.print("Hazards System");
 //delay(400);

 if(gas > 500)
 {
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(Buzzer, HIGH);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("CALL TO RESCUE");
  lcd.setCursor(4,1);
  lcd.print("SERVICES");
 }
 else
 {
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED, LOW);
  digitalWrite(Buzzer, LOW);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("KIONA : HMS");
 }
 delay(200);
}
