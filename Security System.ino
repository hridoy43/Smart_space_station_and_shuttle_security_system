//sooner
#include <NewPing.h>
#define TRIGGER_PIN  5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//peizo
int ledPin = 13;
int knockSensor = A5;               
byte val = 0;
int statePin = LOW;
int THRESHOLD = 85;

//Motion
int pirPin1 = 7;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin1, INPUT);  
  Serial.begin(9600);
}


void loop() {
  val = analogRead(knockSensor);     
 
  delay(50);                     
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  if( sonar.convert_cm(uS) <= 15){
  Serial.println(" ");
  Serial.println("Space object is comming towards the ISS");
  }
  
  if (val >= THRESHOLD) {
  Serial.println(" ");
  Serial.println("Impackted on the shuttle's Left side");
  }
  
  if (digitalRead(pirPin1) == HIGH)
    {
      Serial.println(" ");
      Serial.println("Floating Object detected in Section-1");
    }
  delay(500);
}
