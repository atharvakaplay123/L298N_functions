#include <arduino.h>
#include <L298N.h>
L298N::L298N(int in1, int in2, int in3, int in4, int en1, int en2, float max = 255, bool debug = 0)
{
  IN1 = in1;
  IN2 = in2;
  IN3 = in3;
  IN4 = in4;
  EN1 = en1;
  EN2 = en2;
  Debug = debug;
  MaxSpeed = max;

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
}

void L298N::Move(bool en1_direction, bool en2_direction, float en1_speed = MaxSpeed, float en2_speed = MaxSpeed)
{
  digitalWrite(IN1, en1_direction);
  digitalWrite(IN2, !en1_direction);
  digitalWrite(IN3, en2_direction);
  digitalWrite(IN4, !en2_direction);
  analogWrite(EN1, en1_speed);
  analogWrite(EN2, en2_speed);
  if (Debug == 1)
  {
    Serial.print("en1_direction: ");
    Serial.print(en1_direction);
    Serial.print(" | en2_direction: ");
    Serial.print(en2_direction);
    Serial.print(" | en1_speed: ");
    Serial.print(en1_speed);
    Serial.print(" | en2_speed: ");
    Serial.println(en2_speed);
  }
}
void L298N::Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
}
// void L298N::Move(bool en1_direction, bool en2_direction, float speed = MaxSpeed)
// {
//   digitalWrite(IN1, en1_direction);
//   digitalWrite(IN2, !en1_direction);
//   digitalWrite(IN3, en2_direction);
//   digitalWrite(IN4, !en2_direction);
//   analogWrite(EN1, speed);
//   analogWrite(EN2, speed);
// }
// void L298N::Move(bool en1_direction, bool en2_direction)
// {
//   digitalWrite(IN1, en1_direction);
//   digitalWrite(IN2, !en1_direction);
//   digitalWrite(IN3, en2_direction);
//   digitalWrite(IN4, !en2_direction);
//   analogWrite(EN1, MaxSpeed);
//   analogWrite(EN2, MaxSpeed);
// }
