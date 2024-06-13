%.bc: %.c
	$(CC) -c -O0 -S -emit-llvm -o $@ $<
	sed 's/optnone//g' $@ > opt-$@

test: Loop.bc
	opt -passes="mem2reg" opt-Loop.bc -S > opt-m2r-Loop.bc
	opt -passes="my-loop-fusion" opt-m2r-Loop.bc -S > /dev/null


%-cfg: %.bc
	opt -passes="mem2reg" opt-$< -S -o mr2-opt-$<
	opt -passes="dot-cfg" m2r-opt-$< > /dev/null
	

.PHONY: clean cleanall print-cfg

%.dot:
	echo

THIS = .
open-dots: .*.dot
	for graph in $^; do dot -Tsvg $${graph} > $${graph}.svg; open -a Safari $${graph}.svg; done

clean:
	rm *.bc

cleanall:
	rm *.bc .*.dot .svg
