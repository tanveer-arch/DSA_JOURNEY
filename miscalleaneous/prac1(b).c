#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int checkAnagram(char user[],char input[]){
    int sizeInput= strlen(input);
    int sizeUser=strlen(user);
    if(user==input && sizeUser!=sizeInput){
        return 0;
    }
    return 1;
}

int main(void){
    srand(time(NULL));
    char words[5][20]={
        "apple",
        "banana",
        "watermelon",
        "orange",
        "strawberry"
    };
    
    int random=rand()%6;
    char user[20];
    printf("Find an Anagram for this word: %s",words[random]);
    printf("  ---->");
    scanf("%s",user);
    
    
}
