#include "qtMouseMover.h"

#include <iostream>


qtMouseMover::qtMouseMover(QWidget *parent)
	: QMainWindow(parent), mouseMoverTimer(new QTimer(this))
{
    ui.setupUi(this);

    ui.second_lable->setText(QString::number(timer_value));
	connect(mouseMoverTimer, &QTimer::timeout, this, &qtMouseMover::MoveMouse);

	// Base shortcuts that I may get the user to configure later. 
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_C), this, SLOT(close()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(on_start_btn_clicked()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(on_stop_btn_clicked()));

	pauseHotkey = ui.pause_hotkey->keySequence().toString();

	// Connects the hot keys to the Key Sequence Editor UI components
	connect(PauseHotKey, &QShortcut::activated, this, [this] {on_pause_hotkey(); });
	connect(ResumeHotKey, &QShortcut::activated, this, [this] {on_resume_hotkey();});
}

qtMouseMover::~qtMouseMover()
{}

void qtMouseMover::on_start_btn_clicked()
{
   isRunning = true;
   ui.stop_btn->setEnabled(true);
   ui.status_lable->setText("Running");
   ui.start_btn->setEnabled(false);
   mouseMoverTimer->start(timer_value * 1000);


}

void qtMouseMover::MoveMouse()
{
	int tragetWidth = QRandomGenerator::global()->bounded(screenGeometry.width());
	int targetHight = QRandomGenerator::global()->bounded(screenGeometry.height());
	
	QPoint targetPos(tragetWidth, targetHight);
	int distanceX = targetPos.x() - CurrentMousepos.x();
	int distanceY = targetPos.y() - CurrentMousepos.y();

	for (int i = 1; i <= steps; ++i)
	{
		int newWidth = CurrentMousepos.x() + (distanceX * i / steps);
		int newHieght = CurrentMousepos.y() + (distanceY * i / steps);

		QTimer::singleShot(i * (moveDurration / steps), [this, newWidth, newHieght]() {
			cursor.setPos(newWidth, newHieght);
		});
	}
}


void qtMouseMover::on_stop_btn_clicked()
{
	bool isRunning = false; //Flag just in case the timer is still running
	mouseMoverTimer->stop(); //Stop the timer
	ui.stop_btn->setEnabled(false);
    ui.status_lable->setText("Stopped");
	ui.start_btn->setEnabled(true);
}

void qtMouseMover::on_pause_hotkey()
{
	bool isRunning = false; //Flag just in case the timer is still running
	mouseMoverTimer->stop(); //Stop the timer
	ui.stop_btn->setEnabled(false);
	ui.status_lable->setText("Paused");
	ui.start_btn->setEnabled(true);
}

void qtMouseMover::on_resume_hotkey()
{
	isRunning = true;
	ui.stop_btn->setEnabled(true);
	ui.status_lable->setText("Running");
	ui.start_btn->setEnabled(false);
	mouseMoverTimer->start(timer_value * 1000);
}


void qtMouseMover::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{

}


void qtMouseMover::on_timer_slider_actionTriggered(int action)
{
    
	timer_value = ui.timer_slider->value();
	ui.second_lable->setText(QString::number(timer_value));

}


void qtMouseMover::on_defult_main_btn_clicked()
{

}


void qtMouseMover::on_updates_btn_clicked()
{

}


void qtMouseMover::on_about_btn_clicked()
{
	//QMessageBox::about(this, "About", "This is a simple mouse mover application that moves the mouse around the screen at random intervals. \n\n"
	//	"Created by: FH\n"
	//	"GitHub:  <a href='https://github.com/Fhasaj'> GitHub </a>\n"
	//	"Website: <a href='https://fhasaj.co.uk/'> Website</a>"
	//);
	QMessageBox about(this);
	about.setWindowTitle("About");
	about.setTextFormat(Qt::RichText);
	about.setText("This is a simple mouse mover application that moves the mouse around the screen at random intervals.<br></br>"
		"Created by: FH <br></br>"
		"GitHub:  <a href='https://github.com/Fhasaj'> GitHub </a><br></br>"
		"Website: <a href='https://fhasaj.co.uk/'> Website</a></br>"
	);
	about.exec();
}


void qtMouseMover::on_pause_hotkey_editingFinished()
{
	pauseHotkey = (ui.pause_hotkey->keySequence()).toString();
}


void qtMouseMover::on_Resume_hotkey_editingFinished()
{

}


void qtMouseMover::on_defult_hotkey_btn_clicked()
{

}


void qtMouseMover::on_apply_btn_clicked()
{
	/**
	* This function will apply the setting by storing the values of the UI components to a sqlLite database
	* The values will be stored in a table called settings
	* The table will have the following columns:
	* 2. Timer
	* 3. Steps
	* 4. MoveDurration
	* 5. PauseHotkey
	* 6. ResumeHotkey
	* 
	* This will allow another table called DefaultSettings to be created that will store the default settings for all of these values
	*/
}


void qtMouseMover::on_remove_btn_clicked()
{

}


void qtMouseMover::on_close_btn_clicked()
{
    close();
}

