#define TOUCH_PIN 4
#define LED_PIN 2
#define THRESHOLD 30    // 灵敏度

bool ledState = false;      // LED状态
bool canTouch = true;       // 触摸开关
unsigned long lastTouch = 0;

void gotTouch() {
  // 只在允许触摸时执行
  if (canTouch && millis() - lastTouch > 300) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    
    lastTouch = millis();
    canTouch = false;  // 防止连续触发
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  // 触摸中断
  touchAttachInterrupt(TOUCH_PIN, gotTouch, THRESHOLD);
}

void loop() {
  // 每隔300ms恢复一次触摸
  if (millis() - lastTouch > 300) {
    canTouch = true;
  }
  delay(100);  // 这里已经改成 100 了 ✅
}