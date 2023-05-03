#define _CRT_SECURE_NO_WARNINGS//ʵ�ֺ�������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void Initcontact(struct Contact* ps) {
	//(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;//������Ѹ¼������0��Ԫ��
	ps->data = (struct PeoTnfa*)malloc(CAP_SC * sizeof(struct PeoTnfa));
	if (ps->data == NULL) {
		return;
	 }
	ps->data = 0;
	ps->capacity = CAP_SC;


}
void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		//����
		struct PeoTnfa* pstr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoTnfa));
		if (pstr != NULL) {
			ps->data = pstr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");
		}
	}
}
void addcontact(struct Contact* ps) {
	/*if (ps->size == max) {
		printf("��Ѹ¼����\n");
	}
	else {	
	}*/
	//�����Ѹ¼���������������ӣ�����ɶ�²���
	CheckCapacity(ps);

	printf("������������");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳ�\n");
}
void showontact(struct Contact* ps) {
	if (ps->size == 0) {
		printf("��Ѹ¼Ϊ��\n");
	}
	else {
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫɾ���˵�����\n��");
	scanf("%s", name);
	//����Ҫɾ����λ��
	int pos = findbyname(ps, name);
	if(pos==-1) {
		printf("��ϵ�˲�����\n");
	}
	else {
		//ɾ��
		int j = 0;
		for (j = pos; j < ps->size-1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�!\n");
	}
}
void serachontact(struct Contact* ps) {
	char name[max_name];
	printf("������Ҫ�����˵�����");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1) {
		printf("��ϵ�˲�����\n");
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name, ps->data[pos].age,
			ps->data[pos].sex, ps->data[pos].tele,
			ps->data[pos].addr
		);
	}
}
void modifyontact(struct Contact* ps) {
	char name[max_name];
	printf("������Ҫ�޸��˵�����");
	scanf("%s", name);
	char pos = findbyname(ps, name);
	if (pos == -1) {
		printf("��ϵ�˲�����\n");
	}
	else {
		printf("������������");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		ps->size++;
		printf("�޸ĳɹ�\n");
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
	printf("����ɹ�\n");

} 
void DestroyContact(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}