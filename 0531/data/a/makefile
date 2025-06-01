all: prog gen std

NAME = a

prog: $(NAME).cpp
	g++ $(NAME).cpp -o prog -std=c++14 -O2 -lm -DONLINE_JUDGE
	
gen: gen.cpp
	g++ gen.cpp -o gen -std=c++14 -O2 -lm -DONLINE_JUDGE

std: std.cpp
	g++ std.cpp -o std -std=c++14 -O2 -lm -DONLINE_JUDGE

runstd: std
	./std < a.in

run: prog
	./prog < a.in

chksample: prog
	bash chksample.sh $(NAME)

dp: all
	bash dp.sh
