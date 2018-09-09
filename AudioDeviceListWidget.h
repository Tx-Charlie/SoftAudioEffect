#ifndef AUDIODEVICELISTWIDGET_H
#define AUDIODEVICELISTWIDGET_H

#include <QWidget>
#include <QList>
#include <QAudioDeviceInfo>
#include <QAudioFormat>

typedef QList<QAudioDeviceInfo> AudioDeviceList;

namespace  Ui {
class AudioDeviceListWidget;
}

class AudioDeviceListWidget : public QWidget
{
	Q_OBJECT
    signals:
        void signal_audioDeviceInfo( QAudioDeviceInfo dev_info);
	public:
		explicit AudioDeviceListWidget( QWidget *parent = NULL);
		~AudioDeviceListWidget();

		void initDeviceList();

		QAudioDeviceInfo getInputAudioDeviceInfo( const int &index);
        QAudioDeviceInfo getCurrentDeviceInfo();

private slots:
        void on_combo_devlist_currentIndexChanged(int index);

private:
        Ui::AudioDeviceListWidget *ui;
        AudioDeviceList *audio_dev_list; //audio device list
};

#endif
