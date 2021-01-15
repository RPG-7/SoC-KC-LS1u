all: 74181 *.tv
	vvp 74181

74181: tb.v 74181.v
	iverilog -o $@ $?

*.tv:
	python tv_gen.py

clean:
	rm 74181 74181.tv