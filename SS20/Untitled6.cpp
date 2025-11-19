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
        {101, "Dansuraito Ahiru", 18, "0123456789"},
        {102, "Chinh Chai Am", 19, "0987654321"},
        {103, "Castorice", 20, "0911222333"},
        {104, "Miyamoto Musashi", 21, "0933444555"},
        {105, "Okita Souji", 22, "0944555666"}
    };

    int currentSize = 5;
    if (currentSize >= 50) {
        printf("Mang sinh vien da day! Khong the them moi\n");
        return 0;
    }
    
    printf("Nhap thong tin sinh vien can them: \n");
    struct Gakusei newSv;
    printf("ID: ");
    scanf("%d", &newSv.id);
    getchar();
    printf("Enter name: ");
    fgets(newSv.name, sizeof(newSv.name), stdin);
    newSv.name[strcspn(newSv.name, "\n")] = 0;
    printf("Enter age: ");
    scanf("%d", &newSv.age);
    getchar();
    printf("Enter phone Number: ");
    fgets(newSv.phoneNumber, sizeof(newSv.phoneNumber), stdin);
    newSv.phoneNumber[strcspn(newSv.phoneNumber, "\n")] = 0;

    sv[currentSize] = newSv;
    currentSize++;

    printf("\n=========== Danh sach sinh vien ===========\n");
    for (int i = 0; i < currentSize; i++) {
        printf("ID: %d | Ten: %s | Tuoi: %d | SDT: %s \n\n",
               sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}
