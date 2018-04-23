#include <QList>
#include <QTextStream>
#include <algorithm>

int main(void) {
    QTextStream out(stdout);

    QList<QString> authors = {"Tony Hoang", "Tuan Pham", "London"};

    for (int i = 0; i < authors.size(); i++) {
        out << authors.at(i) << endl;
    }

    authors << "Toan Le" << "Dong Phan";

    out << "****************************" << endl;

    std::sort(authors.begin(), authors.end());

    out << "Sorted: " << endl;

    for (QString author: authors) {
        out << author << endl;
    }

    return 0;
}
