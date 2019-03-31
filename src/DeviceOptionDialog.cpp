#include "include/DeviceOptionDialog.h"
#include "ui_DeviceOptionDialog.h"

DeviceOptionDialog::DeviceOptionDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DeviceOptionDialog)
{
	ui->setupUi(this);
}

DeviceOptionDialog::~DeviceOptionDialog()
{
	delete ui;
}

void DeviceOptionDialog::emitSettings()
{
	emit this->signal_deviceOption( this->ui->audio_device_list_widget->getCurrentDeviceInfo(),
									this->ui->audio_format_list_widget->getAudioFormat());
}

void DeviceOptionDialog::on_button_cancle_clicked()
{	this->hide();}

void DeviceOptionDialog::on_button_apply_clicked()
{	this->emitSettings();	}


void DeviceOptionDialog::on_button_ok_clicked()
{
	this->emitSettings();
	this->hide();
}
