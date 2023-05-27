#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include <dialog_differentiated.h>

#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif
#include "../../calc_functions/calc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class credit_window;
}

class credit_window : public QWidget {
  Q_OBJECT

 public:
  explicit credit_window(QWidget *parent = nullptr);
  ~credit_window();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::credit_window *ui;
  dialog_differentiated *diffWindow;
};

#endif  // CREDIT_WINDOW_H
