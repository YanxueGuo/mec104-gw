//use 18B20 to get in-house temperature
//使用OneWire单总线库进行数据传输
//测试用代码：用于测试只连接温度传感器，将传入数据用串口在电脑上打印出来
//若输出温度为-127摄氏度，则为温传短路
//18B20连接方式：Vcc接5v，DQ接ONE_WIRE_BUS（当前为PD7）对应的digital I/O 端口，GND接地

#include <OneWire.h> //18B20使用1-wire传入数据
#include <DallasTemperature.h>//18B20函数库

#define ONE_WIRE_BUS PD7                //1-wire数据总线连接在数字端口7上
OneWire oneWire(ONE_WIRE_BUS);        //声明连接在单总线上的单总线设备
DallasTemperature sensors(&oneWire);  //声明一个传感器对象

void room_tem_setup(){	
	sensors.begin();						// 初始化总线
  sensors.setWaitForConversion(false); //设置为非阻塞模式
}
/*
void setup(void) {
  Serial.begin(115200);//测试用 设置串口通信波特率，调试用显示到电脑上，后期发送到LED屏幕上
  Serial.println("");
  sensors.begin();  //初始化总线

  Serial.print("总线上DS18系列设备数量为：");
  Serial.println(sensors.getDS18Count());

  Serial.print("总线是否需要寄生供电(1-true; 0-false)：");
  Serial.println(sensors.isParasitePowerMode());

  Serial.print("总线上设备数据最大分辨率为：");
  Serial.println(sensors.getResolution());

  sensors.setResolution(9);  //设置总线上所有设备数据分辨率

  sensors.getAddress(myDS18B20, 0);  //获取索引号0的设备地址（设备序列号）
}//调试查看是否检测读到了传感器
*/

float room_tem(){
//void loop(){	
  sensors.requestTemperatures();				// 向总线上的设备发送温度转换请求，默认情况（阻塞模式）下该方法会阻塞，阻塞间隙等待用于保护温传，（因为温传工作原理为短时间上拉为5v获取温度）
	//Serial.print("此时测量的温度为：");//测试用
  float temperature=sensors.getTempCByIndex(0);//传入室温
	/*Serial.print(temperature);	
	Serial.println(" ℃\n");
	delay(500); //测试用， 获取索引号0的传感器摄氏温度数据，并串口输出*/
  return temperature;
}
