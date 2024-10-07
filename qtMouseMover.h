#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtMouseMover.h"

class qtMouseMover : public QMainWindow
{
    Q_OBJECT

public:
    qtMouseMover(QWidget *parent = nullptr);
    ~qtMouseMover();

private slots:
    void on_start_btn_clicked();

    void on_stop_btn_clicked();

    void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);

    void on_timer_slider_actionTriggered(int action);


    void on_defult_main_btn_clicked();

    void on_updates_btn_clicked();

    void on_about_btn_clicked();

    void on_pause_hotkey_editingFinished();

    void on_Resume_hotkey_editingFinished();

    void on_defult_hotkey_btn_clicked();

    void on_apply_btn_clicked();

    void on_remove_btn_clicked();

    void on_close_btn_clicked();


private:
    Ui::qtMouseMoverClass ui;

    int timer_value = 30;
};
