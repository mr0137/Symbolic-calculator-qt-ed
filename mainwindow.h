#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

using namespace std;


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_AC_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_bkt1_clicked();

    void Show();

    void on_pushButton_bkt2_clicked();

    void on_pushButton_division_clicked();

    void on_radioButton_rad_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_sqrt_clicked();

    void on_radioButton_deg_clicked(bool checked);

    void on_pushButton_cos_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_deg_clicked();

    void on_pushButton_tg_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_ctg_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_buffer_clicked();

private:
    Ui::MainWindow *ui;
    string DataOne;
    bool Deg;
};

#endif // MAINWINDOW_H
