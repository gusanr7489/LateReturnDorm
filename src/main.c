#include "dorm_file.h"

int main() {
    LateApply * dorm[100];
    LateApply * date[100];
    int count = 0, index = 0;
    int menu, delok, num;
    char filename[20];

    while(1) {
        menu = lateApply_menu();

        if(menu == 0) break;

        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) {
                printf("No data available.\n");
                continue;
            }

        if(menu == 1)
            listStudents(dorm, index);

        else if(menu == 2) {
            dorm[count] = (LateApply*)malloc(sizeof(LateApply));
            count += addStudent(dorm[index++]);
        } else if(menu == 3) {
            num = selectDataNo(dorm, count);
            updateStudent(dorm, num-1);
        } else if(menu == 4) {
            num = selectDataNo(dorm, count);
            if(num > 0) {
                printf("Are you sure you want to delete selected data? (Yes : 1, No : 0) : ");
                scanf("%d", &delok);

                if(delok)
                    count -= deleteStudent(dorm, num-1);
                else
                    printf("=> Cancelled\n");
            }
        } else if(menu==5) {
            strcpy(filename, dorm[index]->apply_day);
            saveData(dorm, count, filename);
            printf("saved!\n\n");
        }

    }
}