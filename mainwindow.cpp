#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Calc.h"


//#include "regex"

//regex corr("([0-9]|(|*|/|+|-| )");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //prev_check = 0;
    ui->radioButton_rad->click();
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
    DataOne.clear();

    Show();
}

void MainWindow::on_pushButton_back_clicked()
{
    if (!DataOne.empty())
    {
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_C:
        {
            if(event->modifiers() & Qt::CTRL)
            {
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(DataOne.c_str());
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
