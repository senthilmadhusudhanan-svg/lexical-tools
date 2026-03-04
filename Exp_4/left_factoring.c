#include <stdio.h>
#include <string.h>

int main() {
    char production[50], nonTerminal;
    char first[50], second[50];
    char common[50];
    int i, j = 0;

    FILE *fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter Production (Example: A=ab/ac): ");
    scanf("%s", production);

    nonTerminal = production[0];

    // Separate first production
    for (i = 2; production[i] != '/'; i++)
        first[i - 2] = production[i];
    first[i - 2] = '\0';

    i++; 

    // Separate second production
    int k = 0;
    while (production[i] != '\0')
        second[k++] = production[i++];
    second[k] = '\0';

    // Find common prefix
    i = 0;
    while (first[i] == second[i] && first[i] != '\0') {
        common[j++] = first[i++];
    }
    common[j] = '\0';

    if (strlen(common) == 0) {
        printf("\nNo Left Factoring needed.\n");
        fprintf(fp, "No Left Factoring needed.\n");
    } else {
        printf("\nGrammar after Left Factoring:\n");
        printf("%c -> %s%c'\n", nonTerminal, common, nonTerminal);
        printf("%c' -> %s | %s\n",
               nonTerminal,
               first + strlen(common),
               second + strlen(common));

        fprintf(fp, "Grammar after Left Factoring:\n");
        fprintf(fp, "%c -> %s%c'\n", nonTerminal, common, nonTerminal);
        fprintf(fp, "%c' -> %s | %s\n",
                nonTerminal,
                first + strlen(common),
                second + strlen(common));
    }

    fclose(fp);

    printf("\nFile saved successfully as output_left_factoring.txt\n");

    return 0;
}
