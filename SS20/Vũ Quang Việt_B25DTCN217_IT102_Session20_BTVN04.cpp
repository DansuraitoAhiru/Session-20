#include <stdio.h>
#include <string.h>
struct Gakusei{
	char name[50];
	int age;
	char phoneNumber[15];
};
int main(){
	struct Gakusei svs[50];
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		printf("Nhap thong tin sinh vien %d\n",i+1);
		printf("ID: %d\n",i+1);
		printf("Nhap ten: ");
		fgets(svs[i].name,50,stdin);
		svs[i].name[strcspn(svs[i].name,"\n")]=0;
		printf("Nhap tuoi: ");
		scanf("%d", &svs[i].age);
		getchar();
		printf("Nhap so dien thoai: ");
		fgets(svs[i].phoneNumber, 50, stdin);
		svs[i].phoneNumber[strcspn(svs[i].phoneNumber,"\n")]=0;
		printf("\n");
	}
	printf("--------------Danh sach sinh vien---------------\n");
	for (int i=0;i<n;i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("ID: %d\n", i+1);
        printf("Ten: %s\n", svs[i].name);
        printf("Tuoi: %d\n", svs[i].age);
        printf("SDT: %s\n\n", svs[i].phoneNumber);
    }
}
