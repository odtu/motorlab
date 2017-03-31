

int encoder0Pos=0;
class Motor 
{
  int pinMotor;
int pinState;
long ontime;
long offtime;
unsigned long lasttime;
long runtime;

  public:
  Motor(int pin,long on, long off)
  {
    pinMotor=pin;
    lasttime=0;
    pinMode(pinMotor, OUTPUT);
    ontime=on;
    offtime=off;
    pinState=LOW;
    
    }

  void Update()
  { 
    unsigned long currenttime=millis();
    
    if ((pinState==HIGH)&&(currenttime-lasttime>=ontime))
    {pinState=LOW;
    lasttime=currenttime;
    digitalWrite(pinMotor,pinState);
      }
      else if ((pinState==LOW)&&(currenttime-lasttime>=ontime))
      {pinState=HIGH;
      lasttime=currenttime;
      digitalWrite(pinMotor,pinState);
        }
        
    }
    
    };
    


/*Encoder encoderA(2, 100);
Encoder encoderB(3, 100);*/
Motor motorRun(12,4,6);


void setup(){
Serial.begin(9600);
 pinMode (2,INPUT_PULLUP);
 pinMode (3,INPUT_PULLUP);

attachInterrupt(0, EncoderA, RISING);
//attachInterrupt(1, EncoderB, RISING);
    }

void EncoderA()
{
if (digitalRead(2) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(3) == LOW) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(3) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
  Serial.println (encoder0Pos, DEC);          
  

}


void loop(){
 motorRun.Update();

      }

    
