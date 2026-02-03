#include<stdio.h>
#include<stdlib.h>

// returns maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// prints the innings score in a formatted way
void printInningsScore(int* scoresPtr, int size) {
    
    // return if size is 0
    if (size == 0) {
        return;
    }

    // return if pointer is not valid
    if (scoresPtr == NULL) {
        return;
    }

    // print innings
    printf("Innings\t:");

    for (int i = 0; i < size; i++) {
        printf("%d\t", i + 1);
    }

    //print scores
    printf("\nScores\t:");

    for (int i = 0; i < size; i++) {
        printf("%d\t", scoresPtr[i]);
    }

    printf("\n");
}

// get the innings score from the user
void inputScores(int* scoresPtr, int size) {

    // return if size is zero
    if (size == 0) {
        return;
    }

    // return if pointer is not valid
    if (scoresPtr == NULL) {
        return;
    }
    
    // temporary variable to validate input
    int enteredScore;

    // loop the size of array to input each element
    for (int i = 0; i < size; i++) {

        // loop till valid input or failure
        while (1) {

            printf("Enter the score for game #%d [0-100] ", i + 1);

            // get the score for a particular index from the user
            // check if its a valid integer
            if (scanf_s("%d", &enteredScore) != 1) {
                while (getchar() != '\n');
                printf("Invalid input, Please re-enter.\n");
                continue;
            }

            // check if its an integer in valid range
            if (enteredScore < 0 || enteredScore > 100) {
                printf("Invalid score. Must be between 0 and 100. Please re-enter.\n");
                continue;
            }

            // if input successful then assign it to its index
            scoresPtr[i] = enteredScore;

            // break the while to move to next index
            break;
        }
    }
}

// return the average of innings score
double calculateAverage(const int* scoresPtr, int size) {

    // return 0 if size is 0
    if (size == 0) {
        return 0.0;
    }

    // return 0 if pointer is invalid
    if (scoresPtr == NULL) {
        return 0.0;
    }

    double summation = 0.0;
    for (int i = 0; i < size; i++) {
        summation += scoresPtr[i];
    }
    return summation/size;
}

// return the highest of inning scores
int findHighest(const int* scoresPtr, int size) {

    // return 0 if pointer is invalid
    if (scoresPtr == NULL) {
        return 0;
    }

    // variable to mantain high score for a given prefix
    int highScore = 0;

    // iterate over all indices and update the max value for prefix
    for (int i = 0; i < size; i++) {
        highScore = max(highScore, scoresPtr[i]);
    }

    // return value for the largest prefix (ie. the array itself)
    return highScore;
}

int main() {
    // number of games 
    int numGames;
    
    // scores for each game
    int* inningsScore;

    // loop to validate input
    while (1) {
        printf("Enter the total number of innings played (must be positive):");

        // get the number of games from user
        // check if the input is a valid integer
        if (scanf_s("%d", &numGames) != 1) {
            while (getchar() != '\n');
            printf("Invalid input, Please re-enter.");
        }
        // check if its a positive integer
        else if (numGames <= 0) {
            printf("Number of games must be positive. Please re-enter.\n");
        }
        // otherwise allocate memory for the innings score
        else {
            inningsScore = (int*)malloc(sizeof(int) * numGames);

            // check if the memory allocation was successful
            if (inningsScore == NULL) {
                printf("Could not allocate memory!\n");
                return 1;
            }

            // get scores from user
            inputScores(inningsScore, numGames);

            // print scores
            printInningsScore(inningsScore, numGames);

            // print average and highest of scores
            printf("Average Score: %.2f\n", calculateAverage(inningsScore, numGames));
            printf("Highest Score: %d\n", findHighest(inningsScore, numGames));
            break;
        }
    }

    // deallocate the memory for scores
    if (inningsScore != NULL) {
        free(inningsScore);
        inningsScore = NULL;
    }

    return 0;
}