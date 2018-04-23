#include <QTextStream>
#include <QDate>

int main(void) {

    QTextStream out(stdout);

    QList<QDate> dates = {QDate(2018, 5, 11), QDate(2018, 8, 28), QDate(2018, 02, 50)};

    for (int i = 0; i < dates.size(); i++) {
        if (dates.at(i).isValid()) {
            out << "Date " << i + 1 << " is a valid date" << endl;
        } else {
            out << "Date " << i + 1 << " is not a valid date" << endl;
        }
    }

    return 0;
}
