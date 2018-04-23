#ifndef PLUSMINUS_H
#define PLUSMINUS_H

#include <QLabel>
#include <QWidget>

class PlusMinus : public QWidget
{
    Q_OBJECT

public:
    PlusMinus(QWidget *parent = nullptr);

private slots:
    void OnPlus();
    void onMinus();

private:
    QLabel *lbl;
};

#endif // PLUSMINUS_H
