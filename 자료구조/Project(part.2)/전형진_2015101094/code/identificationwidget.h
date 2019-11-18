#ifndef IDENTIFICATIONWIDGET_H
#define IDENTIFICATIONWIDGET_H
#include <QDialog>
#include <fstream>
#include <QMessageBox>
#include "registerwidget.h"
#include "SingleLinkedList.h"
#include "membertype.h"
using namespace std;

namespace Ui {
class IdentificationWidget;
}

class IdentificationWidget : public QDialog
{
    Q_OBJECT

public:
    explicit IdentificationWidget(QWidget *parent = nullptr);
    ~IdentificationWidget();
    void getIdinfo();
    memberType getPick() const;


private slots:
    void on_Exit_button_clicked();

    void on_loginbutton_clicked();

    void on_idedit_textChanged(const QString &arg1);

    void on_passwordedit_textChanged(const QString &arg1);

    void on_registerbutton_clicked();

private:
    Ui::IdentificationWidget *ui;
    ifstream fin;
    SingleLinkedList<memberType> memberList;
    memberType pick;
};

#endif // IDENTIFICATIONWIDGET_H
