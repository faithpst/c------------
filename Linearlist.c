/*
 * linearlist.c
 *
 *  Created on: 2013-4-21
 *      Author: pacing
 */
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define MAXSIZE 1024

typedef char datatype;

typedef struct {
	datatype data[MAXSIZE];
	int last;
}sequenlist;

sequenlist *L;

//建立顺序表L
sequenlist *Create() {
	int i=0; char ch;
	L=(sequenlist *)malloc(sizeof(sequenlist));
	L->last=-1;
	printf("请输入顺序表L中的元素，以‘#’结束。\n");
	while(((ch=getchar())!='#')){
		L->data[i++]=ch;
		L->last++;
	}
	return L;
}    //Create

//将新节点x插入顺序表L的第i个位置
int Insert(sequenlist *L,int x,int i) {
	int j;
    if((L->last)>=MAXSIZE-1){
    	printf("overflow \n");
    	return 0;
    }
    else
		if((i<1)||(i>(L->last)+2)) {
		printf("error\n");
		return 0;
	}
    else {
    	for (j=L->last;j>=i-1;j--)
    		L->data[j+1]=L->data[j];
    	L->data[i-1]=x;
    	L->last=L->last+1;
    }
    return 1;
}  //Insert

int Delete(sequenlist *L,int i){
    int j;
    if ((i<1)||(i>L->last+1)
    {
       printf("error\n");
       return 0;
    }
    else {
       for (j=i; j < L->last; j++)
            L->data[j-1]=L->data[j];
       L->last--;
    }
}


//输出顺序表L的内容
void Output(sequenlist *L) {
	int i;
	printf("\n顺序表L中的元素为：");
	for (i = 0; i <=L->last; i++) {
		printf("%c",L->data[i]);
    printf("\n");
	}
}

int main() {
	char ch;
	int i,ret;
	L=Create();
	printf("\n请输入插入的字符:"); scanf("%c",&ch);
	printf("\n请输入插入字符的位置："); scanf("%d",&i);
	ret=Insert(L,ch,i);
	if (ret) {
		Output(L);
	}
	return 0;
}//Output
