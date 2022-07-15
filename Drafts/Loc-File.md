# Loc File (Language Files)
## Overview
An **loc** file contains most text used in the game

## LOCH
???
## LOCT
???

## LOCL (Text Entries)
### File Header

| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Byte[4] | Magic Word  |                 | 
| Int32  | Size                  |       |
| Int32  | Padding      |                 |
| Int32  | Entry Count     |                 |

### Entries

| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Text Offset  |                 | 

### Text
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| String  | Unicode Text (Null Terminated String)  |                 | 
