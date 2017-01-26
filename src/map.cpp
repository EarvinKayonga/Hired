#include  "utils.h"

using namespace std;

typedef   map<char, unsigned> Map;
typedef   Map::iterator Iter;

Map       makeMap(char *letters){

    Map     dict;
    if (letters == NULL ) return (dict);

    int     size = 0;
    char    c = letters[0];

    while ( c != '\0' ){
        dict[c] = dict[c] + 1;
        size++;
        c = letters[size];
    }

    dict.erase(' ');

    return (dict);
}

char      getMostUsedLetter(char *letters){

    if (letters == NULL ) return '\0';

    Map     dict;

    dict = makeMap(letters);
    Iter it = dict.begin();
    Iter end = dict.end();

    int max_value = it->second;
    char str = it->first;
    for( ; it != end; ++it) {
        if(it->second > max_value) {
            max_value = it->second;
            str = it->first;
        }
    }

    return (str);
};