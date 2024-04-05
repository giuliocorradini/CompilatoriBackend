
%.bc: %.c
	clang -O0 -emit-llvm -c $^ -S -o $@

test: multiopt.bc
	opt -passes="localopts" multiopt.bc -S -o multiopt.optimized.bc

.PHONY: clean

clean:
	rm *.bc
