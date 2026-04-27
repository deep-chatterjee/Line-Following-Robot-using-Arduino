#define LS 2   // Left IR Sensor
#define RS 3   // Right IR Sensor

#define LM1 8  // Left Motor Control 1
#define LM2 9  // Left Motor Control 2
#define RM1 10 // Right Motor Control 1
#define RM2 11 // Right Motor Control 2

void setup() {
  // Sensor pins as input
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);

  // Motor driver pins as output
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  // Read IR sensors
  int left = digitalRead(LS);
  int right = digitalRead(RS);

  /*
    Tinkercad sensor logic:
    1 = White surface
    0 = Black line

    Cases:
    1 1 -> Forward
    0 1 -> Turn Left
    1 0 -> Turn Right
    0 0 -> Stop
  */

  if (left == 1 && right == 1) {
    forward();
  }
  else if (left == 0 && right == 1) {
    turnLeft();
  }
  else if (left == 1 && right == 0) {
    turnRight();
  }
  else {
    stopRobot();
  }
}

// Move both motors forward
void forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

// Stop left motor, move right motor
void turnLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

// Move left motor, stop right motor
void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

// Stop both motors
void stopRobot() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}