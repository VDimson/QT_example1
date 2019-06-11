#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QSizePolicy"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
    QPixmap pix(":/resource/img/most.png");
    int w=ui->img->width();
    int h=ui->img->height();
    ui->img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    /* Объявляем и инициализируем кнопки
     * */
    QPushButton *but_1 = new QPushButton(this);
    QPushButton *but_2 = new QPushButton(this);
    QPushButton *but_3 = new QPushButton(this);
    QPushButton *knopka = new QPushButton(this);
    /* Устанавливаем номера кнопок
     * */
    but_1->setText("1");
    but_2->setText("2");
    but_3->setText("3");
    knopka->setText("Samba");
//    but_1->sizePolicy().setVerticalPolicy(sizePolicy().Preferred);
//    but_2->sizePolicy().setVerticalPolicy(sizePolicy().Preferred);
//    but_3->sizePolicy().setVerticalPolicy(sizePolicy().Preferred);

    /* Добавляем кнопки на слой с вертикальной ориентацией
     * */
    ui->verticalLayout->addWidget(but_1);
    ui->verticalLayout->addWidget(but_2);
    ui->verticalLayout->addWidget(but_3);
    ui->verticalLayout->addWidget(knopka);

    /* Подключаем к кнопкам индивидуальные слоты
     * */
    connect(but_1, SIGNAL(clicked()), this, SLOT(slotButton1()));
    connect(but_2, SIGNAL(clicked()), this, SLOT(slotButton2()));
    connect(but_3, SIGNAL(clicked()), this, SLOT(slotButton3()));

    /* Подключаем сигнал с передачей номера кнопки к слоту вывода сообщения
     * */
    connect(this, &MainWindow::signalFromButton, this, &MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/* Слоты для обработки нажатия кнопок
 * */
void MainWindow::slotButton1()
{
    emit signalFromButton(1);
}

void MainWindow::slotButton2()
{
    emit signalFromButton(2);
}

void MainWindow::slotButton3()
{
    emit signalFromButton(3);
}

/* Слоты вывода сообщения
 * */
void MainWindow::slotMessage(int buttonID)
{
    QMessageBox::information(this,
                             "Уведомление о нажатой кнопке",
                             "Нажата кнопка под номером " + QString::number(buttonID));
}

void MainWindow::on_pushButton_clicked()
{
//    QMessageBox::information(this,
//                             "Сообщаю!",
//                             "Ку-ка-ре-ку!" );


   QMessageBox::StandardButton reply = QMessageBox::question(this,"Внимание","Хотите закрыть программу?",QMessageBox::Yes | QMessageBox::No);
   if (reply==QMessageBox::Yes)
   {QApplication::quit();}
   else
   {qDebug() << "Кнопка нет была нажата!" << endl ;
   }

}

//void MainWindow::on_pushButton_pressed()
//{
//    QMessageBox::information(this,
//                             "Сообщаю!",
//                             "Событие pressed" );
//}


void MainWindow::on_checkBox_toggled(bool checked)
{
if (checked)
  QMessageBox::information(this,
                             "Сообщаю!",
                             "Выбран ");

     else
//QMessageBox::information(this,
//                                  "Сообщаю!",
//                                  "Не выбран! ");

QMessageBox::warning(this,"Внимание","Не выбрана галка!",1,1,0);
}



void MainWindow::on_verticalSlider_valueChanged(int value)
{
 this->ui->progressBar->setValue(value);
}

void MainWindow::on_slider_valueChanged(int value)
{
    this->ui->progressBar->setValue(value);
}

void MainWindow::on_pushButton_2_clicked()
{
   window = new SecondWindow(this);
   window->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString login=ui->login->text();
    QString password=ui->pass->text();
    if (login=="root" && password=="1")
    {
       //QMessageBox::information(this,"Вход в систему", "Вы успешно авторизованы!");
        ui->statusBar->showMessage("Вы успешно авторизованы!");
    }
    else
    {
        QMessageBox::critical(this,"Внимание","Неправильный логин или пароль!");
    }
}
