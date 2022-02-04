#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include "Init.h"

char *StringFuzzyCmp(const char *a, const char *b) {
    register char *s1, *s2;
    while (*a) {
        s1 = (char *) a;
        s2 = (char *) b;
        while (!(*s1 - *s2) && *s2) {
            s1++;
            s2++;
        }
        if (!*s2) {
            return (char *) a;
        }
        a++;
    }
    return NULL;
}

DataSizeType FileSize(char *fi) {
    struct stat f;
    stat(fi, &f);
    return f.st_size;
}
