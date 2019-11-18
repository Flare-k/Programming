#include "revisewidget.h"
#include "ui_revisewidget.h"
extern MainWindow *Main;

ReviseWidget::ReviseWidget(const MusicType& input,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReviseWidget)
{
    one = input;
    ui->setupUi(this);
    ui->IdEdit->setText(QString::number(one.GetId()));
    ui->IdEdit->setReadOnly(true);
    ui->lyricsedit->setPlaceholderText(QString("Option"));
}

ReviseWidget::~ReviseWidget()
{
    delete ui;
}

void ReviseWidget::on_SubjectEdit_textChanged(const QString &subject)
{
    Subject = subject.toStdString();
    one.SetName(Subject);
}

void ReviseWidget::on_ArtistEdit_textChanged(const QString &artist)
{
    Artist = artist.toStdString();
    one.SetArtist(Artist);
}

void ReviseWidget::on_ComposerEdit_textChanged(const QString &composer)
{
    Composer = composer.toStdString();
    one.SetComposer(Composer);
}

void ReviseWidget::on_GenreEdit_textChanged(const QString &genre)
{
    Genre = genre.toStdString();
    one.SetGenre(Genre);
}
void ReviseWidget::on_Cancle_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setWindowTitle("Cancle");
    MsgBox.setText("Cancle confirm?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        this->close();
}

void ReviseWidget::on_comboBox_activated(int index)
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
        Type = "Instrumental";
        one.SetType(Type);
    }
}


void ReviseWidget::on_Confirm_clicked()
{
    QString str = ui->lyricsedit->toPlainText();
    Lyrics = str.toStdString();
    one.SetLyrics(Lyrics);

    if (Subject.empty() ||Artist.empty() || Composer.empty() || Genre.empty() || Type.empty())
        QMessageBox::information(this,"Error!","Insert right Info.");
    else
    {
        QMessageBox MsgBox;
        MsgBox.setText("Input completed?");
        MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        MsgBox.setDefaultButton(QMessageBox::Ok);
        if ( MsgBox.exec() == QMessageBox::Ok )
        {
            Main->music_replace(one);
            QMessageBox::information(this,"Revise","Revise Succeeded!");
            this->close();
        }
    }
}




void ReviseWidget::on_pictureadd_clicked()
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
