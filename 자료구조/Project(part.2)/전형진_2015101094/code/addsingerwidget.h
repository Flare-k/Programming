#pragma once
#ifndef ADDSINGERWIDGET_H
#define ADDSINGERWIDGET_H
#include "SingerType.h"
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class AddSingerWidget;
}

class AddSingerWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddSingerWidget(QWidget *parent = nullptr);
    ~AddSingerWidget();

private slots:
    void on_bornEdit_userDateChanged(const QDate &date);

    void on_genderBox_activated(const QString &arg1);

    void on_debutEdit_userDateChanged(const QDate &date);

    void on_nameEdit_textEdited(const QString &arg1);

    void on_pictureadd_clicked();

    void on_cancel_clicked();

    void on_ok_clicked();

private:
    Ui::AddSingerWidget *ui;
    SingerType singer;
};

#endif // ADDSINGERWIDGET_H
