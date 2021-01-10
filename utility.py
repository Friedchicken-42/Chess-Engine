import os
import sys

if len(sys.argv) == 1:
    os.system('gcc -g -Isrc -o main.exe ./main.c ./src/*.c')
elif sys.argv[1] == 'dll':
    if len(sys.argv) == 3:
        if '.dynamic_ruleset' not in os.listdir('.'):
            os.mkdir('.dynamic_ruleset')
        item = sys.argv[2]
        os.system(
            f'gcc -shared -Isrc -o ./.dynamic_ruleset/{item}.dll ./ruleset/{item}.c ./src/engine.c')
    else:
        print('Missing name')
elif sys.argv[1] == 'dlls':
    if 'ruleset' in os.listdir('.'):
        if '.dynamic_ruleset' not in os.listdir('.'):
            os.mkdir('.dynamic_ruleset')
        for item in os.listdir('ruleset'):
            if item != 'template.c':
                item = item[:-2]
                os.system(
                    f'gcc -shared -Isrc -o ./.dynamic_ruleset/{item}.dll ./ruleset/{item}.c ./src/engine.c')
    else:
        print('Missing ruleset')
else:
    print('Error')
