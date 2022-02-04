#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <bits/wordsize.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <fcntl.h>

#if __WORDSIZE == 128
#define PointerSize 4
#define DataSizeType Haha128Baka
#define DataSizePlaceholder "%ld"
#elif  __WORDSIZE == 64
#define PointerSize 3
#define DataSizeType long
#define DataSizePlaceholder "%ld"
#elif __WORDSIZE == 32
#define PointerSize 2
#define DataSizeType long
#define DataSizePlaceholder "%ld"
#elif __WORDSIZE == 16
#define PointerSize 1
#define DataSizeType int
#define DataSizePlaceholder "%d"
#endif

#define AllocateMemory 1024
#define ListBinaryLength 4
#define ListLength 16
#define RowLimit 1024
#define MaximumFileSize 12582912
#define Haha128Baka long
#define DataDelimiter "\n"

#define DataLibraryReadOnlyFlag O_RDONLY
#define DataLibraryWriteOnlyFlag O_WRONLY
#define DataLibraryRWFlag O_RDWR

#define DataLibraryCreatFileFlag O_CREAT
#define DataLibraryAppendDataFlag O_APPEND
#define DataLibraryTruncDataFlag O_TRUNC

// File

#define WriteData(fp, v, l) ({\
fwrite(v, l, 1, fp);\
})

#define ReadData(fp, v, l) ({\
fgets(v, l, fp);\
})

#define GetFileSize(a) ({\
FileSize(a);\
})

// DL

#define DataLibraryOpenFile(filepath, datalibraryflags) ({\
open(filepath,datalibraryflags, 0644);\
})

#define DataLibraryCloseFile(file) ({\
close(file);\
})

#define DataLibraryFileWrite(file, mem, len) ({\
write(file,mem,len);\
})

#define DataLibraryFileReadMap(file, fileinfosize) ({\
mmap(NULL, fileinfosize, PROT_READ, MAP_SHARED, file, 0);\
})

#define DataLibraryFileReadMapClose(fileptr, fileinfosize) ({\
munmap(fileptr, fileinfosize);\
})

// File Lock

#define LockDataLibraryFileRW(fd) ({\
struct flock fl;\
fl.l_type = F_WRLCK;\
fl.l_whence = SEEK_SET;\
fl.l_start = 0;\
fl.l_len = 0;\
fcntl(fd, F_SETLKW, &fl);\
})

#define LockDataLibraryFileR(fd) ({\
struct flock fl;\
fl.l_type = F_RDLCK;\
fl.l_whence = SEEK_SET;\
fl.l_start = 0;\
fl.l_len = 0;\
fcntl(fd, F_SETLKW, &fl);\
})

#define UnLockDataLibraryFile(fd) ({\
struct flock fl;\
fl.l_type = F_UNLCK;\
fl.l_whence = SEEK_SET;\
fl.l_start = 0;\
fl.l_len = 0;\
fcntl(fd, F_SETLK, &fl);\
})

// Currency

#ifdef SystemFunction

#define CompareData(a, b) ({\
strcmp(a,b);\
})

#define FuzzyComparison(a, b) ({\
strstr(a,b);\
})

#define DataCopy(a, b) ({\
strcpy(a,b);\
})

#define DataConcatenation(a, b,ai) ({\
strcat(a,b);\
})

#define DataSplit(a, b,c) ({\
strtok_r(a,b,c);\
})

#define DataLength(a) ({\
strlen(a);\
})

#define CharCmp(a, b) ({\
*(unsigned char *)a - *(unsigned char *)b;\
})

#else

#define CompareData(a, b) ({\
register size_t i;\
register char *s1 = (char *) a, *s2 = (char *) b;\
while (!(i = *(unsigned char *) s1++ - *(unsigned char *) s2++) && *s1);\
i;\
})

#define FuzzyComparison(a, b) ({\
StringFuzzyCmp(a,b);\
})

#define DataCopy(a, b) ({\
register char *s1 = a,*s2 = (char*)b;\
while ((*s1++ = *s2++));\
a;\
})

#define DataConcatenation(a, b, ai) ({\
register char *s1 = a + ai,*s2=b;\
while ((*s1++ = *s2++));\
a;\
})

#define DataSplit(a, b, c) ({\
strtok_r((char *) a, (char *) b,c);\
})

#define DataLength(a) ({\
register unsigned DataSizeType i = 1;\
register char* b=a;\
while (*b++ && *b) {\
i++;\
}\
i;\
})

#define CharCmp(a, b) ({\
*(unsigned char *)a- *(unsigned char *)b;\
})

#endif

typedef void *(*Ft)(void *, ...);

char *StringFuzzyCmp(const char *a, const char *b);

DataSizeType FileSize(char *fi);

#endif
