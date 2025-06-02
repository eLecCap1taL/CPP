for ((i=1;i<=1000;i++))
do
    ./gen > a.in
    ./prog < a.in > a.out
    ./std < a.in > a.ans
    if diff a.out a.ans -Z > /dev/null;then
        echo ok accept $i
    else
        break
    fi
done