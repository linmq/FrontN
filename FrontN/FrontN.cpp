// FrontN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int FrontN(int a[], int startIndex, int endIndex, int n);

int main()
{
	int arr[] = { 150,111,1000,99,300,10,189 };

	int ans = FrontN(arr, 0, 6, 2);
	printf("��2�������:%d\n", ans);

    return 0;
}

int FrontN(int arr[], int startIndex, int endIndex, int n)  
{  
    int midOne = arr[startIndex];//�ѵ�һ��ֵ��Ϊ֧��  
    int i = startIndex, j = endIndex;  
    if(i == j) //�ݹ����֮һ  
	{
        return arr[i];
	}
  
    if(i < j)
	{  
        while(i < j)
		{  
            while (i < j && arr[j] >= midOne) 
			{  
                j--;  
            }  
            if (i < j) 
			{  
                arr[i++] = arr[j];  
            }  
  
            while (i < j && arr[i] < midOne) 
			{  
                i++;  
            }  
            if (i < j) 
			{  
                arr[j--] = arr[i];  
            }  
        }  
        arr[i] = midOne;//֧���λ  
        //��ʱarr[i]������ض�������������λ���ϣ���ߵĶ�����С���ұߵĶ�������  
        int th = endIndex - i + 1;//�����±�Ϊi�����ڼ��󣬶�ʹ���±���м��㣻  
  
        if(th == n)
		{//�����ҵ�  
            return arr[i];  
        }  
        else
		{  
			if (th > n)//��֧���ұ���  
			{
				return FrontN(arr, i + 1, endIndex, n);
			}
			else//��֧������ҵ�(n-th)��,��Ϊ�ұ�th��������֧���  
			{
				return FrontN(arr, startIndex, i - 1, n - th);
			}
        }  
    }  
    return 0;  
}  