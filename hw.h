//�ܾ Ű���ϴ� ����Ʈ���� ���
typedef struct node *tree_pointer;
typedef struct node{
	char word[50];                 //�ܾ�=key
	int word_bin;                  //�ܾ��� �󵵼� üũ//ó�� ���� �ȰŶ�� 1�� �����Ų��.
	tree_pointer left_child;
	tree_pointer right_child;
}node;

tree_pointer root=NULL;             //root

//�Լ�
void open_file(char *f_name);//������ ���� �Լ�
void insert_bt(char *key);   //�ܾ ����Ʈ���� ����
void bt_print(tree_pointer); //����Ʈ������ ��� �ǰ� ���Ѵ�.
char*word_processor(char*);  //�ܾ �����ϴ� �Լ�.
void bt_serach(char*key);    //�˻��ϴ� �ܾ ����Ʈ������ ã���ִ� �Լ�
