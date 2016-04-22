#include <NewPing.h>
#define TRIGGER_PIN  5   // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4   // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int led = 13; //led light
int Alarm = 12; //buzzer pin

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(led,LOW);
  pinMode(Alarm,LOW);
  
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50);                          // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping_cm(); // Send ping, get ping time in centemeter (uS).
  delay(100);
  if(uS >= 50){
    pinMode(led,HIGH);
    pinMode(Alarm,HIGH);
    Serial.print("Artronaut is drifting away from the sequred area");
    Serial.println(" ");
    }
  else {
    pinMode(led,LOW);
    pinMode(Alarm,LOW);
  }
  delay(1000);
} 
