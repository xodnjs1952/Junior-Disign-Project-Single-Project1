//단어를 키로하는 이진트리의 노드
typedef struct node *tree_pointer;
typedef struct node{
	char word[50];                 //단어=key
	int word_bin;                  //단어의 빈도수 체크//처음 생성 된거라면 1을 저장시킨다.
	tree_pointer left_child;
	tree_pointer right_child;
}node;

tree_pointer root=NULL;             //root

//함수
void open_file(char *f_name);//파일을 여는 함수
void insert_bt(char *key);   //단어를 이진트리에 저장
void bt_print(tree_pointer); //이진트리에서 출력 되게 끔한다.
char*word_processor(char*);  //단어를 가공하는 함수.
void bt_serach(char*key);    //검색하는 단어를 이진트리에서 찾아주는 함수
