#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contact.h"
//����
void menu() {
    printf("************************************\n");
    printf("****     1,add        2,del     ****\n");
    printf("****     3,serach     4,modify  ****\n");
    printf("****     5,show       6,sort    ****\n");
    printf("****     0,exit                 ****\n");
    printf("************************************\n");
}
int main()
{
    int input = 0;
    //������Ѹ¼
    
    struct Contact con;   
    //��ʼ����Ѹ¼
    Initcontact(&con);
    do {
        menu();
        printf("��ѡ��");
        scanf("%d", &input);
        switch (input) {
        case ADD:
            addcontact(&con);
            break;
        case DEL:
            delontact(&con);
            break;
        case SEARCH:
            serachontact(&con);
            break;
        case HOOIFY:
            modifyontact(&con);
            break;
        case SHOW:
            showontact(&con);
            break;
        case SORT:
            sortontact(&con);
            break;
        case EXTT:
            DestroyContact(&con);
            printf("�˳���Ѹ¼��");
            break;
        default:
            //printf("����������������룺");
                break;

            
        }
    } while (input);

      return 0;
}