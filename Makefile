all: signals1 signals2 signals3

signals1: signals1.c
    gcc -o sig1 signals1.c

signals2: signals2.c
    gcc -o sig2 signals2.c

signals3: signals3.c
    gcc -o sig3 signals3.c