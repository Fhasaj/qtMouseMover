#include "qtMouseMover.h"

#include <iostream>


qtMouseMover::qtMouseMover(QWidget *parent)
	: QMainWindow(parent), mouseMoverTimer(new QTimer(this))
{
    ui.setupUi(this);

    ui.second_lable->setText(QString::number(timer_value));
	ui.time_lcd->display(timer_value);
	connect(mouseMoverTimer, &QTimer::timeout, this, &qtMouseMover::MoveMouse);

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

}


void qtMouseMover::on_pause_hotkey_editingFinished()
{

}


void qtMouseMover::on_Resume_hotkey_editingFinished()
{

}


void qtMouseMover::on_defult_hotkey_btn_clicked()
{

}


void qtMouseMover::on_apply_btn_clicked()
{

}


void qtMouseMover::on_remove_btn_clicked()
{

}


void qtMouseMover::on_close_btn_clicked()
{
    close();
}

