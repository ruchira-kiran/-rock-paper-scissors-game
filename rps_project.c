#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;
    int playerScore = 0, computerScore = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    do {
        printf("\n===== Rock Paper Scissors Game =====\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &user);

        // Generate computer's choice
        computer = rand() % 3 + 1;

        // Display computer's choice
        printf("\nComputer chose: ");
        if (computer == 1)
            printf("Rock\n");
        else if (computer == 2)
            printf("Paper\n");
        else
            printf("Scissors\n");

        // Determine the winner
        if (user == computer) {
            printf("It's a Draw!\n");
        }
        else if ((user == 1 && computer == 3) ||
                 (user == 2 && computer == 1) ||
                 (user == 3 && computer == 2)) {
            printf("You Win!\n");
            playerScore++;
        }
        else if (user >= 1 && user <= 3) {
            printf("Computer Wins!\n");
            computerScore++;
        }
        else {
            printf("Invalid Choice!\n");
        }

        // Ask if the user wants to play again
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    // Display leaderboard after the user quits
    printf("\n=====================================\n");
    printf("           FINAL LEADERBOARD         \n");
    printf("=====================================\n");
    printf("Player Score   : %d\n", playerScore);
    printf("Computer Score : %d\n", computerScore);

    if (playerScore > computerScore)
        printf("\n🏆 Overall Winner: Player\n");
    else if (computerScore > playerScore)
        printf("\n💻 Overall Winner: Computer\n");
    else
        printf("\n🤝 Overall Result: Draw\n");

    printf("\nThanks for playing!\n");

    return 0;
}