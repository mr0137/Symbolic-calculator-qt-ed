#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Calc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_rad->click();
    ui->tableWidget->setColumnWidth(0, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_for_correct_input()
{
    string mass = {' ','+','-','/','*','('};
    int i;

    for (i = 0; i < mass.length(); i++)
    {
        if (DataOne[DataOne.length() - 1] == mass[i])
        {
            return true;
        }
        else if (DataOne[DataOne.length() - 1] == NULL)//если ввод с начала строки
        {
            return true;
        }
    }

    return false;
}

void MainWindow::Show()
{
    ui->label->setText((const QString)DataOne.c_str());

    ui->label->moveCursor(QTextCursor::End); /* для прокрутки вниз  */
}

void MainWindow::on_pushButton_AC_clicked()
{
    if (!DataOne.empty())
    {
       Temp = DataOne;
    }


    DataOne.clear();

    Show();
}

void MainWindow::on_pushButton_back_clicked()
{
    if (!DataOne.empty())
    {
        Temp = DataOne;
        DataOne.erase(DataOne.length()-1, 1);
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
    Calculator Calc(DataOne,Deg);
    DataOne = Calc.Get_Result();

    if (!Calc.isError())
    {
        DataOne.erase(DataOne.length() - 1, 1);
        history_add();
    }
    else
    {
        QMessageBox::information(this, "Error", DataOne.c_str());
        DataOne = Temp;
        Temp.clear();
    }
    Show();
}

void MainWindow::on_pushButton_buffer_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();

    QString text = clipboard->text(QClipboard::Clipboard);

    DataOne += text.toUtf8().constData();
    Show();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Z:
        {
            if(event->modifiers() & Qt::CTRL)
            {
                swap(Temp,DataOne);
            }
            break;
        }
        case Qt::Key_C:
        {
            if(event->modifiers() & Qt::CTRL)
            {
                if (!DataOne.empty())
                {
                    QClipboard *clipboard = QApplication::clipboard();
                    clipboard->setText(DataOne.c_str());
                }
            }
            else
            {
                if (check_for_correct_input())
                {
                    DataOne += "c";
                }
            }
            break;
        }

        case Qt::Key_V:
        {
            if(event->modifiers() & Qt::CTRL)
            {
                on_pushButton_buffer_clicked();
            }
            break;
        }

        case Qt::Key_S:
        {
            if (check_for_correct_input() ||
                    ( DataOne[DataOne.length() - 1] == 'o' && DataOne[DataOne.length() - 2] == 'c'))
            {
                DataOne += "s";
            }
            break;
        }

        case Qt::Key_ParenLeft:
        {
            DataOne += "(";
            break;
        }

        case Qt::Key_ParenRight:
        {
            DataOne += ")";
            break;
        }

        case Qt::Key_AsciiCircum:
        {
             DataOne += "^";
             break;
        }

        case Qt::Key_Plus:
        {
             DataOne += "+";
             break;
        }

        case Qt::Key_Minus:
        {
            DataOne += "-";
            break;
        }

        case Qt::Key_O:
        {
            if (DataOne[DataOne.length() - 1] == 'c' || DataOne[DataOne.length() - 1] == 'l')
            {
                DataOne += "o";
            }
            break;
        }

        case Qt::Key_Backspace:
        {
            on_pushButton_back_clicked();
            break;
        }

        case Qt::Key_Equal:
        {
            on_pushButton_equal_clicked();
            break;
        }

        case Qt::Key_Q:
        {
            if(DataOne[DataOne.length()-1] == 's')
            {
                DataOne += "q";
            }
            break;
        }

        case Qt::Key_R:
        {
            if (DataOne[DataOne.length()-1] == 'q')
            {
                DataOne +="r";
            }
            break;
        }

        case Qt::Key_T:
        {
            if (check_for_correct_input()
                        || DataOne[DataOne.length()-1] == 'c'
                        || DataOne[DataOne.length()-1] == 'r')
            {
                DataOne +="t";
            }

            break;
        }

        case Qt::Key_G:
        {
            if (DataOne[DataOne.length()-1] == 't')
            {
                DataOne +="g";
            }
            else if (DataOne[DataOne.length()-1] == 'o')
            {
                DataOne +="g";
            }
            break;
        }

        case Qt::Key_I:
        {
            if (DataOne[DataOne.length()-1] == 's')
            {
                DataOne +="i";
            }
            else if (DataOne[DataOne.length()-1] == 'p')
            {
                DataOne +="i";
            }
            break;
        }

        case Qt::Key_P:
        {
            if (check_for_correct_input())
            {
                DataOne += "p";
            }

            break;
        }

        case Qt::Key_E:
        {
            if (check_for_correct_input())
            {
                DataOne += "e";
            }

            break;
        }

        case Qt::Key_N:
        {
            if (DataOne[DataOne.length()-1] == 'i' && DataOne[DataOne.length() - 2] == 's')
            {
                DataOne += "n";
            }
            break;
        }

        case Qt::Key_L:
        {
            if (check_for_correct_input())
            {
                DataOne += "l";
            }

            break;
        }

        case Qt::Key_0:
        {
            DataOne += "0";
            break;
        }

        case Qt::Key_1:
        {
            DataOne += "1";
            break;
       }

        case Qt::Key_2:
        {
            DataOne += "2";
            break;
        }

        case Qt::Key_3:
        {
            DataOne += "3";
            break;
        }

        case Qt::Key_4:
        {
            DataOne += "4";
            break;
        }

        case Qt::Key_5:
        {
            DataOne += "5";
            break;
        }

        case Qt::Key_6:
        {
            DataOne += "6";
            break;
        }

        case Qt::Key_7:
        {
            DataOne += "7";
            break;
        }

        case Qt::Key_8:
        {
            DataOne += "8";
            break;
        }
        case Qt::Key_9:
        {
            DataOne += "9";
            break;
        }

        case Qt::Key_Delete:
        {
            on_pushButton_AC_clicked();
            break;
        }

        case Qt::Key_Space:
        {
            DataOne += " ";
            break;
        }
        case Qt::Key_Slash:
        {
            DataOne += "/";
            break;
        }

        case Qt::Key_Escape:
        {
            exit(0);
        }

        case Qt::Key_Asterisk:
        {
            DataOne += "*";
            break;
        }

        case Qt::Key_Period:
        {
            DataOne += ".";
            break;
        }

        case 16777220:
        {
            on_pushButton_equal_clicked();
            break;
        }

        default:
            QWidget::keyPressEvent(event);
            break;
     }
    Show();

}

void MainWindow::on_pushButton_pi_clicked()
{
    char a = DataOne[DataOne.length() - 1];
    if (a == '*' || a == '/' || a == '-' || a == '+' || a == NULL || a == '(' || a == 'g')
    {
        DataOne += "pi";
        Show();
    }
}

void MainWindow::on_pushButton_e_clicked()
{
    char a = DataOne[DataOne.length() - 1];
    if (a == '*' || a == '/' || a == '-' || a == '+' || a == NULL || a == '(' || a == 'g')
    {
        DataOne += "e";
        Show();
    }
}

void MainWindow::history_add()
{
    int j = ui->tableWidget->rowCount();
    j++;

    ui->tableWidget->setRowCount(j);//установка нужного количества строк
    j -= 2;
    for (j; j >= 0;  j--)//перемещаем новый элемент на первую позицию
    {
        ui->tableWidget->setItem(j+1, 0, ui->tableWidget->takeItem(j,0));
        ui->tableWidget->setItem(j+1, 1, ui->tableWidget->takeItem(j,1));

    }

    QTableWidgetItem *table1 = new QTableWidgetItem((QString)Temp.c_str());
    QTableWidgetItem *table2 = new QTableWidgetItem((QString)DataOne.c_str());

    ui->tableWidget->setItem(0, 0, table1);
    ui->tableWidget->setItem(0, 1, table2);

}

void MainWindow::on_pushButton_h_clear_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Exercise" << "Result" );
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *table = ui->tableWidget->item(row, column);
    string A = table->text().toUtf8().constData();
    DataOne += A;
    Show();
}
