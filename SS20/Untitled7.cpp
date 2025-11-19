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
    int maCanXoa;
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%d", &maCanXoa);
    int found = 0;
    for(int i = 0; i < currentSize; i++) {
        if(sv[i].id == maCanXoa) {
            found = 1;
            for(int j = i; j < currentSize - 1; j++) {
            sv[j] = sv[j+1];
            }
            currentSize--;
            printf("\nDa xoa sinh vien thanh cong!\n");
            break;
        }  
    }
    if(!found) {
    printf("Khong tim thay sinh vien co ma %d!\n", maCanXoa);
    }
    printf("\n=========== Danh sach sinh vien ===========\n");
    for (int i = 0; i < currentSize; i++) {
        printf("ID: %d | Ten: %s | Tuoi: %d | SDT: %s \n\n",
               sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}
