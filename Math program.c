/*
Create a math quiz program that prompts the user for how many questions to ask. 
The program should congratulate the player if he or she gets the correct answer or alert 
the user of the correct answer in the event that the question is answered incorrectly. 
The math quiz program should also keep track of how many questions 
the player has answered correctly and incorrectly and display these running totals at the end of the quiz
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_1 10
#define MAX_NUMBER_2 10

int main (void) {

    // Assigning Variables
    int questionNum, response, randomNumber1, randomNumber2, stopCondition = 0;
    char inputQuestion [100];


    // Generate a seed for the random number generator based on the current time
    srand(time(NULL));

    // Prompts user to enter number for questions
    printf("How many questions would you like to answer? ");
    scanf("%s", &inputQuestion);

        // Checks if the user's inputQuestion is not a number
        if (!isdigit(inputQuestion[0])) {
            printf("Sorry, that is not a number. Please try again.\n");
        }

        // Converts the user's inputQuestion to an integer
        else {
            questionNum = atoi(inputQuestion);
        }

    // Loop for generating and evaluating multiplication questions
    for (int question = 1; question <= questionNum; question++) {
            randomNumber1 = rand() % MAX_NUMBER_1;
            randomNumber2 = rand() % MAX_NUMBER_2;

        // Loop for evaluating user response
        printf("Question %d: What is the product of %d times %d?\n", question, randomNumber1, randomNumber2);
        scanf("%d", &response);

        // Checks if the user's response is correct and prints the result.
        if (response == randomNumber1 * randomNumber2) {
            printf("Congratulations! That is correct!\n");
        }

        // Checks if the user's response is incorrect and prints the result.
        else if (response != randomNumber1 * randomNumber2) {
            printf("Sorry, that is incorrect. The correct answer is %d.\n", randomNumber1 * randomNumber2);
        }

        // Checks if the user has run out of questions and prints the result.
        else if (stopCondition) {
            printf("Sorry, you have run out of questions. Goodbye!\n");
            stopCondition = question + 1;
        }

        else {
            break;
        }
}

    return 0;  // Indicates succesful program execution
}
