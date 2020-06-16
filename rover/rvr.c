#include <stdio.h>
#include <string.h>
#include "rvr.h"

int rvr_write(const char* path, char* data) {
    FILE* fptr = fopen(path, "w");
    if (!fptr) {
        perror("rvr_write:fopen");
        return -1;
    }

    int elementsWritten = (int) fwrite(data, 1, strlen(data), fptr);
    fclose(fptr);
    return elementsWritten;
}