#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int cid; // Candidate ID
    char cname[20]; // Candidate name
    int votes; // Number of votes received
} Candidate;

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", candidates[i].cid, candidates[i].cname);
    }
}

void castVote(Candidate candidates[], int numCandidates) {
    int choice;
    printf("\nEnter the candidate number you want to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    printf("You have successfully voted for %s\n", candidates[choice - 1].cname);
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].cname, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates;

    printf("Welcome to the Voting System\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates!\n");
        return 1;
    }

    for (int i = 0; i < numCandidates; i++) {
        candidates[i].cid = i + 1;
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].cname);
        candidates[i].votes = 0;
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCandidates(candidates, numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates);
                break;
            case 3:
                displayResults(candidates, numCandidates);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
