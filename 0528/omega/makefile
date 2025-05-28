all: prog gen std

NAME = omega

prog: $(NAME).cpp
	g++ $(NAME).cpp -o prog -std=c++14 -O2 -lm -DONLINE_JUDGE
	
gen: gen.cpp
	g++ gen.cpp -o gen -std=c++14 -O2 -lm -DONLINE_JUDGE

std: std.cpp
	g++ std.cpp -o std -std=c++14 -O2 -lm -DONLINE_JUDGE

chk: all
	bash dp.sh

runstd: std
	./std < a.in

runprog: prog
	./prog < a.in

chksample: prog
	bash chk.sh