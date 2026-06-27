#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Global storage for questions (shared between Admin & Player)
char question[100][200];
char option1[100][100];
char option2[100][100];
char option3[100][100];
char option4[100][100];
int correct[100];
int total = 0; // keeps track of total questions

// Function to initialize some default questions
void initializeQuestions() {
    strcpy(question[0], "What is always coming, but never arrives?");
    strcpy(option1[0], "Yesterday");
    strcpy(option2[0], "Tomorrow");
    strcpy(option3[0], "A train");
    strcpy(option4[0], "The moon");
    correct[0] = 2;

    strcpy(question[1], "What can travel all around the world while staying in a corner?");
    strcpy(option1[1], "A ship");
    strcpy(option2[1], "A stamp");
    strcpy(option3[1], "A cloud");
    strcpy(option4[1], "A map");
    correct[1] = 2;

    strcpy(question[2], "What has cities, but no houses; forests, but no trees; and water, but no fish?");
    strcpy(option1[2], "The ocean");
    strcpy(option2[2], "A book");
    strcpy(option3[2], "A map");
    strcpy(option4[2], "A mirror");
    correct[2] = 3;

    strcpy(question[3], "Is the Earth flat?");
    strcpy(option1[3], "No");
    strcpy(option2[3], "Yes");
    strcpy(option3[3], "Maybe");
    strcpy(option4[3], "Sometimes");
    correct[3] = 1;

    total = 4; // total default questions
}

// Function to start the quiz
void playQuiz() {
    if (total == 0) {
        printf("No questions available! Ask admin to add some first.\n");
        return;
    }

    int score = 0;
    char guess;

    printf("\n*** QUIZ GAME START ***\n");

    for (int i = 0; i < total; i++) {
        printf("\nQ%d: %s\n", i + 1, question[i]);
        printf("A. %s\n", option1[i]);
        printf("B. %s\n", option2[i]);
        printf("C. %s\n", option3[i]);
        printf("D. %s\n", option4[i]);

        printf("Enter your choice (A-D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        int ansIndex;

        if (guess == 'A') {
            ansIndex = 1;
        } else if (guess == 'B') {
            ansIndex = 2;
        } else if (guess == 'C') {
            ansIndex = 3;
        } else if (guess == 'D') {
            ansIndex = 4;
        } else {
            ansIndex = 0;
        }

        if (ansIndex == correct[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: Option %d\n", correct[i]);
        }
    }

    printf("\nYour final score: %d / %d\n", score, total);
    printf("Thank you for playing!\n");
}

// Function for admin panel
void adminPanel() {
    int pass;

    printf("\nEnter Admin Password: ");
    scanf("%d", &pass);

    if (pass != 2025) {
        printf("Wrong password!\n");
        return;
    }

    int choice;
    getchar(); // clear input buffer

    while (1) {
        printf("\n--- ADMIN PANEL ---\n");
        printf("1. Add Question\n");
        printf("2. Show Questions\n");
        printf("3. Edit Question\n");
        printf("4. Delete Question\n");
        printf("5. Exit Admin\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (total >= 100) {
                printf("Question limit reached! Cannot add more questions.\n");
                continue;
            }

            printf("\nEnter question: ");
            fgets(question[total], 200, stdin);
            question[total][strcspn(question[total], "\n")] = '\0';

            printf("Option 1: ");
            fgets(option1[total], 100, stdin);
            option1[total][strcspn(option1[total], "\n")] = '\0';

            printf("Option 2: ");
            fgets(option2[total], 100, stdin);
            option2[total][strcspn(option2[total], "\n")] = '\0';

            printf("Option 3: ");
            fgets(option3[total], 100, stdin);
            option3[total][strcspn(option3[total], "\n")] = '\0';

            printf("Option 4: ");
            fgets(option4[total], 100, stdin);
            option4[total][strcspn(option4[total], "\n")] = '\0';

            printf("Enter correct option (1-4): ");
            scanf("%d", &correct[total]);
            getchar();

            if (correct[total] < 1 || correct[total] > 4) {
                printf("Invalid correct option! Question was not added.\n");
            } else {
                total++;
                printf("Question added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (total == 0) {
                printf("No questions available.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\nQ%d: %s\n", i + 1, question[i]);
                    printf("1) %s\n", option1[i]);
                    printf("2) %s\n", option2[i]);
                    printf("3) %s\n", option3[i]);
                    printf("4) %s\n", option4[i]);
                    printf("Correct: %d\n", correct[i]);
                }
            }
        }

        else if (choice == 3) {
            int num;

            printf("Enter question number to edit: ");
            scanf("%d", &num);
            getchar();

            if (num < 1 || num > total) {
                printf("Invalid question number!\n");
            } else {
                num--;

                printf("Enter new question: ");
                fgets(question[num], 200, stdin);
                question[num][strcspn(question[num], "\n")] = '\0';

                printf("Option 1: ");
                fgets(option1[num], 100, stdin);
                option1[num][strcspn(option1[num], "\n")] = '\0';

                printf("Option 2: ");
                fgets(option2[num], 100, stdin);
                option2[num][strcspn(option2[num], "\n")] = '\0';

                printf("Option 3: ");
                fgets(option3[num], 100, stdin);
                option3[num][strcspn(option3[num], "\n")] = '\0';

                printf("Option 4: ");
                fgets(option4[num], 100, stdin);
                option4[num][strcspn(option4[num], "\n")] = '\0';

                printf("Enter correct option (1-4): ");
                scanf("%d", &correct[num]);
                getchar();

                if (correct[num] < 1 || correct[num] > 4) {
                    printf("Invalid correct option!\n");
                } else {
                    printf("Question updated successfully!\n");
                }
            }
        }

        else if (choice == 4) {
            int num;

            printf("Enter question number to delete: ");
            scanf("%d", &num);
            getchar();

            if (num < 1 || num > total) {
                printf("Invalid question number!\n");
            } else {
                for (int i = num - 1; i < total - 1; i++) {
                    strcpy(question[i], question[i + 1]);
                    strcpy(option1[i], option1[i + 1]);
                    strcpy(option2[i], option2[i + 1]);
                    strcpy(option3[i], option3[i + 1]);
                    strcpy(option4[i], option4[i + 1]);
                    correct[i] = correct[i + 1];
                }

                total--;
                printf("Question deleted successfully!\n");
            }
        }

        else if (choice == 5) {
            printf("Exiting Admin Panel...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }
}

int main() {
    initializeQuestions(); // default setup

    printf("'WELCOME TO OUR QUIZ CONTEST'\n");

    char name[100];

    printf("\nEnter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int m;

    while (1) {
        printf("\nHello, %s!\n", name);
        printf("What would you like?\n");
        printf("1. Play\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Choose one: ");
        scanf("%d", &m);

        if (m == 1) {
            int n;

            printf("Are you ready?\n");
            printf("1. YES\n");
            printf("2. NO\n");
            printf("Choose one: ");
            scanf("%d", &n);

            if (n == 1) {
                playQuiz();
            }
        }

        else if (m == 2) {
            adminPanel();
        }

        else if (m == 3) {
            printf("Thank you for playing, %s!\n", name);
            break;
        }

        else {
            printf("Invalid input! Try again.\n");
        }
    }

    return 0;
