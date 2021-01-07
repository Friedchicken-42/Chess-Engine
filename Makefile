all: main.exe
	gcc -g -Isrc -o main.exe ./main.c src/*.c

dll: .dynamic_ruleset
	gcc -shared -Isrc -o ./.dynamic_ruleset/$(name).dll ./ruleset/$(name).c ./src/engine.c

.dynamic_ruleset:
	mkdir .dynamic_ruleset