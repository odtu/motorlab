class Encoder{
  
  public:
  Encoder(){}

  void Update()
  {}
  
};


class Motor {
  public:
  Motor(){}

  void update()
  {}
    
    };
    


Encoder encoderA();
Encoder encoderB();
Motor motorRun();


void setup(){
    Serial.begin(9600);
    
    
    }

void loop(){
  encoderA.update();
  encoderB.update();
  motorRun();
      
      }
