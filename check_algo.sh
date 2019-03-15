YELLOW='\033[0;33m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# 			flow-one
printf "\n$GREEN==> flow-one <==$NC\n"

MAP=maps/gen_flow_one1.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 30\n"
time ./lem-in < $MAP | grep L | wc -l

MAP=maps/gen_flow_one2.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 30\n"
time ./lem-in < $MAP | grep L | wc -l

# 			flow-ten
printf "\n$GREEN==> flow-ten <==$NC\n"

MAP=maps/gen_flow_ten1.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 31\n"
time ./lem-in < $MAP | grep L | wc -l

MAP=maps/gen_flow_ten2.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 35\n"
time ./lem-in < $MAP | grep L | wc -l

# 			flow-thousand
printf "\n$GREEN==> flow-thousand <==$NC\n"

MAP=maps/gen_flow_thousand1.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 27\n"
time ./lem-in < $MAP | grep L | wc -l

MAP=maps/gen_flow_thousand2.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 31\n"
time ./lem-in < $MAP | grep L | wc -l

# 			big
printf "\n$GREEN==> big <==$NC\n"

MAP=maps/gen_big1.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 58\n"
time ./lem-in < $MAP | grep L | wc -l

MAP=maps/gen_big2.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 52\n"
time ./lem-in < $MAP | grep L | wc -l

# 			big-superposition
printf "\n$GREEN==> big-superposition <==$NC\n"

MAP=maps/gen_super1.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 77\n"
time ./lem-in < $MAP | grep L | wc -l

MAP=maps/gen_super2.map
printf "$YELLOW$MAP$NC\n"
printf "expect => 82\n"
time ./lem-in < $MAP | grep L | wc -l
