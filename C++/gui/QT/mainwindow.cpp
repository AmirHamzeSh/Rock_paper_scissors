#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h> //rand()

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),
                                        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_sang_clicked()
{
    select_user = game[0];
    action();
}

void MainWindow::on_pushButton_kaghaz_clicked()
{
    select_user = game[1];
    action();
}


void MainWindow::on_pushButton_gheychi_clicked()
{
    select_user = game[2];
    action();
}

void MainWindow::action()
{
    ui->label_user->setText(QString("<p align=\"center\"><span style=\" font-size:14pt;\">انتخاب شما:%1</span></p>").arg(select_user));
    select_computer = game[rand()%(2-0+1)+0];
    ui->label_computer->setText(QString("<p align=\"center\"><span style=\" font-size:14pt;\">انتخاب کامپیوتر:%1</span></p>").arg(select_computer));

    QString win_user     = "<p align=\"center\"><span style=\" font-size:14pt;\">نتیجه:شما بردید</span></p>" ;
    QString win_computer = "<p align=\"center\"><span style=\" font-size:14pt;\">نتیجه:کامپیوتر برد</span></p>";

    if (select_user == select_computer){
        ui->label_result->setText("<p align=\"center\"><span style=\" font-size:14pt;\">نتیجه:مساوی</span></p>");
        changeColorResult(0);
    }
    else if (select_user == game[0] && select_computer == game[1]){
        score_computer++; ui->label_result->setText(win_computer);
        changeColorResult(-1);
    }

    else if (select_user == game[0] && select_computer == game[2]){
        score_user++; ui->label_result->setText(win_user);
        changeColorResult(+1);
    }

    else if (select_user == game[1] && select_computer == game[0]){
        score_user++; ui->label_result->setText(win_user);
        changeColorResult(+1);
    }

    else if (select_user == game[1] && select_computer == game[2]){
        score_computer++; ui->label_result->setText(win_computer);
        changeColorResult(-1);
    }

    else if (select_user == game[2] && select_computer == game[0]){
        score_computer++; ui->label_result->setText(win_computer);
        changeColorResult(-1);
    }

    else if (select_user == game[2] && select_computer == game[1]){
        score_user++; ui->label_result->setText(win_user);
        changeColorResult(+1);
    }
    if(score_user > score_computer)
    {
        ui->label_socre->setText(QString("<p align=\"center\"><span style=\" font-size:14pt;\">امتیاز شما<span style=\"color:rgb(0,255,0)\"> %1 </span>و کامپیوتر <span style=\"color:rgb(255,0,0)\">%2</span> است.</span></p>").arg(score_user).arg(score_computer));

    }else if (score_user < score_computer)
    {
        ui->label_socre->setText(QString("<p align=\"center\"><span style=\" font-size:14pt;\">امتیاز شما<span style=\"color:rgb(255,0,0)\"> %1 </span>و کامپیوتر <span style=\"color:rgb(0,255,0)\">%2</span> است.</span></p>").arg(score_user).arg(score_computer));
    }else
        ui->label_socre->setText(QString("<p align=\"center\"><span style=\" font-size:14pt;\">امتیاز شما %1 و کامپیوتر %2 است.</span></p>").arg(score_user).arg(score_computer));
}

void MainWindow::changeColorResult(int winUser)
{
    if(winUser == 1) // user winned
    {
        ui->label_result->setStyleSheet("color:rgb(0,255,0); background-color:none;");
    }
    else if(winUser == 0) // game tie
    {
        ui->label_result->setStyleSheet("color: rgb(255, 255, 255);"
                                        "background-color: none ;");
    }
    else if(winUser == -1) // computer winned
    {
        ui->label_result->setStyleSheet("color:rgb(255,0,0); background-color:none;");
    }
}




