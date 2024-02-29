#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := GameController.cpp GameView.cpp GameModel.cpp Command.cpp CommandHistory.cpp

# header files in this project
HEADERS := GameController.hpp GameView.hpp GameModel.hpp Command.hpp CommandHistory.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../

# compiler flags for the console version
CONSOLE_DEFINES := -D CONSOLE_VERSION

# compiler flags for the SFML version
SFML_DEFINES := -D SFML_VERSION

# output executable for the console version
CONSOLE_TARGET := main_console.exe

# output executable for the SFML version
SFML_TARGET := main_sfml.exe

include $(RELATIVE)Makefile.native

# rule to compile and link the console version
console:
	bmptk-make clean
	$(MAKE) -f Makefile.console
	


# rule to compile and link the SFML version
ui:
	bmptk-make clean
	$(MAKE) -f Makefile.sfml 
	


	
	