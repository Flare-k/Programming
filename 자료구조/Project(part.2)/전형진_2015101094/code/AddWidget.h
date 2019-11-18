#pragma once
#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddWidget;
}

class AddWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddWidget(QWidget *parent = nullptr);
    ~AddWidget();

private slots:
    void on_IdEdit_textChanged(const QString &arg1);

    void on_SubjectEdit_textChanged(const QString &arg1);

    void on_ArtistEdit_textChanged(const QString &arg1);

    void on_ComposerEdit_textChanged(const QString &arg1);

    void on_GenreEdit_textChanged(const QString &arg1);

    void on_Cancle_clicked();

    void on_Confirm_clicked();

    void on_comboBox_activated(int index);


    void on_pictureadd_clicked();

private:
    string Id;
    string Type;
    string Lyrics;

    MusicType one;
    Ui::AddWidget *ui;
};

#endif // ADDWIDGET_H
