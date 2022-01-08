#include <SimpleDHT.h>
// IR Obstacle Collision Detection Module
// Henry's Bench
#define Rec 0      //Light sensor output
#define Laser 2    //Laser module 
#define Button 3   //Push button input
bool detection;

int LED = 13; // Use the onboard Uno LED
int isObstaclePin = A10;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
///////////////////////////////////////////
int msensor = A1;//moisture sensor
int msvalue = 0;
int led = 13;
boolean flag = false;
/////////////////////////////////////////
int buzzer = A8;
int LED1 = A7;
int flame_sensor = A4;
int flame_detected;
////////////////////////////////////////
int pinDHT11 = A13;
SimpleDHT11 dht11(pinDHT11);
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  ///////////////////////////////
  Serial.begin(9600);
  pinMode(msensor, INPUT);
  pinMode(led, OUTPUT);
////////////////////////////////////
 Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(flame_sensor, INPUT);
  //////////////////////////////////
   Serial.begin(9600);
/////////////////////////////////

  pinMode(Laser, OUTPUT);
  digitalWrite(Laser, HIGH); //Turning on the laser
  delay(2000);
}
void loop()
{
Serial.println("names of crops");
Serial.println("A. Wheat");
Serial.println("B. Rice");
Serial.println("C. Sugarcane");
Serial.println("D. Tobacco");
Serial.println("E. Cotton");
Serial.println("F. Jute");
Serial.println("G. Maize");
Serial.println("H. Potato");
Serial.println("Enter ypur choice via Serial Monitor(in Tools option)");

  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println(" NO OBSTACLE");
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer,LOW);
  }
  else
  {
    Serial.println(" OBSTACLE!!,OBSTACLE!! ");
    digitalWrite(LED, LOW);
     digitalWrite(buzzer, HIGH);
  }
  delay(200);
///////////////////////////////////

  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED1, HIGH);
    delay(200);
    digitalWrite(LED1, LOW);
    delay(200);
  }
  else
  {
    Serial.println("No flame detected. stay cool");
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED1, LOW);
  }
  delay(1000);
/////////////////////////////////////////
 short Detect = analogRead(Rec);            //Constanly reading the module value
 bool  Button_state = digitalRead(Button);  //And the button value (1-0)
 
 if(Detect < 500)              //The Max value is 760, if someone passes it goes below that (every value lower than 700 can do the work)
    detection = true;          //The detection is triggered

 if(detection==true)
    {
       tone(13,2000);        //Alarm sequence will go on as long as the detection is true
       delay(50);            //This alarm has two sounds 2kHz nd 1Khz delayed by 50ms
       tone(13,1000);
       delay(50);
    }
 
 if(Button_state == HIGH)  //If the button is pressed the buzzer is turned off and the detection too
    {
      detection = false;
      noTone(13);
    }//end of common to all prg
//cases will start now.
if(Serial.available() > 0)
{
int inByte = Serial.Read();
switch(inByte)
{
case 65:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:WHEAT"); 
 if(humidity>=50 && humidity<=60)
  Serial.println("Humidity Condition:Perfect");
if(humidity<50)
Serial.println("Humidity Condition:Below level");
if(humidity>60)
Serial.println("Humidity Condition:Above level");

if(temperature>=15 && temperature<=20)
Serial.println("Temperature Condition:PERFECT");
if(temperature<15)
Serial.println("Temperature Condition:Below level");
if(temperature>20)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 20) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 10) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 10) && (msvalue<=20) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;


case 66:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:RICE"); 
 if(humidity>=70 && humidity<=80)
  Serial.println("Humidity Condition:Perfect");
if(humidity<70)
Serial.println("Humidity Condition:Below level");
if(humidity>80)
Serial.println("Humidity Condition:Above level");

if(temperature>=20 && temperature<=35)
Serial.println("Temperature Condition:PERFECT");
if(temperature<20)
Serial.println("Temperature Condition:Below level");
if(temperature>35)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 15) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 10) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 10) && (msvalue<=15) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;


case 67:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:SUGARCANE"); 
 if(humidity>=80 && humidity<=85)
  Serial.println("Humidity Condition:Perfect");
if(humidity<80)
Serial.println("Humidity Condition:Below level");
if(humidity>85)
Serial.println("Humidity Condition:Above level");

if(temperature>=20 && temperature<=35)
Serial.println("Temperature Condition:PERFECT");
if(temperature<20)
Serial.println("Temperature Condition:Below level");
if(temperature>35)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 20) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 10) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 10) && (msvalue<=20) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

case 68:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:TOBACCO"); 
 if(humidity>=60 && humidity<=68)
  Serial.println("Humidity Condition:Perfect");
if(humidity<60)
Serial.println("Humidity Condition:Below level");
if(humidity>68)
Serial.println("Humidity Condition:Above level");

if(temperature>=20 && temperature<=30)
Serial.println("Temperature Condition:PERFECT");
if(temperature<20)
Serial.println("Temperature Condition:Below level");
if(temperature>30)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 16) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 13) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 13) && (msvalue<=16) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

case 69:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:COTTON"); 
 if(humidity>=65 && humidity<=75)
  Serial.println("Humidity Condition:Perfect");
if(humidity<65)
Serial.println("Humidity Condition:Below level");
if(humidity>75)
Serial.println("Humidity Condition:Above level");

if(temperature>=20 && temperature<=28)
Serial.println("Temperature Condition:PERFECT");
if(temperature<20)
Serial.println("Temperature Condition:Below level");
if(temperature>28)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 40) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 40) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue == 40) &&  ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

case 70:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:JUTE"); 
 if(humidity>=70 && humidity<=90)
  Serial.println("Humidity Condition:Perfect");
if(humidity<70)
Serial.println("Humidity Condition:Below level");
if(humidity>90)
Serial.println("Humidity Condition:Above level");

if(temperature>=15 && temperature<=30)
Serial.println("Temperature Condition:PERFECT");
if(temperature<15)
Serial.println("Temperature Condition:Below level");
if(temperature>30)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 35) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 35) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue == 35) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

case 71:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:MAIZE"); 
 if(humidity>=60 && humidity<=80)
  Serial.println("Humidity Condition:Perfect");
if(humidity<60)
Serial.println("Humidity Condition:Below level");
if(humidity>80)
Serial.println("Humidity Condition:Above level");

if(temperature>=15 && temperature<=30)
Serial.println("Temperature Condition:PERFECT");
if(temperature<15)
Serial.println("Temperature Condition:Below level");
if(temperature>30)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 80) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 0) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 0) && (msvalue<=80) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

case 72:      
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
Serial.println("Crop Name:PATATO"); 
 if(humidity>=85 && humidity<=90)
  Serial.println("Humidity Condition:Perfect");
if(humidity<80)
Serial.println("Humidity Condition:Below level");
if(humidity>90)
Serial.println("Humidity Condition:Above level");

if(temperature>=10 && temperature<=35)
Serial.println("Temperature Condition:PERFECT");
if(temperature<10)
Serial.println("Temperature Condition:Below level");
if(temperature>35)
Serial.println("Temperature Condition:Above level");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
////////////////////////////////////////

   msvalue = analogRead(msensor);
  Serial.println(msvalue);

  if ( (msvalue > 40) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Above Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }
  if ( (msvalue < 30) && ( flag == false) )
  {
  Serial.println("Moisture Condition:Below Ideal Condition");
    digitalWrite(led,HIGH);
    flag = true;
    delay(1000);
  }

    if ( (msvalue >= 30) && (msvalue<=40) && ( flag == true) )
  {
    digitalWrite(led,LOW);
    flag = false;
  Serial.println("Moisture Condition:Perfect");
    delay(1000);
  }                                   //prg for moisture...
   delay(1000);

}
break;

default:
         Serial.println("Choice INFO unavailable");
  }switch closed
 }if closed
}//loop closed

