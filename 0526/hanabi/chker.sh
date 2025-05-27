g++ hanabi.cpp -o a -std=c++17 -O2 -DONLINE_JUDGE
echo 1
# g++ bl.cpp -o std -std=c++17 -O2 -DONLINE_JUDGE
# echo 2
g++ gen.cpp -o gen -std=c++17 -O2 -DONLINE_JUDGE
echo 3

while true ;do
    ./gen > a.in
    ./std < a.in > a.ans
    ./a < a.in > a.out
    if diff a.out a.ans -Z; then
        echo ok accept
    else
        echo bad
        break
    fi
done