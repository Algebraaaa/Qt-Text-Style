# Qt-Text-Style
  一个简单的 Qt 桌面应用程序，演示了信号与槽机制的基本使用<br><br>
  可实现的功能如下 
- 字体设置：Underline（下划线）、Italic（斜体）、Bold（粗体）
- 颜色选择：Black（黑色）、Red（红色）、Blue（蓝色）
- 文本显示：可自定义文本，勾选相应的字体颜色可改变其格式
- 按钮操作：包含退出、确定、清空
<img width="534" height="460" alt="image" src="https://github.com/user-attachments/assets/5318ed14-4fa6-4546-9e50-ad9d7cb1d455" />
<br>环境为：Qt6.5.3 MinGW 64-bit<br>
文件列表：<br>
该项目为纯代码实现，无需ui文件<br>
dialog.h 声明了所需要的控件及构造函数，信号槽函数，ui初始化函数<br>
dialog.cpp 对类中声明的函数进行实现<br>
main.cpp 程序入口<br>
