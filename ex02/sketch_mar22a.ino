#define LED1 2
#define fre 10
int re = 8;

void d(int a)
{
  unsigned long now = millis();
  while (1)
  {
    if(millis() - now >= 1000)break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcAttach(LED1,fre,re);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutycycle = 0;dutycycle <= 255;dutycycle++)
  {
    ledcWrite(LED1,dutycycle);
    d(10);
  }
  for (int dutycycle = 255;dutycycle >= 0;dutycycle--)
  {
    ledcWrite(LED1,dutycycle);
     d(10);
  }

}
