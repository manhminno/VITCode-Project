#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#define SIZE_NAME 20
#define SIZE_MEMBER 200

#include "infor.h"

int ReadFromFile(InfoMember **members, int *nmember);
void WriteFile(InfoMember **members, InfoMember **ListMemFile, int nmember, int *mem);

#endif // FILE_H_INCLUDE



