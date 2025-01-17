#include <stdio.h>

void Hanoi(int n, char FromPeg, char auxPeg, char toPeg);

int main() {
    int n;
    printf("Enter the nubmer of disks: ");
    scanf("%d", &n);
    
    printf("The sequence for moves are:\n");
    Hanoi(n, 'A', 'C', 'B');
}

void Hanoi(int n, char fromPeg, char auxPeg, char toPeg) {
    if (n == 0)     return;
    Hanoi(n-1, fromPeg, auxPeg, toPeg);
    printf("Move disk %d from Peg %c to Peg %c\n", n, fromPeg, toPeg);
    Hanoi(n-1, auxPeg, toPeg, fromPeg);
}