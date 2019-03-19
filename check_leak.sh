YELLOW='\033[0;33m'
NC='\033[0m' # No Color

MAP=1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=hard1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=gen_flow_one1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=gen_flow_ten1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=gen_flow_thousand1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=gen_big1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost