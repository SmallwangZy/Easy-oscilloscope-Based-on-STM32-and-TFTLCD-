# 基于STM32与TFTLCD的示波器设计

## 介绍

使用STM32F103与正点原子4.3寸TFTLCD屏幕制作的简易示波器，基于HAL库与Cubemx编写。

## 软件架构

该工程各个目录的含义如下：

- `Inc`文件夹是用于存放头文件的目录；
- `Src`文件夹是用于存放源文件的目录；
- `MDK-ARM`是用于存放==编译和调试结果==以及==项目文件==的目录。
- `WuLiShiYan.ioc`文件是用于配置Cubemx的文件。

### 头文件

在`Inc`头文件目录中：

1. 以下文件是由Cubemx生成的片内外设配置文件：

   `adc.h  gpio.h  fsmc.h  main.h  tim.h  usart.h  `

2. 以下文件是由用户配置的外设模块的头文件：

   `lcd.h  font.h`

3. 以下文件是HAL库的必要文件：

   `stm32f1xx_hal_conf.h  stm32f1xx_it.h`

以下文件

## 开发环境

本项目采用Keil MDK5开发环境编写，需要使用MDK5打开工程文件。

#### 使用说明

1.  xxxx
2.  xxxx
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
