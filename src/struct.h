#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[9];
    int std_id;
    int room_no;
    char applyReason[20];
    char place[20];
    char apply_time[10];
    char apply_day[11];
    char return_time[10];
} LateApply;