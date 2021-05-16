#include "dorm_file.h"

// 파일명 입력받는 함수
void search_file_name(char *searchDay){
    printf("Which day of file would you like to open? ex) 2021-05-08\n");
    scanf("%s", searchDay);  
}

//파일명 데이터 불러오는 함수
int loadData(LateApply *a[], char *fileName){
    int i;
    FILE *fp;
    
    strcat(fileName, ".txt"); 

    fp = fopen(fileName, "rt");
    if(fp == NULL) {
        printf("No saved file!!\n\n");
        return 0;
    }

    for(i = 0; i < 100; i++) {
        a[i] = (LateApply*)malloc(sizeof(LateApply));
        fscanf(fp, "%s", a[i]->name); 
        fscanf(fp, "%d", &a[i]->std_id); 
        fscanf(fp, "%d", &a[i]->room_no); 
        fscanf(fp, "%s ", a[i]->applyReason);
        fgets(a[i]->place, 13, fp); 
        fscanf(fp, "%s", a[i]->apply_time); 
        fscanf(fp, "%s\n", a[i]->return_time); 
        if(feof(fp)) break;
    }
    
    fclose(fp);

    printf("=> Succesfully loaded!\n");
    return i+1;
}

//현재 날짜로 파일명 텍스트 파일 만들고 데이터 저장해주는 함수
void saveData(LateApply *a[], int n, char filename[]) {
    int i;
    FILE *fp;
    fp = fopen(filename, "wt");
    for(i=0;i<n;i++) {
        if(a[i]==NULL) 
            continue;
        fprintf(fp,"%s %d %d %s %s  %s  %s", a[i]->name, a[i]->std_id, a[i]->room_no, a[i]->applyReason, a[i]->place, a[i]->apply_time, a[i]->return_time);
        fprintf(fp,"\n");
    }

    fclose(fp);
}

//학번으로 데이터 정보 찾는 함수
int search_std_no(LateApply *a[], int n) {
    int i, search_id;

    printf("what's your student ID? : ");
    scanf("%d",&search_id);

    printf("\nName\tStudent ID\tRoom No\t  Reason\tPlace\t\tApply Time\tReturn Time\n");
    printf("====================================================================================================\n");
    for(i=0;i<n;i++) {
        if(search_id == a[i]->std_id) {
            readStudents(*a[i]);
            return i;
        }
    }
    return -1;
}

//늦귀 복귀 시간 입력하는 함수
void return_dorm(LateApply *a[], int n){
    int i, search_id;
    time_t currentTime;
    struct tm * time_info;

    time(&currentTime); 
    time_info = localtime(&currentTime);

    printf("what's your student ID? : ");
    scanf("%d",&search_id);

    printf("NO  Name\tStudent ID\tRoom No\t  Reason\tPlace\t\tApply Time\tReturn Time\n");
    printf("====================================================================================================\n");
    for(i=0;i<n;i++) {  
        if(search_id == a[i]->std_id) {
            break;
        }
    }
    strftime(a[i]->return_time, 20, "%H:%M:%S", time_info);
    readStudents(*a[i]);
}