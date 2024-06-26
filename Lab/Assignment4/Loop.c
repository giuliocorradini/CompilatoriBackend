void loops(int *a, int *b, int *c, int *d) {
    int TRIPS = 100;
    for (int i=0; i<TRIPS; i++)
        a[i] = b[i] * c[i];

    for (int i=0; i<TRIPS; i++)
        d[i] = a[i-1] + c[i];
}
