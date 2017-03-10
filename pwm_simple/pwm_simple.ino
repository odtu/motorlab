
int encoderValue=0;

void setup()
{
  
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1)  | _BV(WGM21)|_BV(WGM21)|_BV(WGM20) ;
  
  OCR2A = 180;
  
}
 
void count(void); // code for counting the increasing values of encoder ticks void setup()

{

Serial.begin(9600);

pinMode(3,INPUT);

attachInterrupt(2,count,FALLING);

encoderValue=0;

}
 void loop() { 
   Serial.print("Starting\n");
   
 } 


 void count()

{

encoderValue++;

}
