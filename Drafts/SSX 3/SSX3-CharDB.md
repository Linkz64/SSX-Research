# SSX 3 Character Database (CHARDB.DBL)
## Overview
The SSX 3 Character Database is a file that the game refrences for some biographical data on characters.


### Character Entries
There are 10 Entries in the file
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Byte[32] | Character Full Name  |                 | 
| Byte[16] | First Name  | Also used as the display name in game (Note: In some versions changing this will break the character bio)                | 
| Byte[16] | Nickname  |                 | 
| Int32  | Unknown      |                 |
| Int32  | Stance      | 0 is regular, 1 is goofy                 |
| Int32  | Model Size      | Effects Character Size in game                 |
| Byte[16] | Blood Type  |                 | 
| Int32  | Gender      | 0 is male, 1 is female                 |
| Int32  | Age      |                 |
| Byte[16] | Height  |                 |
| Byte[16] | Nationality  |                 | 
| Int32  | Entry Position      |                 |
