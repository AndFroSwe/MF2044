#define TOP4 160  // Timer 4: 50 kHz
#define TOP5 248  // Timer 5: 1 kHz
#define PPR 2000  // pulses per revolution of encoder (500 per channel, rising and falling)
#define ENC_SAMPLE_RATE 1000  // rate of sampling interrupt for counting encoder, samples per second
#define MAX_RPM 1200
#define MIN_RPM -1200

// define globals
volatile long enc_count = 0;
long enc_count_old = 0;
float rpm = 0;
float duty = 50.0;
float sample_time_ms = 100;

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

float rpmToPwm(uint32_t curr_rpm) { // converts an rpm to the corresponding pwm for motor
  // convert rpm to be within boundaries
  if (curr_rpm > MAX_RPM) {
    curr_rpm = MAX_RPM;
  }
  else if (curr_rpm < MIN_RPM) {
    curr_rpm = MIN_RPM;
  }
  float pwm = 100 / (MAX_RPM - MIN_RPM) * curr_rpm + 50; // y = kx + m conversion
  return pwm;
}


void loop() {
  union {
    float f1;
    uint32_t i1;
  };
  // read duty cycle from serial monitor
  while (Serial.available() > 0) {
    Serial.readBytesUntil('\r', (char *)&i1, 4);

    duty = f1;  // set new duty cycle
    setPWM(duty);
  }
  Serial.write((const char*)&rpm, 4);
  delay(1000);
}


