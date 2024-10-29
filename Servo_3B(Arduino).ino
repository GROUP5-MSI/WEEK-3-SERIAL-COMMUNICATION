#include <Servo.h>
Servo servo; int angle = 90;
void setup() 
{
  servo.attach(9); // Attach the servo to dig. pin 9
  Serial.begin(9600); // Initialize serial communication
}

void loop()
{
  if (Serial.available() > 0) // Check if data is available to read
  {
    angle = Serial.parseInt(); // Read the incoming angle value
    angle = constrain(angle, 0, 180); //Constrain the angle value between 0 and 180
    servo.write(angle); // Set the servo to the new angle
    Serial.print("Set angle: "); Serial.println(angle);
  }

delay(100); // Wait for a short time to avoid continuous reading

 }
