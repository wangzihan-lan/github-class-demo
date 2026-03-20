const int ledPin = 2;
unsigned long lastTime = 0;
const unsigned long interval = 500; // 1Hz=周期1000ms，占空比50%
bool ledOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  // 时间差达到500ms则翻转状态
  if (now - lastTime >= interval) {
    lastTime = now;          // 更新时间戳
    ledOn = !ledOn;          // 翻转LED状态
    digitalWrite(ledPin, ledOn);
  }
}