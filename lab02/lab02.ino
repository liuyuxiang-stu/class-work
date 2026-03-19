#define LED_PIN 2
#define LED_PIN_R 4
#define LED_PIN_W 19

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); 
  pinMode(LED_PIN_R, OUTPUT); 
   pinMode(LED_PIN_W, OUTPUT);
}

void loop() {
  Serial.println("Hello ESP32!");
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_PIN_R, HIGH); 
  digitalWrite(LED_PIN_W, HIGH);  
  delay(50);                   
  digitalWrite(LED_PIN, LOW); 
  digitalWrite(LED_PIN_R, LOW); 
  digitalWrite(LED_PIN_W, LOW); 
  delay(50);              
}