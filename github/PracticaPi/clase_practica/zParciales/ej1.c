#include <stdio.h>

#define ES_VOCAL(c)    ((c) == 'a' || (c) == 'e' || (c)=='i'\
                     || (c) == 'o' || (c) == 'u'\
                        (c) == 'A' || (c) == 'E' || (c)=='I' \
                    ||  (c) == 'O' || (c) == 'U')? 1 : 0 

#define TO_LOWER(c)  (  ((c) >= 'A' && (c) <= 'Z')? ((c) - 'A' + 'a') : (c) )
        