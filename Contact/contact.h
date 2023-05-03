#define _CRT_SECURE_NO_WARNINGS
//#define max 1000
#define max_name 20
//#define max_age 20
#define max_sex 5
#define max_tele 12
#define max_addr 30
#define CAP_SC 3


//声明函数
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
//腾迅录的类型
struct Contact {
	struct PeoTnfa *data;//存放一个信息
	int size;//记录当前已有元素个数 
	int capacity;//当前通讯录最大容量

};
//声明函数
void Initcontact(struct Contact* ps);
void addcontact(struct Contact* ps);
void showontact(struct Contact* ps);
//删除指定的联系人
void delontact(struct Contact* ps);
//查找
void serachontact(struct Contact* ps);
//修改指定联系人
void modifyontact(struct Contact* ps);
//排序
void sortontact(struct Contact* ps);
//释放空间
void DestroyContact(struct Contact* ps);