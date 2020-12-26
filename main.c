#include <stdio.h>
#include <string.h>

int interpreter(char text[]);

int list[10000];
int ptr = 0;

int main(int argc, char *argv[]) {
    for(int pos = 0; pos < sizeof(list); pos++) {
        list[pos] = 0;
    }
    if(argc <= 1) {
        printf("ERROR: too many few arguments");
        return 1;
    }
    else if(argc == 2) {
        if(!strcmp(argv[1], "shell")) {
            char text[50];
            while(1 == 1) {
                printf("brainfuck > ");
                scanf("%s", &text);
                int result = interpreter(text);
                printf("%i", result);
            };
        }
        else {
            printf("ERROR: unknown option");
        };
    };
    return 0;
}

int interpreter(char text[]) {
    if(!strcmp(text, "quit")) {
        printf("quiting program...");
        return 1;
    };
    for(int i = 0; i < sizeof(strlen(text)); i++) {
        if(text[i] == '+') {
            list[ptr]++;
            return list[ptr];
        }
        if(text[i] == '-') {
            list[ptr]--;
            return list[ptr];
        }
        if(text[i] == '>') {
            ptr += 1; 
            return list[ptr];
        }
        if(text[i] == '<') {
            ptr -= 1;
            return list[ptr];
        }
        if(text[i] == ',') {
            char ch;
            printf("type a char: ");
            scanf("%c", ch);
            list[ptr] += (int)ch;
            return list[ptr];
        }
        if(text[i] == '.') {
            printf("%i", list[ptr]);
            return list[ptr];
        }
    }
};