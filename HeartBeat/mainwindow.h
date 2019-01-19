#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool m_bHear_on;
    QTimer *timer_heart;
public slots:
    void timerOuttimer_heart();
private slots:



    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
