#include "window.h"
#include <QtGui>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
QObject *parent;
QProcess *myProcess = new QProcess(parent);
Window::Window(QWidget *parent) :
       QWidget(parent)
{

QPushButton *button1 = new QPushButton(tr("Submit"));
QObject::connect(button1,SIGNAL(clicked()),this, SLOT(compare()));
button1->move(370, 350);
button1->show();

QLabel *label1 = new QLabel(tr("Your Lucky Number"));
QFont font1 = label1->font();
font1.setPointSize(30);
font1.setBold(false);
label1->setFont(font1);
label1->move(300, 260);
label1->show();

QLabel *label2 = new QLabel(tr("Answer:"));
QFont font2 = label2->font();
font2.setPointSize(24);
font2.setBold(true);
label2->setFont(font2);
label2->show();

text1 = new QLineEdit;
text1->setEchoMode(QLineEdit::Password);
text1->clear();
text1->show();


QVBoxLayout *buttonLayout1 = new QVBoxLayout;
buttonLayout1->addWidget(button1);

QGridLayout *mainLayout = new QGridLayout;
mainLayout->addWidget(label1, 0, 1);
mainLayout->addWidget(label2, 1, 0, Qt::AlignTop);
mainLayout->addWidget(text1, 1, 1);
mainLayout->addLayout(buttonLayout1, 1, 2);


setLayout(mainLayout);
setWindowTitle(tr("Hint Mechanism"));
setWindowFlags(Qt::FramelessWindowHint);

QWidget::resize(800,600);
QWidget::move(315,100);

}
void Window::compare()
{
     QString name = text1->text();
     if (name == "26")
     {
        QMessageBox::information(this, tr("Successful"),tr("Log in..."));
        exit (0);
     }
     else
     {
         //this->hide();

           //system("./tata.sh");
        system("/home/harshad/Desktop/login/sms");
QMessageBox::information(this, tr("Successful"),tr("sms..."));
        system("/home/harshad/Desktop/login/web");   //Clicks a camera
QMessageBox::information(this, tr("Successful"),tr("web..."));
        system("/home/harshad/Desktop/login/maketar"); ///making a tar file
QMessageBox::information(this, tr("Successful"),tr("maketar..."));
       system("/home/harshad/Desktop/login/msec.jar");        //cloud
QMessageBox::information(this, tr("Successful"),tr("cloud..."));
     system("/home/harshad/Desktop/login/erase");                  //ensure dat /tmp/msec is present else shred errors occur.
     QMessageBox::information(this, tr("Successful"),tr("erase..."));
     system("/home/harshad/Desktop/login2/login -display :0");

           exit(0);
    }
   return;
}
