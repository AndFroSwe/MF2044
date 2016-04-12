#ifndef MATLAB_MEX_FILE
// timer interrupt for calculating speed on motor.
    float sample_time_ms = 100;
    volatile long enc_count = 0;
    float rpm = 0;

ISR(TIMER3_COMPA_vect) { 
	rpm = enc_count*60*ENC_SAMPLE_RATE/sample_time_ms/PPR; // calculate rotational speed with conversion factor 60*samplerate/ppr
	enc_count = 0;  // reset encoder counter to counter overflow
}
#endif