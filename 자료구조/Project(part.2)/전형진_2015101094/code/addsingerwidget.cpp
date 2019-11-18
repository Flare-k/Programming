#include "addsingerwidget.h"
#include "ui_addsingerwidget.h"
extern MainWindow *Main;

AddSingerWidget::AddSingerWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSingerWidget)
{
    ui->setupUi(this);
}
AddSingerWidget::~AddSingerWidget()
{
    delete ui;
}

void AddSingerWidget::on_bornEdit_userDateChanged(const QDate &date)
{
    QString born = date.toString("yyyy.MM.dd");
    singer.setborn(born.toStdString());

    int age = date.daysTo(QDate::currentDate())/365;

    ui->ageEdit->setText(QString::number(age));
    singer.setAge(age);
}

void AddSingerWidget::on_genderBox_activated(const QString &gender)
{
    singer.setGender(gender.toStdString());
}

void AddSingerWidget::on_debutEdit_userDateChanged(const QDate &date)
{
    QString debut = date.toString("yyyy.MM.dd");
    singer.setDebut(debut.toStdString());
}

void AddSingerWidget::on_nameEdit_textEdited(const QString &name)
{
    singer.setName(name.toStdString());
}


void AddSingerWidget::on_pictureadd_clicked()
{
    QFileDialog::Options options;
    options |= QFileDialog::DontUseNativeDialog;

    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),"/",tr("Image Files (*.png *.jpg *.bmp)"),
                                                    &selectedFilter, options);
    ui->singerpicture->setAlignment(Qt::AlignCenter);
    QPixmap pix;
    if (pix.load(fileName))
    {
        pix = pix.scaled(ui->singerpicture->size(),Qt::KeepAspectRatio);
        ui->singerpicture->setPixmap(pix);
        singer.setPicture(fileName.toStdString());
    }


}

void AddSingerWidget::on_cancel_clicked()
{
    this->close();
}

void AddSingerWidget::on_ok_clicked()
{
    if (singer.getName().empty() ||singer.getGender().empty() || singer.getBorn().empty() || singer.getDebut().empty())
        QMessageBox::information(this,"Error!","Insert right Info.");
    else
    {
        QMessageBox MsgBox;
        MsgBox.setText("Input completed?");
        MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        MsgBox.setDefaultButton(QMessageBox::Ok);
        if ( MsgBox.exec() == QMessageBox::Ok )
        {
            int det = Main->singer_Add(singer);
            if (det == 1)
            {
                QMessageBox::information(this,"ADD","Add Succeeded!");
                this->close();
            }
            else if (det == 0)
                QMessageBox::information(this,"Error!","Same Artist Exists");
            else
                QMessageBox::information(this,"Error!","Full List");
        }

    }
}
