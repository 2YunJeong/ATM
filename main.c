#include "header.h"
#include "administrator.h"
#include "user.h"

int main() {

    int x;

    do
    {
        MENU();
        scanf_s("%d", &x);//�޴��� �Է� ���� 
        switch (x)
        {
        case 0://���α׷� ����
            printf("ATM�� ���α׷��� ����˴ϴ�.\n");
            break;
        case 1://���»���
            ACOUNT_MAKE();
            break;
        case 2://�Ա� 
            DEPOSIT();
            break;
        case 3://��� 
            WITHDRAW();
            break;
        case 4://�۱� 
            SEND();
            break;
        case 5://�ܾ���ȸ
            BALANCE_CHECK();
            break;
        case 6://��й�ȣ ����
            PASSWORD_CHANGE();
            break;
        case 7://�����ڸ޴�
            PASSWORD_CHECK();
            break;
        default: //�߸��� ���� �Է����� ��
            printf("0~7 ������ ���� �Է����ּ���.\n");
            Sleep(1000);
            break;
        }
    } while (x != 0);

	return 0;
}