#include <stdio.h>
#include <string.h>
struct Gakusei{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Gakusei sv[50] = {
        {1001, "Dansuraito Ahiru", 18, "0123456789"},
        {1020, "Chinh Chai Am", 19, "0987654321"},
        {1033, "Castorice", 20, "0911222333"},
        {1043, "Miyamoto Musashi", 21, "0933444555"},
        {1059, "Okita Souji", 22, "0944555666"}
    };

    int currentSize = 5;
    int pos;
    printf("Nhap vi tri can chen (0 -> %d): ", currentSize);
    scanf("%d", &pos);
    if (pos < 0 || pos > currentSize) {
        printf("Vi tri khong hop le!\n");
    } else {
	    struct Gakusei newSv;
	    getchar();
	    printf("Nhap thong tin sinh vien can chen: \n");
	    printf("ID: ");
	    scanf("%d", &newSv.id);
	    getchar();
	    printf("Name: ");
	    fgets(newSv.name, sizeof(newSv.name), stdin);
	    newSv.name[strcspn(newSv.name, "\n")] = 0;
	    printf("Age: ");
	    scanf("%d", &newSv.age);
	    getchar();
	    printf("Phone Number: ");
	    fgets(newSv.phoneNumber, sizeof(newSv.phoneNumber), stdin);
	    newSv.phoneNumber[strcspn(newSv.phoneNumber, "\n")] = 0;
	    for (int i = currentSize; i > pos; i--) {
	        sv[i] = sv[i - 1];
	    }
	    sv[pos] = newSv;
	    currentSize++;
	     printf("\n=========== Danh sach sinh vien ===========\n");
	    for (int i = 0; i < currentSize; i++) {
	        printf("ID: %d | Ten: %s | Tuoi: %d | SDT: %s \n\n",
	               sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
	    }
	}
}
