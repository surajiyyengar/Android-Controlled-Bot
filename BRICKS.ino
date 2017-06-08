int LF=2;
int LB=3;
int RF=4;
int RB=7;
int En1=6;
int vcc=8;
String data;
//motor driver for lift
int Enable=10;
int Up=11;
int Down=12;
int Volt5=9;

void setup()  
{
  Serial.begin(9600); //default baud rate of HC 05
    
  pinMode(LF,OUTPUT);   // LF- in1
  pinMode(LB,OUTPUT);   // LB- in2
  pinMode(RF,OUTPUT);   // RF- in3
  pinMode(RB,OUTPUT);   // RB- in4
  pinMode(En1,OUTPUT);   //pwm-enable 1 of motor driver
  pinMode(En2,OUTPUT);   //pwm-enable 2 of motor driver
  pinMode(vcc,OUTPUT);   //+Vcc
  pinMode(Enable,OUTPUT); // enable for fork lift
  pinMode(Up,OUTPUT);    //take up
  pinMode(Down,OUTPUT);   //take down
  pinMode(Volt5, OUTPUT);  //vcc
  
  digitalWrite(Volt5,HIGH); //for fork lift motor driver
  digitalWrite(vcc,HIGH);   //for motor driver for wheels
  digitalWrite(En1,HIGH);   //for motor driver for wheels
  analogWrite(En2,220);     //for fork lift motor driver
 }
 
 char command; // stores incoming character from other device

void loop()
{
  while(Serial.available()==0);
  command =Serial.read();
  switch(command)
  {
    case 'F':               //forward
    {
      digitalWrite(LF,HIGH);
      digitalWrite(RF,HIGH);
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
    }
    break;
    case 'B':               //backward
    {
      digitalWrite(LF,LOW);
      digitalWrite(RF,LOW);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,HIGH);
    }
    break;
    case 'L':               //ZERO RADIUS LEFT TURN
    {
      digitalWrite(LF,LOW);
      digitalWrite(RF,HIGH);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,LOW);
    }
    break;
    case 'R':               //ZERO RADIUS RIGHT TURN
    {
      digitalWrite(LF,HIGH);
      digitalWrite(RF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RB,HIGH);
    }
    break;
    case 'G':               //stall fwd left turn
    {
      digitalWrite(RF,HIGH);
      digitalWrite(LF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
    }
    break;
    case 'I':               //stall fwd right turn
    {
      digitalWrite(LF,HIGH);
      digitalWrite(RF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
    }
    break;
    case 'H':               //stall back right turn
    {
      digitalWrite(LF,LOW);
      digitalWrite(RF,LOW);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,LOW);
    }
    break;
     case 'J':               //stall back left turn
    {
      digitalWrite(RF,LOW);
      digitalWrite(LF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RB,HIGH);
    }
    break;
     case 'S':               //stop
    {
      digitalWrite(RF,HIGH);
      digitalWrite(LF,HIGH);
      digitalWrite(LB,HIGH);
      digitalWrite(RB,HIGH);
    }
    break;
    //to control the fork lift
   case 'W':                //go up
   {
    digitalWrite(Up,HIGH);
    digitalWrite(Down,LOW);
   }
   break;
      
   case 'U':                 //go down
   {
    digitalWrite(Down,HIGH);
    digitalWrite(Up,LOW);
   }
   break;
   //to stop the fork lift motor 
   case 'u':
   case 'w':
   {
    digitalWrite(Up,HIGH);
    digitalWrite(Down,HIGH);
   }
   break;
   default :                 //free flow
    {
      digitalWrite(RF,LOW);
      digitalWrite(LF,LOW);
      digitalWrite(LB,LOW);
      digitalWrite(RB,LOW);
    }
    break;
  }
  }                                
