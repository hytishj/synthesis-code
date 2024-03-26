#include <stdio.h>
#include <time.h>
#include "feature.h"
#include "testdata.h"

#define ROW_NUM 2
#define COL_NUM 2000    

int main()
{
    float dat[2000];
    float fea_1;

    for(int i=0;i<ROW_NUM;i++)
    {
        for(int j=0;j<COL_NUM;j++)
        {
            dat[j] = data[i][j];
        }
    
        clock_t begin=clock();
        overlay_fea(dat, 2000, &fea_1);
        clock_t end=clock();

        printf("-----time:%f-----\n", (float)(end - begin)/CLOCKS_PER_SEC);       
        printf("pSQI=%.4f\n", fea_1);
        printf("line %d ok\n", i);
}    
    
    return 0;
}