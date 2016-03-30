#define TOP4 160  // Timer 4: 50 kHz
#define TOP5 124  // Timer 5: 1 kHz

float duty = 50.0;

void setup() {
  // set output pin
  pinMode(7, OUTPUT); //OCR4B
  pinMode(46, OUTPUT); //OCR5A
  
  //############################
  // ####Setup pwm####
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
  //############################

  //############################
  // ####Setup velocity calculation speed####
  // reset registers
  TCCR5A = 0x00;
  TCCR5B = 0x00;

  // Set mode
  TCCR5B |= (1 << WGM52); // CTC mode
  TCCR5A |= (1 << COM5A0); // Toggle port on compare match

  // set clock source and prescaler
  TCCR5B |= (1 << CS50) | (1 << CS51); // internal clock source, prescaler 64

  // counter variables
  OCR5A = TOP5;
  //############################

  Serial.begin(115200);
}

void loop() {

  //Read duty cycle from serial data if available
  if (Serial.available() > 0) {
    duty = serialRead();
  }
  //Serial.println(duty); //Debug print
  setPWM(duty); //set motor PWM

}

