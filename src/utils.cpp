#include  "utils.h"

using namespace std;


char      *translate(char *letters){

    char    c;
    int     size = 0;
    char    res[myStrlen(letters)];

    if (letters == NULL ) return (NULL);
        char mostUsed = 'z';


    while ( (c = letters[size]) != '\0' ) {

        int     shift = mostUsed - 'a';

        if (isMaj(c))
            res[size] =  toupper(getTranslate(shift, tolower(c), 'a'));

        if (isMin(c))
            res[size] = getTranslate(shift, c, 'a');


        if (c == ' ')
            res[size] = ' ';

        size++;
    }

    return (res);
}