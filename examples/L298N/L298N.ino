/*
  L298N Motor Driver Example
  --------------------------

  This example demonstrates basic motor movement using the L298N dual H-Bridge motor driver
  through the custom L298N Arduino library.

  Library: L298N
  Author: Atharva Kaplay
  Version: 1.0

  Description:
    Controls two DC motors connected to an L298N motor driver.
    The example moves the robot forward, left, right, backward, and then stops — each for 1 second.

  Connections:
    - IN1: D4
    - IN2: D5
    - IN3: D6
    - IN4: D7
    - EN1: D8 (PWM capable)
    - EN2: D9 (PWM capable)
    - Motor A connected to OUT1 & OUT2
    - Motor B connected to OUT3 & OUT4
    - 12V (or appropriate) power supply connected to L298N motor power input

  Object Initialization:
    L298N motor(4, 5, 6, 7, 8, 9);
      - IN1 to IN4: D4, D5, D6, D7
      - EN1: D8
      - EN2: D9
      - MaxSpeed: 255 (default)
      - Debug: disabled (default)

  Functions Used:
    motor.Move(directionA, directionB, speedA, speedB);
      - directionA: 1 = forward, 0 = backward (for Motor A)
      - directionB: 1 = forward, 0 = backward (for Motor B)
      - speedA & speedB: PWM speed values (0–255)

    motor.Stop();
      - Immediately stops both motors

  Behavior:
    - Moves forward
    - Turns left (left motor backward, right motor forward)
    - Turns right (left motor forward, right motor backward)
    - Moves backward
    - Stops

  Note:
    No pinMode calls are needed — the constructor sets pin modes automatically.
*/
#include <L298N.h>
L298N motor(4, 5, 6, 7, 8, 9); // IN1-IN4, EN1, EN2

void setup()
{
  // no pinMode needed here — constructor handles it
}

void loop()
{
  motor.Move(1, 1, 200, 200); // Move Forward
  delay(1000);

  motor.Move(0, 1, 200, 200); // Move Left
  delay(1000);

  motor.Move(1, 0, 200, 200); // Move Right
  delay(1000);

  motor.Move(0, 0, 200, 200); // Move Backward
  delay(1000);

  motor.Stop(); // Stop
  delay(1000);
}