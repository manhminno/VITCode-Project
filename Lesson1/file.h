#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "infor.h"

int AddFromFile(InfoMember **members, int *nmember, char *file)
{
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Can't open file\n");
        return -1;
    }

    while(!feof(fp)){
		int id = 0, age = 0, group_id = 0;
		char name[256], getId[256];

        if (fgets(name, 256, fp) == NULL){
        	printf("Error: Loi ten\n");
        	return -2;
		}

		if (fgets(getId, 256, fp) == NULL){
        	printf("Error: Loi doc id\n");
        	return -2;
		}

		if (sscanf(getId, "%d%d%d", &id, &age, &group_id) < 0){
        	printf("Error: chuyen so\n");
        	return -2;
		}

		InfoMember *member = InitInfoMember();

        member->id = id;
        for (int i = 0 ; i < strlen(name) ; i++)
        	if (name[i] == '\n')
				name[i] = '\0';
        strcpy(member->name, name);
        member->age = age;
        member->group_id = group_id;

        members[*nmember] = member;
        (*nmember)++;

    }
    printf("OK\n");
}

#endif // FILE_H_INCLUDED
