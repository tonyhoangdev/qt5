#include <QList>
#include <QTextStream>

int main(void) {
    QTextStream out(stdout);

    QString authors = "Tony, Hoang, Tuan, Pham, London";
    QStringList items = authors.split(",");

    QStringListIterator it(items);

    while (it.hasNext()) {
        out << it.next().trimmed() << endl;
    }

    return 0;
}
