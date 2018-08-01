#include "infor.h"
#include "file.h"
//số lượng member
int nmember = 0;
int mem = 0;

void ShowInfoMember(InfoMember **member,int length);
void AddInfoMember(InfoMember **members, int *length);
void ShowChangeInfoMember(InfoMember **members);
void InputInfoMember(InfoMember *member);
void FreeInfoMember(InfoMember *member);
void DeleteInfoMember(InfoMember **members);
void SearchInfoMember(InfoMember **members, InfoMember **listSearchMember);
int SearchMember(InfoMember **members,InfoMember **ListSeachMember, char temp[]);
void DeleteChar(InfoMember *member, int vitri);
void Adjust(InfoMember *member);

void menu(){
    printf("****************************************\n");
    printf("|======================================|\n");
    printf("|[1]. Xem thanh vien                   |\n");
    printf("|[2]. Them thanh vien                  |\n");
    printf("|[3]. Sua thong tin thanh vien         |\n");
    printf("|[4]. Xoa thanh vien                   |\n");
    printf("|[5]. Tim kiem thong tin thanh vien    |\n");
    printf("|[6]. Them thanh vien tu file          |\n");
    printf("|[7]. Luu thong tin vao file           |\n");
    printf("|[8]. Thoat chuong trinh               |\n");
    printf("|======================================|\n");
}

int main(){
    InfoMember **members;
    members = InitListInfoMember(SIZE_MEMBER);
    InfoMember **ListSearchMember;
    ListSearchMember = InitListInfoMember(SIZE_MEMBER);
    InfoMember **ListMemFile;
    ListMemFile = InitListInfoMember(SIZE_MEMBER);
    //do something
    int choose;
    do{
        system("cls");
        menu();
        do{
        printf("Nhap chuc nang:");
        scanf("%d", &choose);
        }while(!(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5 || choose == 6 || choose == 7 || choose == 8));
        switch(choose){
            case 1:
                ShowInfoMember(members, nmember);
                printf("Bam phim bat ki de tiep tuc:.........");
                getch();
                break;
            case 2:
                AddInfoMember(members, &nmember);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 3:
                ShowChangeInfoMember(members);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 4:
                DeleteInfoMember(members);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 5:
                SearchInfoMember(members, ListSearchMember);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 6:
                ReadFromFile(members, &nmember);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 7:
                WriteFile(members, ListMemFile, nmember, &mem);
                printf("Bam phim bat ki de tiep tuc............");
                getch();
                break;
            case 8:
                return 0;
        }
    }while(1);

    //kết thúc
    //getch();
    return 0;
}

//hiển thị thông tin member
void ShowInfoMember(InfoMember **member,int length){
    //in ra màn hình
    printf("Have %d member:\n", length);
    printf("%-4s %-6s %-20s %-6s %-7s\n", "STT", "ID", "Name", "Age", "Group_ID" );
    for (int i = 0; i < length; i++)
    {
        printf("%-4d %-6d %-20s %-6d %-7d\n",i+1 ,member[i]->id ,member[i]->name, member[i]->age, member[i]->group_id );
    }
}

// thêm người vào mảng
void AddInfoMember(InfoMember **members, int *length){
    //nếu vượt quá giới hạn thì ko thêm
    if (*length >= SIZE_MEMBER) return;

    //khởi tạo phần tử
    members[*length] = InitInfoMember();
    //nhập giá trị
    InputInfoMember(members ,members[*length], nmember);
    Adjust(members[*length]);//dinh dang ten
    //cộng số phần tử thêm 1
    (*length)++;
}

//In màn hình và nhập thay đổi giá trị member vị trí index
void ShowChangeInfoMember(InfoMember **members){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
    do {
        printf("Nhap vao STT thanh vien: ");
        scanf("%d", &index);
        if (index-1 >= nmember || index-1 < 0)
            printf("Nhap qua vi tri cho phep, moi ban nhap lai.\n");
    } while(index-1 >= nmember || index-1 < 0);

    //in màn hình và nhập dữ liệu sửa


    printf("Nhap du lieu sua\n");
    printf( "ID: " );
    fflush(stdin);
    scanf( "%d",&members[index-1]->id );
    printf( "Name: " );
    fflush(stdin);
    gets(members[index-1]->name);
    printf( "Age: " );
    fflush(stdin);
    scanf( "%d",&members[index-1]->age );
    printf( "Group_ID: " );
    fflush(stdin);
    scanf( "%d",&members[index-1]->group_id);
    Adjust(members[index-1]);
    printf("Sua thanh cong!\n");

}


//Xóa member tại vị trí index
void DeleteInfoMember(InfoMember **members){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
    do {
        printf("Nhap vao STT thanh vien: ");
        scanf("%d", &index);
        if (index -1 >= nmember || index-1 < 0)
            printf("Nhap qua index cho phep, moi ban nhap lai.\n");
    } while(index -1 >= nmember || index - 1 < 0);

    FreeInfoMember(members[index]);
    //số chuyển phần tử cuối cùng thành phần tử index
    //có thể dich từng phần tử để bảo toàn số thứ tự
    members[index-1] = members[nmember - 1];
    members[nmember - 1] = NULL;
    //số lượng người - 1
    nmember--;
    printf("Xoa thanh vien thu %d thanh cong!\n", index);
}

void SearchInfoMember(InfoMember **members, InfoMember **ListSeachMember){
    char temp[30];
    printf("Nhap thong tin ban muon tim kiem:");
    fflush(stdin);
    gets(temp);
    int check = SearchMember(members,ListSeachMember,temp);
    if(check==0) printf("Khong co thong tin nao lien quan den '%s'\n", temp);
    else if (check < 0) printf("Error %d.\n", check);
    else ShowInfoMember(ListSeachMember,check);
}

//tra ve so luong thanh vien tim kiem duoc, luu so thanh vien tim kiem duoc vao listSearchMember
int SearchMember(InfoMember **members,InfoMember **ListSeachMember, char temp[]){
    int sizeoflist=0;
    for (int i = 0; i < nmember; i++)
    {
        if (members[i]->id==atoi(temp)||strstr(members[i]->name,temp)!=NULL||members[i]->age==atoi(temp)||members[i]->group_id==atoi(temp))
        {
            ListSeachMember[sizeoflist]=members[i];
            sizeoflist++;
        }
    }
    return sizeoflist;
}



