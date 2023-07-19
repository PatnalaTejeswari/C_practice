Program2: Flames game-- Write a program to do flames for 2user inputs and should give the relatin between those inputs in c.

Program that implements the FLAMES game for two user inputs and determines the relationship between them. FLAMES is a popular game that predicts the relationship between two people based on their names. Here's the program:
//The full form of strcspn is "String Complement Span."
Explanation:
In this program, the user is prompted to enter two names. The countRemainingLetters function is used to count the number of non-space letters in a given string. The findFlamesIndex function calculates the index to determine the relationship in FLAMES based on the total number of letters and the remaining number of letters after eliminating common letters between the two names.
The removeLetterAtIndex function removes a letter from a given string at the specified index. The findFlamesRelation function maps the FLAMES index to the corresponding relationship.
The main logic is implemented in the main function. It calculates the total number of letters, counts the remaining letters after eliminating common letters, and determines the FLAMES index. Finally, it maps the index to the relationship and prints the result.
The program outputs the predicted relationship between the two names based on the FLAMES game.
Note: The FLAMES game is based on a simple algorithm and should be considered as entertainment rather than a reliable predictor of relationships.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countRemainingLetters(char *str) {
    int count = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            count++;
    }

    return count;
}

int findFlamesIndex(int totalLetters, int n) {
    return (n % totalLetters == 0) ? totalLetters : (n % totalLetters);
}

void removeLetterAtIndex(char *str, int index) {
    int i;
    int len = strlen(str);

    for (i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

char findFlamesRelation(int index) {
    switch (index) {
        case 1:
            return 'F';
        case 2:
            return 'L';
        case 3:
            return 'A';
        case 4:
            return 'M';
        case 5:
            return 'E';
        case 6:
            return 'S';
        default:
            return '\0';
    }
}

int main() {
    char name1[100], name2[100];
    int i, j;
    int totalLetters, remainingLetters;

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0'; // Remove newline character

    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0'; // Remove newline character

    totalLetters = countRemainingLetters(name1) + countRemainingLetters(name2);

    remainingLetters = countRemainingLetters(name1);

    for (i = 0; i < strlen(name1); i++) {
        for (j = 0; j < strlen(name2); j++) {
            if (name1[i] != ' ' && name2[j] != ' ' && name1[i] == name2[j]) {
                removeLetterAtIndex(name1, i);
                removeLetterAtIndex(name2, j);
                remainingLetters -= 2;
                i--;
                break;
            }
        }
    }

    int flamesIndex = findFlamesIndex(totalLetters, remainingLetters);
    char relation = findFlamesRelation(flamesIndex);

    printf("Relationship: ");
    switch (relation) {
        case 'F':
            printf("Friends\n");
            break;
        case 'L':
            printf("Lovers\n");
            break;
        case 'A':
            printf("Affectionate\n");
            break;
        case 'M':
            printf("Marriage\n");
            break;
        case 'E':
            printf("Enemies\n");
            break;
        case 'S':
            printf("Siblings\n");
            break;
        default:
            printf("No relationship found\n");
    }

    return 0;
}
