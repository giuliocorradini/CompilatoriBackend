
test: Foo.bc
	opt -passes="localopts" Foo.bc -S -o Foo.optimized.bc
	# Run optimizer on localopts pass, defined by us

.PHONY: clean

clean:
	rm *.bc
