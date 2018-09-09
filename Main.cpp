//TODO: Simple Beamforming by QAudioInput/Ouput(Sum and Delay)
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    app.setOrganizationName("yTexas");
    app.setApplicationName("SimpleAudio");

	MainWindow w;
	w.show();

	return app.exec();
}
