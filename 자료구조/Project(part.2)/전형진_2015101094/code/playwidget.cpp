#include "playwidget.h"
#include "ui_playwidget.h"
extern MainWindow *Main;

playwidget::playwidget(const CircularDoubleLinkedList<playItem>& m_playList,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playwidget)
{
    checkboxMapper = new QSignalMapper(this);
    PlayList = m_playList;
    ui->setupUi(this);

    ui->ListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ListTable->setRowCount(0);
    ui->ListTable->setColumnWidth(TITLE, 100);
    ui->ListTable->setColumnWidth(ARTIST, 70);
    ui->ListTable->setColumnWidth(LYRICS, 80);
    ui->ListTable->setColumnWidth(CHECK, 3);

    displayall();
}

playwidget::~playwidget()
{
    delete ui;
}


void playwidget::on_deleteplay_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Sure to erase all?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
    {
        PlayList.MakeEmpty();
        QMessageBox::information(this,"Alert","All Clear!");
        displayall();
    }
}


void playwidget::displayall()
{
    ui->ListTable->setRowCount(0);
    PlayList.ResetList();
    playItem temp;
    if (PlayList.IsEmpty())
    {
        ui->ListTable->setRowCount(1);
        ui->ListTable->setItem(0,0, new QTableWidgetItem("Empty"));
    }
    else
    {
        check = new int[PlayList.GetLength()]{0,};
        for (int i=0;i<PlayList.GetLength();i++)
        {
            PlayList.GetNextItem(temp);
            ui->ListTable->insertRow(ui->ListTable->rowCount());
            int index = ui->ListTable->rowCount()-1;

            pWidget_lyrics = new QWidget();
            btn_lyrics = new QPushButton();
            btn_lyrics->setText("Show Lyrics");
            connect(btn_lyrics, &QPushButton::clicked, this, &playwidget::onClicked_lyrics);
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget_lyrics);
            pLayout->addWidget(btn_lyrics);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget_lyrics->setLayout(pLayout);

            QCheckBox *checkBox =new QCheckBox(this);
            checkBox->setChecked(false);
            connect(checkBox, SIGNAL(clicked()),checkboxMapper,SLOT(map()));
            checkboxMapper->setMapping(checkBox,index);
            connect(checkboxMapper,SIGNAL(mapped(int)),this,SLOT(chkChanged(int)));

            QString title, artist,lyric;
            MusicType load(temp.getId());
            Main->getSong(load);
            title =  QString::fromStdString(load.GetName());
            artist =  QString::fromStdString(load.GetArtist());

            ui->ListTable->setItem(index, TITLE, new QTableWidgetItem(title));
            ui->ListTable->setItem(index, ARTIST, new QTableWidgetItem(artist));
            ui->ListTable->setCellWidget(index, LYRICS, pWidget_lyrics);
            ui->ListTable->setCellWidget(index,CHECK, checkBox);
        }

    }
}


void playwidget::on_closeB_clicked()
{
    Main->update_playlist(PlayList);
    this->close();
}

CircularDoubleLinkedList<playItem> playwidget::getList() const
{
    return PlayList;
}

void playwidget::onClicked_lyrics()
{
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());

    int row = ui->ListTable->indexAt(w->pos()).row();
    MusicType temp;
    temp.SetId(PlayList.at(row).getId());
    Main->getSong(temp);

    Lyrics lyricswidget(temp);
    lyricswidget.exec();
}

void playwidget::chkChanged(int index)
{
    bool state = static_cast<QCheckBox*>(ui->ListTable->cellWidget(index,CHECK))->isChecked();

    if (state)
        check[index] = 1;
    else
        check[index] = 0;
}

void playwidget::on_select_delete_clicked()
{
    int len = PlayList.GetLength();
    bool det = false;
    for (int i=len-1; i>=0; i--)
    {
        if (check[i]==1){
            PlayList.Delete(PlayList.at(i));
            det = true;
        }
    }
    if (det==false)
        QMessageBox::information(this,"Error!","Choose a item!");

    displayall();
}

void playwidget::on_change_clicked()
{

    int chosen_index[2];
    int count =0;
    for (int i=0;i<PlayList.GetLength();i++)
    {
        if (check[i]==1)
        {
            chosen_index[count] = i;
            count++;
            if (count==2)
                break;
        }
    }
    if (count == 2)
        PlayList.ChangeSequence(chosen_index[0], chosen_index[1]);
    else
        QMessageBox::information(this,"Error!","Choose TWO items!");

    displayall();
}

