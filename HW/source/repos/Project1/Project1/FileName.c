#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    int jekyllHP = 100;
    int pigeonHP = 50;    // ���� ��ѱ��� ü��
    int dogHP = 80;       // ���� ���� ü��
    int hasGun = 0;       // ���� �����ϰ� �ִ��� ����
    int selectedGun = 0;  // ���õ� ���� ����
    int isDone = 0;       // ���� �÷���
    int gold = 30;        // �ʱ� ���

    int ak47Damage = 40;
    int m16Damage = 20;
    int m1895Damage = 5;

    int isPigeonDefeated = 0;  // ���� ��ѱ⸦ ó���ߴ��� ����
    int isDogDefeated = 0;     // ���� ���� ó���ߴ��� ����
    int isJekyllDefeated = 0;  // ��ų�ڻ縦 ó���ߴ��� ����

    while (!isDone) {
        printf("������ ���� ���ΰ�?\n 1. ���� �緯 �Դ�.\n 2. ����Ʈ�� ������ �Դ�.\n 3. �̾߱⸦ �Ѵ�.\n ����� ������?");
        if (scanf("%d", &a) != 1) {
            printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
            return 1;  // ���� �ڵ� ��ȯ
        }

        switch (a) {
        case 1:
            printf("\n��, ���� ���� ���ڳ�\n");
            printf("\n 1. AK-47 \n 2. M16 \n 3. ���� M1895\n ����� ������?");
            if (scanf("%d", &b) != 1) {
                printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
                return 1;  // ���� �ڵ� ��ȯ
            }
            switch (b) {
            case 1:
                printf("\n��, ���� AK-47�ϼ�. 30����\n");
                hasGun = 1;       // ���� ������
                selectedGun = 1;  // AK-47 ���õ�
                gold -= 30;       // ���� ��� ��� ����
                break;
            case 2:
                printf("\n��, ���� M16�ϼ�. 15����\n");
                hasGun = 1;       // ���� ������
                selectedGun = 2;  // M16 ���õ�
                gold -= 30;       // ���� ��� ��� ����
                break;
            case 3:
                printf("\n��, ���� ���� M1895�ϼ�. 5����\n");
                hasGun = 1;       // ���� ������
                selectedGun = 3;  // ���� M1895 ���õ�
                gold -= 30;       // ���� ��� ��� ����
                break;
            }
            break;
        case 2:
            if (!hasGun) {
                printf("\n���� ��� ���� �ʾҽ��ϴ�. ���� ���� �緯 ������.\n");
                break;
            }

            printf("\n� ����Ʈ�� ������ �Գ�\n");
            printf("\n 1. ���� ��ѱ� ó���ϱ�\n 2. ���� �� ó���ϱ�\n 3. ��ų�ڻ� ó���ϱ�\n 4. �ٽ� �����ϱ�\n ����� ������?");
            if (scanf("%d", &b) != 1) {
                printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
                return 1;  // ���� �ڵ� ��ȯ
            }
            switch (b) {
                // ... (���� ����)
            }
            break;
        case 3:
            printf("\n�ٸ� ����Ʈ�� ���ٰ�?\n");
            printf("\n 1. ���� ��ѱ� ó���ϱ�\n 2. ���� �� ó���ϱ�\n 3. ��ų�ڻ�� ��ȭ�ϱ�\n ����� ������?");
            if (scanf("%d", &b) != 1) {
                printf("�Է� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.\n");
                return 1;  // ���� �ڵ� ��ȯ
            }
            switch (b) {
                // ... (���� ����)
            }
            break;
        case 4:
            printf("\n�����߳�. ���α׷��� �����մϴ�.\n");
            isDone = 1; // ���� ���� ����
            break;
        default:
            printf("\n�����߳�.\n");
            isDone = 1; // ���� ���� ����
        }
    }

    return 0;
}