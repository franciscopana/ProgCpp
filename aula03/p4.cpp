#include <iostream>

using namespace std;

void rleEncode(const char str[], char rle[]){
    char last_char = str[0];
    int occurences = 1;
    int i = 1, k = 0;
    while(str[i]!='\0'){
        if(str[i] == last_char){
            occurences++;
        }
        else{
            rle[k++] = occurences;
            rle[k++] = last_char;
            last_char = str[i];
            occurences = 1;
        }
        i++;
    }
    rle[k] = '\0';
}
