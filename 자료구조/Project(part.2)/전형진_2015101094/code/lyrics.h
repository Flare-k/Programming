#pragma once
#ifndef LYRICS_H
#define LYRICS_H
#include <QVBoxLayout>
#include <QDialog>
#include "MusicType.h"

namespace Ui {
class Lyrics;
}

class Lyrics : public QDialog
{
    Q_OBJECT

public:
    explicit Lyrics(MusicType item,QWidget *parent = nullptr);
    ~Lyrics();

private slots:
    void on_closeB_clicked();

private:
    Ui::Lyrics *ui;
    QVBoxLayout *layout;
};

#endif // LYRICS_H
