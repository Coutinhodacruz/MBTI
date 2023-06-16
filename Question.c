#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 2

typedef struct {
    char answers[MAX_QUESTIONS];
    int countA;
    int countB;
} PersonalityTest;

void getTrait(char questions[][3], char answerOptions[][MAX_OPTIONS][30], int* counts, char* traitA, char* traitB) {
    char userAnswers[MAX_QUESTIONS];

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %s\n", questions[i]);
        printf("Choose either a or b: \n");
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%s\n", answerOptions[i][j]);
        }

        char userAnswer;
        scanf(" %c", &userAnswer);

        while (userAnswer != 'a' && userAnswer != 'b') {
            printf("Expected a or b as a response\n");
            printf("I know this is an error, please retry again\n");
            scanf(" %c", &userAnswer);
        }

        userAnswers[i] = userAnswer;
        printf("\n");
    }

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (userAnswers[i] == 'a') {
            counts[0]++;
        } else if (userAnswers[i] == 'b') {
            counts[1]++;
        }
    }

    *traitA = (counts[0] > counts[1]) ? 'A' : 'B';
    *traitB = (counts[0] > counts[1]) ? 'B' : 'A';
}

void personalityTest() {
    char questions[MAX_QUESTIONS][3] = {"1", "2", "3", "4", "5"};
    char answerOptions[MAX_QUESTIONS][MAX_OPTIONS][30] = {
        {"a. expend energy, enjoy groups", "b. conserve energy, enjoy one-on-one"},
        {"a. more outgoing, think out loud", "b. more reserved, think to yourself"},
        {"a. seek many tasks, public activities, interaction with others", "b. seek private solitary activities with quiet to concentrate"},
        {"a. external, communicative, express yourself", "b. internal, reticent, keep to yourself"},
        {"a. active, initiate", "b. reflective, deliberate"}
    };

    int counts[2] = {0};
    char traitA, traitB;

    getTrait(questions, answerOptions, counts, &traitA, &traitB);

    printf("Trait A count: %d\n", counts[0]);
    printf("Trait B count: %d\n", counts[1]);
    printf("Trait A: %c\n", traitA);
    printf("Trait B: %c\n", traitB);
}

int main() {
    personalityTest();
    return 0;
}
