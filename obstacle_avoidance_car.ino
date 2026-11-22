// Automatic Obstacle-Detection & Emergency Braking System (Tesla-Inspired)
// Components: Arduino Uno, HC-SR04 Ultrasonic Sensor, L298N Motor Driver, DC Motors, Buzzer/LED

#define TRIG_PIN 9
#define ECHO_PIN 10

// Motor Driver Pins
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// Alert Indicator (Optional)
#define ALERT_PIN 13

// Safe stopping distance in centimeters
const int SAFE_DISTANCE = 25;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ALERT_PIN, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time and calculate distance in cm
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Emergency Braking Logic
  if (distance > 0 && distance <= SAFE_DISTANCE) {
    stopCar();
    digitalWrite(ALERT_PIN, HIGH); // Turn on brake light / buzzer
  } else {
    moveForward();
    digitalWrite(ALERT_PIN, LOW);
  }

  delay(50);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
