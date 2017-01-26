#include  "utils.h"

using namespace std;


int       myStrlen(char *word){
    int   i = 0;

    while (word[i] != '\0')
        i++;

    return (i);
}

bool    isMaj(char c) {
    if (c >= 'A' && c <= 'Z')
        return (true);
    else
        return (false);
}

bool     isMin(char c) {
    if (c >= 'a' && c <= 'z')
        return (true);
    else
        return (false);
}


char       getTranslate(int shift, char letter, char upperBound){
    return ((letter - shift) % 26) + upperBound;
}