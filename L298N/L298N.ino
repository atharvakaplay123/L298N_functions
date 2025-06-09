/*
L298N motor(4, 5, 6, 7, 8, 9); // IN1-IN4, EN1, EN2

void setup() {
  // no pinMode needed here — constructor handles it
}

void loop() {
  motor.Move(1, 1, 200, 200);
  delay(2000);
  motor.Stop();
  delay(1000);
}

*/

class L298N {
private:
  int IN1, IN2, IN3, IN4, EN1, EN2;
  bool Debug=0;
  float MaxSpeed;

public:
  L298N(int in1, int in2, int in3, int in4, int en1, int en2, float max=255, bool debug=0) {
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

  void Move(bool en1_direction, bool en2_direction, float en1_speed=MaxSpeed, float en2_speed=MaxSpeed) {
    digitalWrite(IN1, en1_direction);
    digitalWrite(IN2, !en1_direction);
    digitalWrite(IN3, en2_direction);
    digitalWrite(IN4, !en2_direction);
    analogWrite(EN1, en1_speed);
    analogWrite(EN2, en2_speed);
    if(Debug == 1){
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
  // void Move(bool en1_direction, bool en2_direction, float speed=MaxSpeed) {
  //   digitalWrite(IN1, en1_direction);
  //   digitalWrite(IN2, !en1_direction);
  //   digitalWrite(IN3, en2_direction);
  //   digitalWrite(IN4, !en2_direction);
  //   analogWrite(EN1, speed);
  //   analogWrite(EN2, speed);
  // }
  // void Move(bool en1_direction, bool en2_direction) {
  //   digitalWrite(IN1, en1_direction);
  //   digitalWrite(IN2, !en1_direction);
  //   digitalWrite(IN3, en2_direction);
  //   digitalWrite(IN4, !en2_direction);
  //   analogWrite(EN1, MaxSpeed);
  //   analogWrite(EN2, MaxSpeed);
  // }

  void Stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN1, 0);
    analogWrite(EN2, 0);
  }
};
