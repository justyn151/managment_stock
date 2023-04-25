#include <stdio.h>

void print_data(char* data[], int amountOfData) {
    for (int i = 0; i < amountOfData; i++) {
        printf("data %d: ", (i+1));
        for (int x = 0; data[i][x] != '\0'; x++) {
            printf("%c", data[i][x]);
        }

        printf("\n");
    }
}

void add_to_data(char* data[], char strings[]) {
    printf("TODO\n");
}

int main(int argc, char* argv[]) {
    char* data[50] = {"apple", "orange", "cucumber", "melon", "watermelon"};
}
