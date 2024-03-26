#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

float ksqi_calc(float* data, int length)
{
	float m2=0,m4=0;
	float tmp,tmp2;
	mean = mean_calc(data, length);

	Loop_kur:for(int j=0;j<length;j++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
	{
		tmp = data[j] - mean;
		tmp2 = tmp * tmp;
		m2 += tmp2;		
		m4 += tmp2 * tmp2;
	}

	return length * m4 / m2 / m2;
}

void overlay_fea(float* data, int length, float* kSQI)
{
#pragma HLS INTERFACE m_axi depth=2000 port=data

	float buff[2000];
	memcpy(buff, (const float*) data, 2000 * sizeof(float));

	*kSQI = ksqi_calc(buff, length);
}


