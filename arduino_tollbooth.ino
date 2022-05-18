void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP); //pushbutton up
  pinMode(11, INPUT_PULLUP); //pushbutton down
  pinMode(10, INPUT_PULLUP); //pushbutton reset
  pinMode(9, INPUT); //upper limit
  pinMode(8, INPUT); //lower limit
  pinMode(7, OUTPUT); //motor
}


void loop() {
  int upperLimitState = digitalRead(9);
  int lowerLimitState = digitalRead(8);
  // put your main code here, to run repeatedly:
  if (digitalRead(12) == HIGH) {
    while (true) {
      digitalWrite(7, HIGH); 
      digitalWrite(13, HIGH);  
      if (upperLimitState) {
        break;
      }
    }
  }

  if (digitalRead(11) == HIGH) {
    while (true) {
      digitalWrite(7, ! HIGH);
      digitalWrite(13, LOW);   
      if (lowerLimitState) {
        break;
      }
    }
  }
  
}
