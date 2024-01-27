#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

typedef struct _account {
    char acc_name[20];
    char acc_bankname[20];
    int acc_number;
    char acc_account[20];
    char acc_pass[5];
    int acc_money;
    char acc_balance[20];
}Account;//���� ����ü 

struct PASSWORD {
    char check[5]; // ���� ��й�ȣ Ȯ��
    char new1[5]; //�� ��й�ȣ
    char new2[5]; //�� ��й�ȣ Ȯ��
}; // ������ �޴� ��й�ȣ ����ü

struct BANKINFO {
    char bankname[256]; //���� �̸�
    char username[256]; //���� ���� �̸�
    int balance; // ���� �ܾ�
    char password[256]; //���� ��й�ȣ
}; //���� �⺻ ����

Account person[100], tmp;

int count = 0, i, j, toAccount;
Account fileinfo[100];
Account accountinfo[100];

void ACCOUNT_INFO(void);//�������� ���� ���� �Լ�
void MENU(void); //���� �޴� �Լ�
int ACOUNT_MAKE(void); //���»��� �Լ�
int DEPOSIT(void); //�Ա� �Լ�
int WITHDRAW(void);//��� �Լ�
int SEND(void);//�۱� �Լ�
void BALANCE_CHECK(void);//�ܾ���ȸ �Լ�
void PASSWORD_CHANGE(void);//��й�ȣ ���� �Լ�
void ACCOUNT_LOCK(char* acc);//���� ���� �Լ�
int LOCK_CHECK(char* acc); //���� ���� ���� Ȯ�� �Լ�
int ACCOUNT_CHECK(char* acc); //���� ���� Ȯ�� �Լ�

void PASSWORD_CHECK(void); //������ �޴� ��й�ȣ Ȯ�� �Լ�
void SYSTEM_MENU(void); // ������ �޴� �Լ�
void BANKADD(void); //���� �߰� �Լ�
void ACCOUNT_UNLOCK(void); //���� ���� ���� �Լ�
void ATM_CHECK(void); //ATM �ܰ� Ȯ�� �Լ�
void ATM_ADD(void); //ATM �ܰ� �߰� �Լ�
void SYSTEM_PASSWORD_CHANGE(void);// ������ ��й�ȣ ���� �Լ�
