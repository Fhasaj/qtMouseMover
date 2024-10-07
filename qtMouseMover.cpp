#include "qtMouseMover.h"

qtMouseMover::qtMouseMover(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.second_lable->setText(QString::number(timer_value));
}

qtMouseMover::~qtMouseMover()
{}

void qtMouseMover::on_start_btn_clicked()
{
   ui.stop_btn->setEnabled(true);
   ui.status_lable->setText("Running");
   ui.start_btn->setEnabled(false);
}


void qtMouseMover::on_stop_btn_clicked()
{
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

