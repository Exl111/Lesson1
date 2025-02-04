
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
int led = 9;
int piezoPin = 8;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delay(2000);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration * 0.034) / 2; //Speed of sound in air  at  standard condition = 0.034cm/µs
  // Prints the distance on the Serial Monitor
  if(distance< 20){
    tone(piezoPin, 5000, 500);
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}
