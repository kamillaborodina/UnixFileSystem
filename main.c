#include <stdio.h>
#include "system.h"
#include "command_ex.h"

int main(int argc, char **argv) {
    SYSTEM *s = system_init();
    while (1){
        char input[255];
        pwd(s);
        gets(input);
        execute_command(s, input);
        if (strcmp(input, "quit")==0) break;
    }
}