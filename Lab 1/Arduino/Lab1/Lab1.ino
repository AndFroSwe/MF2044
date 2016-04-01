#define TOP4 160  // Timer 4: 50 kHz
#define TOP5 248  // Timer 5: 1 kHz
#define PPR 1000  // pulses per revolution of encoder (500 per channel)
#define ENC_SAMPLE_RATE 1000  // rate of sampling interrupt for counting encoder

// define globals
float duty = 50.0;
volatile long enc_count = 0;
long enc_count_old = 0;
int rpm = 0;

void setup() {
  // set output pin
  pinMode(7, OUTPUT); //OCR4B

  initPwm(); // initiate pwm ot 50 kHz
  initTimer(); // start 1 kHz timer

  // ###### Define pin interrupts for encoder ########
  attachInterrupt(0, encoder_isr, CHANGE);
  attachInterrupt(1, encoder_isr, CHANGE);

  // REMEMBER TO CHANGE THIS IN SERIAL MONITOR!
  Serial.begin(115200);
}

void loop() {

  //Read duty cycle from serial data if available
  if (Serial.available() > 0) {
    duty = serialRead();
  }
  //Serial.println(duty); //Debug print
  setPWM(duty); //set motor PWM
//  if (enc_count != enc_count_old) {
//    Serial.println(enc_count);
//  }
//  enc_count_old = enc_count;

}

