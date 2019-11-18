#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font;
    font.setFamily(QString("D2Coding"));
    a.setFont(font);

    IdentificationWidget idwidget;
    int det = idwidget.exec();
    if (det == QDialog::Rejected)
        return 0;

    MainWindow w(idwidget.getPick());
    w.show();
    return a.exec();
}
