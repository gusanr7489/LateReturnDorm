#include "dorm_crud.h"

int loadData(LateApply *a[], char *fileName); // ���α׷� ������ �� ���� �����͸� �ҷ���, �ҷ��� ������ ������ index���� �־���

void saveData(LateApply *a[], int n, char filename[20]); // �Է��� �����͵��� ���Ͽ� �����Ŵ

void search_file_name(char * searchDay);

int search_std_no(LateApply *a[], int n);

void return_dorm(LateApply *a[], int n);