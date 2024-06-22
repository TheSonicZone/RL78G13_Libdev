# RL78G13_Libdev
## Development of Libraries for the Renesas RL78/G13 series MCU

## Introduction
The Renesas microcontrollers are really good silicon. Really good, made in JAPAN of course.
Unfortunately the dev tools are utterly rubbish. It also appears that Renesas changed their
tack on development tools somewhere in the mid 2010s so two different sets of incompatible
libraries and sample projects exist for this device. Moreover, the dev tools that are free
(E2 Studio) are based on a customized Eclipse IDE, with a newer version of a really old 
code generator (Appilet) smacked into it, like a square peg in a round hole.
The Appilet tool produces horrendous, unreadable code that has put many developers off this 
otherwise fine piece of silicon. And with user manuals written by non-English speakers, its
a rather hard sell.

This project is the development branch of modern, CLEAN libraries, and sample code for this
microcontroller family, in such a way that its easy to use by cloning the main project, and
additionally to provide proper, tested libraries for the hardware peripherals, of which the
RL78/G13 series has no shortage.

## Goals
* Clean code, easy-to-use, must be just "git clone" and import into E2 Studio and it compiles
* Must also be easy to migrate to Visual Studio[^1]
* Let's move away from that awful Appilet tool, NOW!
* Let's eventually get rid of Eclipse and the consequent eyestrain because it ain't got no dark mode

## Usage
Simply git-clone this repository to a directory, then, in E2 Studio, create (or select existing)
workspace, and then use the Import option to import this project. If all goes well it should
just work, if not, some tweaking might be required.

Please make sure you set up the E2 lite ICD properly in the IDE, also make sure you turn off optimizations
as the GNURL78 GCC compiler is an aggressive beast even in debug (and it f**king inlines variables in 
functions and you can't inspect them with GDB)

## License
This code is free software, under the terms of the GNU General Public license (3.0)

[^1]: Provided the Renesas GCC toolchain is installed correctly

