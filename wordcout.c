#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
	int charCount=0;
	int wordCount=0;
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){
		printf("文件不能打开\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){
				if(isLastBlank==0){
					wordCount++;
				}
				isLastBlank=1;
			}else if(c!='\n'&&c!='\r'){
				charCount++;
				isLastBlank=0;
			}
 
		}
		if(isLastBlank==0)
			wordCount++;
		isLastBlank=1;
	}
	fclose(fp);
	printf("字符数：%d\n",charCount);
	printf("单词数：%d\n",wordCount);
 
	
}
void main(){
	char filename[]="";
	wcexe(filename);
}
