#include <QTextStream>
#include <QTime>

int main(void) {

    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    int wd = cd.dayOfWeek();

    out << "Today is " << QDate::shortDayName(wd) << endl;
    out << "Today is " << QDate::longDayName(wd) << endl;

    return 0;
}
