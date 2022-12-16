# Toledo Nanochess on BBC micro:bit

## Introduction
Some years ago I had the idea of implementing a chess program on the BBC micro:bit (https://microbit.org) since 
this little device has already a built-in 5x5 LED matrix and two buttons for user inputs. After some research I found
the wonderful implementation of Oscar Toledo's Nanochess (https://nanochess.org/chess3.html). I was completely
fascinated of this little program. The time has come and I ported this awesome chess program. This is probably now one of the smallest chess computers in the world.

I used https://nanochess.org/toledo_nanochess.c as a starting point and Arduino IDE 2.0.3 (see https://www.arduino.cc/en/software) with the installed "Adafruit MicroBit library" (see https://github.com/adafruit/Adafruit_Microbit).

Arduino IDE has some problems with the tricky preprocessor defines, so I sent the file through ``gcc`` with the ``-E`` option.
After playing around with the tiny program and redirecting the Standard-I/O to the serial interface I decided to write 
a simple user interface for being completely independent.

## Demo
You can find a demo of the program at https://www.youtube.com/watch?v=Vc_DAjjW53I.

## Upload to the BBC micro:bit
The "one minute solution" for uploading the executable binary to the micro:bit is to drag and drop the file ``microbit-nanochess.hex`` to the micro:bit. The hex file was retrieved with the *uBitTool* from https://github.com/carlosperate/ubittool/releases. Since I don't own a micro:bit v2 I can't promise whether this method works there. If you want to do further development you have to install the Arduino IDE (https://www.arduino.cc/en/software) and micro:bit libraries from *adafruit*, documented at https://learn.adafruit.com/use-micro-bit-with-arduino. Just open the ``microbit_nanochess.ino``file and push the ``Upload`` Button.

## Usage
After starting, the user is welcomed with ``Nanochess`` followed by the color whose turn it is. A ``>`` appears, which means that you can skip the move input and let the micro:bit calculate the move. 

With the A-button you can select the desired letter or number whereas with the B-button you will confirm your selection. 

After entering your first move (eg. ``C2C4``) a ``>``appears again, which should be confirmed. Selecting a letter in this step (either ``N``, ``Q``, ``R``or ``B``) is just for the case of a promotion indicating the desired figure. 

Now the micro:bit confirms the move and repeats the procedure with the other color. So it's quite easy to switch to the other color. 

## Credits
* To Oscar Toledo (https://nanochess.org/author.html) for his awesome little chess program and for his detailed book at https://nanochess.org/chess3.html#book.
* To adafruit (https://www.adafruit.com) for the well documented micro:bit library.
* To BBC R&D (https://www.bbc.co.uk/rd) and other companies for developing this nice little device.

