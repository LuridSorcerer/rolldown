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
