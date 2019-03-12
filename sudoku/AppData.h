#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>

class AppData : public QObject
{
    Q_OBJECT
public:
    explicit AppData(QObject *parent = nullptr);

signals:
    void sendData(QString data);

public slots:
    void parseData(QString a);
    void printSolution(int s[][9]);
    int feasible(int S[][9], int x, int y, int k);
    void solveSudoku(int s[][9], int x, int y);

};

#endif // APPDATA_H
