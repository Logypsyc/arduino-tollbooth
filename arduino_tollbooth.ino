void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP); //button up
  pinMode(11, INPUT_PULLUP); //button down
  pinMode(10, INPUT_PULLUP); //upper limit
  pinMode(9, INPUT_PULLUP); //lower limit
  pinMode(8, OUTPUT); //motor
}


void loop() {
  if (buttonPressed(12)) {
    //flash led
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);

    //turn motor on
    digitalWrite(8, HIGH);
   
    if (buttonPressed(10)) {
      //turn motor off
      digitalWrite(8, LOW);
      //turn led on
      digitalWrite(13, HIGH);
    }
  }

  if (buttonPressed(11)) {
    //flash led
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    
    //turn motor on in other direction
    digitalWrite(8, ! HIGH);

    
    if (buttonPressed(9)) {
      //turn motor off
      digitalWrite(9, LOW);
      digitalWrite(13, LOW);
    }
  }

}

int buttonPressed(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
