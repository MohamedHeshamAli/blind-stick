//#include <SoftwareSerial.h>
#include <Servo.h>
int servoPin = 9;
Servo servo; 
byte buzzerPin=13;
const int trigPin = 2;
const int echoPin = 3;
bool canMoveForward=true;
int val=0;


//SoftwareSerial bluetooth(0, 1);
void setup() {
  servo.attach(servoPin);
 // pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
//  bluetooth.begin(9600);
}

void loop() {
  
  int waterLevel = analogRead(A0);
  if(waterLevel>500){
    Serial.println("watch out from water");
    delay(2000);
  }
  servo.write(90);
  
  int forwardDistance= getDistance(trigPin,echoPin);
    if(forwardDistance < 20){     
 findAWay();
    }
  

}
double getDistance(int tri,int echo){
            digitalWrite(tri, LOW);
          delayMicroseconds(2);
          // Sets the trigPin on HIGH state for 10 micro seconds
          digitalWrite(tri, HIGH);
          delayMicroseconds(10);
          digitalWrite(tri, LOW);
          // Reads the echoPin, returns the sound wave travel time in microseconds
          double duration = pulseIn(echo, HIGH);
          // Calculating the distance
          double distance= duration*0.034/2;
          return distance;
}
void findAWay(){
        //( Serial.available() > 0)
      if( 1){
      Serial.println("stop moving");
      String avilableWaye="";
      servo.write(0);
      delay(1500);
      int rightDistance=getDistance(trigPin,echoPin);
      servo.write(180);
      delay(1500);
      int leftDistance=getDistance(trigPin,echoPin);
      if(rightDistance>=100&leftDistance>=100){
       avilableWaye="you can move right and left"; 
      }
      else if(rightDistance>=100&&leftDistance<100){
        avilableWaye="you can move right ";
      }
       else if(rightDistance<100&&leftDistance>=100){
       avilableWaye="you can move left"; 
      }
      else{
        avilableWaye="you can not move right or left try to go back"; 
      }
      Serial.println(avilableWaye);
       servo.write(90);
      delay(3000);
  }
}
void testServo(){
        delay(1000);
  int forwardDistance= getDistance(trigPin,echoPin);
  Serial.print("forwardDistance");
  Serial.println(forwardDistance);
  
      servo.write(0);
      delay(1000);
      int rightDistance=getDistance(trigPin,echoPin);
      Serial.print("rightDistance");
  Serial.println(rightDistance);
      servo.write(180);
      delay(1000);
      int leftDistance=getDistance(trigPin,echoPin);
  Serial.print("leftDistance");
  Serial.println(leftDistance);}
