int LEDpin1 = 27;
int LEDpin2 = 33;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String strcmd = Serial.readString();

    if (strcmd.startsWith("s")) {
      strcmd.remove(0, 1);
      strcmd.trim();
      processCommand(strcmd);
    }
  }

  delay(1);
}

void processCommand(String command) {
  if (command.startsWith("t")) {
    digitalWrite(LEDpin1, HIGH);
  } else if (command.startsWith("f")) {
    digitalWrite(LEDpin1, LOW);
  } else {
    int brightness = command.toInt();
    analogWrite(LEDpin2, brightness);
  }
}