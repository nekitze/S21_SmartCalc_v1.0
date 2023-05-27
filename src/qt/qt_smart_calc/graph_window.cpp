#include "graph_window.h"

#include "ui_graph_window.h"

graph_window::graph_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::graph_window) {
  ui->setupUi(this);
}

graph_window::~graph_window() { delete ui; }

void graph_window::on_pushButton_clicked() { this->close(); }

void graph_window::on_pushButton_2_clicked() {
  x.clear();
  y.clear();

  QString funcText = ui->functionText->toPlainText();
  QString funcTextTemp = funcText;

  h = 0.1;
  result = 0;

  xBegin =
      ui->dFromText->toPlainText().toDouble();  // область определения X>3||X<-3
  xEnd = ui->dToText->toPlainText().toDouble();

  ui->widget->xAxis->setRange(ui->eFromText->toPlainText().toDouble(),
                              ui->eToText->toPlainText().toDouble());
  ui->widget->yAxis->setRange(ui->eFromText->toPlainText().toDouble(),
                              ui->eToText->toPlainText().toDouble());

  X = xBegin;

  for (X = xBegin; X <= xEnd; X += h) {
    QString x_convert = "(x)";
    x.push_back(X);

    x_convert.replace("x", QString::number(X, 'd'));

    funcTextTemp.replace("x", x_convert);  // replace X with value
    QByteArray ba = funcTextTemp.toLocal8Bit();
    char *source = ba.data();

    init_calc(source, &result);

    y.push_back(result);

    funcTextTemp = funcText;
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->data()->clear();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
