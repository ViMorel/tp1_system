#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>


void function_text(){

};
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    static int variable_DATA = 13;
    static int variable_BSS=0;
    int variable_stack=6;
    char* variable_STR = "je suis un message bienveillant";

    int* variable_heap = malloc(sizeof(int));
    *variable_heap = 53;
    void* variable_mmap = mmap(NULL, 1000, 2, 0x02, 0, 0);

    printf("Adress DATA is %p \n", (void*)&variable_DATA);
    printf("Adress BSS is %p \n", (void*)&variable_BSS);
    printf("Adress STR is %p \n", (void*)variable_STR);
    printf("Adress HEAP is %p \n", (void*)variable_heap);
    printf("Adress MAIN FUNCTION is %p \n", (void*)function_text);
    printf("Adress LIBC is %p \n",(void*)printf);
    printf("Adress MMAP is %p \n", (void*)variable_mmap);
    printf("Adress STACK is %p \n", (void*)&variable_stack);

    pid_t pid = getpid();
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "pmap -X %d", pid);
    system(cmd);


    munmap(variable_mmap, 1000);
    free(variable_heap);

    return 0;
    }


    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.

