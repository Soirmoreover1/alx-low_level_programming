echo -e '#include <time.h>\nunsigned int time(unsigned int *t) { return 12345; }' > time.c
gcc -shared time.c -o time.so
export LD_PRELOAD=$PWD/time.so
