#include <Servo.h>

Servo servo;
int angle = 90;
char key; // Declare key outside of the if block

void setup() 
{
  servo.attach(9); // Attach the servo to digital pin 9
  Serial.begin(9600); // Initialize serial communication
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    key = Serial.read(); // Read the incoming key
  }

  if (key == 'q') 
  { // Halt if 'q' is pressed
    while (true) {} // Halt the program
  }

  int potVal = analogRead(A0); // Read potentiometer value
  int mappedVal = map(potVal, 0, 1023, 0, 180); // Map potentiometer value to servo angle range

  servo.write(mappedVal); // Set servo angle
  Serial.print("Servo Position: "); // Print the servo position
  Serial.println(mappedVal); // Send the position to the serial monitor

  delay(50); // Delay for stability
}
