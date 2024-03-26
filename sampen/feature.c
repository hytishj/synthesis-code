#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


// float log_calc(float in)
// {
// 	float out;
// 	out = log(in);
// 	return out;
// }

float sampen_calc(float *X, int len)
{
    float r=0.2, Max, B, A;
    int m=2, count1=0, count2=0;
	Loop_sampen:for(int i=0;i<len-m;i++)
    #pragma HLS loop_tripcount min=1998 max=1998 avg=1998
    {
        for(int j=0;j<len-m;j++)
        #pragma HLS loop_tripcount min=1997 max=1997 avg=1997
        {
            if(i!=j)
            {
                Max=fmax(fabs(X[i]-X[j]), fabs(X[i+1]-X[j+1]));
                if(Max <= r){count1++;}
                if((i+2 < len) && (j+2 < len))
                {
                    Max=fmax(Max, fabs(X[i+2]-X[j+2]));
                    if(Max <= r){count2++;}
                }
            }
           
        }
    }

    count1 = count1 - len + m - 1;
    B = (float)count1/((len-m+1)*(len-m));
    count2 = count2 - len + m;
    A = (float)count2/((len-m)*(len-m-1));
    // if ((B==0) || (A==0)) // 尽管大部分时候不会是0
    //     SampEn=0;

    // return 10000.0 * log_calc(B / A);
    return 10000.0 * log(B / A);
}

void overlay_fea(float* data, int length, float* SampEn)
{
#pragma HLS INTERFACE m_axi depth=2000 port=data
    float buff[2000];
    memcpy(buff, (const float*) data, 2000 * sizeof(float));

    normalize(buff, length);
    *SampEn = sampen_calc(buff, length);

}