//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, max = 0;
    scanf("%d", &n);
    char names[n][50];
    for(i = 0; i < n; i++)
        scanf("%s", names[i]);
    char winner[50];
    for(i = 0; i < n; i++) {
        int count = 1;
        for(j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0)
                count++;
        }
        if(count > max || (count == max && strcmp(names[i], winner) < 0)) {
            max = count;
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);

    return 0;
}
