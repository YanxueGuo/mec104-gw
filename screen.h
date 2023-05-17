//通过液晶模块 JLX12864G-086-PN显示数据,SPI连接

#include <U8g2lib.h>
//CS=PD2,RESET=PD3,RS=dc?=PD4,SDA=data=PD5,SCLK=clock=PD6,
U8G2_ST7565_JLX12864_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ PD6, /* data=*/ PD5, /* cs=*/ PD2, /* dc=*/ PD4, /* reset=*/ PD3);
void set_screen(void) {
  u8g2.begin();
  u8g2.enableUTF8Print();		// enable UTF8 support for the Arduino print() function,eg.打印中文字符
}
//u8g2.clear() —— 清除操作+u8g2.home()—— 重置显示光标的位置
//u8g2.clearBuffer() —— 清除缓冲区+写入Buffer+u8g2.sendBuffer()
//u8g2.setPowerSave() —— 是否开启省电模式--1开启省电模式，0禁止省电模式
//u8g2.setDrawColor()--改变字符颜色0，1，2，默认为1
/*
void loop(void) {
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 40);
    u8g2.print("你好世界");		// Chinese "Hello World" 
  } while ( u8g2.nextPage() );
  delay(1000);
}
*/
uint8_t m = 24;

//显示室温
void screen_temp(float tem) {
  char tem_str[5];
  sprintf(tem_str,"db value:%f, ",tem);
  //sprintf(char *str, char * format [, argument, ...]);     将 m 转换为字符串
  u8g2.firstPage();
  do {
u8g2.setFont(u8g2_font_unifont_t_symbols);
u8g2.drawUTF8(5,20,"room temperature:");
u8g2.drawUTF8(45,20,tem_str);
  } while ( u8g2.nextPage() );
}
//显示天气
void screen_weather() {

}
