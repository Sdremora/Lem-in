YELLOW='\033[0;33m'
NC='\033[0m' # No Color

MAP=inv_duplicate_rooms.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_duplicate_rooms.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_links.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_no_ants1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_no_end.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_input_in_room1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_no_rooms.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_no_path1.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

MAP=inv_no_path2.map
printf "\n\t$YELLOW$MAP$NC\n"
valgrind ./lem-in < maps/$MAP 2>&1 | grep lost

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