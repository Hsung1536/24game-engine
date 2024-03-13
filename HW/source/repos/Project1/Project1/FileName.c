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
        printf("오늘은 무슨 일인가?\n 1. 총을 사러 왔다.\n 2. 퀘스트를 받으러 왔다.\n 3. 이야기를 한다.\n 당신의 선택은?");
        if (scanf("%d", &a) != 1) {
            printf("입력 에러가 발생했습니다. 프로그램을 종료합니다.\n");
            return 1;  // 에러 코드 반환
        }

        switch (a) {
        case 1:
            printf("\n자, 무슨 총을 고르겠냐\n");
            printf("\n 1. AK-47 \n 2. M16 \n 3. 나강 M1895\n 당신의 선택은?");
            if (scanf("%d", &b) != 1) {
                printf("입력 에러가 발생했습니다. 프로그램을 종료합니다.\n");
                return 1;  // 에러 코드 반환
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
            }
            break;
        case 2:
            if (!hasGun) {
                printf("\n총을 사고 오지 않았습니다. 먼저 총을 사러 오세요.\n");
                break;
            }

            printf("\n어떤 퀘스트를 받으러 왔나\n");
            printf("\n 1. 방사능 비둘기 처리하기\n 2. 방사능 개 처리하기\n 3. 지킬박사 처리하기\n 4. 다시 선택하기\n 당신의 선택은?");
            if (scanf("%d", &b) != 1) {
                printf("입력 에러가 발생했습니다. 프로그램을 종료합니다.\n");
                return 1;  // 에러 코드 반환
            }
            switch (b) {
                // ... (이하 동일)
            }
            break;
        case 3:
            printf("\n다른 퀘스트를 고를텐가?\n");
            printf("\n 1. 방사능 비둘기 처리하기\n 2. 방사능 개 처리하기\n 3. 지킬박사와 대화하기\n 당신의 선택은?");
            if (scanf("%d", &b) != 1) {
                printf("입력 에러가 발생했습니다. 프로그램을 종료합니다.\n");
                return 1;  // 에러 코드 반환
            }
            switch (b) {
                // ... (이하 동일)
            }
            break;
        case 4:
            printf("\n수고했네. 프로그램을 종료합니다.\n");
            isDone = 1; // 무한 루프 종료
            break;
        default:
            printf("\n수고했네.\n");
            isDone = 1; // 무한 루프 종료
        }
    }

    return 0;
}