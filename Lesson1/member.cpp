#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include <conio.h>
=======
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
>>>>>>> 86280e0e314ffc89c156e1df60bc7025dbdc3633

#define SIZE_NAME 20
#define SIZE_MEMBER 200

/* NV: viết hàm ShowInfoMember, ShowChangeInfoMember */

typedef struct InfoMember{
    int id;
    char name[SIZE_NAME];
    int age;
    int group_id;
} InfoMember;

//số lượng member
int nmember = 0;

//hàm
InfoMember *InitInfoMember();
InfoMember **InitListInfoMember(int length);
void ShowInfoMember(InfoMember **member);
void ShowChangeInfoMember(InfoMember **members);
void InputInfoMember(InfoMember *member);
void AddInfoMember(InfoMember **members);
void FreeInfoMember(InfoMember *member);
void DeleteInfoMember(InfoMember **members);
int AddFromFile(InfoMember **members, char *file);


void menu(){
    printf("[1].Xem thanh vien\n" );
    printf("[2].Them thanh vien\n");
    printf("[3].Sua thong tin thanh vien\n");
    printf("[4].Xoa thanh vien\n" );
    printf("[5]. Them thanh vien tu file \n");
    printf("[6.Thoat chuong trinh\n" );
    printf("\n");
    printf("==================================\n");
}
int main(){
    InfoMember **members;
    members = InitListInfoMember(SIZE_MEMBER);

    //do something
    int choose;
    char cont;
    do{
        system("clear");
        menu();
        printf("Nhap chuc nang:");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                ShowInfoMember(members);                
                break;
            case 2:
                AddInfoMember(members);
                break;
            case 3:
                ShowChangeInfoMember(members);
                break;
            case 4:
                DeleteInfoMember(members);
                break;
            case 5:
                AddFromFile(members, "members.txt")
                break;
        }
        printf("Ban co muon tiep tuc khong? (Y/N):");
        __fpurge(stdin);
        scanf("%c", &cont);
    }while(cont == 'y' || cont == 'Y');

    //kết thúc
    //getch();
    return 0;
}

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
void ShowInfoMember(InfoMember **member){
    //in ra màn hình
    for (int i = 0; i < nmember; i++)
    {
        printf("Name: %s\tID: %d\t Age: %d\t Group_ID: %d\n", 
        member[i]->name ,member[i]->id, member[i]->age, member[i]->group_id );
    }
}

//In màn hình và nhập thay đổi giá trị member vị trí index
void ShowChangeInfoMember(InfoMember **members){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
    do {
    	printf("Nhap index: ");
    	scanf("%d", &index);
    	if (index >= nmember || index < 0)
    		printf("Nhap qua index cho phep, moi ban nhap lai.\n");
    } while(index >= nmember || index < 0);

    //in màn hình và nhập dữ liệu sửa
    

    printf("Nhap du lieu sua\n");
    InputInfoMember(members[index]);
    
}

//nhập bàn phím
void InputInfoMember(InfoMember *member){
    //in màn hình
    printf( "ID: " );
    fflush(stdin);
    scanf( "%d",&member->id );
    fflush(stdin);
    printf( "Name: " );
    scanf( "%*c%[^\n]s",member->name );
    printf( "Age: " );
    fflush(stdin);
    scanf( "%d",&member->age );
    printf( "Group_ID: " );
    fflush(stdin);
    scanf( "%d",&member->group_id);
    //gán vào member

}

// thêm người vào mảng
void AddInfoMember(InfoMember **members){
    //nếu vượt quá giới hạn thì ko thêm
    if (nmember >= SIZE_MEMBER) return;

    //khởi tạo phần tử cuối
    members[nmember] = InitInfoMember();
    //nhập giá trị
    InputInfoMember(members[nmember]);
    //cộng số phần tử thêm 1
    nmember++;
}

//free bộ nhớ member
void FreeInfoMember(InfoMember *member){
    free(member->name);
    free(member);
}

//Xóa member tại vị trí index
void DeleteInfoMember(InfoMember **members){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
	do {
    	printf("Nhap index: ");
    	scanf("%d", &index);
    	if (index >= nmember || index < 0)
    		printf("Nhap qua index cho phep, moi ban nhap lai.\n");
    } while(index >= nmember || index < 0);

    FreeInfoMember(members[index]);
    //số chuyển phần tử cuối cùng thành phần tử index
    //có thể dich từng phần tử để bảo toàn số thứ tự
    members[index] = members[nmember - 1];
    members[nmember - 1] = NULL;
    //số lượng người - 1
    nmember--;
}

int AddFromFile(InfoMember **members, char *file)
{
    FILE *fp = fopen(file, "r");
    int getInt;
    char line[255];
    InfoMember *member;

    if (fp) {
        while(1){  
          if (feof(fp))
            break;
          fscanf (fp, "%d", &getInt);
          member->id = getInt;

          fgets(line, sizeof(line), fp);
          member->name = line;

          fscanf(fp, "%d", &getInt);
          member->age = getInt;

          fscanf(fp, "%d", &getInt);
          member->group_id = getInt;

          members[nmember] = member;
          nmember++;

        }
    }
}

