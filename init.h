#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <bits/wordsize.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void (*WData)(FILE *, void *, int);

typedef void *(*RData)(FILE *, void *, int);

typedef bool (*Cmp)(void *, void *);

typedef void *(*Ft)(void *, ...);

#define AllocateMemory 1024
#define ListBinaryLength 4
#define ListLength 16

#if  __WORDSIZE == 64
#define PointerSize 3
#define DataSizeType long
#elif __WORDSIZE == 32
#define PointerSize 2
#define DataSizeType long
#elif __WORDSIZE == 16
#define PointerSize 1
#define DataSizeType int
#endif

void SetWData(WData wd);

void SetRData(RData rd);

void PlaintextWrite(FILE *fp, void *v, int l);

void *PlaintextRead(FILE *fp, void *v, int l);

bool mcmp(void *a, void *b);

bool scmpm(void *a, void *b);

bool mcmpm(void *a, void *b);

bool scmp(void *a, void *b);

static WData WriteData = PlaintextWrite;
static RData ReadData = PlaintextRead;
static Cmp CompareData = scmp;

#endif
