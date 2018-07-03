#ifndef INFOR_H_INCLUDED
#define INFOR_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME 20
#define SIZE_MEMBER 200

/* NV: viết hàm ShowInfoMember, ShowChangeInfoMember */

typedef struct InfoMember{
    int id;
    char name[SIZE_NAME];
    int age;
    int group_id;
} InfoMember;

//Khởi tạo member
//không cần viết hàm này thêm :)) nhưng thử check xem hàm này đúng ko :v
InfoMember *InitInfoMember(){
    //khởi tạo
    InfoMember *member = (InfoMember*) malloc (sizeof(InfoMember));

    //set 1 số trường
    member->id = 0;
    strcpy(member->name, "None");
    member->age = 0;
    member->group_id = 0;

    return member;
}

//Khởi tạo mảng member
InfoMember **InitListInfoMember(int length){
    InfoMember **listMember = (InfoMember**) malloc (length * sizeof(InfoMember*));

    //nếu không thể khởi tạo
    if (listMember == NULL) return listMember;
    //cho các phần tử NULL
    for (int i = 0 ; i < length ; i++){
        listMember[i] = NULL;
    }

    return listMember;
}

//hiển thị thông tin member
void ShowInfoMember(InfoMember **member,int length){
    //in ra màn hình
    printf("Have %d member:\n", length);
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Group_ID" );
    for (int i = 0; i < length; i++)
    {
        printf("%-10d %-20s %-10d %-10d\n", member[i]->id ,member[i]->name, member[i]->age, member[i]->group_id );
    }
}

//nhập bàn phím
void InputInfoMember(InfoMember *member){
    //in màn hình
    printf( "ID: " );
    fflush(stdin);
    scanf( "%d",&member->id );
    fflush(stdin);
    printf( "Name: " );
    gets(member->name);
    printf( "Age: " );
    fflush(stdin);
    scanf( "%d",&member->age );
    printf( "Group_ID: " );
    fflush(stdin);
    scanf( "%d",&member->group_id);
    //gán vào member
}

//free bộ nhớ member
void FreeInfoMember(InfoMember *member){
    free(member);
}


#endif
