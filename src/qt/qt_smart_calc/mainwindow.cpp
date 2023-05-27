#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // Initialize window
  graphWindow = new graph_window();
  connect(graphWindow, &graph_window::firstWindow, this, &MainWindow::show);

  creditWindow = new credit_window();
  // connect(creditWindow, &credit_window::firstWindow, this,
  // &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() { graphWindow->show(); }

void MainWindow::on_pushButton_4_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"1"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_5_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"2"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_6_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"3"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_7_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"4"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_8_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"5"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_9_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"6"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_10_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"7"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_11_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"8"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_12_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"9"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_13_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"0"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_14_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"."};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_20_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"^"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_16_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"+"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_17_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"-"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_18_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"*"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_19_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"/"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_21_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"mod"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_22_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"(+"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_23_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"(-"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_24_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"sin("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_25_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"cos("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_26_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"tan("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_27_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"acos("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_28_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"asin("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_29_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"atan("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_30_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"sqrt("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_31_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"ln("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_32_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"log("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_33_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"X"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_3_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {"("};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_34_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString number = {")"};
  QString result = text + number;

  ui->textEdit->setText(result);  // send something to input field
}

void MainWindow::on_pushButton_37_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  QString clear = {""};
  QString result = clear;

  ui->textEdit->setText(result);
}

void MainWindow::on_pushButton_36_clicked() {
  QString text = ui->textEdit->toPlainText();  // get text from input field
  text.chop(1);
  ui->textEdit->setText(text);
}

void MainWindow::on_pushButton_15_clicked() {
  QString text = ui->textEdit->toPlainText();

  double result = 0;
  int res = 0;

  QByteArray ba = text.toLocal8Bit();
  char *source = ba.data();

  res = init_calc(source, &result);
  if (res != 0) {
    QString err = "Error";

    ui->textEdit->setText(err);
  } else {
    text = QString::number(result);
    ui->textEdit->setText(text);
  }
}

void MainWindow::on_pushButton_2_clicked() { creditWindow->show(); }
