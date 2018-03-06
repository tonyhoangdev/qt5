#include <QImage.h>
#include <QDebug>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>

int main(int argc, char *argv[]) {
    QTextStream out(stdout);
    QString strDir = ".";

    if (argc < 2) {
        out << "usage: <app.exe> <\"folder_path\"> [width = 1536] [height = 576] [x = 0] [y = 0]" << endl;
//        return 1;
    } else {
        strDir = argv[1];
    }

    QDir dir(strDir);

    if (!dir.exists()) {
        qWarning("The directory does not exist");
        return 1;
    }

    int x = 0;
    int y = 0;
    int w = 1536;
    int h = 576;

    if ((argc == 4) || (argc == 6)) {
        w = atoi(argv[2]);
        h = atoi(argv[3]);
        out << "output: width: " << w << " - height: " << h << endl;

        if (argc == 6) {
            x = atoi(argv[4]);
            y = atoi(argv[5]);

            out << "output: x: " << x << " - y: " << y << endl;
        }
    }

    dir.setFilter(QDir::Files | QDir::AllDirs);

    QFileInfoList list = dir.entryInfoList();
    int max_size = 0;

    foreach (QFileInfo finfo, list) {
        QString name = finfo.absoluteFilePath();
        int size = name.size();

        if (size > max_size) {

            max_size = size;
        }
    }
    int len = max_size + 2;
    out << "===== Input files =====" << endl;
    out << QString("Filename").leftJustified(len).append("Bytes") << endl;

    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.fileName().contains(".bmp")) {
            QString str = fileInfo.absoluteFilePath().leftJustified(len);
            str.append(QString("%1").arg(fileInfo.size()));
            out << str << endl;
            QImage image_orig(fileInfo.absoluteFilePath());
            QImage image2 = image_orig.copy(x,y,w, h);
            image2.setDotsPerMeterX(3780);
            image2.setDotsPerMeterY(3780);
            image2.scaled(1200, 450);
            out << "out: " << fileInfo.absolutePath() + "/" + fileInfo.baseName() + ".jpg" << endl;
            out << image2.save(fileInfo.absolutePath() + "/" + fileInfo.baseName() + ".jpg") << endl;
        }
    }

    list.clear();
    list = dir.entryInfoList();
    out << endl;
    out << "===== Output files =====" << endl;
    out << QString("Filename").leftJustified(len).append("Bytes") << endl;

    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.fileName().contains(".jpg")) {
            QString str = fileInfo.absoluteFilePath().leftJustified(len);
            str.append(QString("%1").arg(fileInfo.size()));
            out << str << endl;
        }
    }

    return 0;
}
