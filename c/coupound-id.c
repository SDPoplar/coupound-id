#include "coupound-id.h"
#include <string.h>

const char charlib[] = "0123456789ABCDEFGHJKLMNPQRSTUW";
const unsigned int rate = sizeof( charlib ) - 1;

/*
unsigned short pos( char ch )
{
    unsigned short cursor = 0;
    while( ( cursor < rate ) && ( charlib[ cursor ] != ch ) ) cursor++;
    return cursor;
}
*/
#define pos( ch ) ( strchr( charlib, ch ) - charlib )

char* pack( const CoupoundId id, char* dest )
{
    char* cursor = dest + id.group_len;
    unsigned int vol = id.group;
    memset( dest, charlib[ 0 ], 8 );
    dest[ 0 ] = charlib[ ( id.flag << 3 ) | id.group ];
    while( ( cursor > dest ) && vol )
    {
        *( cursor-- ) = charlib[ vol % rate ];
        vol /= rate;
    }
    cursor = dest + 7;
    vol = id.id;
    while( ( ( cursor > dest + id.group_len ) ) && vol )
    {
        *( cursor-- ) = charlib[ vol % rate ];
        vol /= rate;
    }
    return dest;
}

unsigned int bits2int( const char* res, unsigned short bits )
{
    unsigned int ret = 0, cursor;
    for( cursor = 0; cursor < bits; cursor++ )
    {
        ret *= rate;
        ret += pos( res[ cursor ] );
    }
    return ret;
}

CoupoundId parse( const char* res )
{
    CoupoundId ret;
    unsigned short fb = pos( *res );
    ret.flag = ( fb >> 3 ) % 4;
    ret.group_len = fb % 8;
    ret.group = bits2int( res + 1, ret.group_len );
    ret.id = bits2int( res + ret.group_len + 1, 7 - ret.group_len );
    return ret;
}

