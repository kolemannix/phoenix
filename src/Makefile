# Koleman Nix
# 12/13/13
# Makefile (phoenix)
CXX	 	= clang++
CXXFLAGS 	= -O2 -std=c++11 -stdlib=libc++ -Wc++11-extensions
CXXDBGFLAGS	= -g -Wall
OFILES		= main.cpp bitboard.cpp position.cpp mailbox_util.cpp square.cpp

# Create a .o file from a .cpp file, using CXX and CXXFLAGS macros
.SUFFIXES: .o .cpp

main: 	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) -o phoenix	
	@echo "phoenix has been reborn"


debug: 	$(OFILES)
	$(CXX) $(CXXDBGFLAGS) $(OFILES)	-o phoenixdbg

clean: 	
	/bin/rm -rf *.o *.swp phoenixdbg.dSYM phoenix phoenixdbg
