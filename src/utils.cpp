#include	<stdlib.h>
#include  <map>

#include  "utils.h"

using namespace std;

typedef   map<char, unsigned> Map;

Map     makeMap(char *letters){

  Map   dict;
  if (letters == NULL ) return (dict);

  int   size = 0;
  char  c = letters[0];

  while ( c != '\0' ){
    dict[c] = dict[c] + 1;
    size++;
    c = letters[size];
  }

  dict.erase(' ');

  return (dict);
}

char    getMostUsedLetter(char *letters){

  if (letters == NULL ) return '\0';

  Map   dict;
  dict = makeMap(letters);

  return ('e');
};
