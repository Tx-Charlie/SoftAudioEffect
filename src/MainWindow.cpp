#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QWidget *parent ) : QWidget(parent),
	ui( new Ui::MainWindow),
	flag_device_work_started(false),
	audio_device( new AudioDevice),
	audio_device_thread( new QThread()),
	audio_player( new AudioPlayer),
	audio_player_thread( new QThread() )
{
	ui->setupUi( this );
	this->init();
	this->connectSignalSlot();
}

MainWindow::~MainWindow()
{
	delete this->ui;

	if(this->audio_device_thread->isRunning())
		this->audio_device_thread->exit();
	this->audio_device_thread->deleteLater();

	if(this->audio_player_thread->isRunning())
		this->audio_player_thread->terminate();
	this->audio_player_thread->deleteLater();

	delete this->audio_device;
	delete this->audio_player;

}

void MainWindow::init()
{
	this->audio_device->moveToThread( this->audio_device_thread );
	//this->audio_player->moveToThread( this->audio_player_thread );
	this->audio_device_thread->start();
	//this->audio_player_thread->start();
}

void MainWindow::connectSignalSlot()
{

}

//-------------------------------------------------------------------------------
// slots:

void MainWindow::on_button_start_clicked()
{
	/* set audio format */
	this->audio_player->setFormat( this->ui->audio_format_widget->getAudioFormat());
	this->audio_device->setFormat( this->ui->audio_format_widget->getAudioFormat());

	/* set device info */
	this->audio_device->setDeviceInfo( this->ui->audio_devlist_widget->getCurrentDeviceInfo());

	/* start playing */
	this->audio_player->startPlay();
	this->audio_device->start();

	/* connect audio source to audio sink */
	connect( this->audio_device, &AudioDevice::signal_audioData,
			 this->audio_player, &AudioPlayer::slot_playBuffer,
			 Qt::QueuedConnection);
}

//-------------------------------------------------------------------------------

void MainWindow::slot_deviceOptionApply( QAudioDeviceInfo dev_info, QAudioFormat audio_fmt)
{
	this->audio_player->setFormat( audio_fmt );
	this->audio_device->setFormat( audio_fmt );
	this->audio_device->setDeviceInfo( dev_info );
}


void MainWindow::startDevice()
{
	if( !this->flag_device_work_started )
	{
		connect( this->audio_device, &AudioDevice::signal_audioData,
				 this->audio_player, &AudioPlayer::slot_playBuffer,
				 Qt::DirectConnection);

		this->audio_player->startPlay();
		this->audio_device->start();
	}
}

void MainWindow::stopDevice()
{
	if( this->flag_device_work_started)
	{
		this->audio_player->stopPlay();
		this->audio_device->stop();

		disconnect( this->audio_device, &AudioDevice::signal_audioData,
					this->audio_player, &AudioPlayer::slot_playBuffer);
	}
}
