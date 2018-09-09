#include "AudioPlayer.h"
#include <QDebug>

AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent),
		audio_output(nullptr),
		audio_player(nullptr)

{
}

AudioPlayer::~AudioPlayer()
{
}

void AudioPlayer::setFormat( const QAudioFormat &audio_format)
{	this->audio_format = audio_format;}

void AudioPlayer::startPlay()
{
    this->audio_format.setChannelCount(2);
    this->audio_output = new QAudioOutput( this->audio_format, this );
	this->audio_player = this->audio_output->start();
}

void AudioPlayer::stopPlay()
{	this->audio_output->stop();}

void AudioPlayer::playBuffer( QByteArray data)
{
	if( this->audio_player)
	{
        QByteArray data_sp;

        for( int i = 0; i < data.size(); i += 4)
        {
            // big endian
            /*
            int sum = 0;
            qint16 val;
            for(int j = 0; j < 2; j += 2)
            {
                val = qint16( data[i + j + 1]  | ((data[i + j ] & 0xff) << 8));
                sum += val;
                sum += int(val);
            }

            qDebug() << sum;
            qint8 val_high = ((sum & (0xff00)) >> 8);
            qint8 val_low = sum & (0xff);

            if( sum < 0)
                val_high |= (0x80);

            data_sp.push_back( val_high);
            data_sp.push_back( val_low);
            data_sp.push_back( val_high);
            data_sp.push_back( val_low);
            */

            data_sp.push_back( data[i]);
            data_sp.push_back( data[i + 1]);
            data_sp.push_back( data[i]);
            data_sp.push_back( data[i + 1]);
        }

        this->audio_player->write( data_sp );
	}
}

void AudioPlayer::slot_playBuffer(QByteArray data)
{   this->playBuffer(data);}


void AudioPlayer::slot_setFormat(QAudioFormat audio_format)
{    this->setFormat(audio_format);}
