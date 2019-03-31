#ifndef AUDIOFORMATLISTWIDGET_H
#define AUDIOFORMATLISTWIDGET_H

#include <QWidget>
#include <QAudioFormat>

namespace Ui
{
class AudioFormatListWidget;
}

class AudioFormatListWidget : public QWidget
{
	Q_OBJECT
public:
	explicit AudioFormatListWidget( QWidget *parent = nullptr);
	~AudioFormatListWidget();

	QAudioFormat getAudioFormat();
signals:
	void signal_audioFormat( QAudioFormat audio_format);

private slots:
	//void on_button_apply_clicked();

private:
	void applyFormat();

	Ui::AudioFormatListWidget *ui;
	QAudioFormat audio_format;
};

#endif
