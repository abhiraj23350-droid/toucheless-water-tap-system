// Touchless Water Tap System
// Arduino UNO + HC-SR04 + Relay + Pump

#define trigPin 9
#define echoPin 10
#define relayPin 8

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Relay OFF (most relay modules are ACTIVE LOW)
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH, 30000); // timeout safety
  distance = duration * 0.034 / 2;          // cm

  // Hand detection
  if (distance > 0 && distance <= 10) {
    digitalWrite(relayPin, LOW);   // Relay ON → Pump ON
  } else {
    digitalWrite(relayPin, HIGH);  // Relay OFF → Pump OFF
  }

  delay(100);
}
