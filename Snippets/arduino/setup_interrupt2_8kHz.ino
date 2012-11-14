/**
 * Set timer 2 for interrupts at 8kHz.   
 */
void setup_interrupt2_8kHz(){
  cli(); // stop interrupts

  TCCR2A = 0; // set TCCR2A register to 0
  TCCR2B = 0; // set TCCR2B register to 0 
  TCNT2  = 0; // initialize counter value to 0

  // set interrupt_frequency to 8kHz by setting
  // prescaler to 8 and counter to 249 for
  // 16MHz/prescaler/(counter+ 1)= 16MHz/8/250= 8kHz
  OCR2A = 249; 
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // set prescaler to 8
  TCCR2B |= (1<< CS11); 
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);

  // set prescaler to 64
  //TCCR2B |= (1 << CS10) | (1 << CS11);   

  sei(); //allow interrupts
}

