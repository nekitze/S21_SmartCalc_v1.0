#include "credit_window.h"

#include <QTextStream>

#include "ui_credit_window.h"

credit_window::credit_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::credit_window) {
  ui->setupUi(this);
}

credit_window::~credit_window() { delete ui; }

void credit_window::on_pushButton_clicked() {
  QString amountText = ui->amountLine->text();
  QString rateText = ui->rateLine->text();
  QString termText = ui->termLine->text();

  QTextStream out(stdout);

  double result = 0;
  int res = 0;

  if (ui->annuityRadio->isChecked()) {
    QString resultText = amountText + "*" + rateText + "/100/12" + "/(1-(1+" +
                         rateText + "/100/12)^(-" + termText + "))";

    QByteArray ba = resultText.toLocal8Bit();
    char *source = ba.data();

    res = init_calc(source, &result);
    if (res != 0) {
      QString err = {"Error"};
      QString result = err;

      ui->outputText->setText(err);
    }

    resultText = "Monthly payment: " + QString::number(result);
    ui->outputText->setText(resultText);

  } else {
    QString output;
    QString monthlyPayment;
    QString monthlyPayMain = amountText + "/" + termText;

    QByteArray ba = monthlyPayMain.toLocal8Bit();
    char *source = ba.data();

    res = init_calc(source, &result);
    if (res != 0) {
      QString err = {"Error"};
      QString result = err;

      ui->outputText->setText(err);
    }

    monthlyPayMain = QString::number(result);

    for (int i = 0; i < termText.toInt(); i++) {
      monthlyPayment = monthlyPayMain +
                       "+"
                       "(" +
                       amountText + "-" + monthlyPayMain + "*" +
                       QString::number(i) + ")*" + rateText + "/100*30/365";

      ba = monthlyPayment.toLocal8Bit();
      char *source = ba.data();

      res = init_calc(source, &result);

      output = output + "Month " + QString::number(i + 1) +
               " payment: " + QString::number(result) + "\n";
    }

    ui->outputText->setText(output);
  }
}

void credit_window::on_pushButton_2_clicked() { this->close(); }
