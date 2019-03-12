#include "AppData.h"
#include "QDebug"

AppData::AppData(QObject *parent) : QObject(parent)
{

}

void AppData::parseData(QString a)
{
    QStringList ab = a.split(',');
    int s[9][9];
    for (int i = 0 ; i < ab.count(); i++) {
        s[i/9][i%9] = ab.at(i).toInt();
    }

    solveSudoku(s, 0, 0);
}


void AppData::printSolution(int s[][9]) {
    QList<QString> listResult;
    QList<QString> sendData2;
    for (int i = 0; i < 9 ; i++) {
        QString row = "";
        for(int j = 0; j < 9; j++) {
            sendData2.append(QString::number(s[i][j]));
            row.append(QString::number(s[i][j]) + " ");
        }
        listResult.append(row);
    }

    foreach (QString s, listResult) {
        qDebug() << s;
    }

    emit sendData(sendData2.join(','));
}

int AppData::feasible(int S[][9], int x, int y, int k){
    int i = 0, j = 0;
    for(i = 0; i <9 ; i++){
        if(S[x][i] == k) return 0;
    }
    for(i = 0; i <9 ; i++){
        if(S[i][y] == k) return 0;
    }
    int a = x/3, b = y/3;
    for(i = 3*a; i < 3*a+3; i++){
        for(j = 3*b; j < 3*b+3; j++){
            if(S[i][j] == k) return 0;
        }
    }
    return 1;

}

void AppData::solveSudoku(int s[][9], int x, int y) {
    if (y == 9) {
        if (x == 8) {
            printSolution(s);
            return;
        } else {
            solveSudoku(s, x+1, 0);
        }
    } else if (s[x][y] == 0) {
        int k =0;
        for (k = 1; k <= 9; k++) {
            if (feasible(s, x, y, k)) {
                s[x][y] = k;
                solveSudoku(s, x, y + 1);
                s[x][y] = 0;
            }
        }
    } else {
        solveSudoku(s,x,y+1);
    }
}
