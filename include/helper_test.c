#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main() {
    char* filename = "helper.h";

    //printf("%lu\n", &buffer);
    char* buffer = from_source(filename);
    //printf("%lu\n", &buffer);
    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
