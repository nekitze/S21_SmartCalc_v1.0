#include "dialog_differentiated.h"

#include "ui_dialog_differentiated.h"

dialog_differentiated::dialog_differentiated(QWidget *parent)
    : QDialog(parent), ui(new Ui::dialog_differentiated) {
  ui->setupUi(this);
}

dialog_differentiated::~dialog_differentiated() { delete ui; }

dialog_differentiated::dialog_differentiated(double pay) {
  ui->textEdit->setText(QString::number(pay));
  delete ui;
}
