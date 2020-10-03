# harmonyos-ssd1306



支持HarmonyOS IoT硬件接口的SSD1306 OLED屏驱动库;

* 原始代码内置了一个128*64 bit的内存显示缓冲区，支持一次性全屏刷新;

* 本项目在此基础上优化了屏幕刷新速率，目前测试最大帧率可达到10fps;
* libm_port是从musl libc中抽取的部分数学函数，规避编译不通过的问题;



## 如何编译

1. 在openharmony源码目录下克隆本项目：`git clone https://github.com/xusiwei/harmonyos-ssd1306`

2. 修改openharmony源码的`build/lite/product/wifiiot.json`文件：

   将`//applications/sample/wifi-iot/app`替换为`//harmonyos-ssd1306:app`保存；

3. 在openharmony源码目录下执行：`python build.py wifiiot`



## 参考链接

本项目是基于afiskon的stm32-ssd1306移植的，对部分细节做了修改和优化，原项目链接：

* https://github.com/afiskon/stm32-ssd1306
