#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtMouseMover.h"
#include <QShortcut>
#include <QMessageBox>
#include <QCursor>
#include <QTimer>
#include <QTime>
#include <QScreen>
#include <QRandomGenerator>
#include <qrect.h>

class qtMouseMover : public QMainWindow
{
    Q_OBJECT

public:
    qtMouseMover(QWidget* parent = nullptr);
    ~qtMouseMover();

private slots:
    void on_start_btn_clicked();

    void on_stop_btn_clicked();

    void on_pause_hotkey();

	void on_resume_hotkey();

    void on_checkBox_checkStateChanged(const Qt::CheckState& arg1);

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

    /*
       * Function that moves the mouse around the screen based on the current position and the target position
    */
    void MoveMouse();

    bool isRunning = false;
    int timer_value{ 30 };
    int moveDurration{ 2000 };
    const int steps{ 300 };

	QCursor cursor;
	QTimer* mouseMoverTimer;
	QPoint CurrentMousepos = QCursor::pos();
	QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
	QTime dieTime = QTime::currentTime().addSecs(timer_value);
	
    QString pauseHotkey ;
	QString resumeHotkey;

    /** Keyboard Shortcuts */
    QShortcut* PauseHotKey = new QShortcut(QKeySequence::fromString(pauseHotkey), this);
	QShortcut* ResumeHotKey = new QShortcut(QKeySequence::fromString(resumeHotkey), this);


};
