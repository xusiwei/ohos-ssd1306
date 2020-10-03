# harmonyos-ssd1306



支持HarmonyOS IoT硬件接口的SSD1306 OLED屏驱动库;

* 原始代码内置了一个128*64 bit的内存显示缓冲区，支持一次性全屏刷新;

* 本项目在此基础上优化了屏幕刷新速率，目前测试最大帧率可达到10fps;
* libm_port是从musl libc中抽取的部分数学函数，规避编译不通过的问题;



## 原始README.md内容

STM32 library for working with OLEDs based on SSD1306, SH1106, SH1107 and SSD1309,
supports I2C and 4-wire SPI.

Tested on STM32F0, STM32F1, STM32F3, STM32F4, STM32L0, STM32L4, STM32F7 and STM32H7 MCUs, with 10 random displays from eBay.
Also this code is known to work with
[afiskon/fpga-ssd1306-to-vga](https://github.com/afiskon/fpga-ssd1306-to-vga).

Please see `examples` directory and `ssd1306/ssd1306.h` for more details.

The code is based on
[4ilo/ssd1306-stm32HAL](https://github.com/4ilo/ssd1306-stm32HAL) library
developed by Olivier Van den Eede ( [@4ilo](https://github.com/4ilo) ) in 2016.

See also:

* https://github.com/afiskon/stm32-ssd1351
* https://github.com/afiskon/stm32-st7735
* https://github.com/afiskon/stm32-ili9341

There is a [DuyTrandeLion/nrf52-ssd1309](https://github.com/DuyTrandeLion/nrf52-ssd1309) port to nRF52 of this library made by [@DuyTrandeLion](https://github.com/DuyTrandeLion) in 2020.
