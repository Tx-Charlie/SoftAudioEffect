#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QWidget *parent ) : QWidget(parent),
        ui( new Ui::MainWindow),
		audio_device( new AudioDevice),
        audio_player( new AudioPlayer)
{
    ui->setupUi( this );
    this->connectSignalSlot();
}

MainWindow::~MainWindow()
{
    delete this->ui;
    delete this->audio_device;
    delete this->audio_player;
}

void MainWindow::connectSignalSlot()
{

    connect( this->ui->audio_devlist_widget, SIGNAL(signal_audioDeviceInfo(QAudioDeviceInfo)),
             this->audio_device, SLOT(slot_setDeviceInfo(QAudioDeviceInfo)));

    connect( this->ui->audio_format_widget, SIGNAL(signal_audioFormat(QAudioFormat)),
             this->audio_device, SLOT(slot_setFormat(QAudioFormat)));

    connect( this->ui->audio_format_widget, SIGNAL(signal_audioFormat(QAudioFormat)),
             this->audio_player, SLOT(slot_setFormat(QAudioFormat)));
}



void MainWindow::on_button_start_clicked()
{
    this->audio_player->setFormat( this->ui->audio_format_widget->getAudioFormat());
    this->audio_device->setFormat( this->ui->audio_format_widget->getAudioFormat());
    this->audio_device->setDeviceInfo( this->ui->audio_devlist_widget->getCurrentDeviceInfo());

    this->audio_player->startPlay();
    this->audio_device->start();
    connect( this->audio_device, SIGNAL(signal_audioData(QByteArray)),
             this->audio_player, SLOT(slot_playBuffer(QByteArray)),
			 Qt::DirectConnection);
}
