#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[64];
    int std_id;
    int room_no;
    char applyReason[100];
    char place[64];
    char apply_time[64];
    char return_time[64];
} LateApply;

void readStudents(LateApply a);

void listStudents(LateApply *a[], int n);

int addStudent(LateApply * a);

int selectDataNo(LateApply * a[], int n);

void updateStudent(LateApply * a);

int deleteStudent(LateApply * a);