#include <stdio.h>
#include <string.h>
struct Gakusei{
	char name[50];
	int age;
	char phoneNumber[14];
};
int main(){
	Gakusei ahiru;
	printf("Nhap ten: ");
	fgets(ahiru.name, 50, stdin);
	ahiru.name[strcspn(ahiru.name,"\n")]=0;
	printf("Nhap tuoi: ");
	scanf("%d", &ahiru.age);
	getchar();
	printf("Nhap so dien thoai: ");
	fgets(ahiru.phoneNumber,14,stdin);
	ahiru.phoneNumber[strcspn(ahiru.phoneNumber,"\n")]=0;
	printf("%s - %d - %s", ahiru.name,ahiru.age,ahiru.phoneNumber);
}
