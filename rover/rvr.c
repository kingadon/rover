#include <stdio.h>
#include <string.h>
#include "rvr.h"

const size_t MAX_BYTES = 64;
const size_t MAX_PATH_BYTES = 128;
const int ERROR_VAL = -1;
const char* const ROOT_COMPONENT_DIR = "sys/class";
const char* const PATH_FMT = "%s/%s/%s";
const char* const NUMBER_FORMAT = "%d\n";
const char* const STRING_FORMAT = "%s\n";

int rvrWrite(const char* const path, const char* fmt, struct rvrvalue* val) {
    FILE* fptr = fopen(path, "w");
    if (!fptr) {
        perror("rvr_write:fopen");
        printf("error for path: %s\n", path);
        return ERROR_VAL;
    }

    int charsWritten = -1;
    if (val->type == INTEGER) {
        charsWritten = fprintf(fptr, fmt, val->num);
    } else {
        charsWritten = fprintf(fptr, fmt, val->str);
    }

    fclose(fptr);

    return charsWritten;
}

int rvrWriteStr(const char* const path, const char* const val) {
    struct rvrvalue rvrval = {
        .type = STRING,
        .str = val
    };

    return rvrWrite(path, STRING_FORMAT, &rvrval);
}

int rvrWriteInt(const char* const path, int val) {
    struct rvrvalue rvrval = {
        .type = INTEGER,
        .num = val
    };

    return rvrWrite(path, NUMBER_FORMAT, &rvrval); 
}

int rvrWriteUInt(const char* const path, size_t val) {
    return rvrWriteInt(path, val); 
}

