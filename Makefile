all: libstrbuffer day0hello day1datatypes day2operators day3conditionals day5loops day6review day7arrays

libstrbuffer: src/lib/strbuffer.c
	mkdir -p .build/lib/
	gcc -Wall -o .build/lib/strbuffer.o -c src/lib/strbuffer.c -I src/lib/.
	ar rcs .build/lib/libstrbuffer.a .build/lib/strbuffer.o

day0hello: src/day0hello.c
	mkdir -p .build/
	gcc -o .build/day0hello src/day0hello.c -I src/.

day1datatypes: src/day1datatypes.c
	mkdir -p .build/
	gcc -o .build/day1datatypes src/day1datatypes.c -I src/.

day2operators: src/day2operators.c
	mkdir -p .build/
	gcc -o .build/day2operators src/day2operators.c -I src/.

day3conditionals: src/day3conditionals.c
	mkdir -p .build/
	gcc -o .build/day3conditionals src/day3conditionals.c -I src/.

day5loops: src/day5loops.c
	mkdir -p .build/
	gcc -o .build/day5loops src/day5loops.c -I src/.

day6review: src/day6review.c
	mkdir -p .build/
	gcc -Wall -o .build/day6review src/day6review.c -I src/. -I src/lib/. -L .build/lib/ -lstrbuffer

day7arrays: src/day7arrays.c
	mkdir -p .build/
	gcc -Wall -o .build/day7arrays src/day7arrays.c -I src/. -lm

random9bdaycake: src/random9bdaycake.c
	mkdir -p .build/
	gcc -o .build/random9bdaycake src/random9bdaycake.c -I src/.
