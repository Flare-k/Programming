#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include "membertype.h"
#include "SingleLinkedList.h"

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWidget(const SingleLinkedList<memberType>& ,QWidget *parent = nullptr);
    ~RegisterWidget();
    memberType getNewmember() const;

private slots:
    void on_Exit_button_clicked();

    void on_idedit_textChanged(const QString &arg1);

    void on_passwordedit_textChanged(const QString &arg1);

    void on_registerbutton_clicked();

private:
    Ui::RegisterWidget *ui;
    memberType newmember;
    SingleLinkedList<memberType> memberList;
    string id;
    string pw;
};

#endif // REGISTERWIDGET_H
