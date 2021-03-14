#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* print_path(void* name);
void* countElements(void* name);

int main() {
    char folder[50];
    pthread_t thread_one, thread_two;
    int pth1, pth2;

    printf("Type name of folder: ");
    scanf("%s", folder);

    system("touch path");

    char findpath[150] = "find ~ -type d -name ";
    strcat(findpath, folder);
    strcat(findpath, " > path");
    
    system(findpath);
    
    FILE* fptr;
    if ((fptr = fopen("path", "r")) == NULL) {
        printf("Error! opening file\n");

        exit(1);
    }
    char pathline[50];
    fscanf(fptr, "%[^\n]", pathline);


    pth1 = pthread_create(&thread_one, NULL, print_path, (void*)pathline);
    if (pth1) {
        exit(EXIT_FAILURE);
    }

    pth2 = pthread_create(&thread_two, NULL,countElements, (void*)pathline);
    if (pth2) {
        exit(EXIT_FAILURE);
    }

    pthread_join(thread_one, NULL);
    pthread_join(thread_two, NULL);

    exit(EXIT_SUCCESS);
}

void *print_path(void* name) {
    strcat((char*)name, "/* | tr ' ' '\n'");

    char command[50] = "ls -d ";
    strcat(command, name);
    system(command);
}

void* countElements(void* name) {
    char command[100] = "ls -1 ";

    strcat(command, (char*)name);
    strcat(command, " | wc -l");
    system(command);
}
