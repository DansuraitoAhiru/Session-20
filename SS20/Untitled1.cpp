#include <stdio.h>
struct Gakusei{
	char name[50];
	int age;
	char phoneNumber[12];
};
int main(){
	struct Gakusei ahiru={
		"Dansuraito Aniru",
		18,
		"08699699366" 
	};
	printf("Ho va ten: %s\n", ahiru.name);
	printf("Tuoi: %d\n", ahiru.age);
	printf("SDT: %s",ahiru.phoneNumber);
}
