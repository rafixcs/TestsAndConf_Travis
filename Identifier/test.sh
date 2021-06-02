cppcheck --enable=all identifier.c
gcc -g -Wall -Wfatal-errors -fsanitize=address identifier.c -o identifier
valgrind --leak-check=full --show-leak-kinds=all ./identifier
make clean
make