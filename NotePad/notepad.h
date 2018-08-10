#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class NotePad;
}

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotePad(QWidget *parent = 0);
    ~NotePad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::NotePad *ui;
    QString currentFileName= "";
};

#endif // NOTEPAD_H
