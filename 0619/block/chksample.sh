test_L=1
test_R=5

sample_pre=""
sample_in=".in"
sample_out=".out"

WAstop=0

TimeLimit=5000

# ----------------------------------------------

prog=$1

ACNUM=0

for((i=$test_L;i<=$test_R;i++))
do
    if timeout $TimeLimit ./prog < $sample_pre$prog$i$sample_in > $sample_pre$prog$i$sample_out; then
        echo ok
    else
        echo TLE on testcase $i
    fi
done

echo
echo Accept $ACNUM/`expr $test_R - $test_L + 1 `