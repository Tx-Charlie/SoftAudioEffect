#ifndef DEVICEOPTIONDIALOG_H
#define DEVICEOPTIONDIALOG_H

#include <QDialog>

#include <QAudioDeviceInfo>
#include <QAudioFormat>

namespace Ui {
class DeviceOptionDialog;
}

class DeviceOptionDialog : public QDialog
{
	Q_OBJECT

signals:
	void signal_deviceOption( QAudioDeviceInfo dev_info, QAudioFormat audio_fmt);

public:
	explicit DeviceOptionDialog(QWidget *parent = nullptr);
	~DeviceOptionDialog();

	void emitSettings();

private slots:
	void on_button_cancle_clicked();

	void on_button_apply_clicked();

	void on_button_ok_clicked();

private:
	Ui::DeviceOptionDialog *ui;
};

#endif // DEVICEOPTIONDIALOG_H
