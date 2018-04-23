#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);

    QString fileName = "distros";
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Readhat" << endl;
        out << "Slackware" << endl;
    } else {
        qWarning("Could not open file");
    }

    file.close();

    system("pause");
    return 0;
}
