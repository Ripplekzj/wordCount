#include<stdio.h>
#include<string.h>

void countC(FILE *fp);
void countW(FILE *fp);

int main(int argc,char *argv[])             
{
	FILE *fp;
	fp = fopen(argv[2],"r");//读取文件 

		if(strcmp(argv[1],"-c") == 0)//统计字符数
		{
			countC(fp);
		}
		else if(strcmp(argv[1],"-w") == 0)//统计单词数
		{
			countW(fp);
		}
		else{
			printf("wrong input");
		}
	return 0;
}
void countC(FILE *fp){
	int ch;
	int chars = 0;
	while((ch = fgetc(fp))!= EOF){
		chars++;
		printf("%c",ch);
	}
	printf("\ntotal chars: %d", chars);
}

void countW(FILE *fp){
	int ch;
	int words = 1;
	while((ch = fgetc(fp)) != EOF){
		//printf("%c", ch);
		if(ch == ',' || ch == ' '){
			words++;
		}
	}
	printf("\ntotal words: %d", words);
}

