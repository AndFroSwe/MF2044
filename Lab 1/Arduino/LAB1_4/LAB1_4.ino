#define TOP 160  // 60 kHz

void setup() {
   // set output pin
   pinMode(7, OUTPUT);
  // setup pwm
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
  OCR4A = TOP;  
  OCR4B = 80;  // dutycycle

}

void loop() {
  // main loop
}

