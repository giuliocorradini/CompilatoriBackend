#include <stdio.h>
int main() {
    for(int i=0; i<10; i++) {
        while(1)
            printf("Hello");
        /*if(i % 7 == 0)
            continue;

        else if (i % 6 == 2) {
            goto exit;
        }*/
    }

    int c = 89;
exit:
    c = c / 8;
}