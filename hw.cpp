#pragma warning(disable: 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "hw.h"
void main() {
	//할일 
	// 파일의 이름을 입력 받아 open_file에 넘겨준다.
	//인덱싱(자동으로 되게한다.)
	//인덱싱이 되면 자동으로 프린트 함수를 실행하여 열게한다.
	//찾으려는 단어를 입력 해서 
	//이진트리 탐색으로 넘겨 
	char f_name_insert[50], key_word[50];//파일이름, 이진트리의 키
	
	printf("파일의 이름을 입력해 주세요:");
	scanf("%s", f_name_insert);
	open_file(f_name_insert);
	printf("\n 단어를 정리 중입니다.\n");
	
	bt_print(root);
	
	printf("찾으시려는 단어를 입력해주세요:");
	scanf("%s", key_word);
	bt_serach(key_word);
	getchar();
}

void open_file(char *f_name) {
	char word_k[50];
	FILE *f;
	f = fopen(f_name, "r"); //파일을 연다.

	while (!feof(f)) {      //파일이 끝나는 지점까지 단어를 계속 불러온다.
		fscanf(f, "%s", word_k);
		insert_bt(word_processor(word_k));//단어를 가공한뒤 단어를 이진트리에 저장
	}
	fclose(f);//파일의 끝까지 작업을 다했다면 파일을 닫아준다.
}

void insert_bt(char *key)
{
	tree_pointer temp;
	temp=(tree_pointer)malloc(sizeof(node));
	strcpy(temp->word,key);
	temp->word_bin=1;
	temp->left_child=temp->right_child=NULL;
	
	//단어가 처음들어온 경우
	if(root==NULL){root=temp;}
	//그다음 단어부터
	else{
		tree_pointer p,c; //루트는 계속해서 맨꼭대기를 가리키고 있따.
		p=(tree_pointer)malloc(sizeof(node));
		c=(tree_pointer)malloc(sizeof(node));
		p=NULL;
		c=root;
		//p(parent),c(child)는 단어를 저장해야할 위치를 찾아가기 위한 수단
		while(c){
		p=c;	//실제로 한단계씩 내려갈때마다 위치를 기억
		//단어를 비교해서 key가 작은경우 왼쪽으로 이동
		if(1==(strcmp(temp->word,c->word))){c=c->left_child;}
		//key가 큰경우 오른쪽으로 이동
		else if(-1==(strcmp(temp->word,c->word))){c=c->right_child;}
		//같은경우 빈도수만 하나 증가시켜준후 탈출한다.
		else if(0==(strcmp(temp->word,c->word))){
			c->word_bin++;
			break;}
		}
		if(1==(strcmp(temp->word,p->word))){p->left_child=temp;}
		else if(-1==(strcmp(temp->word,p->word))) {p->right_child=temp;}
	}
}

void bt_print(tree_pointer ptr) 
{       
		if(ptr){
		bt_print(ptr->right_child);
		printf("단어: %s 빈도수: %d\n",ptr->word,ptr->word_bin);
		bt_print(ptr->left_child);
		
	}
}
void bt_serach(char*key) 
{
	tree_pointer ptr;
	ptr=root;
	int serch=0;//찾으려는 단어가 있고 없을 나타낸다.
	//단어가 존재하는경우 serch를 1로 바꾸어 단어를 찾았음을 알린다.
	while(ptr){
	if(0==(strcmp(key,ptr->word))){
		serch =1;
		printf("찾으시려는 단어: %s 빈도수: %d\n",ptr->word,ptr->word_bin);
		getchar();
		break;
		}
	else if(1==(strcmp(key,ptr->word))){
		ptr=ptr->left_child;
		continue;}
	else if(-1==(strcmp(key,ptr->word))){
		ptr=ptr->right_child;
		continue;}
	}
	//없는경우 serch가 0으로 유지 되므로써 단어가 없음을 알린다.
	if(serch==0){
		printf("찾으시려는 단어가 없습니다");
		getchar();}
}
char*word_processor(char*word){
		//알파벳이 아닌 부분들을 null문자로 처리한다.
	//이때 아스키 코드를 이용하게된다.

	//중간중간알파벳이 아닌부분을 전부 공백문자로 바꿔준다.
	for (int j = 0; j<30 && !(word[j] == NULL); j++){
		if (!(97 <= word[j] && word[j] <= 122) && !(65 <= word[j] && word[j] <= 90))
			word[j] = ' ';
		else
			continue;
	}

	//단어의 첫글자가 공백문자일경우 계속해서 앞쪽으로 당겨온다.
	while (word[0] == ' '){
		for (int i = 0; i<30 && !(word[i] == NULL); i++){
			if (word[i] == ' '){
				for (int j = i; j<29 && !(word[j] == NULL); j++){
					word[j] = word[j + 1];
				}
			}
		}
	}

	//단어의 첫머리가 공백문자가 아닌경우 계속 앞으로 당겨온다.
	for (int a = 0; a<30 && !(word[a] == NULL); a++){
		for (int i = a; i<30 && !(word[i] == NULL); i++){
			if (word[i] == ' '){
				for (int j = i; j<29 && !(word[j] == NULL); j++){
					word[j] = word[j + 1];
				}
			}
		}
	}

	//대문자를 소문자로 바꾸는 작업.
	for (int j = 0; j<30; j++){
		if (word[j] == NULL)
			break;
		else if (!(97 <= word[j] && word[j] <= 122))
			word[j] = (char)((int)word[j] + 32);
	}

	return word;
}