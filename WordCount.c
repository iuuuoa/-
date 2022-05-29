#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int CountC(char*file);//计算字符数 
int CountW(char*file);//计算单词数 

int CountC(char*file)//计算字符数 
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
	printf("字符数为：%d\n",num);
}

int CountW(char*file)//计算单词数 
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
		printf("单词数为：%d\n",w);
}

int main(int argc, char *argv[])
{
	char data;
	FILE *fb=fopen(argv[2],"r");
	if(!strcmp(argv[1],"-c"))//计算字符数 
	{
		CountC(argv[2]);
	}
	if(!strcmp(argv[1],"-w"))//计算单词数 
	{
		CountW(argv[2]);
	}
	if(!fb)
	{
		printf("读取文件失败！！\n");
		return -1;
	}
	else
	{
		printf("输入错误！！\n");
	}
	return 0;
}


