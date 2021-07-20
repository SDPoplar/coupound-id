# Coupound ID
This is an ID-format-rule, can format about 87,480,000,000 IDs into string with 8 characters.
I'll use it in my account service in the future.

## data rule
In the 1st version, there're only 30 characters in the dict("0123456789ABCDEFGHJKLMNPQRSTUW")<br />
The formated id string from left to right means:

- 1st bit = information bit, saves the "flag" column and group part size
- 2nd bit to last bit = data bits

there're 2 parts in data bits, first parts saves "group" column, its size saved in info bit<br />
then "id" column takes the other parts

### info bit
info bit can be translate to an integer<br />
its binary's right 3 bits saves the lenth of column "group"<br />
other binary bits saves the column "flag"<br />
*only 2~3 binary bits can be used, so the "flag" column's value better be in [0, 4)*

