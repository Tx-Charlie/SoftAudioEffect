#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QThread>

#include "AudioDevice.h"
#include "AudioPlayer.h"
#include "AudioDeviceListWidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
Q_OBJECT
	public:
	explicit MainWindow( QWidget *parent = nullptr);
	~MainWindow();

	void init();

	void startDevice();
	void stopDevice();

private slots:
    void on_button_start_clicked();

	void slot_deviceOptionApply( QAudioDeviceInfo dev_info, QAudioFormat audio_fmt);

private:
        void connectSignalSlot();
        Ui::MainWindow *ui;

		bool flag_device_work_started;
		AudioDevice *audio_device;
		QThread *audio_device_thread;

		AudioPlayer *audio_player;
		QThread *audio_player_thread;

};

#endif
