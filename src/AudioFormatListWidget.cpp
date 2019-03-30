#include "AudioFormatListWidget.h"
#include "ui_AudioFormatListWidget.h"

AudioFormatListWidget::AudioFormatListWidget( QWidget *parent ) : QWidget (parent),
    ui(new Ui::AudioFormatListWidget)
{
    ui->setupUi( this);
}

AudioFormatListWidget::~AudioFormatListWidget()
{
    delete this->ui;
}

QAudioFormat AudioFormatListWidget::getAudioFormat()
{
    this->applyFormat();
    return this->audio_format;
}

void AudioFormatListWidget::on_button_apply_clicked()
{
    this->applyFormat();
    emit signal_audioFormat( this->audio_format );
}


void AudioFormatListWidget::applyFormat()
{
    this->audio_format.setSampleRate( this->ui->line_sampleRate->text().toInt() );
    this->audio_format.setSampleSize( this->ui->line_sampleSize->text().toInt() );
    this->audio_format.setChannelCount( this->ui->line_channelCount->text().toInt());

    if( this->ui->combo_sampleType->currentText() == "signed int")
        this->audio_format.setSampleType( QAudioFormat::SignedInt);
    else if( this->ui->combo_sampleType->currentText() == "unsigned int")
        this->audio_format.setSampleType( QAudioFormat::UnSignedInt);
    else
        this->audio_format.setSampleType( QAudioFormat::Float);
}
