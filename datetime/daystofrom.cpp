#include <QTextStream>
#include <QDate>

int main(void) {

    QTextStream out(stdout);

    QDate dt(2018, 3, 19);
    QDate cd = QDate::currentDate();

    out << "From " << dt.toString("yyyy-MM-dd") << " " << dt.daysTo(cd) << "th day is " << cd.toString("yyyy-MM-dd") << endl;

    out << "My love " << dt.daysTo(cd) << " days" << endl;

    out << "100 days: " << dt.addDays(100).toString("yyyy-MM-dd") << endl;

    system("pause");
    return 0;
}
