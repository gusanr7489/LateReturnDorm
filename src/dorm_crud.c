#include "dorm_crud.h"

void readStudents(LateApply a) {
    printf("%s\t%8d\t%4d\t  %s\t\t%s\t%s\n", a.name, a.std_id, a.room_no, a.applyReason, a.place, a.apply_time);
    //if(a.return_time != "NULL") printf("%s", a.return_time);
}

void listStudents(LateApply *a[], int n) {
    printf("NO  Name\tStudent ID\tRoom No\t  Reason\tPlace\t\tApply Time\tReturn Time\n");
    printf("====================================================================================================\n");
    for(int i = 0; i < n; i++) {
        if(a[i] == NULL) continue;

        printf("%d  ", i+1);
        readStudents(*a[i]);
    }
}

int addStudent(LateApply * a) {
    time_t currentTime;
    struct tm * time_info;

    getchar();
    printf("Name : ");
    fgets(a->name, 20, stdin);
    a->name[strlen(a->name) - 1] = '\0';

    printf("Student ID : ");
    scanf("%d", &a->std_id);

    printf("Room Number : ");
    scanf("%d", &a->room_no);

    getchar();
    printf("Reason for late return : ");
    fgets(a->applyReason, 64, stdin);
    a->applyReason[strlen(a->applyReason) - 1] = '\0';

    printf("Studying place : ");
    fgets(a->place, 64, stdin);
    a->place[strlen(a->place) - 1] = '\0';

    time(&currentTime);
    time_info = localtime(&currentTime);

    strftime(a->apply_time, 20, "%H:%M:%S", time_info);

    printf("=> Added!\n");
    return 1;
}

int selectDataNo(LateApply * a[], int n);

void updateStudent(LateApply * a);

int deleteStudent(LateApply * a);

int lateApply_menu() {
    int menu;
    printf("\n*** Dorms Late Return Apply ***\n");
    printf("1. List Student Info\n");
    printf("2. Add Student Info\n");
    printf("3. Update Student Info\n");
    printf("4. Delete Stduent Info\n");
    printf("0. End Program\n\n");
    printf("=> Choose option : ");
    scanf("%d", &menu);
    return menu;
}