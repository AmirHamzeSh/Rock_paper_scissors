#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void action();

        int score_computer = 0, score_user = 0;
        QString select_user,select_computer;
        QStringList game = {"سنگ","کاغذ","قیچی"};


    private slots:
        void on_pushButton_sang_clicked();

        void on_pushButton_kaghaz_clicked();

        void on_pushButton_gheychi_clicked();

    private:
            Ui::MainWindow *ui;
            void changeColorResult(int winUser);
};
#endif // MAINWINDOW_H
