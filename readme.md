# Volume Rolldown

This is a command line program that gradually reduces the volume of an Alsa sound output device at regular intervals. It can be used as a sleep timer.

By default it will reduce the volume 2% every five minutes. There is no support for command line arguments at this time.

## Compiling Command Line

1. Install libasound2-dev

    `# apt-get install libasound2-dev`

    Or your your distribution's equivalent.

2. Compile program

    `$ make`

That should pretty much do it. Run it by invoking the created executable.

`$ ./rolldown`

## Compiling GUI (Coming soon)

1. Install libasound2-dev
	
	`# apt-get install libasound2-dev`
	
	Or your distribution's equivalent

2. Install WxWidgets

	This resource may be helpful: [https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries]
	
	`# apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc`
	`# apt-add-repository 'deb http://repos.codelite.org/wx3.0.4/ubuntu/ artful universe'`	
	`# apt-get install libwxbase3.0-0-unofficial libwxbase3.0-dev libwxgtk3.0-0-unofficial libwxgtk3.0-dev wx3.0-headers wx-common`

3. Compile program

	`$ make gui`
	
Should be done. Run it with the following:

`$ ./rolldown-gui`
