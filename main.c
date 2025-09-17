#include <stdlib.h>
#include <stdio.h>

void function_text(){

};
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    static int variable_DATA = 13;
    static int variable_BSS=0;
    char* variable_STR = "je suis un message bienveillant";

    int* variable_heap = malloc(sizeof(int));
    *variable_heap = 53;
    void* variable_mmap = mmap(NULL, 1000, 2, 0x02, 0, 0);
    printf("%p \n", (void*)&variable_DATA);
    printf("%p \n", (void*)&variable_BSS);
    printf("%p \n", (void*)variable_STR);
    printf("%p \n", (void*)variable_heap);
    printf("%p \n", (void*)function_text);
    printf("%p \n", (void*)mmap);
    }


    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.

