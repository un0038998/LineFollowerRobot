// L298N Motor Driver Pin Configuration
// Right motor
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor
int enableLeftMotor = 5;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

// IR Proximity Sensor Pin Configuration
#define IR_SENSOR_RIGHT A0
#define IR_SENSOR_LEFT A1

// Timing Variables
const unsigned long stopInterval = 20000; // 20 seconds stop interval
const unsigned long stopDuration = 3000;  // 3 seconds stop duration
unsigned long lastStopTime = 0;

void setup() {
  // Motor control pins setup
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // IR sensor pins setup
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  // Initial motor rotation
  rotateMotors(180, 180);
}

void loop() {
  // Check if it's time to stop
  if (millis() - lastStopTime >= stopInterval) {
    // Stop the motors
    rotateMotors(0, 0);
    
    // Record the stop time
    lastStopTime = millis();
  }

  // Check if it's time to resume after the stop duration
  if (millis() - lastStopTime >= stopDuration) {
    // Resume moving (implement your motor control logic)
    rotateMotors(0, 0);
  }

  // Your additional logic, such as line following, can go here
}

void rotateMotors(int rightMotorSpeed, int leftMotorSpeed) {
  analogWrite(enableRightMotor, rightMotorSpeed);
  analogWrite(enableLeftMotor, leftMotorSpeed);

  if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }
}

