#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, world!";
    char destination[20];

    printf("Source string: %s\n", source);


    memcpy(destination, source, strlen(source) + 1); //добавяме 1 за да включим \0 (NULL)

    //The memcpy function takes three arguments: a pointer to the destination block of memory,
    // a pointer to the source block of memory, and the number of bytes to copy from the source to the destination.

    printf("Copied string: %s\n", destination);

    return 0;
}
