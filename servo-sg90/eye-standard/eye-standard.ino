#include <Servo.h>

Servo leftEyeServo;  // Create a servo object for the left eye
Servo rightEyeServo; // Create a servo object for the right eye

// This is the setup function that runs once when the Arduino is powered or reset
void setup() {
  leftEyeServo.attach(9);  // Attach the left eye servo to pin 9
  rightEyeServo.attach(10); // Attach the right eye servo to pin 10
}

// This is the loop function that runs continuously in a loop
void loop() {
  moveEyesLeftToRight();    // Move eyes left to right
  delay(1000);              // Pause for a second
  moveEyesRightToLeft();    // Move eyes right to left
  delay(1000);              // Pause for a second
}

// Function to move eyes from left to right (0 to 90 degrees)
void moveEyesLeftToRight() {
  for (int pos = 0; pos <= 90; pos += 1) {
    leftEyeServo.write(pos);   // Move the left eye servo
    rightEyeServo.write(pos);  // Move the right eye servo
    delay(15);                 // Small delay for smooth motion
  }
}

// Function to move eyes from right to left (90 to 0 degrees)
void moveEyesRightToLeft() {
  for (int pos = 90; pos >= 0; pos -= 1) {
    leftEyeServo.write(pos);   // Move the left eye servo
    rightEyeServo.write(pos);  // Move the right eye servo
    delay(15);                 // Small delay for smooth motion
  }
}
