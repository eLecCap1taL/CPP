g++ hoshino.cpp -o hoshino -std=c++17 -O2 -DONLINE_JUDGE
echo 1


./hoshino < sample1.in > hoshino.out
diff hoshino.out sample1.ans -Z
echo 1

./hoshino < sample2.in > hoshino.out
diff hoshino.out sample2.ans -Z
echo 2

./hoshino < sample3.in > hoshino.out
diff hoshino.out sample3.ans -Z
echo 3