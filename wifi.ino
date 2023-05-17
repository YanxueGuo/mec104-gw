#include "temperature.h"
#include "screen.h"
void setup() {
  // put your setup code here, to run once:
  room_tem_setup();//初始化温度传感器
  set_screen();//初始化屏幕
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature;
  temperature=room_tem();
  screen_temp(temperature);

  delay(20000);
}

