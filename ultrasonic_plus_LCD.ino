#include <LiquidCrystal_I2C.h>

int trigPin = 8;    // Trigger
int echoPin = 7;    // Echo
long duration, cm, inches;

LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  //Serial Port begin
  Serial.begin (9600);

  lcd.init();
  lcd.backlight();

  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inches = (duration / 2) / 74; // Divide by 74 or multiply by 0.0135

  Serial.print(inches);
  Serial.println("in, ");
  Serial.print(cm);
  Serial.println("cm");

  lcd.setCursor(0, 0);
  lcd.print("Distance = ");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  lcd.print(" cm, ");
  lcd.print(inches);
  lcd.print(" in");
  
  //lcd.setCursor(0, 1);
  //lcd.print("Distance = ");
  //lcd.print(inches);
  //lcd.println(" in");

  delay(500);
}
