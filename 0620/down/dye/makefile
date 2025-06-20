all: prog.exe gen.exe std.exe

NAME = dye

prog.exe: $(NAME).cpp
	g++ $(NAME).cpp -o prog -std=c++14 -O2 -lm -DCPEDITOR
	
gen.exe: gen.cpp
	g++ gen.cpp -o gen -std=c++14 -O2 -lm -DCPEDITOR

std.exe: std.cpp
	g++ std.cpp -o std -std=c++14 -O2 -lm -DCPEDITOR

runstd: std.exe
	./std < a.in

run: prog.exe
	./prog < a.in

chksample: prog.exe
	bash chksample.sh $(NAME)

dp: all
	bash dp.sh
