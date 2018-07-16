#include "infor.h"
#include "file.h"
//số lượng member
int nmember = 0;

void AddInfoMember(InfoMember **members, int *length);
void ShowChangeInfoMember(InfoMember **members);
void InputInfoMember(InfoMember *member);
void FreeInfoMember(InfoMember *member);
void DeleteInfoMember(InfoMember **members);
void SearchInfoMember(InfoMember **members, InfoMember **listSearchMember);
int SearchMember(InfoMember **members, InfoMember **listSearchMember, char temp);

void menu(){
    printf("***************************************\n");
    printf("|=====================================|\n");
    printf("|[1].Xem thanh vien                   |\n" );
    printf("|[2].Them thanh vien                  |\n");
    printf("|[3].Sua thong tin thanh vien         |\n");
    printf("|[4].Xoa thanh vien                   |\n" );
    printf("|[5].Tim kiem thong tin thanh vien    |\n" );
    printf("|[6].Them thanh vien tu file          |\n" );
    printf("|[7].Luu thong tin vao file           |\n" );
    printf("|[8].Thoat chuong trinh               |\n");
    printf("|=====================================|\n");
}

int main(){
    InfoMember **members;
    members = InitListInfoMember(SIZE_MEMBER);
    InfoMember **listSearchMember;
    listSearchMember = InitListInfoMember(SIZE_MEMBER);
    //do something
    int choose;
    char cont;
    do{
        system("cls");
        menu();
        printf("Nhap chuc nang:");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                ShowInfoMember(members, nmember);
                break;
            case 2:
                AddInfoMember(members, &nmember);
                break;
            case 3:
                ShowChangeInfoMember(members);
                break;
            case 4:
                DeleteInfoMember(members);
                break;
            case 5:
                SearchInfoMember(members, listSearchMember);
                break;
            case 6:
                AddFromFile(members, &nmember);
                break;
            case 7:
                AddFile(members, nmember);
                break;
            case 8:
                return 0;
        }
        printf("Ban co muon tiep tuc khong? (Y/N):");
        fflush(stdin);
        scanf("%c", &cont);
    }while(cont == 'y' || cont == 'Y');

    //kết thúc
    //getch();
    return 0;
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

// thêm người vào mảng
void AddInfoMember(InfoMember **members, int *length){
    //nếu vượt quá giới hạn thì ko thêm
    if (*length >= SIZE_MEMBER) return;

    //khởi tạo phần tử cuối
    members[*length] = InitInfoMember();
    //nhập giá trị
    InputInfoMember(members[*length]);
    //cộng số phần tử thêm 1
    (*length)++;
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

int SearchMember(InfoMember **members,InfoMember **listSeachMember, char temp[]){
    int sizeoflist=0;
    for (int i = 0; i < nmember; i++)
    {
        if (members[i]->id==atoi(temp)||strstr(members[i]->name,temp)!=NULL||members[i]->age==atoi(temp)||members[i]->group_id==atoi(temp))
        {
            listSeachMember[sizeoflist]=members[i];
            sizeoflist++;
        }
    }
    return sizeoflist;
}

void SearchInfoMember(InfoMember **members, InfoMember **listSeachMember){
    char temp[30];
    printf("Nhap thong tin ban muon tim kiem:");
    fflush(stdin);
    gets(temp);
    int check=SearchMember(members,listSeachMember,temp);
    if(check==0) printf("Khong co thong tin nao lien quan den '%s'\n", temp);
    else if (check < 0) printf("Error %d.\n", check);
    else ShowInfoMember(listSeachMember,check);
}


