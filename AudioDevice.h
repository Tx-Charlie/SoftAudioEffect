#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QAudioInput>
#include <QObject>

class AudioDevice : public QObject
{
	Q_OBJECT
		public:
			explicit AudioDevice( QObject *parent = nullptr);
			~AudioDevice();

			void setFormat( const QAudioFormat &audio_format);
			void setDeviceInfo( QAudioDeviceInfo dev_info);

		public slots:
			void start();
			void stop();
            void slot_setDeviceInfo( QAudioDeviceInfo dev_info);
            void slot_setFormat( QAudioFormat audio_format);

			void slot_receiveAudioData();

		signals:
			void signal_audioData( QByteArray data);

		private:
			void checkFormat();	//

			QAudioFormat audio_format;
			QAudioDeviceInfo device_info;

			QAudioInput *audio_input;
			QIODevice *audio_input_io;
};

#endif
