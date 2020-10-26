# harmonyos-ssd1306



支持HarmonyOS IoT硬件接口的SSD1306 OLED屏驱动库;

* 内置了128*64 bit的内存缓冲区，支持全屏刷新;
* 优化了屏幕刷新速率，实测最大帧率10fps;
* `libm_port`是从musl libc中抽取的`sin`和`cos`的实现;
* `gif2imgs.py` 可用于将gif动图中的帧分离出来;
* `img2code.py` 可用于将图片转为C数组，每个字节表示8个像素；


## 如何编译

1. 在openharmony源码目录下克隆本项目：`git clone https://gitee.com/hihopeorg/harmonyos-ssd1306`

2. 修改openharmony源码的`build/lite/product/wifiiot.json`文件：

   将`//applications/sample/wifi-iot/app`替换为`//harmonyos-ssd1306:app`保存；

3. 在openharmony源码目录下执行：`python build.py wifiiot`


## 编译错误解决

本项目代码使用了鸿蒙IoT硬件子系统的I2C API接口，需要连接到hi3861的I2C相关接口；默认情况下，Hi3861的I2C编译配置没有打开，编译时会有如下错误：

```txt
riscv32-unknown-elf-ld: ohos/libs/libhal_iothardware.a(hal_wifiiot_i2c.o): in function `.L0 ':
hal_wifiiot_i2c.c:(.text.HalI2cWrite+0x12): undefined reference to `hi_i2c_write'
riscv32-unknown-elf-ld: hal_wifiiot_i2c.c:(.text.HalI2cInit+0x12): undefined reference to `hi_i2c_init'
scons: *** [output/bin/Hi3861_wifiiot_app.out] Error 1
BUILD FAILED!!!!
```

**解决方法**

需要修改vendor\hisi\hi3861\hi3861\build\config\usr_config.mk文件：
`# CONFIG_I2C_SUPPORT is not set`行，修改为：`CONFIG_I2C_SUPPORT=y`

## 参考链接

本项目是基于afiskon的stm32-ssd1306移植的，对部分细节做了修改和优化，原项目链接：

* https://github.com/afiskon/stm32-ssd1306
