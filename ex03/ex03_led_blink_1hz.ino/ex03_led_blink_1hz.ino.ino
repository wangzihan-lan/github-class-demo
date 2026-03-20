/*
  作业3：使用millis()实现LED SOS闪烁
  SOS定义：3短闪 → 3长闪 → 3短闪 → 长停顿（2000ms），循环执行
  短闪：亮200ms，灭200ms；长闪：亮600ms，灭200ms
  millis()优势：非阻塞延时，避免delay()导致程序卡死  // 新增注释
  硬件适配：适用于Arduino UNO/Nano，内置LED接2号引脚  // 新增注释
*/

const int ledPin = 2;                  // 内置LED引脚
const long shortOn = 200, shortOff = 200;  // 短闪时间
const long longOn = 600, longOff = 200;    // 长闪时间
const long sosPause = 2000;                // SOS完成后停顿时间

unsigned long previousMillis = 0;
int sosState = 0;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  switch(sosState) {
    // 3次短闪
    case 0: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 1; } break;
    case 1: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 2; } break;
    case 2: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 3; } break;
    case 3: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 4; } break;
    case 4: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 5; } break;
    case 5: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 6; } break;

    // 3次长闪
    case 6: if (currentMillis - previousMillis >= longOn) { toggleLed(); sosState = 7; } break;
    case 7: if (currentMillis - previousMillis >= longOff) { toggleLed(); sosState = 8; } break;
    case 8: if (currentMillis - previousMillis >= longOn) { toggleLed(); sosState = 9; } break;
    case 9: if (currentMillis - previousMillis >= longOff) { toggleLed(); sosState = 10; } break;
    case 10: if (currentMillis - previousMillis >= longOn) { toggleLed(); sosState = 11; } break;
    case 11: if (currentMillis - previousMillis >= longOff) { toggleLed(); sosState = 12; } break;

    // 3次短闪
    case 12: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 13; } break;
    case 13: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 14; } break;
    case 14: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 15; } break;
    case 15: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 16; } break;
    case 16: if (currentMillis - previousMillis >= shortOn) { toggleLed(); sosState = 17; } break;
    case 17: if (currentMillis - previousMillis >= shortOff) { toggleLed(); sosState = 18; } break;

    // 长停顿后重置
    case 18: if (currentMillis - previousMillis >= sosPause) { sosState = 0; } break;
  }
}

// 辅助函数：翻转LED状态并更新时间
void toggleLed() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  previousMillis = millis();
}