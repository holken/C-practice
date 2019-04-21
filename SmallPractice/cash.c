#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float rest;
    do {
       rest = get_float("Change owed: \n");
    } while (rest < 0);
    int cents = round(rest*100);
    
    int count = 0;
    while (cents > 0){
        if (cents >= 25){
            cents = cents-25;
        } else if (cents >= 10){
            cents = cents-10;
        } else if (cents >= 5){
            cents = cents-5;
        } else if (cents >= 1){
            cents = cents-1;
        }
        count++;
    }
    printf("%i\n", count);
}
