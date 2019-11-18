#include "AddWidget.h"
#include "ui_AddWidget.h"
extern MainWindow *Main;

AddWidget::AddWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWidget)
{
    QIntValidator *intValidator=new QIntValidator(0,9999);

    ui->setupUi(this);
    ui->IdEdit->setValidator(intValidator);
    ui->IdEdit->setPlaceholderText(QString("Integer"));
    ui->lyricsedit->setPlaceholderText(QString("Option"));
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::on_IdEdit_textChanged(const QString &id)
{
    Id = id.toStdString();
}

void AddWidget::on_SubjectEdit_textChanged(const QString &subject)
{
    one.SetName(subject.toStdString());
}

void AddWidget::on_ArtistEdit_textChanged(const QString &artist)
{
    one.SetArtist(artist.toStdString());
}

void AddWidget::on_ComposerEdit_textChanged(const QString &composer)
{
    one.SetComposer(composer.toStdString());
}

void AddWidget::on_GenreEdit_textChanged(const QString &genre)
{
    one.SetGenre(genre.toStdString());
}

void AddWidget::on_Cancle_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setWindowTitle("Cancle");
    MsgBox.setText("Cancle confirm?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        this->close();
}


void AddWidget::on_Confirm_clicked()
{
    QString str = ui->lyricsedit->toPlainText();
    Lyrics = str.toStdString();
    one.SetLyrics(Lyrics);

    if (Id.empty() || one.GetName().empty() ||one.GetArtist().empty() || one.GetComposer().empty() || one.GetGenre().empty() || one.GetType().empty())
        QMessageBox::information(this,"Error!","Insert right Info.");
    else
    {
        QMessageBox MsgBox;
        MsgBox.setText("Input completed?");
        MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        MsgBox.setDefaultButton(QMessageBox::Ok);
        if ( MsgBox.exec() == QMessageBox::Ok )
        {
            one.SetId(atoi(Id.c_str()));
            SingerType singer;
            singer.setName(one.GetArtist());
            if (Main->getSinger(singer) == false)
            {
                QMessageBox::information(this,"Error!","No Artist, Add first!");
            }
            else
            {
                int det = Main->music_Add(one);
                if (det == 1)
                {
                    //singersonglist add
                    SingerSong song(one.GetId(),one.GetName());
                    singer.addSong(song);
                    QMessageBox::information(this,"ADD","Add Succeeded!");
                    this->close();
                }
                else if (det == 0)
                    QMessageBox::information(this,"Error!","Same Id Exists");
                else
                    QMessageBox::information(this,"Error!","Full List");
            }
            }

    }
}

void AddWidget::on_comboBox_activated(int index)
{
    if (index ==0)
    {
        Type.erase();
    }
    else if (index==1)
    {
        Type = "Song";
        one.SetType(Type);

    }
    else if (index ==2 )
    {
        Type = "Inst.";
        one.SetType(Type);
    }
}



void AddWidget::on_pictureadd_clicked()
{
    QFileDialog::Options options;
    options |= QFileDialog::DontUseNativeDialog;

    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),"/",tr("Image Files (*.png *.jpg *.bmp)"),
                                                    &selectedFilter, options);
    ui->albumcover->setAlignment(Qt::AlignCenter);
    QPixmap pix;
    if (pix.load(fileName))
    {
        pix = pix.scaled(ui->albumcover->size(),Qt::KeepAspectRatio);
        ui->albumcover->setPixmap(pix);
        one.SetAlbumcover(fileName.toStdString());
    }

}
