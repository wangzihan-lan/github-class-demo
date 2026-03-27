// 作业6：警车双闪灯效（双通道PWM反相渐变）
const int ledPin1 = 2;
const int ledPin2 = 4;

const int freq = 5000;
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  ledcAttach(ledPin1, freq, resolution);
  ledcAttach(ledPin2, freq, resolution);
}

void loop() {
  // 灯1变亮，灯2变暗
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledPin1, dutyCycle);
    ledcWrite(ledPin2, 255 - dutyCycle);
    delay(10);
  }

  // 灯1变暗，灯2变亮
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin1, dutyCycle);
    ledcWrite(ledPin2, 255 - dutyCycle);
    delay(10);
  }
}