#include "notepad.h"
#include "ui_notepad.h"

NotePad::NotePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->TextEdit);
    QIcon icon(":/images/D:/Learning Engineering/qt Tutorials/Icons/Turtle.png");
    setWindowIcon(icon);
    setWindowTitle(QString("Turtle Pad"));
}

NotePad::~NotePad()
{
    delete ui;
}

void NotePad::on_actionNew_triggered()
{
    currentFileName.clear();
    ui->TextEdit->setText("");
    setWindowTitle("New file");

}

void NotePad::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFileName = filename;

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"warning", "Can't open file : " + file.errorString());
        return;
    }

    setWindowTitle(QString("Turtle Pad" + filename));
    QTextStream in(&file);
    QString text = in.readAll();
    ui->TextEdit->setText(text);
    file.close();
}

void NotePad::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "save as");
    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"warning", "Can't save file : " + file.errorString());
        return;
    }

    currentFileName = filename;
    setWindowTitle(currentFileName);
    QTextStream out(&file);
    QString text = ui->TextEdit->toPlainText();
    out << text;
    file.close();


}

void NotePad::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "warning", "can't access printer");
        return;
    }

    ui->TextEdit->print(&printer);
}

void NotePad::on_actionExit_triggered()
{
    QApplication::quit();
}

void NotePad::on_actionCopy_triggered()
{
    ui->TextEdit->copy();
}

void NotePad::on_actionPaste_triggered()
{
    ui->TextEdit->paste();
}

void NotePad::on_actionCut_triggered()
{
    ui->TextEdit->cut();
}

void NotePad::on_actionUndo_triggered()
{
    ui->TextEdit->undo();
}


void NotePad::on_actionRedo_triggered()
{
    ui->TextEdit->redo();
}
