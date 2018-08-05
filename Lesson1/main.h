#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "file.h"


void menu();
void ShowInfoMember(InfoMember **member,int length);
void AddInfoMember(InfoMember **members, int *length);
void ShowChangeInfoMember(InfoMember **members);
void DeleteInfoMember(InfoMember **members);
void SearchInfoMember(InfoMember **members, InfoMember **listSearchMember);
int SearchMember(InfoMember **members,InfoMember **ListSeachMember, char temp[]);

#endif // MAIN_H_INCLUDED



