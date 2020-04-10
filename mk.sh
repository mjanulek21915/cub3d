FILE=$1
if [ -z "$FILE" ]
then
    FILE=main
fi
gcc -g lib/*.c src/*.c db/*.c main/$FILE.c -I include -I /usr/include/X11 -I /usr/include/xorg -I db -lXext -lX11
