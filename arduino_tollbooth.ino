void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT); //pushbutton up
  pinMode(11, INPUT); //pushbutton down
  pinMode(10, INPUT); //pushbutton reset
  pinMode(9, INPUT); //upper limit
  pinMode(8, INPUT); //lower limit
  pinMode(7, OUTPUT); //motor
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

void loop() {
  int upperLimitState = digitalRead(9);
  int lowerLimitState = digitalRead(8);
  // put your main code here, to run repeatedly:
  if (buttonPressed(12)) {
    while (true) {
      digitalWrite(7, HIGH);  
      if (upperLimitState) {
        break;
      }
    }
  }

  if (buttonPressed(11)) {
    while (true) {
      digitalWrite(7, ! HIGH);  
      if (lowerLimitState) {
        break;
      }
    }
  }
  
}
