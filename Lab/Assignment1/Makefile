
%.bc: %.c
	clang -O0 -emit-llvm -c $^ -S -o $@

test: multiopt.bc
	opt -passes="localopts" multiopt.bc -S -o multiopt.optimized.bc

test-anto: anto.bc
	opt -passes="localopts" anto.bc -S -o anto.optimized.bc

test-algebraic: algebraic.bc
	opt -passes="localopts" algebraic.bc -S -o algebraic.optimized.bc

test-manu: manu.bc
	opt -passes="localopts" manu.bc -S -o manu.optimized.bc

.PHONY: clean

clean:
	rm *.bc
