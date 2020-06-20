#include <stdio.h>
#include <string.h>
#include "rvr.h"

const size_t MAX_BYTES = 8;
const size_t MAX_PATH_BYTES = 64;
const char* const ROOT_COMPONENT_DIR = "sys/class";

int rvrWrite(const char* path, char* data) {
    FILE* fptr = fopen(path, "w");
    if (!fptr) {
        perror("rvr_write:fopen");
        return -1;
    }

    int elementsWritten = (int) fwrite(data, 1, strlen(data), fptr);
    fclose(fptr);
    return elementsWritten;
}

int rvrWriteUInt(const char* path, size_t val) {
    char strVal[MAX_BYTES];
    int elementsWritten = sprintf(strVal, "%zu", val);
    if (elementsWritten < 1) {
        perror("rvr_write_uint:sprintf");
        return -1;
    }

    return rvrWrite(path, strVal); 
}