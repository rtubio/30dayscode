all: day0hello day1datatypes day2operators day3conditionals

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

random9bdaycake: src/random9bdaycake.c
	mkdir -p .build/
	gcc -o .build/random9bdaycake src/random9bdaycake.c -I src/.
