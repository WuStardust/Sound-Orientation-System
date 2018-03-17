# Sound-Orientation-System
Code for Embedded System Design Course. Written by XC Group, Seedclass 2015. Code is here: [sound-Orientation-System](https://github.com/WuStardust/Sound-Orientation-System.git)


# 嵌入式课设重启安排


## 1. 目标与计划
* 从下周（2018.3.19之后）起重启嵌入式课设，制定计划，逐步完成工程目标。
1. 下周三(2018.3.21)**前**搞定环境。最好能研究一下代码。

2. 当晚我们抽空讨论一下。无论如何都要抽时间。十分钟对进度也好，花一晚上搞定后面的排期也好，具体按当晚项目组的情况决定。


## 2. 综述
1. 寒假前焊好了**两块**板子，工作均基本正常：
    * 有一块板子指示方向的LED似乎坏了一个，但不影响使用。
    * 两块板子的**晶振**有考虑做更换，对后面的**计时**和**计算方位**会有影响。

2. 寒假期间做了前期的代码开发。所有代码均在github上，地址：[声音定向-Github](https://github.com/WuStardust/Sound-Orientation-System.git)。需要Push权限请及时和我联系。建议使用**Source tree**，和在项目组一样，做好**分支管理**。

3. 代码使用了Microchip提供的XC32编译器和配套宏定义lib。

4. 目前分别尝试了两种外设：**比较器**和**ADC**，来确定声音到达麦克风的时间，两个方向都还没有走完。

5. 具体安装和使用介绍见[下节](#environment)。


## <span id="environment">3. 环境搭建</sapn>
1. 首先，需要在电脑上安装XC32编译器(我用的是v2.05)，可以从Microchip官网获得并安装，也可以找我要安装包。

2. 其次，在电脑上安装配套的宏定义lib(**PIC32 Legacy Peripheral Libraries**)，同样可以在官网处获得，或者直接向我要。这个库装上之后，可以在程序安装目录下找到数据手册，在我就是F:\Microchip\xc32\v2.05\docs\pic32-lib-help\

* P.S: 我当时用MPLAB v3.xx（就是上微机原理时的版本），貌似搞着搞着就崩掉了，所以我现在用的是v4.10。这个版本目前用起来还没有遇到问题，安装包依旧我有。

3. 上述两个东西装上后就应该可以编译通过git上任一分支上的代码了，如果不行，赶紧一起研究一下。

4. PIC32的**数据手册**我这边基本都齐了，如果没有找到中文版的也可以找我要。


## 4. 代码进度
1. 代码里所有寄存器操作都**不再**是使用直接写寄存器的方式，而是使用lib中封装好的宏定义方法配置各类外设。这个方法上手有点慢，但是后面用起来很方便。

2. 仓库内有很多分支，主要还是两个方向：操控比较器和操控ADC。Commit comments写的还算易懂，可以做参考。

3. 分支develop/20180214-dev是由我来维护的，实现的功能是：简单根据声音第一次到达的麦克风位置，来决定是三个灯中的哪一个亮。在其后的feature/201802-moreLEDBySeq是希望根据声音触发麦克风的顺序（共六种排列）来决定六个灯中的哪一个亮，这个分支的功能目前神神叨叨的，还没开发完。可能和没有用上定时器有关。

4. 分支/feature/adc_design是由郭维护的，大意是和ADC有关的一些设计。具体功能实现我不清楚。


## tips
* 代码编码格式为UTF-8
* 仿真时，晶振的振荡频率是22.1184MHz
* 我不熟悉MPLAB的工程要上传哪些文件到git，可能有必要重新设置工程才能正常编译orz
* 设置工程时注意给PIC32的供电状态
