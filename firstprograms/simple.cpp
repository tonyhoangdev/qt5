#include <QApplication>
#include <QIcon>
#include <QWidget>

// Simple example
// A tooltip
// The application icon
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.move(0, 0);

    //
    window.setWindowTitle("Simple example");

    //
    window.setToolTip("QWidget");

    //
    window.setWindowIcon(QIcon("png_Minh_64x64.png"));

    window.show();

    return app.exec();
}
