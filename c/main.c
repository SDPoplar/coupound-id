#include <stdio.h>
#include "coupound-id.h"

int main()
{
    const CoupoundId id = { 3, 2, 2, 882 };
    CoupoundId parsed;
    char buff[ 16 ] = "";
    puts( pack( id, buff ) );
    
    parsed = parse( buff );
    printf( "%u %u %u %u", parsed.flag, parsed.group_len, parsed.group, parsed.id );
    return 0;
}
