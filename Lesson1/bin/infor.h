#ifndef INFOR_H_INCLUDED
#define INFOR_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/* Cac ham CheckLower CheckSpace chu yeu dua tren bo ma ASCII de code
       - Chu viet hoa co gia tri tu 65 den 90 theo ASCII
       - Chu viet thuong co gia tri tu 97 den 122 theo ASCII
       - Chu thuong = chu hoa + 32;
/* Ham kiem tra va sua loi viet hoa sai vi tri */
int CheckLower(InfoMember *member){
    for(int i = 0; i < strlen(member->name); i++){
        if(member->name[i] == ' ' && member->name[i+1] > 96)
            member->name[i+1] -= 32; /* sua loi khong viet hoa dau ten */
        if(member->name[i] > 96 && member->name[i+1] < 96 && member->name[i+1] > 64)
            member->name[i+1] +=32; /* sua loi viet hoa sai vi tri */
        if(member->name[i] < 96 && member->name[i] > 64 && member->name[i+1] < 96)
            member->name[i+1] +=32; /* sua loi viet hoa sai vi tri */
    }
    if(member->name[0] > 96)
        member->name[0] -= 32; /* sua loi khong viet hoa dau ten */
    return 0;
}

/* Ham kiem tra va sua loi thua dau cach tra ve vi tri thua dau cach */
int CheckSpace(InfoMember *member){
    for(int i = 0; i < strlen(member->name); i++){
        if(member->name[i]==' ' && member->name[i+1]==' ') return i+1;
    }
    return 0;
}

/* Ham xoa ki tu theo vi tri dua vao */
void DeleteChar(InfoMember *member, int vitri){
    for(int i = vitri; i < strlen(member->name)-1; i++){
        member->name[i] = member->name[i+1];
    }
    member->name[strlen(member->name)-1] = '\0';
}

/* Ham dinh dang ten */
void Adjust(InfoMember *member){
    int check;
    do{
        check = CheckSpace(member);
        if(check == 0) break;
        DeleteChar(member, check);
    }while(check);
    if(member->name[0] == ' ') DeleteChar(member, 0);
    if(member->name[strlen(member->name)-1] == ' ') DeleteChar(member, strlen(member->name)-1);
// sau khi xoa cac dau cach thua thi sua lai viet hoa chua dung vi tri bang ham CheckLower
    CheckLower(member);
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
    Adjust(member);
    //gán vào member
}

//free bộ nhớ member
void FreeInfoMember(InfoMember *member){
    free(member);
}


#endif
