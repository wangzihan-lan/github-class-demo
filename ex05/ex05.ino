// 定义引脚
const int ledPin = 2;       // LED 接 GPIO2
const int touchPin = T0;    // GPIO4 = T0 触摸引脚

// PWM 设置
const int freq = 5000;
const int resolution = 8;

// 档位与速度
int speedGear = 1;
int delayTime = 12;

// 触摸防抖
unsigned long lastTouchTime = 0;
const int debounceDelay = 200;

void setup() {
  Serial.begin(115200);
  ledcAttach(ledPin, freq, resolution);

  // 注册触摸中断（修复后的正确写法）
  touchAttachInterrupt(touchPin, onTouch, 40); // 40 = 触摸灵敏度
  
  Serial.println("触摸呼吸灯准备就绪！");
}

// 触摸触发函数（档位切换）
void onTouch() {
  if (millis() - lastTouchTime < debounceDelay) return;

  speedGear++;
  if (speedGear > 3) speedGear = 1;

  // 设置三档速度
  switch (speedGear) {
    case 1: delayTime = 12; break;
    case 2: delayTime = 6;  break;
    case 3: delayTime = 2;  break;
  }

  Serial.print("当前档位：");
  Serial.println(speedGear);
  lastTouchTime = millis();
}

void loop() {
  // 逐渐变亮
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledPin, dutyCycle);
    delay(delayTime);
  }

  // 逐渐变暗
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin, dutyCycle);
    delay(delayTime);
  }

  Serial.println("Breathing cycle completed");
}