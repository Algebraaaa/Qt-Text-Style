#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);  //注意：setUi(this)会以以ui文件的方式重新初始化整个界面，包括窗口标题。
    iniUI();
    iniSigalSlots();
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::iniUI()
{
    //创建Uderline,Italic,Bold三个复选框，并水平布局
    chkBoxUnder=new QCheckBox("Underline",this);
    chkBoxItalic=new QCheckBox("Italic",this);
    chkBoxBold=new QCheckBox("Bold",this);
    QHBoxLayout *HLay1=new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxBold);
    HLay1->addWidget(chkBoxItalic);

    //创建Black,Red,Blue三个单选框，并水平布局
    radioBlack=new QRadioButton("Black",this);
    radioBlue=new QRadioButton("Blue",this);
    radioRed=new QRadioButton("Red",this);
    QHBoxLayout *HLay2=new QHBoxLayout;
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioBlue);
    HLay2->addWidget(radioRed);

    //创建“确定”，“取消”，“退出”三个按钮，并水平布局
    btnOK=new QPushButton("确定",this);
    btnCancel=new QPushButton("取消",this);
    btnClose=new QPushButton("退出",this);
    QHBoxLayout *HLay3=new QHBoxLayout();
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    //创建文本框，并设置初始字体
    txtEdit=new QPlainTextEdit(this);
    txtEdit->setPlainText("Hello world\n手工创建");
    QFont font=txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay=new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void Dialog::iniSigalSlots()
{
    //3个设置颜色的单选按钮
    connect(radioBlue,&QRadioButton::clicked,this,&Dialog::do_setFrontColor);
    connect(radioBlack,SIGNAL(clicked()),this,SLOT(do_setFrontColor()));
    connect(radioRed,SIGNAL(clicked()),this,SLOT(do_setFrontColor()));
    //3个设置字体的复选框
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxBold(bool)));
    //3个按钮与窗口的槽函数关联
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
}

void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFrontColor()
{
    QPalette plet=txtEdit->palette();
    if(radioBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(radioBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(radioRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    txtEdit->setPalette(plet);
}

