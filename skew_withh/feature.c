#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "feature.h"

float mean=0;

float mean_calc(float* data, int length)
{
	float sum=0;
	Loop_mean:for(int i=0;i<length;i++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
	{
		sum += data[i];
	}
	return sum / length;
}

float ssqi_calc(float* data, int length)
{
	float m2=0,m3=0, l=sqrt(length);
	float tmp, tmp2;
	mean = mean_calc(data, length);

	Loop_skew:for(int k=0;k<length;k++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
	{
		tmp = data[k] - mean;
		tmp2 = tmp * tmp;
		m2 += tmp2;	
		m3 += tmp2 * tmp;
	}

	return l * m3 / m2 / sqrt(m2);
}

void overlay_fea(float* data, int length, float* sSQI)
{
	float dat[2000];

	*sSQI = ssqi_calc(data, length);
}


