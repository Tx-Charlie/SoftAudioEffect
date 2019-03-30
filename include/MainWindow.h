#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
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

private slots:
    void on_button_start_clicked();

private:
        void connectSignalSlot();
        Ui::MainWindow *ui;

		AudioDevice *audio_device;
		AudioPlayer *audio_player;
};

#endif
