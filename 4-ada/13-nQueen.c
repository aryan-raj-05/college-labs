#include <stdio.h>
#include <stdlib.h>

int solutionCount = 0;

// Function to print the board
void printSolution(int boardSize, int queenPositions[20]) {
    char board[10][10];

    for (int row = 1; row <= boardSize; row++) {
        for (int col = 1; col <= boardSize; col++) {
            board[row][col] = 'x';
        }
    }

    for (int row = 1; row <= boardSize; row++) {
        board[row][queenPositions[row]] = 'Q';
    }

    for (int row = 1; row <= boardSize; row++) {
        for (int col = 1; col <= boardSize; col++) {
            printf("%c\t", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at the given position
int canPlace(int queenPositions[20], int currentRow) {
    for (int previousRow = 1; previousRow < currentRow; previousRow++) {
        if (
            queenPositions[previousRow] == queenPositions[currentRow] || 
            abs(queenPositions[previousRow] - queenPositions[currentRow]) == abs(previousRow - currentRow)
        ) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens(int boardSize) {
    int queenPositions[20];
    int currentRow = 1;
    queenPositions[currentRow] = 0;

    while (currentRow != 0) {
        queenPositions[currentRow] += 1;

        while (queenPositions[currentRow] <= boardSize && !canPlace(queenPositions, currentRow)) {
            queenPositions[currentRow] += 1;
        }

        if (queenPositions[currentRow] <= boardSize) {
            if (currentRow == boardSize) {
                solutionCount++;
                printf("Solution %d:\n", solutionCount);
                printSolution(boardSize, queenPositions);
            } else {
                currentRow++;
                queenPositions[currentRow] = 0;
            }
        } else {
            currentRow--;
        }
    }
}

// Entry point
int main() {
    int numberOfQueens;

    printf("Enter the number of queens: ");
    scanf("%d", &numberOfQueens);

    solveNQueens(numberOfQueens);

    return 0;
}
