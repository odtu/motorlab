



class Encoder{
  int pin;
  int value;
  long runtime;
  
  public:
  Encoder(int pin, long runtime ){
    pinMode(pin,INPUT);
    
   
    }

  void Update()
  {
    unsigned long currenttime=millis();
    int value=0;
    if (currenttime<=runtime)
    {
    value += digitalRead(pin);
   
    Serial.println(value,DEC);
    }
    
    }
    };


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
    


Encoder encoderA(2, 100);
Encoder encoderB(3, 100);
Motor motorRun(12,4,6);


void setup(){
  Serial.begin(9600);
    
    }

void loop(){
  encoderA.Update();
  encoderB.Update();
  motorRun.Update();
  /*int pinState;
pinMode(12, OUTPUT);
unsigned long  Now=millis();
  if (Now==1000)
        {
          pinState=LOW;
        digitalWrite(12,pinState);
        }*/
      
      }
