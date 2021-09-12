#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Reverse(char word[], int start,int end);
void Flip(char string[]);

int main(){

    char word[100];
    printf("Please enter a string\n");
    gets(word);
    Flip(word);
    printf("%s",word);

    return 0;
}

void Reverse(char word[],int start,int end){
    int i=0,stop=(end-start)/2;
    //the stop is a number that will point to the middle of the word.
    while(i<stop){
        // we will keep looping until i reaches the middle of the word, the loop will switch the last letter of the word with the first, and then the before last with the second letter and etc...
        char tmp = word[start];
        word[start]=word[end-i-1];
        word[end-i-1]=tmp;
        start++,i++;
    }

}

void Flip(char string[]){
    int start=0;
    int end=0;
    /*
     * start will be the index pointer to the start of the word, and end will the index pointer to the space after the word
     */
    for(int i=0;i< strlen(string);i++){
        end=i;
        //end will keep increasing until we find a space in the string
        if(string[i]==' '||i== strlen(string)-1){
            //once we find the end of the word we want to reverse, we send it to another function that will receive the string and 2 index numbers that point to the start and end of the word.
            if(i== strlen(string)-1)    //this if statement is if we reach the end of the strong we increase end by one
                end++;
            Reverse(string,start,end);
            start=end+1;    //after we reverse the word, the start index will start pointing to the start of the next word
        }
    }
}
