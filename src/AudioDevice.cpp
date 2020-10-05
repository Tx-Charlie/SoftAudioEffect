#include "AudioDevice.h"
#include <QDebug>

AudioDevice::AudioDevice( QObject *parent ) : QObject( parent),
		audio_input(nullptr),
		audio_input_io(nullptr)
{
}

AudioDevice::~AudioDevice()
{
}

void AudioDevice::setFormat( const QAudioFormat &audio_format)
{	this->audio_format = audio_format;	}

void AudioDevice::setDeviceInfo( QAudioDeviceInfo dev_info)
{    this->device_info = dev_info;}

void AudioDevice::start()
{
    this->checkFormat();
	this->audio_input = new QAudioInput( this->device_info, this->audio_format );
	this->audio_input_io = this->audio_input->start();

    if( this->audio_input_io)
    {
		connect( this->audio_input_io, &QIODevice::readyRead,
				 this, &AudioDevice::slot_receiveAudioData,
				 Qt::QueuedConnection);

				 //Qt::DirectConnection);
    }
}

void AudioDevice::stop()
{
    this->audio_input->stop();
    if( this->audio_input_io )
    {
		disconnect( this->audio_input_io, &QIODevice::readyRead,
				 this, &AudioDevice::slot_receiveAudioData);
	}
}

void AudioDevice::slot_receiveAudioData()
{
	if( this->audio_input_io )
	{
		QByteArray buffer = this->audio_input_io->readAll();
		emit signal_audioData( buffer );
	}
}

void AudioDevice::checkFormat()
{
	if( !this->device_info.isFormatSupported( this->audio_format) )
		this->audio_format = this->device_info.nearestFormat( this->audio_format );
}


void AudioDevice::slot_setDeviceInfo(QAudioDeviceInfo dev_info)
{    this->setDeviceInfo( dev_info);}

void AudioDevice::slot_setFormat(QAudioFormat audio_format)
{   this->setFormat(audio_format);}
