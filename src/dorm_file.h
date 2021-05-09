#include "dorm_crud.h"

int loadData(LateApply *a[], char *fileName); // 프로그램 시작할 때 날짜별로 정리된 특정 파일의 데이터를 불러오는 함수

void saveData(LateApply *a[], int n, char filename[20]); // 입력한 데이터들을 파일에 저장하는 함수

void search_file_name(char * searchDay); // loadData 함수에 필요한 파일명 찾기 함수

int search_std_no(LateApply *a[], int n);  // 학번 입력하면 해당 데이터 불러오는 함수

void return_dorm(LateApply *a[], int n); // 기숙사 리턴 시간을 입력받아 데이터에 저장하는 함수