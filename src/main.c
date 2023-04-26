#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_data(char data[50][255], int stocks[], int amountOfData) {
    if (amountOfData == 0) {
        printf("Please input the data first!\n");
    } else {
        printf("-- DATA LOG --\n");
        for (int i = 0; i <= amountOfData; i++) {
            if (data[i][0] == '\0') {
                printf("Reach the null termination charcter!\n");
                break;
            } else {
                int formatToUse;
                int arg1 = strlen(data[i]);
                int arg2 = strlen(data[0]);

                if (strlen(data[i]) >= strlen(data[0])) {
                    formatToUse = 15 - (strlen(data[i]) - strlen(data[0]));
                } else if (strlen(data[i]) <= strlen(data[0])) {
                    formatToUse = 15 + (strlen(data[i]) - strlen(data[0]));
                }

                printf("Data %d: %s %*d\n", (i+1), data[i], formatToUse, stocks[i]);
            }
        }
    }
}

int get_size_filled(char data[50][255], int amountOfData) {
    int size = 0;

    for (int i = 0; i < amountOfData; i++) {
        if (data[i][0] == '\0') {
            return size;
        } else {
            size++;
        }
    }

    return size;
}

void input(char data[50][255], int stocks[50], int data_size) {
    char object_name[30];
    int stock;
    int filled = get_size_filled(data, data_size);

    printf("Enter object name (255 char limits): ");
    scanf("%s", object_name);

    printf("Enter object stock: ");
    scanf("%d", &stock);

    printf("filled: %d\n", filled);

    stocks[filled] = stock;
    strcpy(data[filled], object_name);
}

void print_menu() {
    printf("1. Tambah Barang\n");
    printf("2. List Barang\n");
    printf("0. Exit\n");
}

int main(int argc, char* argv[]) {
    char data[50][255];
    int stock[50];
    int data_size = sizeof(data) / sizeof(data[0]);

    bool exit = false;
    int code;
    while (!exit) {
        print_menu();
        printf("Select: ");
        scanf("%d", &code);

        switch(code) {
            case 1:
            input(data, stock, data_size);
            break;
            case 2:
            print_data(data, stock, get_size_filled(data, data_size));
            break;
            case 0:
            exit = true;
            printf("Exit\n");
            break;
            default:
            printf("Code doesn't exist please select another one!\n");
        }
    }
}
