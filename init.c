#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "init.h"
#include "mtmm.h"

void SetWData(WData wd) {
    WriteData = wd;
}

void SetRData(RData rd) {
    ReadData = rd;
}

void SetCData(Cmp cmp) {
    CompareData = cmp;
}

void PlaintextWrite(FILE *fp, void *v, int l) {
    fwrite(v, l, 1, fp);
}

void *PlaintextRead(FILE *fp, void *v, int l) {
    return fgets(v, l, fp);
}

bool scmp(void *a, void *b) {
    if (strcmp((char *) a, (char *) b) == 0) {
        return true;
    } else {
        return false;
    }
}

bool scmpm(void *a, void *b) {
    if (strstr(a, b) != NULL) {
        return true;
    } else {
        return false;
    }
}

bool mcmpm(void *a, void *b) {
    if (strstr(((MemoryInfo *) a)->m, ((MemoryInfo *) b)->m) != NULL) {
        return true;
    } else {
        return false;
    }
}

bool mcmp(void *a, void *b) {
    if (strcmp(((MemoryInfo *) a)->m, ((MemoryInfo *) b)->m) == 0) {
        return true;
    } else {
        return false;
    }
}