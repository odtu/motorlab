void setup()
{
  
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1)  | _BV(WGM21)|_BV(WGM21)|_BV(WGM20) ;
  
  OCR2A = 180;
 
}

 

void loop()
{
  
}



