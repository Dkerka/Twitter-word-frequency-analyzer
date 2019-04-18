makefile:
build:
	g++ -o map map.cc | g++ -o reduce reduce.cc
clean:
	-rm *.out map reduce
