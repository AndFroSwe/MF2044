void setPWM(float duty) {
  //Boundary value correction to become between 0-100
  if (duty > 100) {
    duty = 100;
  }
  else if (duty < 0) {
    duty = 0;
  }

  OCR4B = duty;  //set dutycycle
}

float serialRead(void) { //Reads data (if it exists) from serial 0 and returns it.
  float inData = 0;
  inData = Serial.parseFloat();
  //Serial.println(inData); //Debug print
  return inData;
}
