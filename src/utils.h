#ifndef     UTILS_H
#define     UTILS_H

#include	<stdlib.h>
#include    <map>
#include    <ctype.h>

int         myStrlen(char *);
char        getMostUsedLetter(char *letters);
char        *translate(char* text);
bool        isMaj(char c);
char        getTranslate(int shift, char letter, char upperBound);
bool        isMin(char c);

#endif
