#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i,n,temp=0;
	int flag=0;
	printf("enter a string:");
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i] !=str[n-i-1])
		{
		temp=1;
		break;
			
		}
	}
	if (temp==0)
	{
		printf("string is a palindrome");
	}
	else
	{
		printf("string is not a palindrome");
	}
	return 0;
}

