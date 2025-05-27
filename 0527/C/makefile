all: chk std
	
run: chk std
	./std < data1.in > data1.out
	./chk data1.in data1.out data1.ans

clean:
	rm -f data1.out std chk

std: std.cpp
	g++ std.cpp -O2 -o std
	
chk: chk.cpp
	g++ chk.cpp -O2 -o chk

