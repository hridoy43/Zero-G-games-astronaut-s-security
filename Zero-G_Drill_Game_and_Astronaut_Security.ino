#include <NewPing.h>
#define TRIGGER_PIN  5   // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4   // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int led = 13; //led light
int Alarm = 12; //buzzer pin

//Laser box Ray1 (Motion)
int pirPin1 = 6;
int pirSupply1 = 7;

//Laser box Ray2 (Motion)
int pirPin2 = 8;
int pirSupply2 = 9;

int soner_read = 0;
int motion_read = 0; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(led,OUTPUT);
  pinMode(Alarm,OUTPUT);
  
  pinMode(pirPin1, INPUT);
  pinMode(pirSupply1,OUTPUT);
  
  pinMode(pirPin2, INPUT);
  pinMode(pirSupply2,OUTPUT);

  digitalWrite(Alarm,LOW);
  
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
     digitalWrite(pirSupply1,HIGH);
     digitalWrite(pirSupply2,HIGH);
     
     
  
  delay(50);                          // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping_cm(); // Send ping, get ping time in centemeter (uS).
  delay(100);
  
  if(uS >= 35 && uS <= 50){          //For Outside Game
    digitalWrite(led,HIGH);
    digitalWrite(Alarm,HIGH);
    Serial.print("Artronaut is drifting away from the sequred area");
    Serial.println(" ");
    int soner_read = 1;
    }
  else {
    digitalWrite(led,LOW);
    digitalWrite(Alarm,LOW);
  }
  
  delay(100);
  
  if ((digitalRead(pirPin1) == HIGH) || (digitalRead(pirPin2) == HIGH))  ////For Inside laser box Game
    {
     
     Serial.print("Object detected in laser box");
     Serial.println(" ");
     digitalWrite(led,HIGH);
     digitalWrite(Alarm,HIGH);
     int motion_read = 1; 
     
    }
    else{
     digitalWrite(led,LOW);
    digitalWrite(Alarm,LOW);
    }

    if((soner_read == 1) || (motion_read == 1))
    {
      delay(5000);
      digitalWrite(led,LOW);
    digitalWrite(Alarm,LOW);
    }

    
  
  delay(1000);
} 
