
%.bc: %.c
	clang -O2 -emit-llvm -c $^ -S -o $@

test: Loop.bc
	opt -passes='testpass' Loop.bc -S 1> /dev/null

.PHONY: clean

clean:
	rm *.bc