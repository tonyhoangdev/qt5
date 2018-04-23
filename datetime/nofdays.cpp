#include <QTextStream>
#include <QTime>

int main(void) {

    QTextStream out(stdout);

    QList<QString> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    QDate dt1(2018, 03, 19);
    QDate dt2(2018, 04, 24);
    QDate dt3(2018, 8, 28);
    QDate dt4(2018, 02, 28);
    QDate dt5(2018, 11, 06);

    out << "There are " << dt1.daysInMonth() << " days in " << months.at(dt1.month() - 1) << endl;
    out << "There are " << dt2.daysInMonth() << " days in " << months.at(dt2.month() - 1) << endl;
    out << "There are " << dt3.daysInMonth() << " days in " << months.at(dt3.month() - 1) << endl;
    out << "There are " << dt4.daysInMonth() << " days in " << months.at(dt4.month() - 1) << endl;
    out << "There are " << dt5.daysInYear() << " days in year " << QString::number(dt5.year()) << endl;

    return 0;
}
