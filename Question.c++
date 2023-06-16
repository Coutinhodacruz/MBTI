#include <iostream>
#include <string>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 2

struct PersonalityTest {
    char answers[MAX_QUESTIONS];
    int countA;
    int countB;
};

void getTrait(std::string questions[], std::string answerOptions[][MAX_OPTIONS], int* counts, char* traitA, char* traitB) {
    char userAnswers[MAX_QUESTIONS];

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        std::cout << "Question " << questions[i] << std::endl;
        std::cout << "Choose either a or b: " << std::endl;
        for (int j = 0; j < MAX_OPTIONS; j++) {
            std::cout << answerOptions[i][j] << std::endl;
        }

        char userAnswer;
        std::cin >> userAnswer;

        while (userAnswer != 'a' && userAnswer != 'b') {
            std::cout << "Expected a or b as a response" << std::endl;
            std::cout << "I know this is an error, please retry again" << std::endl;
            std::cin >> userAnswer;
        }

        userAnswers[i] = userAnswer;
        std::cout << std::endl;
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
    std::string questions[MAX_QUESTIONS] = {"1", "2", "3", "4", "5"};
    std::string answerOptions[MAX_QUESTIONS][MAX_OPTIONS] = {
        {"a. expend energy, enjoy groups", "b. conserve energy, enjoy one-on-one"},
        {"a. more outgoing, think out loud", "b. more reserved, think to yourself"},
        {"a. seek many tasks, public activities, interaction with others", "b. seek private solitary activities with quiet to concentrate"},
        {"a. external, communicative, express yourself", "b. internal, reticent, keep to yourself"},
        {"a. active, initiate", "b. reflective, deliberate"}
    };

    int counts[2] = {0};
    char traitA, traitB;

    getTrait(questions, answerOptions, counts, &traitA, &traitB);

    std::cout << "Trait A count: " << counts[0] << std::endl;
    std::cout << "Trait B count: " << counts[1] << std::endl;
    std::cout << "Trait A: " << traitA << std::endl;
    std::cout << "Trait B: " << traitB << std::endl;
}

int main() {
    personalityTest();
    return 0;
}
