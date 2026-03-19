#define LED1  2
#define LED2  5
#define LED3  23
int fre = 10;
int resolution = 8;
unsigned long starttime = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcAttach(LED1, fre, resolution);
  ledcAttach(LED2, fre, resolution);
  ledcAttach(LED3, fre, resolution);
}
void shortshine(int a,int b,int c)
{
    for(int dutycycle=0;dutycycle<=255;dutycycle+=2)
    {ledcWrite(a,dutycycle); 
     ledcWrite(b,dutycycle); 
     ledcWrite(c,dutycycle);
    }
    for(int dutycycle=255;dutycycle>=0;dutycycle-=2)
    {ledcWrite(a,dutycycle);
     ledcWrite(b,dutycycle); 
     ledcWrite(c,dutycycle);
    }
  starttime=millis();
  }


void longshine(int a,int b,int c)
{
    for(int dutycycle=0;dutycycle<=255;dutycycle++)
    {ledcWrite(a,dutycycle); 
     ledcWrite(b,dutycycle); 
     ledcWrite(c,dutycycle);
    }
    for(int dutycycle=255;dutycycle>=0;dutycycle--)
    {ledcWrite(a,dutycycle);
     ledcWrite(b,dutycycle); 
     ledcWrite(c,dutycycle);
    }
  starttime=millis();
  }

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long time = millis();
  for(int i=3;i<=5;i++)
  {
    if(i%2!=0) shortshine(LED1,LED2,LED3);
    else longshine(LED1,LED2,LED3);
  }
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  if(time-starttime>=10000)starttime=time;
}
