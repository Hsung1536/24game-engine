#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    int jekyllHP = 100;
    int pigeonHP = 50;    // 방사능 비둘기의 체력
    int dogHP = 80;       // 방사능 개의 체력
    int hasGun = 0;       // 총을 소유하고 있는지 여부
    int selectedGun = 0;  // 선택된 총의 종류
    int isDone = 0;       // 종료 플래그
    int gold = 30;        // 초기 골드

    int ak47Damage = 40;
    int m16Damage = 20;
    int m1895Damage = 5;

    int isPigeonDefeated = 0;  // 방사능 비둘기를 처리했는지 여부
    int isDogDefeated = 0;     // 방사능 개를 처리했는지 여부
    int isJekyllDefeated = 0;  // 지킬박사를 처리했는지 여부

    while (!isDone) {
        printf("오늘은 무슨 일인가?\n 1. 총을 사러 왔다.\n 2. 퀘스트를 받으러 왔다.\n 3. 이야기를 한다.\n 당신의 선택은? ");
        if (scanf("%d", &a) != 1) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (a) {
        case 1:
            printf("\n자, 무슨 총을 고르겠냐\n");
            printf(" 1. AK-47 \n 2. M16 \n 3. 나강 M1895\n 당신의 선택은? ");
            if (scanf("%d", &b) != 1) {
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                while (getchar() != '\n');
                continue;
            }

            switch (b) {
            case 1:
                printf("\n자, 여기 AK-47일세. 30골드야\n");
                hasGun = 1;       // 총을 소유함
                selectedGun = 1;  // AK-47 선택됨
                gold -= 30;       // 총을 사고 골드 차감
                break;
            case 2:
                printf("\n자, 여기 M16일세. 15골드야\n");
                hasGun = 1;       // 총을 소유함
                selectedGun = 2;  // M16 선택됨
                gold -= 30;       // 총을 사고 골드 차감
                break;
            case 3:
                printf("\n자, 여기 나강 M1895일세. 5골드야\n");
                hasGun = 1;       // 총을 소유함
                selectedGun = 3;  // 나강 M1895 선택됨
                gold -= 30;       // 총을 사고 골드 차감
                break;
            default:
                printf("\n잘못된 선택입니다. 다시 선택하세요.\n");
                break;
            }
            break;
        case 2:
            if (!hasGun) {
                printf("\n총을 사고 오지 않았습니다. 먼저 총을 사러 오세요.\n");
                break;
            }

            printf("\n어떤 퀘스트를 받으러 왔나\n");
            printf(" 1. 방사능 비둘기 처리하기\n 2. 방사능 개 처리하기\n 3. 지킬박사 처리하기\n 4. 다시 선택하기\n 당신의 선택은? ");
            if (scanf("%d", &b) != 1) {
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                while (getchar() != '\n');
                continue;
            }

            switch (b) {
            case 1:
                if (!isPigeonDefeated) {
                    printf("\n방사능 비둘기 처리하기는 엄청 어려울거다. 만약 처리하고 온다면 30골드를 주지\n");
                    pigeonHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n방사능 비둘기의 남은 HP: %d\n", pigeonHP);

                    if (pigeonHP <= 0) {
                        isPigeonDefeated = 1;
                        printf("\n방사능 비둘기를 처리했습니다. 보상으로 30골드를 획득했습니다.\n");
                        gold += 30;  // 비둘기 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            case 2:
                if (!isDogDefeated) {
                    printf("\n방사능 개 처리하기는 어려운 퀘스트야. 처리하면 50골드를 주지\n");
                    dogHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n방사능 개의 남은 HP: %d\n", dogHP);

                    if (dogHP <= 0) {
                        isDogDefeated = 1;
                        printf("\n방사능 개를 처리했습니다. 보상으로 50골드를 획득했습니다.\n");
                        gold += 50;  // 개 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            case 3:
                if (!isJekyllDefeated) {
                    printf("\n지킬박사를 처리하기는 어려운 퀘스트야. 처리하면 1000골드를 주지\n");
                    jekyllHP -= (selectedGun == 1) ? ak47Damage : ((selectedGun == 2) ? m16Damage : m1895Damage);
                    printf("\n지킬박사의 남은 HP: %d\n", jekyllHP);

                    if (jekyllHP <= 0) {
                        isJekyllDefeated = 1;
                        printf("\n지킬박사를 처리했습니다. 보상으로 1000골드를 획득했습니다.\n");
                        gold += 1000;  // 지킬박사 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            case 4:
                // 사용자가 다시 선택할 수 있도록 루프 종료 조건을 만듦
                isDone = 1;
                break;
            default:
                printf("\n잘못된 선택입니다. 다시 선택하세요.\n");
                break;
            }
            break;
        case 3:
            printf("\n다른 퀘스트를 고를텐가?\n");
            printf("\n 1. 방사능 비둘기 처리하기\n 2. 방사능 개 처리하기\n 3. 지킬박사와 대화하기\n 당신의 선택은?");
            scanf("%d", &b);
            switch (b) {
            case 1:
                if (!isPigeonDefeated) {
                    printf("\n방사능 비둘기를 처리하고 왔구만. 여기 20골드 일세\n");
                    pigeonHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n방사능 비둘기의 남은 HP: %d\n", pigeonHP);

                    if (pigeonHP <= 0) {
                        isPigeonDefeated = 1;
                        printf("\n방사능 비둘기를 처리했습니다. 보상으로 20골드를 획득했습니다.\n");
                        gold += 20;  // 비둘기 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            case 2:
                if (!isDogDefeated) {
                    printf("\n방사능 개를 처리하고 왔구만. 여기 40골드 일세\n");
                    dogHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n방사능 개의 남은 HP: %d\n", dogHP);

                    if (dogHP <= 0) {
                        isDogDefeated = 1;
                        printf("\n방사능 개를 처리했습니다. 보상으로 40골드를 획득했습니다.\n");
                        gold += 40;  // 개 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            case 3:
                if (!isJekyllDefeated) {
                    printf("\n지킬박사를 처리하기는 어려운 퀘스트야. 처리하면 1000골드를 주지\n");
                    jekyllHP -= (selectedGun == 1) ? ak47Damage / 2 : ((selectedGun == 2) ? m16Damage / 2 : m1895Damage / 2);
                    printf("\n지킬박사의 남은 HP: %d\n", jekyllHP);

                    if (jekyllHP <= 0) {
                        isJekyllDefeated = 1;
                        printf("\n지킬박사를 처리했습니다. 보상으로 1000골드를 획득했습니다.\n");
                        gold += 1000;  // 지킬박사 처리 완료 시 골드 획득
                    }
                }
                else {
                    printf("\n이미 처리한 퀘스트입니다.\n");
                }
                break;
            }
            break;
        case 4:
            printf("\n수고했네. ");

            // 모든 보스를 처치했는지 확인
            if (isPigeonDefeated && isDogDefeated && isJekyllDefeated) {
                printf("게임을 클리어했다 자네!\n");
            }
            else {
                printf("프로그램을 종료합니다.\n");
            }

            isDone = 1; // 무한 루프 종료
            break;
        default:
            printf("\n잘못된 선택입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}