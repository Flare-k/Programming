#pragma once
#ifndef REVISEWIDGET_H
#define REVISEWIDGET_H

#include <MusicType.h>
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ReviseWidget;
}

class ReviseWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ReviseWidget(const MusicType& input,QWidget *parent = nullptr);
    ~ReviseWidget();

private slots:
    void on_SubjectEdit_textChanged(const QString &arg1);

    void on_ArtistEdit_textChanged(const QString &arg1);

    void on_ComposerEdit_textChanged(const QString &arg1);

    void on_GenreEdit_textChanged(const QString &arg1);

    void on_Cancle_clicked();

    void on_Confirm_clicked();

    void on_comboBox_activated(int index);

    void on_pictureadd_clicked();

private:
    Ui::ReviseWidget *ui;
    MusicType one;
    string Subject;
    string Artist;
    string Composer;
    string Genre;
    string Type;
    string Lyrics;
};

#endif // REVISEWIDGET_H
