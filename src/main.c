#include "dorm_crud.h"

int main() {
    LateApply * dorm[100];
    LateApply * date[100];
    int count = 0, index = 0;
    int menu, delok, num;

    while(1) {
        menu = lateApply_menu();

        if(menu == 0) break;

        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) {
                printf("No data available.\n");
                continue;
            }

        if(menu == 1)
            listStudents(dorm, count);
        else if(menu == 2) {
            dorm[count] = (LateApply*)malloc(sizeof(LateApply));
            count += addStudent(dorm[index++]);
        }

    }
}