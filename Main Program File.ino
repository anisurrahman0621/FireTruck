#include <Servo.h>
 int speedpin1 = 11;
 int Lpin1 = 10;
int Lpin2 = 8;
int speedpin2 = 9;
int Rpin1 = 7;
int Rpin2 = 6;
int triggerPin = 13;
int EchoPin = 12;
int ledpinRED = A1;
int ledpinWHITE = A3; 
Servo myservo;
int pos = 0;

void forward(){
   analogWrite(speedpin1, 255);
   analogWrite(speedpin2, 255);
   digitalWrite(Lpin1, LOW);
   digitalWrite(Lpin2, HIGH);
   digitalWrite(Rpin1, LOW);
   digitalWrite(Rpin2, HIGH);}

   void brake(){
    analogWrite(speedpin1, 0);
    analogWrite(speedpin2, 0);
   }
   
   void turnL(){
    analogWrite(speedpin2, 240);
    analogWrite(speedpin1, 220);
    digitalWrite(Lpin1, LOW);
   digitalWrite(Lpin2, HIGH);
   digitalWrite(Rpin1, LOW);
   digitalWrite(Rpin2, HIGH);
   }
   void turnR(){
    analogWrite(speedpin2, 220);
    analogWrite(speedpin1, 240);
    digitalWrite(Lpin1, LOW);
   digitalWrite(Lpin2, HIGH);
   digitalWrite(Rpin1, LOW);
   digitalWrite(Rpin2, HIGH);}
   void reverse(){
   analogWrite(speedpin1, 255);
   analogWrite(speedpin2, 255);
   digitalWrite(Lpin1, HIGH);
   digitalWrite(Lpin2, LOW);
   digitalWrite(Rpin1, HIGH);
   digitalWrite(Rpin2, LOW);}
    
   


void setup(){
  pinMode(speedpin1, OUTPUT);
  pinMode(Lpin1, OUTPUT);
  pinMode(Lpin2, OUTPUT);
  pinMode(speedpin2, OUTPUT);
  pinMode(Rpin1, OUTPUT);
  pinMode(Rpin2, OUTPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  Serial.begin(9600); 
pinMode(ledpinRED, OUTPUT);
pinMode(ledpinWHITE, OUTPUT);
myservo.attach(4); 

}

void loop() 
{
 int sensorReading = analogRead(A0); 
 forward(); 
 Serial.println(sensorReading); 
  long duration, distance;
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  duration=pulseIn(EchoPin,HIGH);
  distance=(duration/2)/29.1 ;
  Serial.print(distance);
  Serial.println("cm"); 
  digitalWrite(ledpinWHITE, LOW);
  digitalWrite(ledpinRED, LOW);

  if((distance<4) && (sensorReading>50))
  {
     digitalWrite(ledpinWHITE,HIGH); 
    brake();
    delay(1000);
    reverse();
    delay(2000);
    turnR();
    delay(2000);
    forward();
    delay(2000);
     } 
  else 
     {  
        forward();   
     }
  
  
   if(sensorReading < 60)
   {
   digitalWrite(ledpinRED,HIGH);
   
   }
  
  
  
  if(sensorReading <= 50)
    {
       brake();
        
        for(pos=0;pos<=180;pos+=1)
             {
                myservo.write(90);
                delay(10);
             }

        for(pos=180;pos >= 0; pos-=1)
             {
               myservo.write(0);
               delay(10);
              }
    }}
   
