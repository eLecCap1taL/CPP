test_L=1
test_R=2

sample_pre=""
sample_in=".in"
sample_out=".ans"

WAstop=0

TimeLimit=5

# ----------------------------------------------

prog=$1

ACNUM=0

for((i=$test_L;i<=$test_R;i++))
do
    timeout $TimeLimit ./prog < $sample_pre$prog$i$sample_in
done

echo
echo Accept $ACNUM/`expr $test_R - $test_L + 1 `