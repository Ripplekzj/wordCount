#include<stdio.h>
#include<string.h>

void countC(FILE *fp);
void countW(FILE *fp);

int main(int argc,char *argv[])             
{
	FILE *fp;
	fp = fopen(argv[2],"r");//read-only mode 

		if(strcmp(argv[1],"-c") == 0)//-c mode 
		{
			countC(fp);
		}
		else if(strcmp(argv[1],"-w") == 0)//-w mode 
		{
			countW(fp);
		}
		else{
			printf("wrong input");
		}
	return 0;
}
void countC(FILE *fp){
	int ch1;
	int count = 0;
	while((ch1 = fgetc(fp))!= EOF){
		count++;
	}
	printf("总计字符数: %d\n", count);
}

void countW(FILE *fp){
	int ch1;
	int count = 1;
	while((ch1 = fgetc(fp)) != EOF){
		if(ch1 == ',' || ch1 == ' '){
			count++;
		}
	}
	printf("总计单词数: %d\n", count);
}

