#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QSignalMapper>
#include <QCheckBox>
#include <string>
#include <QAction>
#include <QMessageBox>
#include <QHBoxLayout>

#include "SingleLinkedList.h"
#include "CircularDoubleLinkedList.h"
#include "UnsortedList.h"
#include "SortedList.h"

#include "playItem.h"
#include "MusicType.h"
#include "SingerType.h"
#include "membertype.h"

#include "lyrics.h"
#include "AddWidget.h"
#include "revisewidget.h"
#include "addsingerwidget.h"
#include "playwidget.h"
#include "identificationwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(memberType ,QWidget *parent = nullptr);
    ~MainWindow();
    void displayAll(const SortedList<MusicType>&);
    void music_replace(MusicType one);
    int music_Add(MusicType one);
    int singer_Add(SingerType one);
    bool getSinger(SingerType& one);
    bool getSong(MusicType& one);
    void login();
    void update_playlist(const CircularDoubleLinkedList<playItem>&);

private slots:
    void SaveFile();
    void on_ExitButton_clicked();
    void onClicked_lyrics();
    void onClicked_AddToPlaylist();
    void chkChanged(int id);
    void on_select_delete_clicked();

    void on_AddButton_clicked();

    void on_select_revise_clicked();

    void on_artist_addButton_clicked();

    void on_PlayListButton_clicked();

    void on_deleteAllbutton_clicked();

    void on_SearchCombo_activated(const QString &arg1);

    void on_searchButton_clicked();

    void on_searchedit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    SortedList<MusicType> m_musicList;
    SortedList<MusicType> m_displayList;
    SortedList<int> check_list;
    CircularDoubleLinkedList<playItem> m_playList;
    SingleLinkedList<SingerType> m_singerList;

    QWidget* pWidget_lyrics;
    QPushButton* btn_lyrics;
    QWidget* pWidget_add;
    QPushButton* btn_add;
    QSignalMapper* checkboxMapper;

    string search_type;
    string search_text;

    memberType nowmember;

    enum Column
    {
       CHECK, ID ,TITLE, ARTIST, COMPOSER, GENRE, TYPE, LYRICS, ADD
    };


};
#endif // MAINWINDOW_H
