#define _CRT_SECURE_NO_WARNINGS
//#define max 1000
#define max_name 20
//#define max_age 20
#define max_sex 5
#define max_tele 12
#define max_addr 30
#define CAP_SC 3


//��������
struct PeoTnfa {
	char name[max_name];
	int age;
	char sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];

};
enum option {
	EXTT,
	ADD,
	DEL,
	SEARCH,
	HOOIFY,
	SHOW,
	SORT
};
//��Ѹ¼������
struct Contact {
	struct PeoTnfa *data;//���һ����Ϣ
	int size;//��¼��ǰ����Ԫ�ظ��� 
	int capacity;//��ǰͨѶ¼�������

};
//��������
void Initcontact(struct Contact* ps);
void addcontact(struct Contact* ps);
void showontact(struct Contact* ps);
//ɾ��ָ������ϵ��
void delontact(struct Contact* ps);
//����
void serachontact(struct Contact* ps);
//�޸�ָ����ϵ��
void modifyontact(struct Contact* ps);
//����
void sortontact(struct Contact* ps);
//�ͷſռ�
void DestroyContact(struct Contact* ps);