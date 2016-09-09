#include <stdio.h>

/******************************************************************************
ģ�ظ�ƽ�����㷨 ������ַ http://blog.csdn.net/yxtxiaotian/article/details/52464496

��ģ�㷨��ģ�ظ�ƽ���㷨����ʱ�临�Ӷ�O(log(n))��ʵ�֡�
Ӧ�ã�����b��n�η� ģm��������RSA�ӽ����㷨�������ģ��
******************************************************************************/
/******************************************************************************
����b��n�η� ģm�����ݹ�ʵ�֣�
�ݹ鹫ʽ��
b^n (mod m) = b* (b^(n-1) (mod m)) (mod m)
******************************************************************************/ 
int powerModRec(int b, int n, int m)
{
	if(0==n)
		return 1;
	return b*powerModRec(b, n-1, m)%m;
}

/*����b��n�η� ģm�� ���ǵݹ�ʵ��-->��ģ�㷨��
*/ 
int powerMod(int b, int n, int m)
{
	printf("����ĵ���Ϊb=%d��ָ��Ϊn=%d��ģΪm=%d\n", b, n, m);
	// a��ż���������ʼ��Ϊ1. 
	int a=1;
	int i, k=0, num=n;
	/*����ָ���Ķ�����λ��k.
	*/ 
	while(num)
	{
		num = num>>1;
		++k;
	}
	
	// Ҳ���Խ�ָ���Ķ�������һ���������д�ţ�����ȡֵ.
	for(i=0; i<k; ++i)
	{
		// ȡn�Ķ����Ƶĵ�iλ���ж��Ƿ�Ϊ1.
		if((n>>i)&1)
			a = a*b %m;
		b = b*b %m;
	}
	
	return a;
}

int main()
{
	//printf("�ֱ��������b��ָ��n��ģm��ֵ��");
	int b, n, m; 
	//scanf("%d%d%d", &b, &n, &m);
	b=12996, n=227, m=37909;
	printf("����ĵ���Ϊb=%d��ָ��Ϊn=%d��ģΪm=%d\n", b, n, m);
	int result = 0;
	result = powerModRec(b, n, m);
	printf("�ݹ飺b^n (mod m) = %d\n", result);

	result = powerMod(b, n, m);
	printf("�ǵݹ飺b^n (mod m) = %d\n", result);
	return 0;
}

/*
testData: b=12996, n=227, m=37909;
output: result = b^n (mod m) = 7775;
*/

