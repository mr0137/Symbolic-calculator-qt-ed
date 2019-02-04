#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Calc.h"
#include "QClipboard"

string Temp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_rad->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show()
{
    ui->label->setText((const QString)DataOne.c_str());
}

void MainWindow::on_pushButton_AC_clicked()
{
    Temp = DataOne;
    DataOne.clear();
    Show();
}

void MainWindow::on_pushButton_back_clicked()
{
    if (!DataOne.empty())
    {
        DataOne.erase(DataOne.length()-1, 1);
    }
    else
    {
        DataOne = Temp;
    }
    Show();
}

void MainWindow::on_pushButton_bkt1_clicked()
{
    DataOne += "(";
    Show();
}

void MainWindow::on_pushButton_bkt2_clicked()
{
    DataOne += ")";
    Show();
}

void MainWindow::on_pushButton_division_clicked()
{
    DataOne += "/";
    Show();
}

void MainWindow::on_radioButton_rad_clicked()
{
    Deg = false;
}

void MainWindow::on_radioButton_deg_clicked(bool checked)
{
    Deg = checked;
}

void MainWindow::on_pushButton_sin_clicked()
{
    DataOne += "sin(";
    Show();
}

void MainWindow::on_pushButton_7_clicked()
{
    DataOne += "7";
    Show();
}

void MainWindow::on_pushButton_8_clicked()
{
    DataOne += "8";
    Show();
}

void MainWindow::on_pushButton_9_clicked()
{
    DataOne += "9";
    Show();
}

void MainWindow::on_pushButton_multiply_clicked()
{
    DataOne += "*";
    Show();
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    DataOne += "sqrt(";
    Show();
}


void MainWindow::on_pushButton_cos_clicked()
{
    DataOne += "cos(";
    Show();
}

void MainWindow::on_pushButton_4_clicked()
{
    DataOne += "4";
    Show();
}

void MainWindow::on_pushButton_5_clicked()
{
    DataOne += "5";
    Show();
}

void MainWindow::on_pushButton_6_clicked()
{
    DataOne += "6";
    Show();
}

void MainWindow::on_pushButton_minus_clicked()
{
    DataOne += "-";
    Show();
}

void MainWindow::on_pushButton_deg_clicked()
{
    DataOne += "^";
    Show();
}

void MainWindow::on_pushButton_tg_clicked()
{
    DataOne += "tg(";
    Show();
}

void MainWindow::on_pushButton_1_clicked()
{
    DataOne += "1";
    Show();
}

void MainWindow::on_pushButton_2_clicked()
{
    DataOne += "2";
    Show();
}

void MainWindow::on_pushButton_3_clicked()
{
    DataOne += "3";
    Show();
}

void MainWindow::on_pushButton_plus_clicked()
{
    DataOne += "+";
    Show();
}

void MainWindow::on_pushButton_log_clicked()
{
    DataOne += "log";
    Show();
}

void MainWindow::on_pushButton_ctg_clicked()
{
    DataOne += "ctg(";
    Show();
}

void MainWindow::on_pushButton_0_clicked()
{
    DataOne += "0";
    Show();
}

void MainWindow::on_pushButton_dot_clicked()
{
     DataOne += ".";
     Show();
}

void MainWindow::on_pushButton_equal_clicked()
{
    Temp = DataOne;
    DataOne = call(DataOne,Deg);
    DataOne.erase(DataOne.length() - 1, 1);
    Show();
}

void MainWindow::on_pushButton_buffer_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();

    QString text = clipboard->text(QClipboard::Clipboard);

    DataOne = text.toUtf8().constData();
    Show();
}
