LUAHOME=$(HOME)/lua-5.3.0/src
all: exercise2
exercise2: exercise2.cpp
	g++ -g exercise2.cpp -llua -L$(LUAHOME) -I$(LUAHOME) -o exercise2
