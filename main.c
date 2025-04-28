// 프로그램 소개
// 프로그램 이름 : 숫자 맞추기 게임
// 프로그램 설명 : 랜덤으로 생성한 숫자를 10번의 기회 안에 맞추는 게임
// 프로그램 작성자 : 이종권
// 프로그램 작성일 : 2025년 4월 28일
// 프로그램 버전 : 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS_COUNT 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int gameStart();
void gameEnd(int result, int answer);
int gamePlay(int answer); //정답을 맞추면 0, 틀리면 1 반환

int main() {
    int answer;
    int result = 0;

    printf("숫자 맞추기 게임\n");
    printf("1부터 100 사이의 숫자를 맞추세요.\n");

    answer = gameStart();
    result = gamePlay(answer);
    gameEnd(result, answer);

    return 0;
}

int gameStart() {
    printf("게임을 시작합니다.\n");
    srand((unsigned int)time(NULL));
    return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void gameEnd(int result, int answer) {
    if (result == 0) {
        printf("정답입니다.\n");
        printf("게임을 종료합니다.\n");
    } else {
        printf("기회를 모두 소진했습니다. 정답은 %d입니다.\n", answer);
        printf("게임을 종료합니다.\n");
    }
}

int gamePlay(int answer) {
    int guess;
    int guess_count = 0;

    while (guess_count < MAX_GUESS_COUNT) {
        printf("%d번쨰 예상 숫자를 입력하세요: ", guess_count + 1);
        while (scanf("%d", &guess) != 1 || guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("1부터 100 사이의 숫자를 입력하세요.\n");
        }

        if (guess == answer) {
            return 0;
        }

        if (guess < answer) {
            printf("정답은 더 큰 수입니다.\n");
        } else {
            printf("정답은 더 작은 수입니다.\n");
        }

        guess_count++;
    }
    return 1;
}

