// 定义LED引脚（ESP32板载LED默认2号，若你接了26号可改为26）
const int ledPin = 2; 

// 定义摩尔斯电码的时间参数（可根据需要调整）
const int shortFlash = 200;    // 短闪时长（毫秒）
const int longFlash = 600;     // 长闪时长（毫秒）
const int charInterval = 500;  // 字母之间的间隔
const int wordInterval = 2000; // 单词（SOS）之间的间隔

void setup() {
  Serial.begin(115200);       // 初始化串口
  pinMode(ledPin, OUTPUT);    // 设置LED引脚为输出模式
  Serial.println("SOS信号灯程序启动...");
}

void loop() {
  // 发送SOS信号（S：三短，O：三长，S：三短）
  sendSOS();
  
  // SOS发送完成后，间隔wordInterval毫秒重复
  delay(wordInterval);
}

// 封装SOS信号发送函数，让代码更模块化
void sendSOS() {
  Serial.println("开始发送SOS信号...");
  
  // 1. 发送字母S（三短闪）
  Serial.println("发送字母S（三短）");
  for(int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON (短闪)");
    delay(shortFlash);
    
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
    delay(shortFlash); // 短闪之间的间隔
  }
  delay(charInterval); // S和O之间的间隔

  // 2. 发送字母O（三长闪）
  Serial.println("发送字母O（三长）");
  for(int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON (长闪)");
    delay(longFlash);
    
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
    delay(shortFlash); // 长闪之间的间隔（短间隔即可）
  }
  delay(charInterval); // O和S之间的间隔

  // 3. 再次发送字母S（三短闪）
  Serial.println("发送字母S（三短）");
  for(int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON (短闪)");
    delay(shortFlash);
    
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
    delay(shortFlash);
  }
  
  Serial.println("SOS信号发送完成，等待下一轮...");
}