#include "mainwindow.h"
#include "ui_mainwindow.h"

double result = 0.0;
double Mem = 0.0;
bool division = false;
bool mul = false;
bool add = false;
bool sub = false;
bool operatorFlag = false;
double solution = 0.0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(result));
    QPushButton *numButtons[10];
    for (int i = 0 ; i<10 ; ++i)
    {
        QString buttName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(buttName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Add, SIGNAL(released()), this, SLOT(OperatorPressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(OperatorPressed()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(OperatorPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(OperatorPressed()));

    connect(ui->Calculate, SIGNAL(released()), this, SLOT(CalculatePressed()));
    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeSignPressed()));
    connect(ui->Clear, SIGNAL(released()), this, SLOT(ClearPressed()));

    connect(ui->MemAdd, SIGNAL(released()), this, SLOT(MemoryAdd()));
    connect(ui->MemGet, SIGNAL(released()), this, SLOT(MemoryRet()));
    connect(ui->MemDel, SIGNAL(released()), this, SLOT(MemoryDel()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed()
{
    if(operatorFlag)
    {
        ui->lineEdit->clear();
    }
    QPushButton *Button = (QPushButton *)sender();
    QString buttonValue = Button->text();
    QString displayValue = ui->lineEdit->text();
    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0))
    {
        ui->lineEdit->setText(buttonValue);
    }
    else
    {
        QString newvalue = displayValue + buttonValue;
        double dblNewValue = newvalue.toDouble();
        ui->lineEdit->setText(QString::number(dblNewValue));


    }


}

void MainWindow::OperatorPressed()
{
    QString displayValue = ui->lineEdit->text();
    result = displayValue.toDouble();

    division = false;
    mul = false;
    add = false;
    sub = false;
    operatorFlag = true;
    QPushButton * button = (QPushButton *)sender();
    QString buttValue = button->text();
    if(QString::compare(buttValue, "/", Qt::CaseInsensitive)==0)
    {
        division = true;
    }
    else if(QString::compare(buttValue, "*", Qt::CaseInsensitive)==0)
    {
        mul = true;
    }
    else if(QString::compare(buttValue, "+", Qt::CaseInsensitive)==0)
    {
        add = true;
    }
    else
    {
        sub = true;
    }

    ui->lineEdit->setText(buttValue);
}

void MainWindow::CalculatePressed()
{

    QString displayValue = ui->lineEdit->text();
    double dblDisplayValue = displayValue.toDouble();
    if((add || sub || division || mul))
    {
        if(add)
        {
            solution = result + dblDisplayValue ;
        }

        else if(sub)
        {
            solution = result - dblDisplayValue ;
        }

        else if(division)
        {
            solution = result / dblDisplayValue ;
        }

        else
        {
            solution = result * dblDisplayValue;
        }

        ui->lineEdit->setText(QString::number(solution));

    }
    operatorFlag = false;
}

void MainWindow::ChangeSignPressed()
{
    QString displayValue = ui->lineEdit->text();
    QRegExp reg("[-]?[0-9.]*");
    if (reg.exactMatch(displayValue))
    {
        double dbldisplayvalue = displayValue.toDouble();
        dbldisplayvalue = -1 * dbldisplayvalue;
        ui->lineEdit->setText(QString::number(dbldisplayvalue));

    }
}

void MainWindow::ClearPressed()
{
    result = 0.0;
    ui->lineEdit->setText("0");
    division = false;
    mul = false;
    add = false;
    sub = false;
}

void MainWindow::MemoryAdd()
{
    QString displayValue = ui->lineEdit->text();
    double dblDisplayValue = displayValue.toDouble();
    Mem = dblDisplayValue;
}

void MainWindow::MemoryRet()
{
    ui->lineEdit->setText(QString::number(Mem));
}

void MainWindow::MemoryDel()
{
    Mem = 0.0;
}
