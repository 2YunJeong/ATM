#pragma once
#include "header.h"

void MENU(void)
{
    system("cls");
    printf("=======ATM���α׷�=======\n");
    printf("1. ���»���\n2. �Ա�\n3. ���\n4. �۱�\n5. �ܾ���ȸ\n6. ��й�ȣ ����\n7. ������ �޴�\n0. ���α׷� ����\n");
    printf("=========================\n>> ");
}//���� �޴� �Լ�


void ACCOUNT_INFO(void) {

    int a;

    FILE* ftr1 = NULL;

    // ���� ���� ���н� ���� 
    if ((ftr1 = fopen("��������.txt", "a")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    for (a = 0; a < count; a++)
    {
        fprintf(ftr1, "����\t|�̸�\t|����\t\t|��й�ȣ\t|�ܾ�\n");
        fprintf(ftr1, "%s\t|%s\t|%d\t|%s\t|%d\n", person[a].acc_bankname, person[a].acc_name, person[a].acc_number, person[a].acc_pass, person[a].acc_money);
    }
    // ���� ���� 
    fclose(ftr1);
}

int ACOUNT_MAKE(void) {

    system("cls");

    FILE* bank, * newfile;
    char buffer[256];
    int count1 = 0, count2 = 0, END = 0, END2 = 0;

    printf("\n");

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    printf("[���»���]\n");
    printf("\n===��ϵǾ� �ִ� ����===\n");
    while (fgets(buffer, 64, bank)) {
        if (strstr(buffer, "����")) {
            printf("%s", buffer);
            count2++;
        }
    }
    printf("========================\n");
    printf("\n");
    fclose(bank);

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }
    if ((newfile = fopen("���� 2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    printf("���� �̸��� �Է��Ͻÿ�: ");
    scanf("%s", person[count].acc_bankname);

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, person[count].acc_bankname)) {
            fputs(buffer, newfile);

            printf("�̸� : ");
            scanf("%s", person[count].acc_name);

            srand(time(NULL));
            int b = 9, c, d;
            c = (int)pow(10, 8);
            d = (int)pow(10, 8);

            printf("���¹�ȣ ���� ���� \n");

            person[count].acc_number = (rand() % b + 1) * d + (rand() % c);
            printf("\n���¹�ȣ�� �����Ǿ����ϴ�.\n\n");
            printf("������ ���¹�ȣ : %d\n", person[count].acc_number);

            fprintf(newfile, "%d\n", person[count].acc_number);
        }
        else {
            if (strstr(buffer, "����")) {
                count1++;
            }
            fputs(buffer, newfile);
        }
    }

    if (count1 == count2) {
        printf("�ش� ������ ��ϵǾ� ���� ���� �����Դϴ�.\n\n");
        Sleep(2500);
        return 0;
    }

    while (END2 != 1) {
        printf("��й�ȣ : ");
        scanf("%s", person[count].acc_pass);

        if (strlen(person[count].acc_pass) != 4) {
            printf("\n��й�ȣ�� 4�ڸ� ���ڷ� �Է����ֽñ� �ٶ��ϴ�.\n\n");
        }
        else
            END2 = 1;
    }

    printf("���� ������ �Ϸ��Ͽ����ϴ�.\n");

    person[count].acc_money = 0;

    count++;//�Էµ� ���� ������ ī��Ʈ 

    ACCOUNT_INFO();

    Sleep(2000);

    fclose(bank);
    fclose(newfile);

    remove("����.txt");
    if (rename("���� 2.txt", "����.txt") != 0) {
        printf("�̸� ���� ����\n");
    }

    system("cls");
    for (i = 0; i < count; i++) {
        printf("======================\n\n");
        printf("����: %s\n", person[i].acc_bankname);
        printf("���¹�ȣ: %d\n", person[i].acc_number);
        printf("�̸�: %s\n", person[i].acc_name);
        printf("��й�ȣ: %s\n\n", person[i].acc_pass);
        printf("======================\n");
    }

    system("pause");

}//���»��� �Լ�

int DEPOSIT(void) {

    FILE* account, * newfile;
    FILE* bank;
    char bankbuffer[256];
    char buffer[256];
    char* ptr;
    char* arr[5] = { NULL, };
    char acc[20];
    int count1 = 0, count2 = 0, END = 0;
    int errcount = 0;
    int i = 0;
    int balance;

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    system("cls");

    printf("[�Ա�]\n");
    printf("���¹�ȣ : ");
    scanf("%d", &tmp.acc_number);
    sprintf(acc, "%d", tmp.acc_number);

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, acc)) {
            if (strstr(buffer, "x")) {
                printf("�ش� ���´� ���� �����Դϴ�.\n");
                Sleep(2000);
                return 0;
            }
        }
    }

    fclose(bank);

    if ((account = fopen("��������.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }
    if ((newfile = fopen("��������2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while (fgets(buffer, 256, account) != NULL) {
        if (strstr(buffer, acc)) {
            ptr = strtok(buffer, "\t|");
            while (ptr != NULL) {
                arr[i] = ptr;
                i++;
                ptr = strtok(NULL, "\t|");
            }
            balance = atoi(arr[4]);

            do {
                printf("��й�ȣ : ");
                scanf("%s", tmp.acc_pass);
                if (strcmp(tmp.acc_pass, arr[3]) == 0) {
                    printf("�Աݱݾ� : ");
                    scanf("%d", &tmp.acc_money);
                    balance += tmp.acc_money;

                    printf("�ԱݵǾ����ϴ�.\n");

                    Sleep(2000);

                    system("cls");
                    printf("======= ��ǥ =======\n");
                    struct tm* t;
                    time_t timer;
                    timer = time(NULL);
                    t = localtime(&timer);

                    printf("%d-%d-%d     %d:%d:%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

                    printf("����: %s\n", arr[0]);
                    printf("�Աݰ���: %s\n", arr[2]);
                    printf("����: %s\n", arr[1]);
                    printf("�Աݱݾ�: %d\n", tmp.acc_money);
                    printf("�����ܾ�: %d\n", balance);
                    printf("======================\n");

                    fprintf(newfile, "%s\t|%s\t|%s\t|%s\t|%d\n", arr[0], arr[1], arr[2], arr[3], balance);

                    system("pause");//�Է� ��� 
                    END = 1;
                }
                else {
                    errcount++;
                    printf("��й�ȣ ����. �ٽ� �Է����ֽñ� �ٶ��ϴ�.\n");
                    if (errcount == 3) {
                        printf("��й�ȣ %dȸ ����. ���°� �����Ǿ����ϴ�.\n\n", errcount);
                        fprintf(newfile, "%s\t|%s\t|%s\t|%s\t|%s\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
                        ACCOUNT_LOCK(&acc);
                        Sleep(2000);
                        END = 1;
                    }
                    else
                        printf("��й�ȣ %dȸ ����. 3ȸ ������ ���°� �����˴ϴ�.\n", errcount);
                }

            } while (END != 1);

        }
        else {
            fputs(buffer, newfile);
            count2++;
        }
        count1++;
    }

    if (count2 == count1) {
        printf("%d ���´� ���� �����Դϴ�.\n", tmp.acc_number);
        Sleep(2000);
        return 0;
    }

    fclose(account);
    fclose(newfile);

    remove("��������.txt");
    if (rename("��������2.txt", "��������.txt") != 0) {
        printf("�̸� ���� ����\n");
    }
}//�Ա� �Լ�

int WITHDRAW(void) {
    FILE* account, * newfile;
    char buffer[256];
    char* ptr;
    char* arr[5] = { NULL, };
    char acc[20];
    int END = 0;
    int errcount = 0;
    int i = 0;
    int balance;

    system("cls");

    printf("[���]\n");
    printf("���¹�ȣ : ");
    scanf("%d", &tmp.acc_number);
    sprintf(acc, "%d", tmp.acc_number);

    if (LOCK_CHECK(acc) == 1) {
        return 0;
    }

    if (ACCOUNT_CHECK(acc) == 1) {
        return 0;
    }

    if ((account = fopen("��������.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }
    if ((newfile = fopen("��������2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while (fgets(buffer, 256, account) != NULL) {
        if (strstr(buffer, acc)) {
            ptr = strtok(buffer, "\t|");
            while (ptr != NULL) {
                arr[i] = ptr;
                i++;
                ptr = strtok(NULL, "\t|");
            }
            balance = atoi(arr[4]);

            do {
                printf("��й�ȣ : ");
                scanf("%s", tmp.acc_pass);
                if (strcmp(tmp.acc_pass, arr[3]) == 0) {
                    printf("���� �ܾ� : %d\n", balance);
                    printf("��ݱݾ� : ");
                    scanf("%d", &tmp.acc_money);
                    balance -= tmp.acc_money;

                    if (balance >= 0) {
                        printf("��ݵǾ����ϴ�.\n");

                        Sleep(2000);

                        system("cls");
                        printf("======= ��ǥ =======\n");
                        struct tm* t;
                        time_t timer;
                        timer = time(NULL);
                        t = localtime(&timer);

                        printf("%d-%d-%d     %d:%d:%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

                        printf("����: %s\n", arr[0]);
                        printf("��ݰ���: %s\n", arr[2]);
                        printf("����: %s\n", arr[1]);
                        printf("��ݱݾ�: %d\n", tmp.acc_money);
                        printf("�����ܾ�: %d\n", balance);
                        printf("======================\n");

                        fprintf(newfile, "%s\t|%s\t|%s\t|%s\t|%d\n", arr[0], arr[1], arr[2], arr[3], balance);

                        system("pause");//�Է� ��� 
                        END = 1;
                    }
                    else {
                        printf("�ܾ��� �����մϴ�.\n");
                        Sleep(2000);
                        return 0;
                    }

                }
                else {
                    errcount++;
                    printf("��й�ȣ ����. �ٽ� �Է����ֽñ� �ٶ��ϴ�.\n");
                    if (errcount == 3) {
                        printf("��й�ȣ %dȸ ����. ���°� �����Ǿ����ϴ�.\n\n", errcount);
                        fprintf(newfile, "%s\t|%s\t|%s\t|%s\t|%s\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
                        ACCOUNT_LOCK(acc);
                        Sleep(2000);
                        END = 1;
                    }
                    else
                        printf("��й�ȣ %dȸ ����. 3ȸ ������ ���°� �����˴ϴ�.\n", errcount);
                }

            } while (END != 1);

        }
        else {
            fputs(buffer, newfile);
        }
    }

    fclose(account);
    fclose(newfile);

    remove("��������.txt");
    if (rename("��������2.txt", "��������.txt") != 0) {
        printf("�̸� ���� ����\n");
    }

}//��� �Լ�


int SEND(void) {
    FILE* account, * newfile;
    char buffer[256];
    char* ptr;
    char acc[20], acc2[20];
    int END = 0;
    int errcount = 0;
    int idx = 0, i = 0;
    int balance1, balance2;

    system("cls");

    printf("[�۱�]\n");
    printf("Ÿ �������� �۱� �� ������ 500���� �ΰ��˴ϴ�.\n");
    printf("�� ���� : ");
    scanf("%d", &tmp.acc_number);
    sprintf(acc, "%d", tmp.acc_number);

    if (LOCK_CHECK(acc) == 1) {
        return 0;
    }

    if (ACCOUNT_CHECK(acc) == 1) {
        return 0;
    }

    if ((account = fopen("��������.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while (fgets(buffer, 256, account) != NULL) {
        ptr = strtok(buffer, "\t|");
        strcat(fileinfo[idx].acc_bankname, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(fileinfo[idx].acc_name, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(fileinfo[idx].acc_account, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(fileinfo[idx].acc_pass, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(fileinfo[idx].acc_balance, ptr);
        ptr = strtok(NULL, "\t|");
        idx++;
    }

    for (i = 0; i < idx; i++) {
        if (strcmp(acc, fileinfo[i].acc_account) == 0) {
            do {
                printf("��й�ȣ : ");
                scanf("%s", tmp.acc_pass);
                if (strcmp(tmp.acc_pass, fileinfo[i].acc_pass) == 0) {
                    printf("�ݾ� : ");
                    scanf("%d", &tmp.acc_money);
                    balance1 = atoi(fileinfo[i].acc_balance);
                    balance1 -= tmp.acc_money;

                    if (balance1 >= 0) {
                        printf("�Ա� ���� : ");
                        scanf("%d", &toAccount);
                        sprintf(acc2, "%d", toAccount);

                        if (LOCK_CHECK(acc2) == 1) {
                            return 0;
                        }

                        if (ACCOUNT_CHECK(acc2) == 1) {
                            return 0;
                        }

                        for (int p = 0; p < idx; p++) {
                            if (strcmp(acc2, fileinfo[p].acc_account) == 0) {
                                balance2 = atoi(fileinfo[p].acc_balance);
                                if (strcmp(fileinfo[i].acc_bankname, fileinfo[p].acc_bankname) == 0) {
                                    balance2 += tmp.acc_money;
                                }
                                else {
                                    balance1 -= 500;
                                    if (balance1 >= 0) {
                                        balance2 += tmp.acc_money;
                                    }
                                    else {
                                        printf("�ܾ��� �����մϴ�.\n");
                                        Sleep(2000);
                                        return 0;
                                    }
                                }

                                printf("�۱� �Ǿ����ϴ�.\n");

                                Sleep(2000);

                                system("cls");
                                printf("======= ��ǥ =======\n");
                                struct tm* t;
                                time_t timer;
                                timer = time(NULL);
                                t = localtime(&timer);

                                printf("%d-%d-%d     %d:%d:%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

                                printf("����: %s\n", fileinfo[i].acc_bankname);
                                printf("�� ����: %d\n", tmp.acc_number);
                                printf("������: %s\n\n", fileinfo[i].acc_name);
                                printf("�Ա� ����: %d\n", toAccount);
                                printf("����: %s\n", fileinfo[p].acc_name);
                                printf("�����ݾ�: %d\n", tmp.acc_money);
                                printf("�����ܾ�: %d\n", balance1);
                                printf("======================\n");

                                sprintf(fileinfo[i].acc_balance, "%d\n", balance1);
                                sprintf(fileinfo[p].acc_balance, "%d\n", balance2);

                                system("pause");

                                END = 1;
                            }

                        }
                    }

                    else {
                        printf("�ܾ��� �����մϴ�.\n");
                        Sleep(2000);
                        return 0;
                    }

                }

                else {
                    errcount++;
                    printf("��й�ȣ ����. �ٽ� �Է����ֽñ� �ٶ��ϴ�.\n");
                    if (errcount == 3) {
                        printf("��й�ȣ %dȸ ����. ���°� �����Ǿ����ϴ�.\n\n", errcount);
                        ACCOUNT_LOCK(acc);
                        Sleep(2000);
                        END = 1;
                    }
                    else
                        printf("��й�ȣ %dȸ ����. 3ȸ ������ ���°� �����˴ϴ�.\n", errcount);
                }
            } while (END != 1);
        }
        else {
            continue;
        }
    }

    if ((newfile = fopen("��������2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    for (i = 0; i < idx; i++) {
        if (i == 0) {
            fprintf(newfile, "%s\t|%s\t|%s\t\t|%s\t|%s", fileinfo[i].acc_bankname, fileinfo[i].acc_name, fileinfo[i].acc_account, fileinfo[i].acc_pass, fileinfo[i].acc_balance);
        }
        else {
            fprintf(newfile, "%s\t|%s\t|%s\t|%s\t|%s", fileinfo[i].acc_bankname, fileinfo[i].acc_name, fileinfo[i].acc_account, fileinfo[i].acc_pass, fileinfo[i].acc_balance);
        }
    }

    fclose(account);
    fclose(newfile);

    remove("��������.txt");
    if (rename("��������2.txt", "��������.txt") != 0) {
        printf("�̸� ���� ����\n");
    }

    return 0;
} //�۱� �Լ�

void BALANCE_CHECK(void) {
    FILE* account;
    char buffer[256];
    char* ptr;
    char acc[20];
    int idx = 0, i = 0;

    system("cls");

    printf("[�ܾ���ȸ]\n");
    printf("�ܾ� ��ȸ�� ���¸� �Է��ϼ��� : ");
    scanf("%d", &tmp.acc_number);
    sprintf(acc, "%d", tmp.acc_number);
    printf("\n");

    if (LOCK_CHECK(acc) == 1) {
        return 0;
    }

    if (ACCOUNT_CHECK(acc) == 1) {
        return 0;
    }

    if ((account = fopen("��������.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while (fgets(buffer, 256, account) != NULL) {
        ptr = strtok(buffer, "\t|");
        strcat(accountinfo[idx].acc_bankname, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(accountinfo[idx].acc_name, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(accountinfo[idx].acc_account, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(accountinfo[idx].acc_pass, ptr);
        ptr = strtok(NULL, "\t|");
        strcat(accountinfo[idx].acc_balance, ptr);
        ptr = strtok(NULL, "\t|");
        idx++;
    }

    for (i = 0; i < idx; i++) {
        if (strcmp(acc, accountinfo[i].acc_account) == 0) {
            printf("���� �ܾ� : %s", accountinfo[i].acc_balance);
            system("pause");
            return 0;
        }
    }

    fclose(account);
}//�ܾ� ��ȸ �Լ�

void PASSWORD_CHANGE(void) {

    char new1[5], new2[5];
    int END = 0;
    char buffer[256];

    FILE* ftr1, * new = NULL;

    if ((ftr1 = fopen("��������.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    if ((new = fopen("�������� 2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }


    fscanf(ftr1, "%s\t|%s\t|%d\t|%s\t|%d\n", person[i].acc_bankname, person[i].acc_name, &person[i].acc_number, person[i].acc_pass, &person[i].acc_money);

    system("cls");

    printf("���¹�ȣ : ");
    scanf("%d", &tmp.acc_number);

    for (i = 0; i < count; i++)
    {
        if (person[i].acc_number == tmp.acc_number)
        {
            do {
                printf("���� ��й�ȣ�� �Է����ּ���: ");
                scanf("%s", &tmp.acc_pass);

                if (strcmp(person[i].acc_pass, tmp.acc_pass) == 0) {
                    while (END != 1) {
                        printf("\n�� ��й�ȣ�� �Է����ּ��� (4�ڸ� ����) : ");
                        scanf("%s", new1);

                        if (strlen(new1) != 4) {
                            printf("\n��й�ȣ ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
                        }//�� ��й�ȣ�� �ڸ����� 4�ڸ��� �ƴ� ��
                        else {
                            printf("�� ��й�ȣ�� �ٽ� �Է����ּ��� (4�ڸ� ����) : ");
                            scanf("%s", new2);

                            //�� ��й�ȣ ��ġ
                            if (strcmp(new1, new2) == 0) {
                                while (fgets(buffer, 256, ftr1) != NULL)
                                    fputs(buffer, new);
                                fprintf(new, "%s\t|%s\t|%d\t|%s\t|%d\n", person[i].acc_bankname, person[i].acc_name, person[i].acc_number, new1, person[i].acc_money);

                                strcpy(person[i].acc_pass, new1);

                                printf("\n��й�ȣ�� ����Ǿ����ϴ�.\n");
                                system("pause");
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
        }

        fclose(ftr1);
        fclose(new);

        remove("��������.txt");

        if (rename("�������� 2.txt", "��������.txt") != 0) {
            printf("�̸� ���� ����\n");
        }
    }

}//��й�ȣ ���� �Լ�

void ACCOUNT_LOCK(char* acc) {
    FILE* bank, * newfile;
    char buffer[256];

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    if ((newfile = fopen("����2.txt", "w")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, acc)) {
            fprintf(newfile, "%s x\n", acc);
        }
        else {
            fputs(buffer, newfile);
        }
    }

    fclose(bank);
    fclose(newfile);

    remove("����.txt");
    if (rename("����2.txt", "����.txt") != 0) {
        printf("�̸� ���� ����\n");
    }
}//���� ���� �Լ�


int LOCK_CHECK(char* acc) {
    int k = 0;
    FILE* bank;
    char buffer[256];

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, acc)) {
            if (strstr(buffer, "x")) {
                printf("�ش� ���´� ���� �����Դϴ�.\n");
                Sleep(2000);
                k = 1;
            }
        }
    }

    fclose(bank);
    return k;
}//���� ���� Ȯ�� �Լ�

int ACCOUNT_CHECK(char* acc) {
    int count1 = 0, count2 = 0;
    FILE* bank;
    char buffer[256];

    if ((bank = fopen("����.txt", "r")) == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    while ((fgets(buffer, 256, bank)) != NULL) {
        if (strstr(buffer, acc)) {
            return 0;
        }
        else
            count2++;
        count1++;
    }

    if (count1 == count2) {
        printf("��ϵǾ� ���� ���� ���¹�ȣ�Դϴ�.\n");
        Sleep(2000);
        return 1;
    }

    fclose(bank);
} //���� ���� Ȯ�� �Լ�
