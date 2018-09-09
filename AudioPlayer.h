#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioOutput>
#include <QIODevice>
#include <QAudioFormat>

class AudioPlayer : public QObject
{
	Q_OBJECT
		public:
			explicit AudioPlayer(QObject *parent = nullptr);
			~AudioPlayer();
			void setFormat( const QAudioFormat &audio_format);

			void startPlay();
			void stopPlay();

			void playBuffer( QByteArray data);

        public slots:
            void slot_setFormat( QAudioFormat audio_format);
            void slot_playBuffer( QByteArray data);

		private:
			QAudioOutput *audio_output;
			QIODevice *audio_player;
			QAudioFormat audio_format;
};

#endif
