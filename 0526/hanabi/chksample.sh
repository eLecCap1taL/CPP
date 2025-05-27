g++ hanabi.cpp -o hanabi -std=c++17 -O2 -DONLINE_JUDGE
echo 1

./hanabi < ex_binding1.in > hanabi.out
diff hanabi.out ex_binding1.out -Z
./hanabi < ex_binding2.in > hanabi.out
diff hanabi.out ex_binding2.out -Z
./hanabi < ex_binding3.in > hanabi.out
diff hanabi.out ex_binding3.out -Z
./hanabi < ex_binding4.in > hanabi.out
diff hanabi.out ex_binding4.out -Z

./hanabi < sample1.in > hanabi.out
diff hanabi.out sample1.ans -Z

./hanabi < sample2.in > hanabi.out
diff hanabi.out sample2.ans -Z