#include "dorm_crud.h"

void readStudents(LateApply a) {
    printf("%s\t%8d\t%-4d\t  %s\t\t%s\t%s\t%s", a.name, a.std_id, a.room_no, a.applyReason, a.place, a.apply_time, a.return_time);
    printf("\n");
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
    char checkHour[5];

    time(&currentTime); 
    time_info = localtime(&currentTime);

    strftime(checkHour, 5, "%H", time_info);

    // 현재 실제 시간에 따라서 늦은귀관 신청을 가능하게 해주는 코드
    // 21시부터 23시 사이의 시간이 아니라면 늦은귀관 신청을 하지 못 함.
    // 프로그램 구현단계에서 각 함수 테스트를 위해 주석처리를 해놓음.
    /*if(atoi(checkHour) < 21 || atoi(checkHour) > 23) {
        printf("Reserve is not available\n");
        return 0;
    }*/

    getchar();
    printf("Name : ");
    fgets(a->name, 9, stdin);
    a->name[strlen(a->name) - 1] = '\0';

    printf("Student ID : ");
    scanf("%d", &a->std_id);

    printf("Room Number : ");
    scanf("%d", &a->room_no);

    getchar();
    printf("Reason for late return : ");
    fgets(a->applyReason, 20, stdin);
    a->applyReason[strlen(a->applyReason) - 1] = '\0';

    printf("Studying place : ");
    fgets(a->place, 20, stdin);
    a->place[strlen(a->place) - 1] = '\0';

    strftime(a->apply_time, 10, "%H:%M:%S", time_info);
    strftime(a->apply_day, 11, "%Y-%m-%d", time_info);

    strcpy(a->return_time, "N/A");

    printf("=> Added!\n");
    return 1;
}

int selectDataNo(LateApply * a[], int n) {
    int num;

    listStudents(a, n);
    printf("Choose number (Cancel : 0) : ");
    scanf("%d", &num);

    if(!num) printf("=> Cancelled\n");

    return num;    
}

void updateStudent(LateApply * a[], int n) {
    time_t currentTime;
    struct tm * time_info;
    char checkHour[5];

    time(&currentTime); 
    time_info = localtime(&currentTime);

    strftime(checkHour, 5, "%H", time_info);

    // 현재 실제 시간에 따라서 늦은귀관 신청을 가능하게 해주는 코드
    // 21시부터 23시 사이의 시간이 아니라면 늦은귀관 신청을 하지 못 함.
    // 프로그램 구현단계에서 각 함수 테스트를 위해 주석처리를 해놓음.
    /*if(atoi(checkHour) < 21 || atoi(checkHour) > 23) {
        printf("Reserve is not available\n");
        return 0;
    }*/

    getchar();
    printf("Name : ");
    fgets(a[n]->name, 9, stdin);
    a[n]->name[strlen(a[n]->name) - 1] = '\0';

    printf("Student ID : ");
    scanf("%d", &a[n]->std_id);

    printf("Room Number : ");
    scanf("%d", &a[n]->room_no);

    getchar();
    printf("Reason for late return : ");
    fgets(a[n]->applyReason, 20, stdin);
    a[n]->applyReason[strlen(a[n]->applyReason) - 1] = '\0';

    printf("Studying place : ");
    fgets(a[n]->place, 20, stdin);
    a[n]->place[strlen(a[n]->place) - 1] = '\0';

    strftime(a[n]->apply_time, 10, "%H:%M:%S", time_info);
    strftime(a[n]->apply_day, 11, "%Y-%m-%d", time_info);

    strcpy(a[n]->return_time, "N/A");

    printf("=> Updated!\n");
}

int deleteStudent(LateApply * a[], int n) {
    free(a[n]);
    a[n] = NULL;
    printf("=> Deleted!\n");
    return 1;
}

int lateApply_menu() {
    int menu;
    printf("\n*** Dorms Late Return Apply ***\n");
    printf("1. List Student Info\n");
    printf("2. Add Student Info\n");
    printf("3. Update Student Info\n");
    printf("4. Delete Stduent Info\n");
    printf("5. Save data\n");
    printf("6. Search reserved data\n");
    printf("7. Return dorm\n");
    printf("0. End Program\n\n");
    printf("=> Choose option : ");
    scanf("%d", &menu);
    return menu;
}