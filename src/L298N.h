#ifndef L298N_H
#define L298N_H

class L298N {
 private:
  int IN1, IN2, IN3, IN4, EN1, EN2;
  bool Debug = 0;
  // float MaxSpeed = 255;

 public:
  L298N(int in1, int in2, int in3, int in4, int en1, int en2);
  // void SetMaxSpeed(int speed);
  void debug(bool debugging);
  void Move(bool en1_direction, bool en2_direction, float en1_speed = 255, float en2_speed = 255);
  void Stop();
};

#endif