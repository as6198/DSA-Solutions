#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int choice, i, len;

    printf("Enter string: ");
    scanf("%s", str);

    do {
        printf("\n1.Length\n2.Reverse\n3.Palindrome\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Length = %lu\n", strlen(str));
                break;

            case 2:
                len = strlen(str);
                for(i = 0; i < len; i++)
                    rev[i] = str[len - i - 1];
                rev[len] = '\0';
                printf("Reverse = %s\n", rev);
                break;

            case 3:
                len = strlen(str);
                for(i = 0; i < len / 2; i++) {
                    if(str[i] != str[len - i - 1]) {
                        printf("Not Palindrome\n");
                        break;
                    }
                }
                if(i == len / 2)
                    printf("Palindrome\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
