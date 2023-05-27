#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QVector>
#include <QWidget>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
#include "../../calc_functions/calc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class graph_window;
}

class graph_window : public QWidget {
  Q_OBJECT

 public:
  explicit graph_window(QWidget *parent = nullptr);
  ~graph_window();

 signals:
  void firstWindow();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::graph_window *ui;

  double xBegin, xEnd, h, X, result;
  int N;

  QVector<double> x, y;
};

#endif  // GRAPH_WINDOW_H
