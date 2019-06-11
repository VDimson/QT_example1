#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QMessageBox>
#include "secondwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void signalFromButton(int buttonID);    // Сигнал для передачи номер нажатой кнопки

private:
    Ui::MainWindow *ui;
    SecondWindow *window;

private slots:
    void slotButton1();     // Слоты-обработчики нажатий кнопок
    void slotButton2();
    void slotButton3();

    // Слоты вызывающий сообщение с номеро нажатой кнопки
    void slotMessage(int buttonID);
    void on_pushButton_clicked();
    //void on_pushButton_pressed();
    void on_checkBox_toggled(bool checked);

    void on_verticalSlider_valueChanged(int value);
    void on_slider_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
