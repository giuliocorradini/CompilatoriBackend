%.bc: %.c
	$(CC) -c -O0 -S -emit-llvm -o $@ $<
	sed 's/optnone//g' $@ > opt-$@

test: Loop.bc
	opt -passes="mem2reg,licmy" opt-Loop.bc -S 1> /dev/null

prof: licm.bc
	opt -passes="mem2reg,licmy" opt-licm.bc -S 1> /dev/null

%-cfg: %.bc
	opt -passes="dot-cfg" opt-$<
	open-dots
	

.PHONY: clean cleanall print-cfg

THIS = .
open-dots: $(MYDIR)/*.dot
	for graph in $^; do dot -Tsvg $${graph} > $${graph}.svg; open -a Safari $${graph}.svg; done

clean:
	rm *.bc

cleanall:
	rm *.bc .*.dot .svg
