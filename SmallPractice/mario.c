int main(void)
{
    int height;
    do{
        height = get_int("Height: \n");
    } while(height < 1 || height > 8);
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < height - i; j++){
            printf(" ");
        }
        for (int j = 0; j < i+1; j++){
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i+1; j++){
            printf("#");
        }
        printf("\n");
    }  
}