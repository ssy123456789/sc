#define _CRT_SECURE_NO_WARNINGS//实现函数功能
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void Initcontact(struct Contact* ps) {
	//(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;//设置腾迅录最终有0个元素
	ps->data = (struct PeoTnfa*)malloc(CAP_SC * sizeof(struct PeoTnfa));
	if (ps->data == NULL) {
		return;
	 }
	ps->data = 0;
	ps->capacity = CAP_SC;


}
void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		//增容
		struct PeoTnfa* pstr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoTnfa));
		if (pstr != NULL) {
			ps->data = pstr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else {
			printf("增容失败\n");
		}
	}
}
void addcontact(struct Contact* ps) {
	/*if (ps->size == max) {
		printf("腾迅录已满\n");
	}
	else {	
	}*/
	//检测腾迅录的容量，满了增加，不满啥事不干
	CheckCapacity(ps);

	printf("请输入姓名：");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成\n");
}
void showontact(struct Contact* ps) {
	if (ps->size == 0) {
		printf("腾迅录为空\n");
	}
	else {
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","名字","年龄","性别","电话","地址");
		for (i = 0; i < ps->size; i++) {
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->data[i].name, ps->data[i].age,
				ps->data[i].sex, ps->data[i].tele,
				ps->data[i].addr
			);
		}
	}
}
int findbyname(struct Contact* ps, char name[max_name]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == strcmp(ps->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}
void delontact(struct Contact* ps) {
	char name[max_name];
	printf("请输入要删除人的名字\n：");
	scanf("%s", name);
	//查找要删除的位置
	int pos = findbyname(ps, name);
	if(pos==-1) {
		printf("联系人不存在\n");
	}
	else {
		//删除
		int j = 0;
		for (j = pos; j < ps->size-1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功!\n");
	}
}
void serachontact(struct Contact* ps) {
	char name[max_name];
	printf("请输入要查找人的名：");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1) {
		printf("联系人不存在\n");
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name, ps->data[pos].age,
			ps->data[pos].sex, ps->data[pos].tele,
			ps->data[pos].addr
		);
	}
}
void modifyontact(struct Contact* ps) {
	char name[max_name];
	printf("请输入要修改人的名：");
	scanf("%s", name);
	char pos = findbyname(ps, name);
	if (pos == -1) {
		printf("联系人不存在\n");
	}
	else {
		printf("请输入姓名：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);
		ps->size++;
		printf("修改成功\n");
	}
}
void sortontact(struct Contact* ps) {
	int i = 0; 
	for (i = 0; i <ps-> size-1; i++) {
		int j = 0;
		for (i = 0; j < ps->size - 1 - i; j++) {
			if (ps->data[j].age > ps->data[j + 1].age) {
				int temp = ps->data[j].age;
				ps->data[j].age = ps->data[j + 1].age;
				ps->data[j + 1].age = ps->data[j].age;

			}
		}
	}
	printf("排序成功\n");

} 
void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}