#include <stdio.h>
#include <string.h>
#include "rvr.h"

const size_t MAX_BYTES = 32;
const size_t MAX_PATH_BYTES = 64;
const char* const ROOT_COMPONENT_DIR = "sys/class";
const char* const PATH_FMT = "/%s/%s/%s";

enum rvrValueType {
    INTEGER,
    STRING
};

extern struct rvrvalue {
    enum rvrValueType type;
    union {
        int num;
        char str[MAX_BYTES];
    };
};

const char* const NUMBER_FORMAT = "%d\n";
const char* const STRING_FORMAT = "%s\n";

int rvrWrite(const char* path, const char* fmt, struct rvrvalue* val) {
    FILE* fptr = fopen(path, "w");
    if (!fptr) {
        perror("rvr_write:fopen");
        return -1;
    }

    int charsWritten = -1;
    if (val->type == INTEGER) {
        charsWritten = fprintf(fptr, fmt, val->num);
    } else {
        charsWritten = fprintf(fptr, fmt, val->str);
    }

    return charsWritten;
}

int rvrWriteInt(const char* path, int val) {
    char strVal[MAX_BYTES];
    struct rvrvalue rvrval = {
        .type = INTEGER,
        .num = val
    };

    return rvrWrite(path, NUMBER_FORMAT, &rvrval); 
}

int rvrWriteUInt(const char* path, size_t val) {
    char strVal[MAX_BYTES];
    return rvrWriteInt(path, val); 
}

