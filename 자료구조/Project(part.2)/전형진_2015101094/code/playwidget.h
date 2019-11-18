#pragma once

#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class playwidget;
}

class playwidget : public QDialog
{
    Q_OBJECT

public:
    playwidget(const CircularDoubleLinkedList<playItem>& m_playList,QWidget *parent = nullptr);
    ~playwidget();
    void displayall();
    CircularDoubleLinkedList<playItem> getList() const;

private slots:
    void on_deleteplay_clicked();

    void on_closeB_clicked();

    void onClicked_lyrics();

    void chkChanged(int index);

    void on_select_delete_clicked();

    void on_change_clicked();

private:
    Ui::playwidget *ui;
    CircularDoubleLinkedList<playItem> PlayList;
    QWidget* pWidget_lyrics;
    QPushButton* btn_lyrics;
    QSignalMapper* checkboxMapper;
    int* check;

    enum Column
    {
         CHECK, TITLE, ARTIST, LYRICS
    };
};

#endif // PLAYWIDGET_H
