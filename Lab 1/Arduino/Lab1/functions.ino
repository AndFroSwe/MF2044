// initiate 50 kHz pwm
void initPwm() {// ####Setup pwm####
  // reset registers
  TCCR4A = 0x00;
  TCCR4B = 0x00;

  // Set mode
  TCCR4A |= (1 << WGM40) | (1 << WGM41); // phase correct mode
  TCCR4B |= (1 << WGM43);
  //
  TCCR4A |= (1 << COM4B1);
  // set clock source and prescaler
  TCCR4B |= (1 << CS40); // internal clock source, no prescaler

  // counter variables
  OCR4A = TOP4;
  setPWM(duty); //set dutycycle
}

// Set duty cycle on pwm
void setPWM(float duty) {
  int duty_ticks;

  //Boundary value correction to become between 0-100
  if (duty > 100) {
    duty = 100;
  }
  else if (duty < 0) {
    duty = 0;
  }

  duty_ticks = int(TOP4 * duty / 100); // calculate number of ticks in compare register
  OCR4B = duty_ticks;  //set dutycycle
}

//Initiate 1 kHz timer
void initTimer() {
  // reset registers
  TCCR5A = 0x00;
  TCCR5B = 0x00;
  // Set mode
  TCCR5B |= (1 << WGM52); // CTC mode
  // set clock source and prescaler
  TCCR5B |= (1 << CS50) | (1 << CS51); // internal clock source, prescaler 64
  // timer mask register set
  TIMSK5 |= (1 << OCIE5A);
  // counter variables
  OCR5A = TOP5;
}

//Reads data from serial 0 and returns it.
float serialRead(void) {
  float inData = 0;
  inData = Serial.parseFloat();
  //Serial.println(inData); //Debug print
  return inData;
}

// read encoder and determine direction
void encoder_isr() {
  static int8_t lookup_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
  static uint8_t enc_val = 0;

  enc_val = enc_val << 2;    // make room for new readings
  enc_val = enc_val | ((PINE & 0b110000) >> 4);  // mask in pin 4 and 5 in register pine

  enc_count = enc_count + lookup_table[enc_val & 0b1111];  // update encoder history
}

// timer interrupt for calculating speed on motor. 
ISR(TIMER5_COMPA_vect) {  // interrupt on 1 kHz clock
  
}

