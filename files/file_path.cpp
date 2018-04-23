#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[]) {

    QTextStream out(stdout);

    if (argc != 2) {
        out << "Usage: file_times file" << endl;
        return 1;
    }

    QString fileNames = argv[1];
    QFileInfo fileInfo(fileNames);

    QString absPath = fileInfo.absoluteFilePath();
    QString baseName = fileInfo.baseName();
    QString compBaseName = fileInfo.completeBaseName();
    QString fileName = fileInfo.fileName();
    QString suffix = fileInfo.suffix();
    QString compSuffix = fileInfo.completeSuffix();

    out << "Absolute file path: " << absPath << endl;
    out << "Base name: " << baseName << endl;
    out << "Complete base name: " << compBaseName << endl;
    out << "File name: " << fileName << endl;
    out << "Suffix: " << suffix << endl;
    out << "Whole suffix: " << compSuffix << endl;

    return 0;
}
