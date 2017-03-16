

int encoder0Pos=0;
void setup()
{
 pinMode(3, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode (2,INPUT);
 pinMode (4,INPUT);
   
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 250;
  OCR2B = 0;
 
   attachInterrupt(0, doEncoderA, CHANGE);
   attachInterrupt(1, doEncoderB, CHANGE);  
  Serial.begin (9600);
  Serial.println (encoder0Pos, DEC);
}
 


 void loop() { 
  
 } 

 
void doEncoderA(){

  // look for a low-to-high on channel A
  if (digitalRead(2) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(4) == LOW) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(4) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
  Serial.println (encoder0Pos, DEC);          
  // use for debugging - remember to comment out
}

void doEncoderB(){

  // look for a low-to-high on channel B
  if (digitalRead(4) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(2) == HIGH) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(2) == LOW) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
}


