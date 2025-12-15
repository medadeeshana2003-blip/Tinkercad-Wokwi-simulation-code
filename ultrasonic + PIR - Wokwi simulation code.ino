#define PIR_PIN 27
#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 19

long duration;
int distance;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (motion == HIGH && distance < 50) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
