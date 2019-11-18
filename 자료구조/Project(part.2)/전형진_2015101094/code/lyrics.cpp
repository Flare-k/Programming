#include "lyrics.h"
#include "ui_lyrics.h"

Lyrics::Lyrics(MusicType item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lyrics)
{
    ui->setupUi(this);
    ui->inputitle->setText(QString::fromStdString(item.GetName()));
    ui->inputartist->setText(QString::fromStdString(item.GetArtist()));
    layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    if (item.GetLyrics().empty())
        layout->addWidget(new QLabel("None"));
    else
        layout->addWidget(new QLabel(QString::fromStdString(item.GetLyrics())));

    ui->albumcover->setAlignment(Qt::AlignCenter);
    QPixmap pix;
    QString fileName = QString::fromStdString(item.GetAlbumcover());
    if (pix.load(fileName))
    {
        pix = pix.scaled(ui->albumcover->size(),Qt::KeepAspectRatio);
        ui->albumcover->setPixmap(pix);
    }
}

Lyrics::~Lyrics()
{
    delete ui;
}


void Lyrics::on_closeB_clicked()
{
    this->close();
}
