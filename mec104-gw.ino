const int micPin = A0; // 麦克风传感器连接到模拟引脚 A0
const int sleepTime = 10000; // 休眠时间（毫秒）
unsigned long lastSoundTime = 0; // 上次检测到声音的时间
int wakeUpPin = 2;//看看能不能用旋钮或者其他开关什么的实现

void setup() {
  pinMode(micPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(micPin); // 读取麦克风传感器的值
  if (micValue > 10) { // 如果检测到声音
    lastSoundTime = millis(); // 更新上次检测到声音的时间
    Serial.println("Sound detected");
  }
  if (millis() - lastSoundTime > sleepTime) { // 如果一段时间内未检测到声音
    Serial.println("Entering sleep mode");
    delay(1000); // 等待一段时间，以便串口输出完成
    enterSleep(); // 进入休眠模式
  }
}

void enterSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // 设置休眠模式为掉电模式
  sleep_enable(); // 启用休眠功能
  attachInterrupt(wakeUpPin, wakeUp, HIGH); // 配置中断，当检测到低电平时唤醒
  sleep_mode(); // 进入休眠模式
}

void wakeUp() {
  sleep_disable(); // 禁用休眠功能
  detachInterrupt(0); // 取消中断配置
}