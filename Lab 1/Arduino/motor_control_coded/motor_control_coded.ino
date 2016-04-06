#define TOP4 160  // Timer 4: 50 kHz
#define TOP5 248  // Timer 5: 1 kHz
#define PPR 2000  // pulses per revolution of encoder (500 per channel, rising and falling)
#define ENC_SAMPLE_RATE 1000  // rate of sampling interrupt for counting encoder, samples per second
#define MAX_RPM 1200
#define MIN_RPM -1200
#define KP 0.0001
#define KI 0.05

// define globals
volatile long enc_count = 0;
long enc_count_old = 0;
float rpm = 0;
float duty = 50.0;
float sample_time_ms = 100;
float sample_time_ms_control = 100;

static union {
  float ref;
  uint32_t il;
};

void setup() {
  pinMode(5, OUTPUT);

  // set output pin
  pinMode(7, OUTPUT); //OCR4B

  initPwm(); // initiate pwm ot 50 kHz
  initEncTimer(); // start 1 kHz Enconder timer
  initControlTimer(); // Start 1kHz Control timer

    // ###### Define pin interrupts for encoder ########
  attachInterrupt(0, encoder_isr, CHANGE);
  attachInterrupt(1, encoder_isr, CHANGE);

  // REMEMBER TO CHANGE THIS IN SERIAL MONITOR!
  Serial.begin(115200);
}

void loop() {

  // read duty cycle from serial monitor
  while (Serial.available() > 0) {
    Serial.readBytesUntil('\r', (char *)&il, 4);
  }
  Serial.write((const char*)&rpm, 4);
  delay(50);
}



