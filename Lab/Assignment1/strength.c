void strength_reduction(int a, int b) {
    int f, g, h, i;

    f = a * 2;
    f = a * 4;
    f = a * 8;
    f = a * 16;
    f = a * 32;
    //...

    g = a * 1;  // Should not be optimized
    g = a * 3;
    g = a * 7;
    g = a * 15;
    g = a * 31;

    h = a * 5;
    h = a * 9;
    h = a * 17;
    h = a * 33;
}

void reverse_expression_strength_reduction(int a) {
    int f, g, h, i;

    f = 2 * a;
    f = 4 * a;
    f = 8 * a;
    f = 16 * a;
    f = 32 * a;

    g = 1 * a;
    g = 3 * a;
    g = 7 * a;
    g = 15 * a;
    g = 31 * a;
    
    h = 5 * a;
    h = 9 * a;
    h = 17 * a;
    h = 33 * a;
}