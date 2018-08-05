#ifndef INFOR_H_INCLUDED
#define INFOR_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_NAME 20
#define SIZE_MEMBER 200


typedef struct InfoMember{
    int id;
    char name[SIZE_NAME];
    int age;
    int group_id;
} InfoMember;

InfoMember *InitInfoMember();
InfoMember **InitListInfoMember(int length);
int CheckID(InfoMember **members, InfoMember *member, int nmember);
int CheckLower(InfoMember *member);
int CheckSpace(InfoMember *member);
void DeleteChar(InfoMember *member, int vitri);
void Adjust(InfoMember *member);
void InputInfoMember(InfoMember **members, InfoMember *member, int nmember);
void FreeInfoMember(InfoMember *member);

#endif
