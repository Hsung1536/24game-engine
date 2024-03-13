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
        printf("������ ���� ���ΰ�?\n 1. ���� �緯 �Դ�.\n 2. ����Ʈ�� ������ �Դ�.\n 3. �̾߱⸦ �Ѵ�.\n ����� ������? ");
        if (scanf("%d", &a) != 1) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (a) {
        case 1:
            printf("\n��, ���� ���� ���ڳ�\n");
            printf(" 1. AK-47 \n 2. M16 \n 3. ���� M1895\n ����� ������? ");
            if (scanf("%d", &b) != 1) {
                printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
                while (getchar() != '\n');
                continue;
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
            default:
                printf("\n�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
                break;
            }
            break;
        case 2:
            if (!hasGun) {
                printf("\n���� ��� ���� �ʾҽ��ϴ�. ���� ���� �緯 ������.\n");
                break;
            }

            printf("\n� ����Ʈ�� ������ �Գ�\n");
            printf(" 1. ���� ��ѱ� ó���ϱ�\n 2. ���� �� ó���ϱ�\n 3. ��ų�ڻ� ó���ϱ�\n 4. �ٽ� �����ϱ�\n ����� ������? ");
            if (scanf("%d", &b) != 1) {
                printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
                while (getchar() != '\n');
                continue;
            }

            switch (b) {
            case 1:
                if (!isPigeonDefeated) {
                    printf("\n���� ��ѱ� ó���ϱ�� ��û �����Ŵ�. ���� ó���ϰ� �´ٸ� 30��带 ����\n");
                    pigeonHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n���� ��ѱ��� ���� HP: %d\n", pigeonHP);

                    if (pigeonHP <= 0) {
                        isPigeonDefeated = 1;
                        printf("\n���� ��ѱ⸦ ó���߽��ϴ�. �������� 30��带 ȹ���߽��ϴ�.\n");
                        gold += 30;  // ��ѱ� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            case 2:
                if (!isDogDefeated) {
                    printf("\n���� �� ó���ϱ�� ����� ����Ʈ��. ó���ϸ� 50��带 ����\n");
                    dogHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n���� ���� ���� HP: %d\n", dogHP);

                    if (dogHP <= 0) {
                        isDogDefeated = 1;
                        printf("\n���� ���� ó���߽��ϴ�. �������� 50��带 ȹ���߽��ϴ�.\n");
                        gold += 50;  // �� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            case 3:
                if (!isJekyllDefeated) {
                    printf("\n��ų�ڻ縦 ó���ϱ�� ����� ����Ʈ��. ó���ϸ� 1000��带 ����\n");
                    jekyllHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n��ų�ڻ��� ���� HP: %d\n", jekyllHP);

                    if (jekyllHP <= 0) {
                        isJekyllDefeated = 1;
                        printf("\n��ų�ڻ縦 ó���߽��ϴ�. �������� 1000��带 ȹ���߽��ϴ�.\n");
                        gold += 1000;  // ��ų�ڻ� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            case 4:
                // ����ڰ� �ٽ� ������ �� �ֵ��� ���� ���� ������ ����
                isDone = 1;
                break;
            default:
                printf("\n�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
                break;
            }
            break;
        case 3:
            printf("\n�ٸ� ����Ʈ�� ���ٰ�?\n");
            printf("\n 1. ���� ��ѱ� ó���ϱ�\n 2. ���� �� ó���ϱ�\n 3. ��ų�ڻ�� ��ȭ�ϱ�\n ����� ������?");
            scanf("%d", &b);
            switch (b) {
            case 1:
                if (!isPigeonDefeated) {
                    printf("\n���� ��ѱ⸦ ó���ϰ� �Ա���. ���� 20��� �ϼ�\n");
                    pigeonHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n���� ��ѱ��� ���� HP: %d\n", pigeonHP);

                    if (pigeonHP <= 0) {
                        isPigeonDefeated = 1;
                        printf("\n���� ��ѱ⸦ ó���߽��ϴ�. �������� 20��带 ȹ���߽��ϴ�.\n");
                        gold += 20;  // ��ѱ� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            case 2:
                if (!isDogDefeated) {
                    printf("\n���� ���� ó���ϰ� �Ա���. ���� 40��� �ϼ�\n");
                    dogHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n���� ���� ���� HP: %d\n", dogHP);

                    if (dogHP <= 0) {
                        isDogDefeated = 1;
                        printf("\n���� ���� ó���߽��ϴ�. �������� 40��带 ȹ���߽��ϴ�.\n");
                        gold += 40;  // �� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            case 3:
                if (!isJekyllDefeated) {
                    printf("\n��ų�ڻ縦 ó���ϱ�� ����� ����Ʈ��. ó���ϸ� 1000��带 ����\n");
                    jekyllHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n��ų�ڻ��� ���� HP: %d\n", jekyllHP);

                    if (jekyllHP <= 0) {
                        isJekyllDefeated = 1;
                        printf("\n��ų�ڻ縦 ó���߽��ϴ�. �������� 1000��带 ȹ���߽��ϴ�.\n");
                        gold += 1000;  // ��ų�ڻ� ó�� �Ϸ� �� ��� ȹ��
                    }
                }
                else {
                    printf("\n�̹� ó���� ����Ʈ�Դϴ�.\n");
                }
                break;
            }
            break;
        case 4:
            printf("\n�����߳�. ");

            // ��� ������ óġ�ߴ��� Ȯ��
            if (isPigeonDefeated && isDogDefeated && isJekyllDefeated) {
                printf("������ Ŭ�����ߴ� �ڳ�!\n");
            }
            else {
                printf("���α׷��� �����մϴ�.\n");
            }

            isDone = 1; // ���� ���� ����
            break;
        default:
            printf("\n�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    }

    return 0;
}