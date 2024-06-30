extern void *callback();

void L1_guarded(int guard) {
    if (guard) {
        for (int i=0; i<100; i++) {
            callback();
        }
    }

    for (int i=0; i<100; i++) {
        callback();
    }
}

void L2_guarded(int guard) {
    for (int i=0; i<100; i++) {
        callback();
    }

    if (guard) {
        for (int i=0; i<100; i++) {
            callback();
        }
    }
}

void both_guarded(int guard) {
    if (guard) {
        for (int i=0; i<100; i++) {
            callback();
        }
    }

    if (guard) {
        for (int i=0; i<100; i++) {
            callback();
        }
    }
}
