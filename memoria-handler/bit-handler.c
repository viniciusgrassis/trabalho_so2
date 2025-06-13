#include "./bit-handler.h"


int hex_int(const char *hex){
    return (int)strtol(hex, NULL, 16);
}