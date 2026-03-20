/*
  作业2：使用millis()函数实现LED 1Hz稳定闪烁
  1Hz = 周期1000ms → 亮500ms，灭500ms
  millis()：返回Arduino启动后的毫秒数，无溢出（约50天溢出一次，不影响普通使用）
  硬件适配：此代码适用于Arduino UNO/Nano板，内置LED在2号引脚  // 这是新增的注释
*/
const int ledPin = 2;
unsigned long lastTime = 0;
const unsigned long interval = 500; // 闪烁间隔：500ms（1Hz周期的一半）  // 改变这行注释
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