char ta;

void setup() {
  pinMode(5, OUTPUT);   //left motors  reverse
  pinMode(3, OUTPUT);   //left motors forward
  pinMode(11, OUTPUT);   //right  motors reverse
  pinMode(10, OUTPUT);   //right motors forward 
  pinMode(9, OUTPUT);    //Led
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    ta = Serial.read();
    Serial.println(ta);

    if (ta == 'F') {       // move forward (all motors rotate in forward direction)
      digitalWrite(5, LOW);
      digitalWrite(3 , HIGH);
       digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    } else if (ta == 'B') { // move backward (all motors rotate in reverse direction)
      digitalWrite(5, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
    } else if (ta == 'L') { // turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
      digitalWrite(5, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    } else if (ta == 'R') { // turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
      digitalWrite(5, LOW);
      digitalWrite(3, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    } else if (ta == 'W') { // turn led on or off)
      digitalWrite(9, HIGH);
    } else if (ta == 'w') {
      digitalWrite(9, LOW);
    } else if (ta == 'S') { // STOP (all motors stop)
      digitalWrite(5, LOW);
      digitalWrite(3, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(10, LOW);
    } else if (ta == 'G') { // Custom action (example: both reverse)
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(10, LOW);
    }
  }
  delay(100);
}
