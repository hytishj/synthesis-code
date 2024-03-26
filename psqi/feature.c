#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535

void power_spec(float* fft_signal, int length, float* spec)
{
    float fs=200, temp;

    Loop_freq:for(int i=0;i<length;i++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
    {
        temp = fft_signal[i] / fs;
        spec[i] = temp * temp;
    }
}

float pow_of_two(int a)
{
	float result=1;
	for(int i=1;i<=a;i++)
	{
		result=result*2;
	}
	return result;
}

void FFT(float dataR[],float dataI[],float dataA[],int N,int M)
{

	int i,j,k,r;
	int p,L,B;
	unsigned int I,J,K,F0,F1,m,n;
	float Tr,Ti,temp,si,co;

	Loop_fft_inFFT:for(I=0;I< N;I++)
	#pragma HLS loop_tripcount min=2048 max=2048 avg=2048   //根据规律四，需要对数组元素执行码间倒序
	{  
		/*获取下标I的反序J的数值*/ 
		J=0;
		Loop_fft2:for(k=0;k<(M/2+0.5);k++) 
		#pragma HLS loop_tripcount min=6 max=6 avg=6    //k表示操作
	     {
	         //*反序操作*/
	         m=1;//m是最低位为1的二进制数
			 n=(unsigned int)pow_of_two(M-1);//n是第M位为1的二进制数
			 m <<= k; //对m左移k位
	         n >>= k; //对n右移k位
	         F0=I & n;//I与n按位与提取出前半部分第k位
			 F1=I & m;//I与m按位与提取出F0对应的后半部分的低位
	         if(F0) J=J | m; //J与m按位或使F0对应低位为1
	         if(F1) J=J | n; //J与n按位或使F1对应高位为1 
	     }
	 		//printf("I为：");printBin(I,M);printf(" %d\n",I);
	 		//printf("J为：");printBin(J,M);printf(" %d\n\n",J);
	 		
	 	 if(I<J)
			{
				temp = dataR[I];
				dataR[I] = dataR[J];
				dataR[J] = temp;
				//补充虚数部分交换： 
				temp = dataI[I];
				dataI[I] = dataI[J];
				dataI[J] = temp;
			}                                
	} 


	Loop_fft3:for(L=1; L<=M;L++)
	#pragma HLS loop_tripcount min=11 max=11 avg=11	//FFT蝶形级数L从1--M
	{		
		/*第L级的运算:
		然后对于第L级，我们在问题五种提到，蝶形运算的种类数目等于间隔B:有多少种蝶形运算就要需要循环多少次;
		随着循环的不同，旋转指数P也不同，P的增量为k=2^(M-L)*/	
		//先计算一下间隔 B = 2^(L-1);
		B = 1;
		B = (int)pow_of_two(L-1);	
		for(j=0;j<=B-1;j++)	
		#pragma HLS loop_tripcount min=1 max=1024 avg=512	
		//j = 0,1,2,...,2^(L-1) - 1
		{	/*同种蝶形运算*/	
			//先计算增量k=2^(M-L)
			k=1;
			k = (int)pow_of_two(M-L);
			//计算旋转指数p，增量为k时，则P=j*k
			p=1;
			p=j*k;
			si=sin(2.0*PI*p/N);
			co=sqrt(1-(si*si));
			/*接下来，由问题六我们可以知道同种蝶形运算的次数刚好为增量k=2^(M-L)；
			同种蝶形的运算次数即为蝶形运算的次数*/
			for(i=0; i<=k-1;i++) 
			#pragma HLS loop_tripcount min=1 max=1024 avg=512
				{
					//数组下标定为r
					r=1;
					r=j+2*B*i;
					Tr=dataR[r+B]*co + dataI[r+B]*si;
					Ti=dataI[r+B]*co - dataR[r+B]*si;
					dataR[r+B]=dataR[r]-Tr;
					dataI[r+B]=dataI[r]-Ti;
					dataR[r]=dataR[r]+Tr;
					dataI[r]=dataI[r]+Ti;
				}	
			}
	}
	//计算幅值 
	for ( i=0;i<N;i++ )
	#pragma HLS loop_tripcount min=2048 max=2048 avg=2048
	{ 		
	 	dataA[i]=sqrt(dataR[i]*dataR[i]+dataI[i]*dataI[i]);
	}
}

float psqi_calc(float* power_spec)
{
	float lf_p=0, hf_p=0;

	Loop_psqi:for(int k=5;k<41;k++)
	{
		hf_p += power_spec[k];
		if(k<16)
		{
			lf_p += power_spec[k];
		}		
	}

	return lf_p / hf_p;
}

void overlay_fea(float* data, int length, float* pSQI)
{
	int N=2048, M=11;
	float InR[2048]={0}, InI[2048]={0}, InA[2048]={0}, spectrum[2048];

	Loop_fft:for(int i=0;i<length;i++)
	#pragma HLS loop_tripcount min=2000 max=2000 avg=2000
	{
		InR[i] = data[i];       
	}
	FFT(InR, InI, InA, N, M);

	power_spec(InA, length, spectrum);
	*pSQI = psqi_calc(spectrum);

	Loop_fftclear:for(int j=2000;j<2048;j++)
	#pragma HLS loop_tripcount min=48 max=48 avg=48
    {
        InR[j]=0;
		InI[j]=0;
		InA[j]=0;
		spectrum[j]=0;
    }
}


