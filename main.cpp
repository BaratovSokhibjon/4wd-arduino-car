#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int leftMotorForward = 5;
const int leftMotorBackward = 6;
const int rightMotorForward = 7;
const int rightMotorBackward = 8;
const int servoPin = 9;

const int safeDistance = 20; /
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  myServo.attach(servoPin);

  myServo.write(90);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if distance is below the safe threshold
  if (distance < safeDistance) {
    // Stop the robot and buzz
    stopMotors();
    buzz();

    avoidObstacle();
  } else {
    moveForward();
    digitalWrite(buzzerPin, LOW); 
  }

  delay(100); 
}

void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void stopMotors() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

void buzz() {
  digitalWrite(buzzerPin, HIGH);
  delay(100); 
  digitalWrite(buzzerPin, LOW);
}

void avoidObstacle() {
  int leftDistance, rightDistance;

  myServo.write(45); 
  delay(500); 
  leftDistance = measureSideDistance();

  myServo.write(135); 
  delay(500); 
  rightDistance = measureSideDistance();

  if (rightDistance > leftDistance) {
    turnRight();
  } else {
    turnLeft();
  }

  myServo.write(90);
  delay(500);
}

int measureSideDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; 
  return distance;
}

void turnRight() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
  delay(500);
  stopMotors();
}

void turnLeft() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  delay(500); 
  stopMotors();
}
