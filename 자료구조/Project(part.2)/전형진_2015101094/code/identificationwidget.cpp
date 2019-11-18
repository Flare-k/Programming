#include "identificationwidget.h"
#include "ui_identificationwidget.h"

IdentificationWidget::IdentificationWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdentificationWidget)
{
    ui->setupUi(this);
    getIdinfo();
}

IdentificationWidget::~IdentificationWidget()
{
    delete ui;
}

void IdentificationWidget::on_Exit_button_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        reject();
}

void IdentificationWidget::getIdinfo()
{
    fin.open("memberinfo.txt");
    if (fin.is_open())
    {
        memberType in_member;
        in_member.ReadDataFromFile(fin);
        while(!fin.eof())
        {
            memberList.Push(in_member);
            in_member.ReadDataFromFile(fin);
        }
        fin.close();
    }
    else
    {
        ofstream fout("memberinfo.txt");
        fout.close();
        getIdinfo();
    }
}

memberType IdentificationWidget::getPick() const
{
    return pick;
}

void IdentificationWidget::on_loginbutton_clicked()
{
    memberType temp;
    temp.setId(pick.getId());
    if (pick.getId().empty() || pick.getPw().empty())
    {
        QMessageBox::information(this,"Error","Input Registration Info!");
    }
    else if (memberList.Retrieve(temp))
    {
        if (temp.getPw() != pick.getPw())
            QMessageBox::information(this,"Error","Wrong Password!");
        else
            done(QDialog::Accepted);
    }
    else
    {
        QMessageBox::information(this,"Error","No ID!");
    }
}



void IdentificationWidget::on_idedit_textChanged(const QString &in_id)
{
    pick.setId(in_id.toStdString());
}

void IdentificationWidget::on_passwordedit_textChanged(const QString &in_password)
{
    pick.setPw(in_password.toStdString());
}

void IdentificationWidget::on_registerbutton_clicked()
{
    RegisterWidget registerwidget(memberList);
    int res =registerwidget.exec();
    if (res == QDialog::Accepted)
    {
        memberList.Push(registerwidget.getNewmember());
        ofstream fout("memberinfo.txt");
        memberType temp;
        memberList.ResetList();
        for (int i=0;i<memberList.getLength();i++)
        {
            memberList.GetNextItem(temp);
            temp.WriteDataToFile(fout);
        }
        fout.close();
        QMessageBox::information(this,"Registration","Succeed!");

    }

}
