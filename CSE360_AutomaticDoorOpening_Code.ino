#include <Servo.h>  // Include the Servo Library

Servo myservo;  // Create servo object to control a servo
bool Open_Door;

void setup() 
{
  pinMode(12, INPUT);  // Make pin 12 an INPUT
  pinMode(8, OUTPUT);  // Make pin 8 an OUTPUT

  myservo.attach(10);  // Attaches the servo to pin 10
  myservo.write(5);    // Tells the servo to go to initial position
}

void loop() 
{
  int PIR_State = digitalRead(12);  // Read the input pin // logicstate

  if (PIR_State == HIGH)   // Check if PIR Sensor Detected Motion
  {
    Open_Door = true;
  }
  else if (PIR_State == LOW)
  {
    Open_Door = false;
    digitalWrite(8, LOW);  // Turn OFF LED
    myservo.write(5); // Tell servo to go to initial position
  }

  if (Open_Door)
  {
    digitalWrite(8, HIGH);  // Turn ON LED
    for (int pos = 5; pos <= 90; pos++) // Go from 5 degrees to 93 degrees
    {
      myservo.write(pos); // Tell servo to go to position in variable 'pos'
      delay(15);   // Wait 15ms for the servo to reach the position
      // Set Open_Door flag to false
      
    }
    delay(1000);
	int PIR_State = digitalRead(11);
  PIR_State = LOW;
 	digitalWrite(8, LOW);  // Turn OFF LED
    myservo.write(5);
  }
	
}