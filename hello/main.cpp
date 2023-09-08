#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QMessageBox>
void hello()
{
//    QLabel * label = new QLabel("Hello Qt!");
    QLabel * label = new QLabel("<h2><i>Hello </i>"
                                "<font color=red>Qt!</font></h2>");
    label->show();
}

void quit()
{

}

void age()
{
    QWidget * window = new QWidget();
    window->setWindowTitle("Enter Your Age");

    QSpinBox * spinBox = new QSpinBox();
    spinBox->setRange(0, 130);
    QSlider * slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout * layout = new QHBoxLayout();
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    window->setLayout(layout);
    window->show();
}

#include "ui_gotocelldialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(false)
    {
        QPushButton *btn = new QPushButton("Quit");
        QObject::connect(btn, SIGNAL(clicked()), &a, SLOT(quit()));
        btn->show();
    }
    if(false)
    {
        Ui::GoToCellDialog ui;
        QDialog *dialog = new QDialog;
        ui.setupUi(dialog);
        dialog->show();
    }
    if(false)
    {
        GoToCellDialog *dialog = new GoToCellDialog;
        dialog->show();
    }
    if(!false)
    {
        QDialog *dialog = new SortDialog;
        dialog->show();
    }

    return a.exec();
}
