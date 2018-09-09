# Introduce
This is a simple software for playing sound from plugin-dev with Qt.
Aim at build a small Guitar Effect.

# Progress: Unfinished
	So it is hard to use >_<

# Build:
	1. prepare:
		install Qt5.9 from https://download.qt.io:

	2. build: (with qmake)
		$qmake
		$make -j${proc}
		./SoftAudioEffect

# Use:
	#1 Play Electric Guitar:
		First, plug-in your E-Guitar to your PC.(on Line-in Port)
		Then, select device (for example: "plughw:CARD=intel,DEV=0")
		click "Start":

# Trouble Shooting:
	# No sound:
		setup sample size to 16 , rate to 44100 and set ChannelCount to 2
