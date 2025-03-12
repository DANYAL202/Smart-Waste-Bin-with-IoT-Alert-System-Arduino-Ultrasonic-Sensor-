#define trigPin 9    // Pin connected to the trigger pin of the ultrasonic sensor
#define echoPin 10   // Pin connected to the echo pin of the ultrasonic sensor

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a pulse to the sensor to measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;  // Convert duration to distance

  // Print the distance
  Serial.print("Distance: ");
  Serial.println(distance);

  // If the bin is almost full, send an alert
  if (distance < 10) {
    Serial.println("Alert: Bin is full!");
  }

  delay(1000);  // Wait for 1 second before taking the next reading
}
