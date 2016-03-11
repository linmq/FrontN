// FrontN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int FrontN(int a[], int startIndex, int endIndex, int n);

int main()
{
	int arr[] = { 150,111,1000,99,300,10,189 };

	int ans = FrontN(arr, 0, 6, 2);
	printf("第2大的数是:%d\n", ans);

    return 0;
}

int FrontN(int arr[], int startIndex, int endIndex, int n)  
{  
    int midOne = arr[startIndex];//把第一个值作为支点  
    int i = startIndex, j = endIndex;  
    if(i == j) //递归出口之一  
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
        arr[i] = midOne;//支点归位  
        //此时arr[i]这个数必定处于它真正的位置上，左边的都比他小，右边的都比他大；  
        int th = endIndex - i + 1;//计算下标为i的数第几大，都使用下标进行计算；  
  
        if(th == n)
		{//正好找到  
            return arr[i];  
        }  
        else
		{  
			if (th > n)//在支点右边找  
			{
				return FrontN(arr, i + 1, endIndex, n);
			}
			else//在支点左边找第(n-th)大,因为右边th个数都比支点大  
			{
				return FrontN(arr, startIndex, i - 1, n - th);
			}
        }  
    }  
    return 0;  
}  