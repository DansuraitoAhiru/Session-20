#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Food {
    char name[50];
    int price;
};

void printMenu(struct Food menu[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s : %d\n", i + 1, menu[i].name, menu[i].price);
    }
}

void addPosition(struct Food menu[], int *size, int pos) {
    if (pos < 0 || pos > *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    struct Food newFood;
    getchar();
    printf("Nhap ten mon: ");
    fgets(newFood.name, sizeof(newFood.name), stdin);
    newFood.name[strcspn(newFood.name, "\n")] = 0;
    printf("Nhap gia: ");
    scanf("%d", &newFood.price);
    for (int i = *size; i > pos; i--) {
        menu[i] = menu[i - 1];
    }
    menu[pos] = newFood;
    (*size)++;
    printf("Them thanh cong!\n");
}

void editPosition(struct Food menu[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    getchar();
    printf("Nhap ten mon moi: ");
    fgets(menu[pos].name, sizeof(menu[pos].name), stdin);
    menu[pos].name[strcspn(menu[pos].name, "\n")] = 0;
    printf("Nhap gia moi: ");
    scanf("%d", &menu[pos].price);
    printf("Sua thanh cong!\n");
}

void removePosition(struct Food menu[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*size)--;
    printf("Xoa thanh cong!\n");
}

void sortIncreasing(struct Food menu[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (menu[i].price > menu[j].price) {
                struct Food temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
    printf("Da sap xep tang dan theo price!\n");
}

void sortDecreasing(struct Food menu[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (menu[i].price < menu[j].price) {
                struct Food temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
    printf("Da sap xep giam dan theo price!\n");
}

void searchLinear(struct Food menu[], int size) {
    char search[50];
    getchar();
    printf("Nhap ten mon can tim: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(menu[i].name, search) == 0) {
            printf("Tim thay! %s : %d\n", menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay!\n");
}

void searchBinary(struct Food menu[], int size) {
    char search[50];
    getchar();
    printf("Nhap ten mon can tim (yeu cau danh sach sap xep): ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(menu[mid].name, search);
        if (cmp == 0) {
            printf("Tim thay! %s : %d\n", menu[mid].name, menu[mid].price);
            return;
        }
        if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Khong tim thay!\n");
}

int main() {
    struct Food menu[50] = {
        {"Com tam", 35000},
        {"Pho bo", 40000},
        {"Banh mi", 20000},
        {"Tra sua", 25000},
        {"Bun cua", 45000}
    };
    int size = 5;
    int choice;
    do {
        printf("\n=========== MENU ===========\n");
        printf("1. In danh sach mon an\n");
        printf("2. Them mon tai vi tri chi dinh\n");
        printf("3. Sua mon tai vi tri chi dinh\n");
        printf("4. Xoa mon tai vi tri chi dinh\n");
        printf("5. Sap xep theo price\n");
        printf("6. Tim kiem mon theo name\n");
        printf("7. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printMenu(menu, size);
            break;

        case 2: {
            int pos;
            printf("Nhap vi tri can them (0 -> %d): ", size);
            scanf("%d", &pos);
            addPosition(menu, &size, pos);
            break;
        }

        case 3: {
            int pos;
            printf("Nhap vi tri can sua (0 -> %d): ", size - 1);
            scanf("%d", &pos);
            editPosition(menu, size, pos);
            break;
        }

        case 4: {
            int pos;
            printf("Nhap vi tri can xoa (0 -> %d): ", size - 1);
            scanf("%d", &pos);
            removePosition(menu, &size, pos);
            break;
        }

        case 5: {
            int chon;
            printf("1. Giam dan theo price \n");
            printf("2. Tang dan theo price \n");
            printf("Chon: ");
            scanf("%d", &chon);

            if (chon == 1) sortDecreasing(menu, size);
            else if (chon == 2) sortIncreasing(menu, size);
            else printf("Lua chon khong hop le!\n");
            break;
        }

        case 6: {
            int chon;
            printf("1. Tuyen tinh \n");
            printf("2. Nhi phan \n");
            printf("Chon: ");
            scanf("%d", &chon);
            if (chon == 1) searchLinear(menu, size);
            else if (chon == 2) searchBinary(menu, size);
            else printf("Lua chon khong hop le!\n");
            break;
        }

        case 7:
            printf("Thoat chuong trinh!\n");
            exit(0);

        default:
            printf("Ko co lua chon %d!\n", choice);
        }
    } while (choice != 7);
}
