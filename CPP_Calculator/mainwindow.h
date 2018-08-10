#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void NumPressed();
    void OperatorPressed();
    void CalculatePressed();
    void ChangeSignPressed();
    void ClearPressed();
    void MemoryRet();
    void MemoryDel();
    void MemoryAdd();

};

#endif // MAINWINDOW_H
