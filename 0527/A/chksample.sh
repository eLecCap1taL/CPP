g++ lirililarila.cpp -o lirililarila -std=c++17 -O2 -DONLINE_JUDGE
echo 1

ulimit -s unlimited

./lirililarila < sample1.in > lirililarila.out
diff lirililarila.out sample1.ans -Z
echo 1 ok

./lirililarila < sample2.in > lirililarila.out
diff lirililarila.out sample2.ans -Z
echo 2 ok

./lirililarila < sample3.in > lirililarila.out
diff lirililarila.out sample3.ans -Z
echo 3 ok

./lirililarila < sample4.in > lirililarila.out
diff lirililarila.out sample4.ans -Z
echo 4 ok

./lirililarila < sample5.in > lirililarila.out
diff lirililarila.out sample5.ans -Z
echo 5 ok

./lirililarila < sample6.in > lirililarila.out
diff lirililarila.out sample6.ans -Z
echo 6 ok
