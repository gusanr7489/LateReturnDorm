#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int std_id;
    int room_no;
    char applyReason[64];
    char place[64];
    char apply_time[20];
    char apply_day[20];
    char return_time[20];
} LateApply;