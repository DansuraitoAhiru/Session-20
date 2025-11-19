#include <stdio.h>
#include <string.h>
struct Gakusei{
	int id;
	char name[50];
	int age;
};

int main() {
    struct Gakusei sv[50] = {
        {101, "Dansuraito Ahiru", 18},
        {2010, "Tram Ai Chinh", 19},
        {3001, "Hola Hermosa", 21},
        {44044, "Tokuda Shigure", 22},
        {555, "Samsung Oppo", 18}
    };
    int n=5; 
    int searchId;
    int found=-1;

    printf("Nhap ID sinh vien muon sua: ");
    scanf("%d", &searchId);
    getchar();

    for (int i = 0; i < n; i++) {
        if (sv[i].id == searchId) {
            found=i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay sinh vien co ID = %d\n", searchId);
    } else {
        printf("Nhap ten moi: ");
        fgets(sv[found].name, sizeof(sv[found].name), stdin);
        sv[found].name[strcspn(sv[found].name, "\n")] = 0;
        printf("Nhap tuoi moi: ");
        scanf("%d", &sv[found].age);
        printf("Da cap nhat thong tin sinh vien!\n");
    }
    printf("\n=========== Danh sach sinh vien ===========\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Ten: %s | Tuoi: %d \n\n",
               sv[i].id, sv[i].name, sv[i].age);
    }
}
