#include <stdio.h>
#include <string.h>

typedef struct {
    int num1;
    char middle_thing[2];
    int num2;
} EXAMPLE;

EXAMPLE input(EXAMPLE *example) {
    char string[20];
    printf("Please type a mathematical example in the format '12 + 48'.\nAllowed characters: '+', '-', '*', '/'.\n");
    fgets(string, sizeof(string), stdin);
    sscanf(string, "%d%1s%d", &example->num1, example->middle_thing, &example->num2);
}

int calculate(EXAMPLE *example) {
    if (strcmp(example->middle_thing, "+") == 0) {
        printf("%d %s %d = ", example->num1, example->middle_thing, example->num2);
        printf("%d\n", example->num1 + example->num2);
    }
    else if (strcmp(example->middle_thing, "-") == 0) {
        printf("%d %s %d = ", example->num1, example->middle_thing, example->num2);
        printf("%d\n", example->num1 - example->num2);
    }
    else if (strcmp(example->middle_thing, "*") == 0) {
        printf("%d %s %d = ", example->num1, example->middle_thing, example->num2);
        printf("%d\n", example->num1 * example->num2);
    }
    else if (strcmp(example->middle_thing, "/") == 0) {
        printf("%d %s %d = ", example->num1, example->middle_thing, example->num2);
        printf("%d\n", example->num1 / example->num2);
    }
    else {
        printf("invalid example!\n");
    }
}

int main(void) {
    EXAMPLE example;
    char again;
    do {
        input(&example);
        calculate(&example);
        printf("You want more? [y/n]\n");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y' || again == '\n');
    return 0;
}
