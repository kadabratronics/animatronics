#include <Servo.h>

Servo leftEyeServo;  // Create a servo object for the left eye
Servo rightEyeServo; // Create a servo object for the right eye

// This is the setup function that runs once when the Arduino is powered or reset
void setup() {
  leftEyeServo.attach(9);  // Attach the left eye servo to pin 9
  rightEyeServo.attach(10); // Attach the right eye servo to pin 10
  
  randomSeed(analogRead(0)); // Seed the random generator using an analog pin
}

// This is the loop function that runs continuously in a loop
void loop() {
  randomEyeMovement();  // Call the function that randomizes the eye movement
  delay(random(500, 1500)); // Random delay between 0.5 and 1.5 seconds
}

// Function to move the eyes randomly
void randomEyeMovement() {
  int startPos = random(0, 91);   // Random starting position between 0 and 90 degrees
  int endPos = random(0, 91);     // Random ending position between 0 and 90 degrees
  int movementSpeed = random(10, 30); // Random movement speed (delay between steps)

  if (startPos < endPos) {
    // Move eyes from startPos to endPos
    for (int pos = startPos; pos <= endPos; pos++) {
      leftEyeServo.write(pos);   // Move the left eye
      rightEyeServo.write(pos);  // Move the right eye
      delay(movementSpeed);      // Random speed for smoother motion
    }
  } else {
    // Move eyes from startPos to endPos in reverse
    for (int pos = startPos; pos >= endPos; pos--) {
      leftEyeServo.write(pos);   // Move the left eye
      rightEyeServo.write(pos);  // Move the right eye
      delay(movementSpeed);      // Random speed for smoother motion
    }
  }
}

