void algebraic_identity(int a, int b) {
    //  Add 0
    int c = a + 0;
    c = 0 + a;

    //  Add 1
    int d = a + 1;
    d = 1 + a;

    //  Add together
    int e = a + b;

    //  Multiply by 0
    int f = b * 0;
    f = 0 * b;

    //  These are constant folded by the frontend
    f = 0 * 1;
    f = 1 * 0;
    f = 0 * 2;
    f = 2 * 0;

    //  Multiply by 1
    int g = b * 1;
    g = 1 * b;

    //  Multiply together
    int h = a * b;
}