#define PWMOUT 7
#define LED 13
#define TOP 160

unsigned long tick = 0;
unsigned long tock = 0;
unsigned long diff = 0;
int rounds = 0;
int pwmHigh = 0;
int ledHigh = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
     // set output pin
  // setup pwm
   // set output compare max
  OCR4A = TOP;
  // set clock source and prescaler
  TCCR4A = 0x00;
  TCCR4B = 0x00;
  TCCR4B |= _BV(CS40) | _BV(CS41) | _BV(CS42);    // External clock on rising edge, no prescaler
  // waveform generator mode, table 17-2
  TCCR4A |= _BV(WGM40) | _BV(WGM41);  // PWM phase correct
  TCCR4B |= _BV(WGM43);
  // Set output compare mode
  TCCR4A |= _BV(COM4A1) | _BV(COM4A1); // non inverting
}

// the loop function runs over and over again forever
void loop() {
  // Ticks every microsecond
  tock = micros();
  // time since last update of state
  diff = tock - tick;

  // increase every 50th microsecond
  if (diff >= 50) {
    rounds += 1;
    // if high set low
    if (pwmHigh) {
      // set pin low
      digitalWrite(PWMOUT, LOW);
      // reset timer
      tick = micros();
      // update state variable
      pwmHigh = 0;
    }
    // if low set high
    else if (!pwmHigh) {
      // set pin high
      digitalWrite(PWMOUT, HIGH);
      // reset timer
      tick = micros();
      // update state variable
      pwmHigh = 1;
    }
  }
  // if 1 second has passed, toggle led
  if (rounds >= 20000) { // 200 rounds of 50 microseconds per second
    // if led on, set led off
    if (ledHigh) {
      digitalWrite(LED, LOW);
      ledHigh = 0;
      rounds = 0;
    }
    else if (!ledHigh) {
      digitalWrite(LED, HIGH);
      rounds = 0;
      ledHigh = 1;
    }
  }
}

