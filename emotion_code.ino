#include "LedControlMS.h"
#include <Servo.h>
 
Servo MG996_TILT;
Servo MG995_PAN;

//#include <LedControlMS.h>


//#include <LedControl.h>
#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
int pos;

const int trigPin = 7;
const int echoPin = 8;

int randomNumber = 2;
//LiquidCrystal_I2C lcd(0x27, 16, 1);
//define variables


#define NBR_MTX 2
#define NEUTRAL 1
#define SURPRISED 2
#define HAPPY 3
#define ANGRY 4
#define LOVE 5
#define SAD 6




int emotion = NEUTRAL;

LedControl lc = LedControl(13, 12, 11, NBR_MTX);

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


byte neutral[8] = {0x00, 0x3c, 0x42, 0x5a, 0x5a, 0x42, 0x3c, 0x00};
byte happy[8] = {0x00, 0x1c, 0x24, 0x5c, 0x5c, 0x24, 0x1c, 0x00};
byte angry[8] = {0x00, 0x3c, 0x42, 0x5a, 0x5a, 0x42, 0x3c, 0x00};
byte surprised[8] = {0x7e, 0x81, 0x81, 0x99, 0x99, 0x81, 0x81, 0x7e};
byte love[8] = {0x00, 0x66, 0x99, 0x81, 0x42, 0x24, 0x18, 0x00};
byte sad[8] = {0x00, 0x0c, 0x12, 0x3a, 0x5a, 0x42, 0x3c, 0x00};

void setup()
{
  MG996_TILT.attach(2);
  MG995_PAN.attach(3);
  int randomNumber = 2;

  lc.shutdown(0, false);
  lc.shutdown(1, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  lc.setIntensity(1, 8);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);


  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  //Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  //Serial.println("with Arduino UNO R3");
  /*lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);*/
  if (randomNumber == 1)
  {
    Serial.println("I am Hap         ");
  }
  else
  {
    Serial.println("I am Angy          ");
  }
  //lcd.println("Distance: ");



}
void printByte(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
    lc.setRow(1, i, character[i]);
  }
}

void neutralMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = NEUTRAL;
  printByte(neutral);
}
void neutralMethodServo(){
  for(pos = 0; pos <= 60; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 60; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}
void surprisedMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = SURPRISED;
  printByte(surprised);
}
void surprisedMethodServo(){
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 90; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}
void loveMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = LOVE;
  printByte(love);
}
void loveMethodServo(){
  for(pos = 0; pos <= 120; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 120; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}
void happyMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = HAPPY;
  printByte(happy);
}
void happyMethodServo(){
  for(pos = 0; pos <= 150; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 150; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}

void angryMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = ANGRY;
  printByte(angry);
}
void angryMethodServo(){
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}
void sadMethod() {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  emotion = SAD;
  printByte(sad);}
void sadMethodServo(){
  for(pos = 0; pos <= 30; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    MG996_TILT.write(pos); // tell servo to go to position in variable 'pos'
    MG995_PAN.write(pos);
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos = 30; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees
  {
    MG995_PAN.write(pos);
    MG996_TILT.write(pos);
    delay(15); 
  }
}

void loop()
{

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delay(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  delay(100);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("distance ");
  Serial.println(distance);
  /*lcd.setCursor(0, 1);
    if (distance < 200) {
      lcd.print(distance);
      //lcd.print(" cm              ");
    }
    else {
    lcd.print("Error       ");
    }*/

  /*if (randomNumber == 1) {
    if (distance <= 5 && emotion != SURPRISED)  {
    surprisedMethod();
    }
    else if (5 < distance && distance <= 15 && emotion != LOVE )
    {
      loveMethod();
    }
    else if (15 < distance && distance < 25 && emotion != HAPPY)
    {
      happyMethod();
    }
    else if (distance >= 25 && emotion != NEUTRAL)
    {
      neutralMethod();
    }
  }*/
    if(distance >= 1 && distance <= 5)
    {
      happyMethod();
      happyMethodServo();
    }
    else if(distance>=6 && distance<=10)
    {
      sadMethod();
      sadMethodServo();
    }
    else if(distance>=11 && distance<=15)
    {
      angryMethod();
      angryMethodServo();
    }
    else if(distance>=16 && distance<= 20)
    {
      loveMethod();
      loveMethodServo();
    }
    else if(distance>=1000)
    {
      surprisedMethod();
      surprisedMethodServo();      
    }
    else
    {
      neutralMethod();
      neutralMethodServo();
    }
    



  /*else {

    if (distance <= 5 && emotion != SURPRISED)  {
      surprisedMethod();
    }
    else if (5 < distance && distance <= 15 && emotion != NEUTRAL )
    {
      neutralMethod();
    }
    else if (15 < distance && distance < 25 && emotion != ANGRY)
    {
      angryMethod();
    }

    else if (distance >= 25 && emotion != SAD)
    {
      sadMethod();
    }

  }*/





  delay(100);
  //exit(0);
}
