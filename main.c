#include <stdio.h>
#include <string.h>

int list[10000];
int ptr = 0;
// list[ptr] is the content on the index the user is currently in.

int main(int argc, char *argv[]) {
    for(int pos = 0; pos < sizeof(list); pos++) {
        list[pos] = 0;
    }
    #pragma region terminalcommands
    if(argc == 1) {
        printf("ERROR: too many few arguments");
        return 1;
    }
    else if(argc == 2) {
        if(!strcmp(argv[1], "shell")) {
            char text[50];
            while(1 == 1) {
                printf("brainfuck > ");
                scanf("%s", &text);
                printf(interpreter(text));
            };
        }
        else {
            printf("ERROR: unknown option");
        };
    };
    #pragma endregion terminalcommands
    return 0;
}

int interpreter(char text[]) {
    if(!strcmp(text, "quit")) {
        printf("quiting program...");
        return -1;
    };
    for(int i = 0; i < sizeof(strlen(text)); i++) {
        if(text[i] == '+') {
            list[ptr]++;
        }
    }
    return list[ptr];
};