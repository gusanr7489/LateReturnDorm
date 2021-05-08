#include "dorm_file.h"

void search_file_name(char *searchDay){
    printf("Which day of file would you like to open? ex) 2021-05-08\n");
    scanf("%s", searchDay);
}


int loadData(LateApply *a[], char *fileName){
    int i;
    FILE *fp;

    fp = fopen(fileName, "rt");
    if(fp == NULL) {
        printf("No saved file!!\n\n");
        return 0;
    }
    else 
    for(i=0;i<100;i++) {
        fscanf(fp,"%s", a[i]->name);
        if(feof(fp)) break;
        fscanf(fp,"%d", &a[i]->std_id);
        fscanf(fp,"%d", &a[i]->room_no);
        fscanf(fp,"%s", a[i]->applyReason);
        fscanf(fp, "%s", a[i]->place);
        fscanf(fp, "%s", a[i]->apply_time);
    }
    fclose(fp);
    return i;
}

void saveData(LateApply *a[], int n, char filename[]) {
    int i;
    FILE *fp;
    fp = fopen(filename, "wt");
    for(i=0;i<n;i++) {
        if(a[n]==NULL)
            continue;
        fprintf(fp,"%s\t%8d\t%4d\t  %s\t\t%s\t%s", a[n]->name, a[n]->std_id, a[n]->room_no, a[n]->applyReason, a[n]->place, a[n]->apply_time);
        
    }
    fclose(fp);
}

int search_std_no(LateApply *a[], int n) {
    int i, search_id;

    printf("what's your student ID? : ");
    scanf("%d",&search_id);

    for(i=0;i<n;i++) {
        if(search_id == a[i]->std_id) {
            readStudents(*a[i]);
            return i;
        }
    }
    return -1;
}

void return_dorm(LateApply *a[], int n){
    int i, search_id;
    time_t currentTime;
    struct tm * time_info;

    time(&currentTime); 
    time_info = localtime(&currentTime);

    printf("what's your student ID? : ");
    scanf("%d",&search_id);

    for(i=0;i<n;i++) {
        if(search_id == a[i]->std_id) {
            readStudents(*a[i]);
            break;
        }
    }

    strftime(a[i]->return_time, 20, "%H:%M:%S", time_info);

}