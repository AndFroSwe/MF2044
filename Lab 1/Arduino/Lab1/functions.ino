void setPWM(float duty) {
  int duty_ticks;
  
   //Boundary value correction to become between 0-100
  if (duty > 100) {
    duty = 100;
  }
  else if (duty < 0) {
    duty = 0;
  }
  
  duty_ticks = int(TOP4*duty/100); // calculate number of ticks in compare register
  OCR4B = duty_ticks;  //set dutycycle
}

float serialRead(void) { //Reads data from serial 0 and returns it.
  float inData = 0;
  inData = Serial.parseFloat();
  //Serial.println(inData); //Debug print
  return inData;
}
