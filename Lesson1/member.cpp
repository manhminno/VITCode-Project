#include <stdio.h>
#include <conio.h>

#define SIZE_NAME 20
#define SIZE_MEMBER 200

struct InfoMember{
	int id;
	char name[SIZE_NAME];
	int age;
	int group_id;
}

//số lượng member
int nmember = 0;

//hàm
InfoMember *InitInfoMember();
InfoMember **InitListInfoMember(int length);
void ShowInfoMember(InfoMember member);
void ShowChangeInfoMember(InfoMember **member);
void InputInfoMember(InfoMember *member);
void AddInfoMember(InfoMember **members);
void FreeInfoMember(InfoMember *member);
void DeleteInfoMember(InfoMember **members);


//main chạy chương trình
int main(){
	InfoMember **members;	
	member = InitListInfoMember(SIZE_MEMBER);
	
	//do something
	
	//kết thúc
	getch();
	return 0;
}

//Khởi tạo member
//không cần viết hàm này thêm :)) nhưng thử check xem hàm này đúng ko :v
InfoMember *InitInfoMember(){
	//khởi tạo
	InfoMember *member = (InfoMember*) malloc (size_of(InfoMember));
	
	//set 1 số trường
	member->id = 0;
	stpcpy(member->name, "None");
	member->age = 0;
	member->group_id = 0;
	
	return member;
}

//Khởi tạo mảng member
InfoMember **InitListInfoMember(int length){
	InfoMember **listMember = (InfoMember**) malloc (length * size_of(InfoMember*));
	
	//nếu không thể khởi tạo
	if (listMember == NULL) return listMember;
	//cho các phần tử NULL
	for (int i = 0 ; i < length ; i++){
		listMember[i] = NULL;
	}
	
	return listMember;
}

//hiển thị thông tin member
void ShowInfoMember(InfoMember member){
	//in ra màn hình
}

//In màn hình và nhập thay đổi giá trị member vị trí index
void ShowChangeInfoMember(InfoMember **members){
	int index;
	// nhập vị trí index. nếu index sai quay lại việc nhập.
	
	//in màn hình và nhập dữ liệu sửa
	InputInfoMember(member[index]);
}

//nhập bàn phím
void InputInfoMember(InfoMember *member){
	//in màn hình
	
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
	
	FreeInfoMember(member[index]);
	//số chuyển phần tử cuối cùng thành phần tử index
	//có thể dich từng phần tử để bảo toàn số thứ tự
	member[index] = member[nmember - 1];
	member[nmember - 1] = NULL;
	//số lượng người - 1
	nmember--;
}
