#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

char* hex_string_to_bin(const char *hex_string) {
    size_t i, len = strlen(hex_string) / 2;
    char *ret = (char*)malloc(len);
    for(i = 0; i < len; i++) {
        sscanf(hex_string + i * 2, "%2hhx", &ret[i]);
    }
    return ret;
}
