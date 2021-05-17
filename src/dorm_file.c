#include "dorm_file.h"

// ���ϸ� �Է¹޴� �Լ�
void search_file_name(char *searchDay){
    printf("Which day of file would you like to open? ex) 2021-05-08\n");
    scanf("%s", searchDay);  
}

//���ϸ� ������ �ҷ����� �Լ�
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

//���� ��¥�� ���ϸ� �ؽ�Ʈ ���� ����� ������ �������ִ� �Լ�
void saveData(LateApply *a[], int n, char filename[]) {
    int i;
    FILE *fp;
    fp = fopen(filename, "wt");
    for(i = 0; i < n; i++) {
        if(a[i] == NULL) 
            continue;
        fprintf(fp,"%s %d %d %s %s  %s  %s", a[i]->name, a[i]->std_id, a[i]->room_no, a[i]->applyReason, a[i]->place, a[i]->apply_time, a[i]->return_time);
        fprintf(fp,"\n");
    }

    fclose(fp);
}

//�й����� ������ ���� ã�� �Լ�
void search_std_no(LateApply *a[], int n, int x) {
    int i;

    printf("\nName\tStudent ID\tRoom No\t  Reason\tPlace\t\tApply Time\tReturn Time\n");
    printf("============================================================================================\n");
    for(int i = 0; i < n; i++) {
        if(x == a[i]->std_id) {
            readStudents(*a[i]);
            break;
        }
    }
}

//�ʱ� ���� �ð� �Է��ϴ� �Լ�
void return_dorm(LateApply *a[], int n, int x){
    int i;
    time_t currentTime;
    struct tm * time_info;

    time(&currentTime); 
    time_info = localtime(&currentTime);

    printf("\nName\tStudent ID\tRoom No\t  Reason\tPlace\t\tApply Time\tReturn Time\n");
    printf("============================================================================================\n");
    for(i = 0; i < n; i++) {  
        if(x == a[i]->std_id) {
            strftime(a[i]->return_time, 20, "%H:%M:%S", time_info);
            readStudents(*a[i]);
            break;
        }
    }
    
    printf("\nSaved!\n\n");
}

//�й� �Է¹޴� �Լ�
int getStdID(LateApply *a[], int n) {
    int stdid;

    printf("what's your student ID? : ");
    scanf("%d", &stdid);

    for(int i = 0; i < n; i++) {  
        if(stdid == a[i]->std_id) {
            return stdid;
        }
    }

    return -1;
}