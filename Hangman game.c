#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[] = "computer";
    char guessed[20];
    char letter;
    int len = strlen(word);
    int attempts = 6;
    int correct = 0;

    // Initialize guessed word with underscores
    for(int i = 0; i < len; i++) {
        guessed[i] = '_';
    }
    guessed[len] = '\0';

    printf("=== HANGMAN GAME ===\n");

    while(attempts > 0 && correct < len) {
        printf("\nWord: ");
        for(int i = 0; i < len; i++) {
            printf("%c ", guessed[i]);
        }

        printf("\nAttempts left: %d", attempts);
        printf("\nEnter a letter: ");
        scanf(" %c", &letter);

        letter = tolower(letter);

        int found = 0;

        for(int i = 0; i < len; i++) {
            if(word[i] == letter && guessed[i] == '_') {
                guessed[i] = letter;
                correct++;
                found = 1;
            }
        }

        if(found) {
            printf("Correct guess!\n");
        } else {
            attempts--;
            printf("Wrong guess!\n");
        }
    }

    if(correct == len) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        printf("\nGame Over! The word was: %s\n", word);
    }

    return 0;
}