#include <AccelStepper.h>

// Define stepper motor connections and interface type
#define motorInterfaceType 1  // DRIVER mode (STEP + DIR)

// Define pins for stepper motors
#define stepPin1 2  // Motor 1 STEP
#define dirPin1 5   // Motor 1 DIR
#define stepPin2 3  // Motor 2 STEP
#define dirPin2 6   // Motor 2 DIR

// Initialize the stepper motors
AccelStepper motor1(motorInterfaceType, stepPin1, dirPin1);
AccelStepper motor2(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  // Set maximum speed and acceleration
  motor1.setMaxSpeed(1000); // Max steps per second
  motor1.setAcceleration(500); // Steps/sec^2

  motor2.setMaxSpeed(1000);
  motor2.setAcceleration(500);

  // Set initial positions
  motor1.setCurrentPosition(0);
  motor2.setCurrentPosition(0);
}

void loop() {
  // Run both motors for 5 seconds
  motor1.moveTo(2000); // 2000 steps forward
  motor2.moveTo(-2000); // 2000 steps backward

  // Run motors until they reach their target positions
  while (motor1.distanceToGo() != 0 || motor2.distanceToGo() != 0) {
    motor1.run();
    motor2.run();
  }

  // Pause for 2 seconds
  delay(2000);

  // Reverse direction
  motor1.moveTo(-2000);
  motor2.moveTo(2000);

  while (motor1.distanceToGo() != 0 || motor2.distanceToGo() != 0) {
    motor1.run();
    motor2.run();
  }

  // Pause again
  delay(2000);
}
