.PRECIOUS: %.bc

%.bc: %.c
	clang -O0 -disable-O0-optnone -emit-llvm -c $^ -S -o $@

test-%: %.bc
	opt -passes="localopts" $*.bc -S -o $*.optimized.bc


.PHONY: clean compare

# Compare optimized and unoptimized bitcode
compare-%:
	diff --side-by-side $*.bc $*.optimized.bc

clean:
	rm *.bc
