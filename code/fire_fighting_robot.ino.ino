/*
  Project: Autonomous Fire-Fighting Robot
  Author: Om Pandey
  Description:
  Arduino-based autonomous robot capable of detecting and 
  extinguishing fire using multi-sensor integration.

  Performance:
  - Detection range: 25–30 cm
  - Response time: 2–3 seconds
  - Extinguishes within 1–2 attempts
*/

// ================= PIN DEFINITIONS =================
#define enA 10   // Enable1 L298 Pin
#define in1 9    // Motor1 L298 Pin in1
#define in2 8    // Motor1 L298 Pin in2
#define in3 7    // Motor2 L298 Pin in3
#define in4 6    // Motor2 L298 Pin in4
#define enB 5    // Enable2 L298 Pin

#define ir_R A0  // Right flame sensor
#define ir_F A1  // Front flame sensor
#define ir_L A2  // Left flame sensor

#define servoPin A4
#define pumpPin  A5

int Speed = 160;   // Motor speed (0–255)
int s1, s2, s3;

// ================= SETUP =================
void setup() {
  Serial.begin(9600);

  pinMode(ir_R, INPUT);
  pinMode(ir_F, INPUT);
  pinMode(ir_L, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(servoPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  digitalWrite(pumpPin, LOW);

  delay(500);
}

// ================= MAIN LOOP =================
void loop() {

  s1 = analogRead(ir_R);
  s2 = analogRead(ir_F);
  s3 = analogRead(ir_L);

  Serial.print(s1); Serial.print("\t");
  Serial.print(s2); Serial.print("\t");
  Serial.println(s3);

  delay(50);

  // ===== FIRE DETECTION LOGIC =====

  if (s1 < 250) {
    Stop();
    extinguishLeft();
  }
  else if (s2 < 350) {
    Stop();
    extinguishFront();
  }
  else if (s3 < 250) {
    Stop();
    extinguishRight();
  }
  else if (s1 >= 251 && s1 <= 700) {
    digitalWrite(pumpPin, LOW);
    backward();
    delay(100);
    turnRight();
    delay(200);
  }
  else if (s2 >= 251 && s2 <= 800) {
    digitalWrite(pumpPin, LOW);
    forward();
  }
  else if (s3 >= 251 && s3 <= 700) {
    digitalWrite(pumpPin, LOW);
    backward();
    delay(100);
    turnLeft();
    delay(200);
  }
  else {
    digitalWrite(pumpPin, LOW);
    Stop();
  }

  delay(10);
}

// ================= FIRE EXTINGUISH FUNCTIONS =================

void extinguishLeft() {
  digitalWrite(pumpPin, HIGH);

  for (int angle = 90; angle >= 40; angle -= 3)
    servoPulse(servoPin, angle);

  for (int angle = 40; angle <= 90; angle += 3)
    servoPulse(servoPin, angle);

  digitalWrite(pumpPin, LOW);
}

void extinguishFront() {
  digitalWrite(pumpPin, HIGH);

  for (int angle = 90; angle <= 140; angle += 3)
    servoPulse(servoPin, angle);

  for (int angle = 140; angle >= 40; angle -= 3)
    servoPulse(servoPin, angle);

  for (int angle = 40; angle <= 90; angle += 3)
    servoPulse(servoPin, angle);

  digitalWrite(pumpPin, LOW);
}

void extinguishRight() {
  digitalWrite(pumpPin, HIGH);

  for (int angle = 90; angle <= 140; angle += 3)
    servoPulse(servoPin, angle);

  for (int angle = 140; angle >= 90; angle -= 3)
    servoPulse(servoPin, angle);

  digitalWrite(pumpPin, LOW);
}

// ================= SERVO CONTROL =================
void servoPulse(int pin, int angle) {
  int pwm = (angle * 11) + 500;
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(50);
}

// ================= MOTOR FUNCTIONS =================
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
