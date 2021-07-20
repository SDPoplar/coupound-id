#ifndef  __SD_COMMON_COUPOUND_ID_H__
#define  __SD_COMMON_COUPOUND_ID_H__

typedef struct _id
{
    unsigned short flag;
    unsigned short group_len;
    unsigned int group;
    unsigned int id;
} CoupoundId;

char* pack( const CoupoundId id, char* dest );
CoupoundId parse( const char* res );

#endif

