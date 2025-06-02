all: prog gen std

NAME = memory

prog: $(NAME).cpp grader.cpp
	g++ $(NAME).cpp grader.cpp -o prog -std=c++14 -O2 -lm -DONLINE_JUDGE
	
gen: gen.cpp
	g++ gen.cpp -o gen -std=c++14 -O2 -lm -DONLINE_JUDGE

std: std.cpp
	g++ std.cpp grader.cpp -o std -std=c++14 -O2 -lm -DONLINE_JUDGE

runstd: std
	./std < .in

run: prog
	./prog

chksample: prog
	bash chksample.sh $(NAME)

dp: all
	bash dp.sh
