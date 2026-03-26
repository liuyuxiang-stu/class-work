 #define TOUCH_PIN 4
#define LED_PIN 2
#define THRESHOLD 500 

bool ledState = false;
int touchValue;

// 中断服务函数 (ISR)
void gotTouch() {
  if(touchValue<500){
    ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
   Serial.print("中断 ");
   }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  touchAttachInterrupt(TOUCH_PIN, gotTouch, THRESHOLD);
}

void loop() {
  touchValue = touchRead(TOUCH_PIN);
  Serial.print("Touch Value: ");
  Serial.println(touchValue);
  delay(100);
}