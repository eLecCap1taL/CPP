test_L=1
test_R=5

sample_pre=""
sample_in=".in"
sample_out=".ans"

WAstop=0

TimeLimit=1

# ----------------------------------------------

prog=$1

ACNUM=0

for((i=$test_L;i<=$test_R;i++))
do
    if timeout $TimeLimit ./prog < $sample_pre$prog$i$sample_in > $prog.out; then
        if diff $prog.out $sample_pre$prog$i$sample_out -Z > /dev/null; then
            echo OK accept testcase $i
            ACNUM=`expr $ACNUM + 1`
        else
            echo Check failed testcase $i
            if [ $WAstop -eq 1 ]; then
                break
            fi
        fi
    else
        echo TLE on testcase $i
    fi
done

echo
echo Accept $ACNUM/`expr $test_R - $test_L + 1 `