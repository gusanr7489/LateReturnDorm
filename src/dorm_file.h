#include "dorm_crud.h"

int loadData(LateApply *a[], char *fileName); // ���α׷� ������ �� ��¥���� ������ Ư�� ������ �����͸� �ҷ����� �Լ�

void saveData(LateApply *a[], int n, char filename[20]); // �Է��� �����͵��� ���Ͽ� �����ϴ� �Լ�

void search_file_name(char * searchDay); // loadData �Լ��� �ʿ��� ���ϸ� ã�� �Լ�

int search_std_no(LateApply *a[], int n);  // �й� �Է��ϸ� �ش� ������ �ҷ����� �Լ�

void return_dorm(LateApply *a[], int n); // ����� ���� �ð��� �Է¹޾� �����Ϳ� �����ϴ� �Լ�