// ���α׷� �Ұ�
// ���α׷� �̸� : ���� ���߱� ����
// ���α׷� ���� : �������� ������ ���ڸ� 10���� ��ȸ �ȿ� ���ߴ� ����
// ���α׷� �ۼ��� : ������
// ���α׷� �ۼ��� : 2025�� 4�� 28��
// ���α׷� ���� : 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS_COUNT 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int gameStart();
void gameEnd(int result, int answer);
int gamePlay(int answer); //������ ���߸� 0, Ʋ���� 1 ��ȯ

int main() {
    int answer;
    int result = 0;

    printf("���� ���߱� ����\n");
    printf("1���� 100 ������ ���ڸ� ���߼���.\n");

    answer = gameStart();
    result = gamePlay(answer);
    gameEnd(result, answer);

    return 0;
}

int gameStart() {
    printf("������ �����մϴ�.\n");
    srand((unsigned int)time(NULL));
    return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void gameEnd(int result, int answer) {
    if (result == 0) {
        printf("�����Դϴ�.\n");
        printf("������ �����մϴ�.\n");
    } else {
        printf("��ȸ�� ��� �����߽��ϴ�. ������ %d�Դϴ�.\n", answer);
        printf("������ �����մϴ�.\n");
    }
}

int gamePlay(int answer) {
    int guess;
    int guess_count = 0;

    while (guess_count < MAX_GUESS_COUNT) {
        printf("%d���� ���� ���ڸ� �Է��ϼ���: ", guess_count + 1);
        while (scanf("%d", &guess) != 1 || guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("1���� 100 ������ ���ڸ� �Է��ϼ���.\n");
        }

        if (guess == answer) {
            return 0;
        }

        if (guess < answer) {
            printf("������ �� ū ���Դϴ�.\n");
        } else {
            printf("������ �� ���� ���Դϴ�.\n");
        }

        guess_count++;
    }
    return 1;
}

