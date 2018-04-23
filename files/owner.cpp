#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);

    if (argc != 2) {
        qWarning("Usage: owner file");
        return 1;
    }

    QString fileName = argv[1];

    QFileInfo fileInfo(fileName);

    out << "fileName: " << fileName << endl;

    QString group = fileInfo.group();
    QString owner = fileInfo.owner();

    out << "Group: " << group << endl;
    out << "Owner: " << owner << endl;

    QDateTime last_rea = fileInfo.lastRead();
    QDateTime last_mod = fileInfo.lastModified();
    out << "Last read: " << last_rea.toString() << endl;
    out << "Last modified: " << last_mod.toString() << endl;

    return 0;
}
