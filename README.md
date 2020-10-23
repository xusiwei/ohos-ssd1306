# harmonyos-ssd1306



支持HarmonyOS IoT硬件接口的SSD1306 OLED屏驱动库;

* 内置了128*64 bit的内存缓冲区，支持全屏刷新;
* 优化了屏幕刷新速率，实测最大帧率10fps;
* `libm_port`是从musl libc中抽取的`sin`和`cos`的实现;
* `gif2imgs.py` 可用于将gif动图中的帧分离出来;
* `img2code.py` 可用于将图片转为C数组，每个字节表示8个像素；


## 如何编译

1. 在openharmony源码目录下克隆本项目：`git clone https://github.com/xusiwei/harmonyos-ssd1306`

2. 修改openharmony源码的`build/lite/product/wifiiot.json`文件：

   将`//applications/sample/wifi-iot/app`替换为`//harmonyos-ssd1306:app`保存；

3. 在openharmony源码目录下执行：`python build.py wifiiot`



## 参考链接

本项目是基于afiskon的stm32-ssd1306移植的，对部分细节做了修改和优化，原项目链接：

* https://github.com/afiskon/stm32-ssd1306
