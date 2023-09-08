#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegExp>
#include <QRegExpValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);
    const QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    ui->lineEdit->setText("invalid");
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::on_lineEdit_textChanged(const QString &arg1)
{
//    ui->okButton->setEnabled(!arg1.isEmpty());
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

