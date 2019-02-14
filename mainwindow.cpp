#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Calc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    prev_check = 0;
    ui->radioButton_rad->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::ChangeXpos(int count)
{
   // MainWindow::setGeometry(MainWindow::x(), MainWindow::y()-count, MainWindow::width(), MainWindow::height()+count);

    if (count >= 0)
    {
        MainWindow::setGeometry(x() + 8,y() + 12, width(), height() + count);
    }
    else
    {
        MainWindow::setGeometry(x() + 8,y() + 50, width(), height() + count);
    }


    ui->pushButton_0->setGeometry(ui->pushButton_0->x(),
                                  ui->pushButton_0->y() + count, ui->pushButton_0->width(), ui->pushButton_0->height());

    ui->pushButton_1->setGeometry(ui->pushButton_1->x(),
                                  ui->pushButton_1->y() + count, ui->pushButton_1->width(), ui->pushButton_1->height());

    ui->pushButton_2->setGeometry(ui->pushButton_2->x(),
                                      ui->pushButton_2->y() + count, ui->pushButton_2->width(), ui->pushButton_2->height());

    ui->pushButton_3->setGeometry(ui->pushButton_3->x(),
                                      ui->pushButton_3->y() + count, ui->pushButton_3->width(), ui->pushButton_3->height());

    ui->pushButton_4->setGeometry(ui->pushButton_4->x(),
                                      ui->pushButton_4->y() + count, ui->pushButton_4->width(), ui->pushButton_4->height());

    ui->pushButton_5->setGeometry(ui->pushButton_5->x(),
                                      ui->pushButton_5->y() + count, ui->pushButton_5->width(), ui->pushButton_5->height());

    ui->pushButton_6->setGeometry(ui->pushButton_6->x(),
                                      ui->pushButton_6->y() + count, ui->pushButton_6->width(), ui->pushButton_6->height());

    ui->pushButton_7->setGeometry(ui->pushButton_7->x(),
                                      ui->pushButton_7->y() + count, ui->pushButton_7->width(), ui->pushButton_7->height());

    ui->pushButton_8->setGeometry(ui->pushButton_8->x(),
                                      ui->pushButton_8->y() + count, ui->pushButton_8->width(), ui->pushButton_8->height());

    ui->pushButton_9->setGeometry(ui->pushButton_9->x(),
                                      ui->pushButton_9->y() + count, ui->pushButton_9->width(), ui->pushButton_9->height());

    ui->pushButton_AC->setGeometry(ui->pushButton_AC->x(),
                                      ui->pushButton_AC->y() + count, ui->pushButton_AC->width(), ui->pushButton_AC->height());

    ui->pushButton_tg->setGeometry(ui->pushButton_tg->x(),
                                      ui->pushButton_tg->y() + count, ui->pushButton_tg->width(), ui->pushButton_tg->height());

    ui->pushButton_cos->setGeometry(ui->pushButton_cos->x(),
                                      ui->pushButton_cos->y() + count, ui->pushButton_cos->width(), ui->pushButton_cos->height());

    ui->pushButton_ctg->setGeometry(ui->pushButton_ctg->x(),
                                      ui->pushButton_ctg->y() + count, ui->pushButton_ctg->width(), ui->pushButton_ctg->height());

    ui->pushButton_deg->setGeometry(ui->pushButton_deg->x(),
                                      ui->pushButton_deg->y() + count, ui->pushButton_deg->width(), ui->pushButton_deg->height());

    ui->pushButton_dot->setGeometry(ui->pushButton_dot->x(),
                                      ui->pushButton_dot->y() + count, ui->pushButton_dot->width(), ui->pushButton_dot->height());

    ui->pushButton_log->setGeometry(ui->pushButton_log->x(),
                                      ui->pushButton_log->y() + count, ui->pushButton_log->width(), ui->pushButton_log->height());

    ui->pushButton_sin->setGeometry(ui->pushButton_sin->x(),
                                      ui->pushButton_sin->y() + count, ui->pushButton_sin->width(), ui->pushButton_sin->height());

    ui->pushButton_back->setGeometry(ui->pushButton_back->x(),
                                      ui->pushButton_back->y() + count, ui->pushButton_back->width(), ui->pushButton_back->height());

    ui->pushButton_bkt1->setGeometry(ui->pushButton_bkt1->x(),
                                      ui->pushButton_bkt1->y() + count, ui->pushButton_bkt1->width(), ui->pushButton_bkt1->height());

    ui->pushButton_bkt2->setGeometry(ui->pushButton_bkt2->x(),
                                      ui->pushButton_bkt2->y() + count, ui->pushButton_bkt2->width(), ui->pushButton_bkt2->height());

    ui->pushButton_plus->setGeometry(ui->pushButton_plus->x(),
                                      ui->pushButton_plus->y() + count, ui->pushButton_plus->width(), ui->pushButton_plus->height());

    ui->pushButton_sqrt->setGeometry(ui->pushButton_sqrt->x(),
                                      ui->pushButton_sqrt->y() + count, ui->pushButton_sqrt->width(), ui->pushButton_sqrt->height());

    ui->pushButton_equal->setGeometry(ui->pushButton_equal->x(),
                                      ui->pushButton_equal->y() + count, ui->pushButton_equal->width(), ui->pushButton_equal->height());

    ui->pushButton_minus->setGeometry(ui->pushButton_minus->x(),
                                      ui->pushButton_minus->y() + count, ui->pushButton_minus->width(), ui->pushButton_minus->height());

    ui->pushButton_buffer->setGeometry(ui->pushButton_buffer->x(),
                                      ui->pushButton_buffer->y() + count, ui->pushButton_buffer->width(), ui->pushButton_buffer->height());

    ui->pushButton_division->setGeometry(ui->pushButton_division->x(),
                                      ui->pushButton_division->y() + count, ui->pushButton_division->width(), ui->pushButton_division->height());

    ui->pushButton_multiply->setGeometry(ui->pushButton_multiply->x(),
                                      ui->pushButton_multiply->y() + count, ui->pushButton_multiply->width(), ui->pushButton_multiply->height());

    ui->radioButton_deg->setGeometry(ui->radioButton_deg->x(),
                                      ui->radioButton_deg->y() + count, ui->radioButton_deg->width(), ui->radioButton_deg->height());

    ui->radioButton_rad->setGeometry(ui->radioButton_rad->x(),
                                      ui->radioButton_rad->y() + count, ui->radioButton_rad->width(), ui->radioButton_rad->height());

}

/*void MainWindow::ChangedResolution()
{
    int check = ui->label->fontMetrics().width(DataOne.c_str()) / (ui->label->width() - 4);

    int h = ui->label->fontMetrics().height();

    if (check > 0 && prev_check < check)
    {
        ui->label->setGeometry(ui->label->x(),ui->label->y(), ui->label->width(), label_size_h +
                               h * check);

        if (prev_check == 0)
        {
            ChangeXpos(h*check);
        }
        else
        {
            ChangeXpos(h);
        }
    }
    else if (check < prev_check && !DataOne.empty())
    {
       ui->label->setGeometry(ui->label->x(),ui->label->y(), ui->label->width(), label_size_h +
                               h * check);
       ChangeXpos(-h);
    }
    else if (check == 0 && DataOne.empty() && check < prev_check)
    {
        ui->label->setGeometry(ui->label->x(),ui->label->y(), ui->label->width(), label_size_h +
                                h * check);
        for (int i = 0; i < prev_check; i++)
        {
            ChangeXpos(-h);
        }
    }
    prev_check = check;
}
*/

void MainWindow::Show()
{
    ui->label->setText((const QString)DataOne.c_str());

    ui->label->moveCursor(QTextCursor::End);
}

void MainWindow::on_pushButton_AC_clicked()
{
    DataOne.clear();
    //ChangedResolution();

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
                DataOne += "c";
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
               DataOne += "s";
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
            DataOne += "o";
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
                DataOne +="t";
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
            DataOne += "p";
            break;
        }

        case Qt::Key_E:
        {
            DataOne += "e";
            break;
        }

        case Qt::Key_N:
        {
            DataOne += "n";
            break;
        }

        case Qt::Key_L:
        {
            DataOne += "l";
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
