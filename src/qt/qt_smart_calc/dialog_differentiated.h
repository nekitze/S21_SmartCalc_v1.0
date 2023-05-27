#ifndef DIALOG_DIFFERENTIATED_H
#define DIALOG_DIFFERENTIATED_H

#include <QDialog>

namespace Ui {
class dialog_differentiated;
}

class dialog_differentiated : public QDialog {
  Q_OBJECT

 public:
  explicit dialog_differentiated(QWidget *parent = nullptr);
  ~dialog_differentiated();
  dialog_differentiated(double pay);

 private:
  Ui::dialog_differentiated *ui;
};

#endif  // DIALOG_DIFFERENTIATED_H
