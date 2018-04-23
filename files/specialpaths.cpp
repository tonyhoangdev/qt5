#include <QTextStream>
#include <QDir>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);
    QDir dir;

    out << "Current path: " << QDir::currentPath() << endl;
    out << "Home path: " << QDir::homePath() << endl;
    out << "Temporary path: " << QDir::tempPath() << endl;
    out << "Rooth path: " << QDir::rootPath() << endl;

    return 0;
}
