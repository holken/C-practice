#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void checkIfMax(char ** maxWord, char ** word, int i);

int main(void)
{
	char *maxWord = NULL;
	int count = 1;
	int i = 0;
	char *word = (char *)malloc(count*sizeof(char));
	char c;
	while ((c = getchar()) != EOF) {
		if (c == '9')
			break;
		if (!isalpha(c)){
			checkIfMax(&maxWord, &word, i);
			count = 1;
			i = 0;
			word = malloc(count*sizeof(char));
		} else {
			word[i] = c;
			if (i == count) {
				count++;
				char* tmp = (char *)realloc(word, count*sizeof(char));
				if (tmp == NULL){
					free(tmp);
					return 1;
				}
				word = tmp;	
			}	
			i++;
		}		
	}
	if (strlen(word) > 0){
		
		checkIfMax(&maxWord, &word, i);	
	}
	printf("%i characters in longest word: %s", (int) strlen(maxWord), maxWord);
	free(maxWord);
	return 0;
}

void checkIfMax(char ** maxWord, char ** word, int i){
	if (!*maxWord){
		*maxWord = malloc(i*sizeof(char));
		strcpy(*maxWord, *word);
	} else if (strlen(*word) > strlen(*maxWord)){
		free(*maxWord);
		*maxWord = malloc(i*sizeof(char));
		strcpy(*maxWord, *word);
	}
	free(*word);
}
