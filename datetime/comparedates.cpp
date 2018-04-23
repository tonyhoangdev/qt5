#include <QTextStream>
#include <QDate>
#include <QTime>

int main(void) {

    QTextStream out(stdout);

    QDate dt1(2018, 04, 23);
    QDate dt2(2018, 03, 19);

    if (dt1 < dt2) {
        out << dt1.toString() << " comes before "
            << dt2.toString() << endl;
    } else {
        out << dt1.toString() << " comes after "
            << dt2.toString() << endl;
    }

    return 0;
}
