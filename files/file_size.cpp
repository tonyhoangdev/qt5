#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);

    if (argc != 2) {
        qWarning("Usage: files fileName");
        return 1;
    }

    QString fileName = argv[1];

    if (!QFile(fileName).exists()) {
        qWarning("The file does not exist");
        return 1;
    }

    out << QString("fileName: %1").arg(fileName) << endl;

    QFileInfo fileInfo(fileName);
    qint64 size = fileInfo.size();

    QString str = "The size is: %1 bytes";
    out << str.arg(size) << endl;

    return 0;
}
