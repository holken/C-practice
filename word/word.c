#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	unsigned int start = 0;
	unsigned int start_max = -1;
	unsigned int end_max = -1;
	unsigned int size = 100;
	int i = 0;
	char *word = malloc(size);
	char c;
	while ((c = getchar()) != EOF) {
		if ((c > 'z' || c < 'a') && (c < 'A' || c > 'Z')){
			if (start_max == -1){
				start_max = start;
				end_max = i;
			} else if ((i - start) > (end_max - start_max)){
				start_max = start;
				end_max = i;
			}
			start = i;
		} else {
			if (i == size) {
				printf("resize");
				size *= 2;
				word = realloc(word, size);
			}
			word[i] = c;
			i++;
		}
	}
	char *word_max = malloc((end_max - start_max)+1);
	for (int j = start_max; j < end_max; j++){
		word_max[j-start_max] = word[j];
	}
	word_max[(end_max - start_max)] = '\0';
	printf("%i characters in longest word: %s\n", (end_max - start_max), word_max);
	free(word_max);
	free(word);
	return 0;
}