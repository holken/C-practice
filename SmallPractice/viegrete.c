#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    printf("%i", ('Z' - 'a'));
    if (argc != 2) {
        printf("Usage: ./vigenere keyword");
        return 1;
    }
    
    char *keyword = argv[1];
    for (int i = 0, n = strlen(keyword); i < n; i++){
        if (!isalpha(keyword[i])){
            printf("Usage: ./vigenere keyword");
            return 1;
        }
    }
    
    int keys[strlen(keyword)];
    printf("plaintext: %s\n", keyword);
    for (int i = 0, n = strlen(keyword); i < n; i++){
        keys[i] = tolower(keyword[i]) - 'a';
        if (keys[i] < 0 || keys[i] > 25){
            printf("Usage: ./vigenere keyword");
            return 1;
        }
    }
    for (int i = 0, n = strlen(keyword), count = 0; i < n; i++, count++){
        if (count == n){
            count = 0;
        }
        
    }
    
    return 0;
}
