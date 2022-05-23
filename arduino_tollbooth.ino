int speed_value_motor1;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP); //button up
  pinMode(11, INPUT_PULLUP); //button down
  pinMode(10, INPUT_PULLUP); //upper limit
  pinMode(9, INPUT_PULLUP); //lower limit
  pinMode(7, OUTPUT); //h-bridge leg 2
  pinMode(6, OUTPUT); //h-bridge leg 1
  pinMode(3, OUTPUT);
}


void loop() {
  
  // just invert the above values for reverse motion,
 // i.e. motor1APin = HIGH and motor2APin = LOW

  
  if (buttonPressed(12)) {
    //flash led
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    digitalWrite(6, LOW); // set leg 1 of the H-bridge low
    digitalWrite(7, HIGH); // set leg 2 of the H-bridge high
    speed_value_motor1 = 127; // half speed
    analogWrite(3, speed_value_motor1);
    if (buttonPressed(10)) {
      digitalWrite(6, LOW); // set leg 1 of the H-bridge low
      digitalWrite(7, LOW);
    }
  }

  if (buttonPressed(11)) {
    //flash led
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH); // set leg 1 of the H-bridge low
    digitalWrite(7, LOW); // set leg 2 of the H-bridge high
    speed_value_motor1 = -127; // half speed
    analogWrite(3, speed_value_motor1);
    if (buttonPressed(9)) {
      digitalWrite(6, LOW); // set leg 1 of the H-bridge low
      digitalWrite(7, LOW);
    }
  }

  if (buttonPressed(10)) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
  }

  if (buttonPressed(9)) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
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
