
 int pinA = 2; // Encoder OUTA
 int pinB = 3; // Encoder OUTB
 int encoderPosCount = 0; 
 int pinALast; 
 int aVal;
 boolean bCW;

 void setup() { 
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1)  | _BV(WGM21)|_BV(WGM21)|_BV(WGM20) ;
  
  OCR2A = 180;
   pinALast = digitalRead(pinA); 
   Serial.begin (9600);
 } 

 void loop() { 
   aVal = digitalRead(pinA);
   if (aVal != pinALast){
     if (digitalRead(pinB) != aVal) { 
       encoderPosCount ++;
       bCW = true;
     } else {
       bCW = false;
       encoderPosCount--;
     }
     Serial.print ("Rotated: ");
     if (bCW){
       Serial.println ("clockwise");
     }else{
       Serial.println("counterclockwise");
     }
     Serial.print("Encoder Position: ");
     Serial.println(encoderPosCount);
     
   } 
   pinALast = aVal;
 } 
 

