#include <stdio.h>

void should_licm(int a, int b, int c, int d, int e, int f) {
    for(int i=0; i<100; i++) {
        a = b + c;

        if (i < 50)
            e = 2;
        else
            e = 3;

        d = a + 1;
        f = e + 2;
    }
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    for(int i=0; i<100; i++) {
        a = b + c;

        if (i < 50)
            e = 2;
        else
            e = 3;

        d = a + 1;
        f = e + 2;
    }

    should_licm(9, 8, 7, 6, 5, 4);
}