/*
int IN1 = 9;  //Left(-)
int IN2 = 8;  //Left(+)

int IN3 = 11;  //Right(-)
int IN4 = 10;  //Right(+)

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
}
*/
void Move(bool en1_direction, bool en2_direction, float en1_speed, float en2_speed){
    digitalWrite(IN1, en1_direction);
    digitalWrite(IN2, !en1_direction);
    digitalWrite(IN3, en2_direction);
    digitalWrite(IN4, !en2_direction);
    analogWrite(EN1, en1_speed);
    analogWrite(EN2, en2_speed); 
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, 0);
  analogWrite(EN1, 0);
  //Serial.println("Stop");
}
/*
void Forward(int en1, int en2) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, en1);
  analogWrite(EN1, en2);
  //Serial.println("Forward");
}
void Backward(int en1, int en2) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, en1);
  analogWrite(EN1, en2);
  //Serial.println("Backward");
}
void Left(int en1, int en2) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, en1);
  analogWrite(EN1, en2);
  //Serial.println("Left");
}
void Right(int en1, int en2) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, en1);
  analogWrite(EN1, en2);
  //Serial.println("Right");
}
*/
