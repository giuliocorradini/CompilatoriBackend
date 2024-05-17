%.bc: %.c
	$(CC) -c -O0 -S -emit-llvm -o $@ $<

test: Loop.bc
	opt -passes="loopwalk" Loop.bc -S 1> /dev/null

.PHONY: clean

clean:
	rm *.bc
