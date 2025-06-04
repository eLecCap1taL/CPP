test_L=1
test_R=8

sample_pre=""
sample_in=".in"
sample_out=".ans"

WAstop=0

TimeLimit=1

# ----------------------------------------------

prog=$1

for((i=$test_L;i<=$test_R;i++))
do
    if timeout $TimeLimit ./prog < $sample_pre$prog$i$sample_in > $prog.out; then
        if ./checker $sample_pre$prog$i$sample_in $prog.out $sample_pre$prog$i$sample_out ; then
            echo OK accept testcase $i
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