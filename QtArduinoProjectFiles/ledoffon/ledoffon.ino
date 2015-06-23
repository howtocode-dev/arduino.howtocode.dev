int led = 13;
char command;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()){
  command = Serial.read();
  if (command == 'a') digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  }
}
