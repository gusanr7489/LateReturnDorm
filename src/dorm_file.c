#include "dorm_file.h"

int loadData(LateApply *a){
    
}
void saveData(LateApply *a[], int n, char filename[]) {
    int i;
    //char filename[20];
    //strcpy(filename, a[]->apply_day);
    FILE *fp;
    fp = fopen(filename, "wt");
    for(i=0;i<n;i++) {
        if(a[n]==NULL)
            continue;
        fprintf(fp,"%s\t%8d\t%4d\t  %s\t\t%s\t%s", a[n]->name, a[n]->std_id, a[n]->room_no, a[n]->applyReason, a[n]->place, a[n]->apply_time);
        
    }
    fclose(fp);
}