#pragma warning(disable: 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "hw.h"
void main() {
	//���� 
	// ������ �̸��� �Է� �޾� open_file�� �Ѱ��ش�.
	//�ε���(�ڵ����� �ǰ��Ѵ�.)
	//�ε����� �Ǹ� �ڵ����� ����Ʈ �Լ��� �����Ͽ� �����Ѵ�.
	//ã������ �ܾ �Է� �ؼ� 
	//����Ʈ�� Ž������ �Ѱ� 
	char f_name_insert[50], key_word[50];//�����̸�, ����Ʈ���� Ű
	
	printf("������ �̸��� �Է��� �ּ���:");
	scanf("%s", f_name_insert);
	open_file(f_name_insert);
	printf("\n �ܾ ���� ���Դϴ�.\n");
	
	bt_print(root);
	
	printf("ã���÷��� �ܾ �Է����ּ���:");
	scanf("%s", key_word);
	bt_serach(key_word);
	getchar();
}

void open_file(char *f_name) {
	char word_k[50];
	FILE *f;
	f = fopen(f_name, "r"); //������ ����.

	while (!feof(f)) {      //������ ������ �������� �ܾ ��� �ҷ��´�.
		fscanf(f, "%s", word_k);
		insert_bt(word_processor(word_k));//�ܾ �����ѵ� �ܾ ����Ʈ���� ����
	}
	fclose(f);//������ ������ �۾��� ���ߴٸ� ������ �ݾ��ش�.
}

void insert_bt(char *key)
{
	tree_pointer temp;
	temp=(tree_pointer)malloc(sizeof(node));
	strcpy(temp->word,key);
	temp->word_bin=1;
	temp->left_child=temp->right_child=NULL;
	
	//�ܾ ó������ ���
	if(root==NULL){root=temp;}
	//�״��� �ܾ����
	else{
		tree_pointer p,c; //��Ʈ�� ����ؼ� �ǲ���⸦ ����Ű�� �ֵ�.
		p=(tree_pointer)malloc(sizeof(node));
		c=(tree_pointer)malloc(sizeof(node));
		p=NULL;
		c=root;
		//p(parent),c(child)�� �ܾ �����ؾ��� ��ġ�� ã�ư��� ���� ����
		while(c){
		p=c;	//������ �Ѵܰ辿 ������������ ��ġ�� ���
		//�ܾ ���ؼ� key�� ������� �������� �̵�
		if(1==(strcmp(temp->word,c->word))){c=c->left_child;}
		//key�� ū��� ���������� �̵�
		else if(-1==(strcmp(temp->word,c->word))){c=c->right_child;}
		//������� �󵵼��� �ϳ� ������������ Ż���Ѵ�.
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
		printf("�ܾ�: %s �󵵼�: %d\n",ptr->word,ptr->word_bin);
		bt_print(ptr->left_child);
		
	}
}
void bt_serach(char*key) 
{
	tree_pointer ptr;
	ptr=root;
	int serch=0;//ã������ �ܾ �ְ� ���� ��Ÿ����.
	//�ܾ �����ϴ°�� serch�� 1�� �ٲپ� �ܾ ã������ �˸���.
	while(ptr){
	if(0==(strcmp(key,ptr->word))){
		serch =1;
		printf("ã���÷��� �ܾ�: %s �󵵼�: %d\n",ptr->word,ptr->word_bin);
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
	//���°�� serch�� 0���� ���� �ǹǷν� �ܾ ������ �˸���.
	if(serch==0){
		printf("ã���÷��� �ܾ �����ϴ�");
		getchar();}
}
char*word_processor(char*word){
		//���ĺ��� �ƴ� �κе��� null���ڷ� ó���Ѵ�.
	//�̶� �ƽ�Ű �ڵ带 �̿��ϰԵȴ�.

	//�߰��߰����ĺ��� �ƴѺκ��� ���� ���鹮�ڷ� �ٲ��ش�.
	for (int j = 0; j<30 && !(word[j] == NULL); j++){
		if (!(97 <= word[j] && word[j] <= 122) && !(65 <= word[j] && word[j] <= 90))
			word[j] = ' ';
		else
			continue;
	}

	//�ܾ��� ù���ڰ� ���鹮���ϰ�� ����ؼ� �������� ��ܿ´�.
	while (word[0] == ' '){
		for (int i = 0; i<30 && !(word[i] == NULL); i++){
			if (word[i] == ' '){
				for (int j = i; j<29 && !(word[j] == NULL); j++){
					word[j] = word[j + 1];
				}
			}
		}
	}

	//�ܾ��� ù�Ӹ��� ���鹮�ڰ� �ƴѰ�� ��� ������ ��ܿ´�.
	for (int a = 0; a<30 && !(word[a] == NULL); a++){
		for (int i = a; i<30 && !(word[i] == NULL); i++){
			if (word[i] == ' '){
				for (int j = i; j<29 && !(word[j] == NULL); j++){
					word[j] = word[j + 1];
				}
			}
		}
	}

	//�빮�ڸ� �ҹ��ڷ� �ٲٴ� �۾�.
	for (int j = 0; j<30; j++){
		if (word[j] == NULL)
			break;
		else if (!(97 <= word[j] && word[j] <= 122))
			word[j] = (char)((int)word[j] + 32);
	}

	return word;
}