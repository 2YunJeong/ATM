#pragma once
#include "header.h"

void PASSWORD_CHECK(void) {
    struct BANKINFO B;
    FILE* atm;
    char buffer[256];
    char check[256];
    int END = 0;

    if ((atm = fopen("atm.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    fgets(buffer, 256, atm);
    fscanf(atm, "%s %s %d %s", B.bankname, B.username, &B.balance, B.password);

    do {
        printf("��й�ȣ�� �Է��ϼ��� : ");
        scanf("%s", check);
        printf("\n");

        if (strcmp(check, B.password) == 0) {
            SYSTEM_MENU();
            return 0;
            END = 1;
        }
        else {
            printf("\n��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
        }
    } while (END != 1);

    fclose(atm);
}//��й�ȣ Ȯ�� �Լ�

void SYSTEM_MENU(void) {
    int choice; //�޴� ���� ����

    do {
        system("cls");

        printf("=======������ �޴�=======\n");
        printf("1. ���� �߰�\n2. ���� ���� ����\n3. ATM�ܰ� Ȯ��\n4. ATM�ܰ� ����\n5. ������ ��й�ȣ ����\n0. ���θ޴�\n");
        printf("=========================\n>> ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 0: //���θ޴�
            printf("���θ޴��� ���ư��ϴ�.\n\n");
            Sleep(2000);
            break;
        case 1: //���� �߰�
            BANKADD();
            break;
        case 2: //���� ���� ����
            ACCOUNT_UNLOCK();
            break;
        case 3: //ATM�ܰ� Ȯ��
            ATM_CHECK();
            break;
        case 4: //ATM�ܰ� ����
            ATM_ADD();
            break;
        case 5: //������ ��й�ȣ ����
            SYSTEM_PASSWORD_CHANGE();
            break;
        default: //�߸��� ���� �Է����� ��
            printf("0~5 ������ ���� �Է����ּ���.\n");
            Sleep(1000);
            break;
        }
    } while (choice != 0);
}// ������ �޴� �Լ�

void BANKADD(void) {
    system("cls");

    FILE* bank;
    char bank_add[256];

    if ((bank = fopen("����.txt", "a")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    printf("�߰��� ������ �Է����ּ��� : ");
    scanf("%s", bank_add);

    fprintf(bank, "%s\n", bank_add);
    printf("%s��(��) �߰��Ǿ����ϴ�.\n\n", bank_add);
    fclose(bank);
    Sleep(2000);
}// ���� �߰� �Լ�

void ACCOUNT_UNLOCK(void) {
    system("cls");

    FILE* bank, * newfile;
    char buffer[256];
    char account[256];
    int count1 = 0, count2 = 0;

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    if ((newfile = fopen("����2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    printf("������ ������ ���¹�ȣ�� �Է��ϼ��� : ");
    scanf("%s", account);

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, account)) {
            if (strstr(buffer, "x")) {
                fprintf(newfile, "%s\n", account);
                printf("%s ���°� �����Ǿ����ϴ�.\n", account);
            }
            else {
                printf("�ش� ���´� ���� ���°� �ƴմϴ�.\n");
                fputs(buffer, newfile);
            }
        }
        else {
            fputs(buffer, newfile);
            count2++;
        }
        count1++;
    }
    if (count2 == count1) {
        printf("%s ���´� ���� �����Դϴ�.\n", account);
    }

    fclose(bank);
    fclose(newfile);

    remove("����.txt");
    if (rename("����2.txt", "����.txt") != 0) {
        printf("�̸� ���� ����\n");
    }
    Sleep(2000);
}// ���� ���� ���� �Լ�

void ATM_CHECK(void) {
    system("cls");

    FILE* atm;
    char buffer[256];
    struct BANKINFO B;

    if ((atm = fopen("atm.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }
    fgets(buffer, 256, atm);
    fscanf(atm, "%s %s %d %s", B.bankname, B.username, &B.balance, B.password);
    printf("ATM�� ���� �ܰ�� %d�� �Դϴ�.\n", B.balance);

    fclose(atm);
    Sleep(2000);
}// ATM �ܰ� Ȯ�� �Լ�

void ATM_ADD(void) {
    system("cls");

    FILE* atm, * newfile;
    char buffer[256];
    int money;
    struct BANKINFO B;

    if ((atm = fopen("atm.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    if ((newfile = fopen("atm2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    fgets(buffer, 256, atm);

    fscanf(atm, "%s %s %d %s", B.bankname, B.username, &B.balance, B.password);
    printf("�߰��� �ݾ��� �Է��ϼ��� : ");
    scanf("%d", &money);
    B.balance += money;

    printf("ATM�� ���� �ܰ�� %d�� �Դϴ�.\n", B.balance);

    fputs(buffer, newfile);
    fprintf(newfile, "    %s   %s   %d       %s\n", B.bankname, B.username, B.balance, B.password);

    fclose(atm);
    fclose(newfile);

    remove("atm.txt");
    if (rename("atm2.txt", "atm.txt") != 0) {
        printf("�̸� ���� ����\n");
    }
    Sleep(2000);
}//ATM �ܰ� �߰� �Լ�

void SYSTEM_PASSWORD_CHANGE() {
    system("cls");

    struct PASSWORD P;
    struct BANKINFO B;
    FILE* atm, * newfile;
    char buffer[256];
    int END = 0;

    if ((atm = fopen("atm.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    if ((newfile = fopen("atm2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    fgets(buffer, 256, atm);
    fscanf(atm, "%s %s %d %s", B.bankname, B.username, &B.balance, B.password);

    do {
        printf("���� ��й�ȣ�� �Է����ּ��� : ");
        scanf("%s", P.check);

        //���� ��й�ȣ ��ġ
        if (strcmp(B.password, P.check) == 0) {
            while (END != 1) {
                printf("\n�� ��й�ȣ�� �Է����ּ��� (4�ڸ� ����) : ");
                scanf("%s", P.new1);
                printf("�� ��й�ȣ�� �ٽ� �Է����ּ��� (4�ڸ� ����) : ");
                scanf("%s", P.new2);

                //�� ��й�ȣ�� �ڸ����� 4�ڸ��� �ƴ� ��
                if (strlen(P.new1) != 4) {
                    printf("\n��й�ȣ ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
                }
                else {
                    //�� ��й�ȣ ��ġ
                    if (strcmp(P.new1, P.new2) == 0) {
                        fputs(buffer, newfile);
                        fprintf(newfile, "    %s   %s   %d       %s\n", B.bankname, B.username, B.balance, P.new1);
                        printf("\n��й�ȣ�� ����Ǿ����ϴ�.\n");
                        END = 1;
                    }

                    //�� ��й�ȣ ����ġ
                    else {
                        printf("\n��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
                    }
                }
            }
        }
        //���� ��й�ȣ ����ġ
        else {
            printf("\n��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n\n");
        }
    } while (END != 1);

    fclose(atm);
    fclose(newfile);

    remove("atm.txt");
    if (rename("atm2.txt", "atm.txt") != 0) {
        printf("�̸� ���� ����\n");
    }
    Sleep(2000);
} //������ ��й�ȣ ���� �Լ�
