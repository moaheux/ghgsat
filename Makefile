#
# **************************************************************
# *                Simple C++ Makefile Template                *
# *                                                            *
# * Author: Arash Partow (2003)                                *
# * URL: http://www.partow.net/programming/makefile/index.html *
# *                                                            *
# * Copyright notice:                                          *
# * Free use of this C++ Makefile template is permitted under  *
# * the guidelines and in accordance with the the MIT License  *
# * http://www.opensource.org/licenses/MIT                     *
# *                                                            *
# **************************************************************
#
native: CXX=g++
native:
	$(CXX) -o ghgsat_native $(wildcard src/*.cpp)

cross: CXX=arm-linux-gnueabihf-g++
cross:
	$(CXX) $(wildcard src/*.cpp) -o ghgsat_cross -static
