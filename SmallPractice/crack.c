#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    if (argc != 2){
        printf("Please enter a hashed password!\n");
        return 1;
    }
    //Create our possible salt characters to combo
    /*char possible_salt_chars[64];
    int count = 0;
    for (int i = '.', n = '9'; i <= n; i++){
        possible_salt_chars[count] = i;
        count++;
    }
    for (int i = 'A'; i <= 'Z'; i++){
        possible_salt_chars[count] = i;
        count++;
    }
    for (int i = 'a'; i <= 'z'; i++){
        possible_salt_chars[count] = i;
        count++;
    }*/

    string hash = argv[1];
    char salt[] = {hash[0], hash[1]};
    char key[5];
    for (char a = 'A'; a <= 'z'; a++){
        key[0] = a;
        for (char b = 'A'; b <= 'z'; b++){
            key[1] = b;
            for (char c = 'A'; c <= 'z'; c++){
                key[2] = c;
                for (char d = 'A'; d <= 'z'; d++){
                    key[3] = d;
                    for (char e = 'A'; e <= 'z'; e++){
                        key[4] = e;
                        for (int i = 1; i <= 5; i++){
                            char test_key[i];
                            for (int j = 0; j < i; j++){
                                test_key[j] = key[4-j];
                            }
                            string test_hash = crypt(test_key, salt);
                            
                            if (strcmp(test_hash, hash)){
                                printf("%s\n", key);
                                return 0;
                            }
                            
                        }    
                    }
                }
            }
        }
    }
    printf("done\n");
    return 1;
}
