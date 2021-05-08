#include "dorm_crud.h"

int loadData(LateApply *a[], char *fileName); // 프로그램 시작할 때 파일 데이터를 불러옴, 불러온 데이터 갯수를 index값에 넣어줌

void saveData(LateApply *a[], int n, char filename[20]); // 입력한 데이터들을 파일에 저장시킴

void search_file_name(char * searchDay);

int search_std_no(LateApply *a[], int n);

void return_dorm(LateApply *a[], int n);