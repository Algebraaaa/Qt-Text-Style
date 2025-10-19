# Qt-Text-Style
这是一个使用 **C++ + Qt Widgets** 编写的小项目，演示了如何在不依赖 Qt Designer 的情况下 **手工创建界面元素（UI）**，并使用 **信号与槽机制** 实现控件间交互。
## 🧱 项目简介
本项目是基于《Qt6 C++开发指南》中的示例练习而完成的 Qt 小项目，主要用于学习和交流，更多内容推荐购买原书  
原书作者：王维波  
出版信息：人民邮电出版社
> ⚠️ 本项目仅用于学习参考，非商业用途。

本项目实现了一个简单的文本编辑对话框，支持：

* 使用复选框控制字体样式（**加粗、斜体、下划线**）；
* 使用单选按钮改变文字颜色（**黑色、蓝色、红色**）；
* 提供“确定”、“取消”、“退出”按钮；
* 所有控件均 **通过代码动态创建与布局**，未使用 `.ui` 文件。

主要用于学习：

* Qt 手工界面布局（QHBoxLayout、QVBoxLayout）；
* 信号与槽的连接方式（新旧语法对比）；
* QFont 和 QPalette 的应用；
* QDialog 的基本使用。

## 📂 文件结构

```
├── dialog.h          // 对话框类头文件
├── dialog.cpp        // 对话框类实现文件
└── main.cpp          // 程序入口（需自行添加）
```

## 🖥️ 运行效果
运行程序后，会看到一个窗口，包含：
<br><img width="534" height="460" alt="image" src="https://github.com/user-attachments/assets/5318ed14-4fa6-4546-9e50-ad9d7cb1d455" /><br>
* 三个复选框：**Underline**, **Italic**, **Bold**
* 三个单选框：**Black**, **Blue**, **Red**
* 一个可编辑文本框（初始内容为 “Hello world\n手工创建”）
* 三个按钮：“确定”、“取消”、“退出”

操作复选框和单选框即可实时改变文本样式。

## 🧩 核心功能讲解

### 1️⃣ 动态创建控件与布局

在 `Dialog::iniUI()` 中通过 `new QCheckBox`、`new QRadioButton`、`QHBoxLayout`、`QVBoxLayout` 构建完整界面。

### 2️⃣ 信号与槽机制

在 `Dialog::iniSigalSlots()` 中展示了：

* 新语法：`connect(radioBlue, &QRadioButton::clicked, this, &Dialog::do_setFrontColor);`
* 旧语法：`connect(radioBlack, SIGNAL(clicked()), this, SLOT(do_setFrontColor()));`

### 3️⃣ 字体样式与颜色控制

复选框槽函数使用 `QFont` 修改字体样式；
单选按钮槽函数使用 `QPalette` 修改字体颜色。

## ⚙️ 构建与运行

### 环境要求

* Qt 5 或 Qt 6
* C++98 及以上
* qmake 构建系统
* 支持 Qt 的 IDE（**Qt Creator** 或 **Visual Studio + Qt 插件**）
