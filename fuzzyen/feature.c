#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "feature.h"

void get_maxmin(float data[], int length, float* max_result, float* min_result)
{
    float max=data[0], min=data[0];
    Loop_max:for(int i=1;i<length;i++)
	#pragma HLS loop_tripcount min=1999 max=1999 avg=1999
    {
        if(data[i] > max)
            max = data[i];
		if(data[i] < min)
			min = data[i];
    }

    *max_result = max;
	*min_result = min;
}

void normalize(float* data, int length)
{
    float xmax, xmin, temp;
    // xmax = get_max(data, length);
    // xmin = get_min(data, length);
	get_maxmin(data, length, &xmax, &xmin);
    temp = xmax - xmin;

    Loop_norm:for(int i=0;i<length;i++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
    {
        data[i] = (data[i] - xmin) / temp;
    }
}

float log_calc(float in)
{
	float out;
	out = log(in);
	return out;
}

float fuzzyen_calc(float *in, int len)
{
    float r=0.2, fuzzyen, Max, count1, count2, B, A;
    int n=2, m=2;
    
    Loop_fuzzy:for(int i = 0; i < len - 1; i ++)
	#pragma HLS loop_tripcount min=1999 max=1999 avg=1999
    {
        for(int j = 0; j < len - 1; j ++)
		#pragma HLS loop_tripcount min=1999 max=1999 avg=1999
        {
            Max = fmax(fabs(in[i] - in[j]),fabs(in[i+1] - in[j+1]));
            count1 = count1 + exp(-(Max*Max)/r);	                           
            if (i+2 < len && j+2 < len ) 
            {
                Max = fmax(Max,fabs(in[i+2] - in[j+2]));
                count2 = count2 + exp(-(Max*Max)/r);			
            }
        }
    }
        
    count1 = count1 - len + m - 1;
    B = (float)count1/((len-m+1)*(len-m));
    count2 = count2 - len + m;
    A = (float)count2/((len-m)*(len-m-1));

    fuzzyen = 10000.0 * log_calc(B/A);

    return fuzzyen;
}

void overlay_fea(float* data, int length, float* FuzzyEn)
{
#pragma HLS INTERFACE m_axi depth=2000 port=data
    
    float buff[COL_NUM];
    memcpy(buff, data, COL_NUM*sizeof(float));
    
    normalize(buff, length);
	*FuzzyEn = fuzzyen_calc(buff, length);
}