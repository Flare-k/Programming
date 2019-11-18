#include "registerwidget.h"
#include "ui_registerwidget.h"

RegisterWidget::RegisterWidget(const SingleLinkedList<memberType>& in_List,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    memberList = in_List;
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

memberType RegisterWidget::getNewmember() const
{
    return newmember;
}
void RegisterWidget::on_Exit_button_clicked()
{
    reject();
}

void RegisterWidget::on_idedit_textChanged(const QString &in_id)
{
    id = in_id.toStdString();

}

void RegisterWidget::on_passwordedit_textChanged(const QString &in_password)
{
    pw = in_password.toStdString();
}

void RegisterWidget::on_registerbutton_clicked()
{
    memberType temp;
    temp.setId(id);

    if (id.empty() || pw.empty())
        QMessageBox::information(this,"Error","Input Registration Info!");
    else if (memberList.Retrieve(temp))
        QMessageBox::information(this,"Error","same ID exists!");
    else
    {
        newmember.setRecord(id, pw);
        accept();
    }
}


