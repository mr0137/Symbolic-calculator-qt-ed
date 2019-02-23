#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "QClipboard"
#include "QScrollEvent"
#include "QKeySequence"
#include "QMessageBox"


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

    bool check_for_correct_input();

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

    void keyPressEvent(QKeyEvent *event);

    void on_pushButton_pi_clicked();

    void on_pushButton_e_clicked();

    void history_add();

    void on_pushButton_h_clear_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:

    Ui::MainWindow *ui;

    string DataOne;
    string Temp;

    bool Deg;

};

#endif // MAINWINDOW_H
