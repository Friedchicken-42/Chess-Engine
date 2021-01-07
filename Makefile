all:
	gcc -Isrc -o main.exe ./main.c src/*.c

dll:
	gcc -shared -Isrc -o ./.dynamic_ruleset/$(name).dll ./ruleset/$(name).c ./src/engine.c
