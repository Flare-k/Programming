#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow *Main;

MainWindow::MainWindow(memberType user,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Main = this;
    QMenu *pFileMenu;
    ui->setupUi(this);
    nowmember = user;
    login();

    //file processing menu
    pFileMenu = menuBar() ->addMenu(tr("File"));
    QAction *pSlotSaveFile = new QAction(tr("Save"),this);
    pSlotSaveFile->setShortcut(tr("Ctrl+S"));
    pSlotSaveFile->setStatusTip(tr("Save Data to textfile"));
    connect(pSlotSaveFile, SIGNAL(triggered()),this, SLOT(SaveFile()));
    pFileMenu->addAction(pSlotSaveFile);


    //checkboxmapping and table initialization
    checkboxMapper = new QSignalMapper(this);
    ui->ListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ListTable->setRowCount(0);
    ui->ListTable->setColumnWidth(ID, 50);
    ui->ListTable->setColumnWidth(TITLE, 100);
    ui->ListTable->setColumnWidth(ARTIST, 100);
    ui->ListTable->setColumnWidth(COMPOSER, 100);
    ui->ListTable->setColumnWidth(GENRE, 70);
    ui->ListTable->setColumnWidth(TYPE, 70);
    ui->ListTable->setColumnWidth(LYRICS, 90);
    ui->ListTable->setColumnWidth(CHECK, 10);
    ui->ListTable->setColumnWidth(ADD, 90);


    displayAll(m_musicList);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayAll(const SortedList<MusicType>& givenList)
{
    m_displayList = givenList;
    ui->ListTable->setRowCount(0);
    if (m_displayList.IsEmpty())
    {
        ui->ListTable->setRowCount(1);
        ui->ListTable->setItem(0,0, new QTableWidgetItem("Empty"));
    }
    else
    {
        m_displayList.ResetList();
        MusicType temp;
        while(m_displayList.GetNextItem(temp)!=-1)
        {

            ui->ListTable->insertRow(ui->ListTable->rowCount());
            int index = ui->ListTable->rowCount()-1;

            //lyrics button
            pWidget_lyrics = new QWidget();
            btn_lyrics = new QPushButton();
            btn_lyrics->setText("Show Lyrics");
            connect(btn_lyrics, &QPushButton::clicked, this, &MainWindow::onClicked_lyrics);
            QHBoxLayout* pLayout = new QHBoxLayout(pWidget_lyrics);
            pLayout->addWidget(btn_lyrics);
            pLayout->setAlignment(Qt::AlignCenter);
            pLayout->setContentsMargins(0, 0, 0, 0);
            pWidget_lyrics->setLayout(pLayout);

            //playList Add button
            pWidget_add = new QWidget();
            btn_add = new QPushButton();
            btn_add->setText("+Add+");
            connect(btn_add, &QPushButton::clicked, this, &MainWindow::onClicked_AddToPlaylist);
            QHBoxLayout* AddLayout = new QHBoxLayout(pWidget_add);
            AddLayout->addWidget(btn_add);
            AddLayout->setAlignment(Qt::AlignCenter);
            AddLayout->setContentsMargins(0, 0, 0, 0);
            pWidget_add->setLayout(AddLayout);

            //checkbox setting
            QCheckBox *checkBox =new QCheckBox(this);
            checkBox->setChecked(false);
            connect(checkBox, SIGNAL(clicked()),checkboxMapper,SLOT(map()));
            checkboxMapper->setMapping(checkBox,temp.GetId());
            connect(checkboxMapper,SIGNAL(mapped(int)),this,SLOT(chkChanged(int)));

            //table show
            QTableWidgetItem* id = new QTableWidgetItem(QString::number(temp.GetId()));
            QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.GetName()));
            QTableWidgetItem* artist = new QTableWidgetItem(QString::fromStdString(temp.GetArtist()));
            QTableWidgetItem* composer = new QTableWidgetItem(QString::fromStdString(temp.GetComposer()));
            QTableWidgetItem* genre = new QTableWidgetItem(QString::fromStdString(temp.GetGenre()));
            QTableWidgetItem* type = new QTableWidgetItem(QString::fromStdString(temp.GetType()));
            id->setTextAlignment(Qt::AlignCenter);
            title->setTextAlignment(Qt::AlignCenter);
            artist->setTextAlignment(Qt::AlignCenter);
            composer->setTextAlignment(Qt::AlignCenter);
            genre->setTextAlignment(Qt::AlignCenter);
            type->setTextAlignment(Qt::AlignCenter);

            ui->ListTable->setItem(index, ID, id);
            ui->ListTable->setItem(index, TITLE, title);
            ui->ListTable->setItem(index, ARTIST, artist);
            ui->ListTable->setItem(index, COMPOSER, composer);
            ui->ListTable->setItem(index, GENRE, genre);
            ui->ListTable->setItem(index, TYPE, type);
            ui->ListTable->setCellWidget(index, LYRICS, pWidget_lyrics);
            ui->ListTable->setCellWidget(index,CHECK, checkBox);
            ui->ListTable->setCellWidget(index, ADD, pWidget_add);


        }
    }
}


void MainWindow::SaveFile()
{
    string m_filename = nowmember.getId() + "_mfile.txt";
    string p_filename = nowmember.getId() + "_pfile.txt";
    string s_filename = nowmember.getId() + "_sfile.txt";

    ofstream m_Outfile(m_filename);
    ofstream p_Outfile(p_filename);
    ofstream s_Outfile(s_filename);

    m_musicList.ResetList();
    MusicType tempMusic;
    while (m_musicList.GetNextItem(tempMusic)!=-1)
    {
        tempMusic.WriteDataToFile(m_Outfile);
    }

    m_playList.ResetList();
    playItem tempPlay;
    for (int i=0;i<m_playList.GetLength();i++)
    {
        m_playList.GetNextItem(tempPlay);
        tempPlay.WriteDataToFile(p_Outfile);
    }

    m_singerList.ResetList();
    SingerType tempSinger;
    for (int i=0;i<m_singerList.getLength();i++)
    {
        m_singerList.GetNextItem(tempSinger);
        tempSinger.WriteDataToFile(s_Outfile);
    }

    QMessageBox::information(this,"Save","Completed!");
    m_Outfile.close();
    p_Outfile.close();
    s_Outfile.close();
}

void MainWindow::on_ExitButton_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        this->close();
}

void MainWindow::onClicked_lyrics()
{
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());

    int row = ui->ListTable->indexAt(w->pos()).row();
    MusicType temp = m_displayList.at(row);
    Lyrics lyricswidget(temp);
    lyricswidget.exec();
}

void MainWindow::onClicked_AddToPlaylist()
{
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());

    int row = ui->ListTable->indexAt(w->pos()).row();
    playItem add_item(m_displayList.at(row).GetId());
    int det = m_playList.Add(add_item);
    if (det==1)
        QMessageBox::information(this,"Add_to_PlayList","Add Complete!");
    else if (det==0)
        QMessageBox::information(this,"Error","Add Fail:Already Exists");
    else
    {
        playItem last = m_playList.at(m_playList.GetLength()-1);
        m_playList.Delete(last);
        m_playList.Add(add_item);
        QMessageBox::information(this,"Add_to_PlayList","Add Complete!(Last Song Deleted)");
    }
}

void MainWindow::chkChanged(int id)
{
    MusicType item(id);
    m_musicList.Retrieve_Binary(item);
    int index = m_musicList.GetCurPointer();

    bool state = static_cast<QCheckBox*>(ui->ListTable->cellWidget(index,CHECK))->isChecked();

    if (state)
        check_list.Add(id);
    else
        check_list.Delete(id);
}

void MainWindow::on_select_delete_clicked()
{
    if (check_list.GetLength()==0)
    {
        QMessageBox::information(this,"Error!","Choose a item!");
        return;
    }

    QMessageBox MsgBox;
    MsgBox.setText("Sure to delete?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Cancel )
        return;

    int id;
    check_list.ResetList();
    while(check_list.GetNextItem(id)!=-1)
    {
        MusicType one(id);

        m_musicList.Delete(one);
        SingerType singer;
        singer.setName(one.GetArtist());
        getSinger(singer);
        SingerSong song(id ,one.GetName());
        singer.deleteSong(song);
        playItem play;
        play.setId(id);
        m_playList.Delete(play);
    }
    check_list.MakeEmpty();
    ui->searchedit->setText("");
    displayAll(m_musicList);
}

void MainWindow::on_select_revise_clicked()
{

    if (check_list.GetLength() == 0)
    {
        QMessageBox::information(this,"Error!","Choose a item!");
        return;

    }

    else if (check_list.GetLength() > 1 )
    {
        QMessageBox::information(this,"Error!","Choose one item!");
        return;
    }
    else
    {
        int id;
        check_list.ResetList();
        while(check_list.GetNextItem(id)!=-1)
        {
            MusicType revise(id);
            ReviseWidget revisewidget(revise);
            revisewidget.exec();
        }
        ui->searchedit->setText("");
        check_list.MakeEmpty();
        displayAll(m_musicList);
    }
}

void MainWindow::on_AddButton_clicked()
{
    AddWidget addwidget;
    addwidget.setModal(true);
    addwidget.exec();

    displayAll(m_musicList);
}

void MainWindow::music_replace(MusicType one)
{
    m_musicList.Replace(one);
}

int MainWindow::music_Add(MusicType one)
{
    return m_musicList.Add(one);
}

int MainWindow::singer_Add(SingerType one)
{
    return m_singerList.Push(one);
}

bool MainWindow::getSinger(SingerType& one)
{
    return m_singerList.Retrieve(one);
}

bool MainWindow::getSong(MusicType &one)
{
    return m_musicList.Retrieve_Binary(one);
}
void MainWindow::on_artist_addButton_clicked()
{
    AddSingerWidget addsingerwidget;
    addsingerwidget.exec();
}

void MainWindow::on_PlayListButton_clicked()
{
    playwidget Playwidget(m_playList);
    Playwidget.exec();
}


void MainWindow::on_deleteAllbutton_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Sure to delete All?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Cancel )
        return;
    m_musicList.MakeEmpty();
    m_playList.MakeEmpty();
    displayAll(m_musicList);
}

void MainWindow::on_SearchCombo_activated(const QString &type)
{
    search_type = type.toStdString();
}


void MainWindow::on_searchButton_clicked()
{
    m_displayList.MakeEmpty();


   if (search_type == "Search")
    {
        QMessageBox::information(this,"Error!","Choose a Search Type");
        return;
    }

    else if (search_text.empty())
        displayAll(m_musicList);

    else if (search_type == "ID")
    {
        int id = atoi(search_text.c_str());
        MusicType search(id);
        if (getSong(search))
        {
            m_displayList.Add(search);
            displayAll(m_displayList);
        }
    }

    else if (search_type == "Title")
    {
        m_musicList.ResetList();
        MusicType search;
        while(m_musicList.GetNextItem(search)!=-1)
        {
            if (search.GetName().find(search_text) != string::npos)
                m_displayList.Add(search);
        }
        displayAll(m_displayList);
    }

    else if (search_type == "Artist")
    {
        m_musicList.ResetList();
        MusicType search;
        while(m_musicList.GetNextItem(search)!=-1)
        {
            if (search.GetArtist().find(search_text) != string::npos)
                m_displayList.Add(search);
        }
        displayAll(m_displayList);
    }

    else if (search_type == "Genre")
    {
        m_musicList.ResetList();
        MusicType search;
        while(m_musicList.GetNextItem(search)!=1)
        {
            if (search.GetGenre()==search_text)
                m_displayList.Add(search);
        }
        displayAll(m_displayList);
    }
}


void MainWindow::on_searchedit_textEdited(const QString &context)
{
    search_text = context.toStdString();
}

void MainWindow::login()
{
    string m_filename = nowmember.getId() + "_mfile.txt";
    string p_filename = nowmember.getId() + "_pfile.txt";
    string s_filename = nowmember.getId() + "_sfile.txt";

   ifstream m_Infile(m_filename);
   ifstream p_Infile(p_filename);
   ifstream s_Infile(s_filename);

   //singerList update
   if (s_Infile.is_open())
   {
       SingerType tempSinger;
       tempSinger.ReadDataFromFile(s_Infile);
       while(!s_Infile.eof())
       {
           m_singerList.Push(tempSinger);
           tempSinger.ReadDataFromFile(s_Infile);

       }
       s_Infile.close();
   }

   //musicList update
   if (m_Infile.is_open())
   {
       MusicType tempMusic;
       tempMusic.ReadDataFromFile(m_Infile);
       while(!m_Infile.eof())
       {
           m_musicList.Add(tempMusic);

           SingerSong tempSong(tempMusic.GetId(), tempMusic.GetName());
           SingerType tempSinger;
           tempSinger.setName(tempMusic.GetArtist());

           m_singerList.Retrieve(tempSinger);
           tempSinger.addSong(tempSong);

           tempMusic.ReadDataFromFile(m_Infile);
       }
       m_Infile.close();
   }


   //playList update
   if (p_Infile.is_open())
   {
       playItem tempPlay;
       tempPlay.ReadDataFromFile(p_Infile);
       while(!p_Infile.eof())
       {
           m_playList.Add(tempPlay);
           tempPlay.ReadDataFromFile(p_Infile);

       }
       m_Infile.close();
   }

}


void MainWindow::update_playlist(const CircularDoubleLinkedList<playItem>& input)
{
    m_playList = input;
}
