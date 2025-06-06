for ((i=1;i<=1000;i++))
do
    ./gen > a.in
    if ./prog < a.in > a.out;then
        echo test done
    else
        break
    fi
    ./std < a.in > a.ans
    if diff a.out a.ans -Z > /dev/null;then
        echo ok accept $i
    else
        break
    fi
done