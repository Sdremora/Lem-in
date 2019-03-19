# sh check_algo.sh --flow-one
# sh check_algo.sh --flow-ten
# sh check_algo.sh --flow-thousand
# sh check_algo.sh --big
# sh check_algo.sh --big-superposition

OUT=$(time ./maps/generator $1 | ./lem-in)
echo "$OUT" | grep "#Here is the number of lines required:" | head -n1
echo "$OUT" | grep L | wc -l