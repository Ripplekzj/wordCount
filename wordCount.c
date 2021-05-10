#include<stdio.h>
#include<string.h>

void countC(FILE *fp);
void countW(FILE *fp);

int main(int argc,char *argv[])             
{
	FILE *fp;
	fp = fopen(argv[2],"r");//r代表read-only mode打开被统计文件，argv[2]存放的是第二个输入值，即被统计文件名字

		if(strcmp(argv[1],"-c") == 0)//-c代表使用统计字符功能，argv[1]存放的是第一个输入值，即-c或-w
		{
			countC(fp);
		}
		else if(strcmp(argv[1],"-w") == 0)//-w代表使用统计单词功能
		{
			countW(fp);
		}
		else{
			printf("wrong input");
		}
	return 0;
}
void countC(FILE *fp){
	int ch1;//ch1代表被取出的字符
	int count = 0;//计数器
	while((ch1 = fgetc(fp))!= EOF){//使用fgetc（）获取字符，字符非EOF则计数器加一
		count++;
	}
	printf("总计字符数: %d\n", count);
}

void countW(FILE *fp){
	int ch1;
	int count = 1;
	while((ch1 = fgetc(fp)) != EOF){
		if(ch1 == ',' || ch1 == ' '){//通过统计空格或,变相统计出单词数
			count++;
		}
	}
	printf("总计单词数: %d\n", count);
}

