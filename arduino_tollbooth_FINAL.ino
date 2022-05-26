void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP); //button up
  pinMode(11, INPUT_PULLUP); //button down
  pinMode(10, INPUT_PULLUP); //upper limit
  pinMode(9, INPUT_PULLUP); //lower limit
  pinMode(7, OUTPUT); //h-bridge leg 2
  pinMode(6, OUTPUT); //h-bridge leg 1
  pinMode(5, OUTPUT); //red light
  pinMode(4, OUTPUT); //green light
  pinMode(3, OUTPUT); //motor output
}


void loop() {
  if (digitalRead(12) == HIGH) {
    do {
    digitalWrite(6, LOW); // set leg 1 of the H-bridge low
    digitalWrite(7, HIGH); // set leg 2 of the H-bridge high
    analogWrite(3, 255);
    digitalWrite(5, LOW);
    } while (digitalRead(10) == HIGH);
      digitalWrite(6, LOW); // set leg 1 of the H-bridge low
      digitalWrite(7, LOW);
      digitalWrite(4, HIGH);
  }

  if (digitalRead(11) == HIGH) {
    do {
    digitalWrite(6, HIGH); // set leg 1 of the H-bridge low
    digitalWrite(7, LOW); // set leg 2 of the H-bridge high
    analogWrite(3, 255);
    digitalWrite(4, LOW);
    } while (digitalRead(9) == HIGH);
    digitalWrite(6, LOW); // set leg 1 of the H-bridge low
    digitalWrite(7, LOW);
    digitalWrite(5, HIGH);
  }
}
