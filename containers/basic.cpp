#include <QTextStream>
#include <QDate>

int main(void) {

    QTextStream out(stdout);

    QDate dt(2015, 5, 11);
    QDate nd = dt.addDays(55);

    QDate curr = QDate::currentDate();

    QDate xmas(2015, 12, 24);

    out << "55 days from " << dt.toString() << " is "
        << nd.toString() << endl;
    out << "There are " << curr.daysTo(xmas)
        << " days till Christmas" << endl;

    for (int i = 0; i< 100; i++) {
        out << curr.addDays(i).toString() << endl;
    }

    return 0;
}
