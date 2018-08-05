#include "infor.h"

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

int CheckID(InfoMember **members, InfoMember *member, int nmember){
    for(int i = 0; i < nmember; i++){
        if(members[i]->id == member->id) return 1;
    }
    return 0;
}


//Cac ham CheckLower CheckSpace chu yeu dua tren bo ma ASCII de code
//Ham kiem tra va sua loi viet hoa sai vi tri
int CheckLower(InfoMember *member){
    for(int i = 0; i < strlen(member->name); i++){
        if(member->name[i] == ' ' && member->name[i+1] >= 'a')
            member->name[i+1] -= 'a' - 'A'; /* sua loi khong viet hoa dau ten */
        else if(member->name[i] >= 'a' && member->name[i+1] <= 'Z' && member->name[i+1] >= 'A')
            member->name[i+1] += 'a' - 'A'; /* sua loi viet hoa sai vi tri */
        else if(member->name[i] <= 'Z' && member->name[i] >= 'A' && member->name[i+1] <= 'Z')
            member->name[i+1] += 'a' - 'A'; /* sua loi viet hoa sai vi tri */
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
void InputInfoMember(InfoMember **members, InfoMember *member, int nmember){
    //in màn hình
    printf( "ID: " );
    fflush(stdin);
    scanf( "%d",&member->id );
    if(CheckID(members, member, nmember)){
        do{
            printf("ID bi trung vui long nhap lai:\n");
            printf( "ID: " );
            fflush(stdin);
            scanf( "%d",&member->id );
        }while(CheckID(members, member, nmember));
    }
    printf( "Name: " );
    fflush(stdin);
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



