#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int CountC(char*file);//�����ַ��� 
int CountW(char*file);//���㵥���� 

int CountC(char*file)//�����ַ��� 
{
	FILE *fb;
	fb=fopen(file,"r");
	char temp;
    int num = 0;
    temp = fgetc(fb); 
    while( temp != EOF )
	{
		temp = fgetc(fb);
    	num++;
    }
	printf("�ַ���Ϊ��%d\n",num);
}

int CountW(char*file)//���㵥���� 
{
	FILE *fb=fopen(file,"r");
	int w = 0;
    char a = fgetc(fb);
	while(a!= EOF)
	{
		if((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
		{
				w++;
			while((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
			{
				a =fgetc(fb);
            }
        }
		else
		{
			a =fgetc(fb);
		}
	}
		printf("������Ϊ��%d\n",w);
}

int main(int argc, char *argv[])
{
	char data;
	FILE *fb=fopen(argv[2],"r");
	if(!strcmp(argv[1],"-c"))//�����ַ��� 
	{
		CountC(argv[2]);
	}
	if(!strcmp(argv[1],"-w"))//���㵥���� 
	{
		CountW(argv[2]);
	}
	if(!fb)
	{
		printf("��ȡ�ļ�ʧ�ܣ���\n");
		return -1;
	}
	else
	{
		printf("������󣡣�\n");
	}
	return 0;
}


