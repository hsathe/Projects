#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>

    class QPushButton;
    class QLabel;
    class QLineEdit;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

public slots:
     void compare();


private:

    QPushButton *button1;
    QString name;
    QLineEdit *text1;
    //QProcess *proc;
 };

#endif // WINDOW_H
