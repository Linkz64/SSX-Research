# SSX 3 Store PS2 (BoltPS2.Dat)
## Overview
This file governs details about the ssx 3 store

Character ID
0-Moby
1-Kaori
2-Arielle
3-Mac
4-Zoe
5-Grommet
6-Elise
7-Rocco
8-Psymon
9-Deiter
10-Brodi
11-Eddie
12-Jp
13-Luther
14-Marisol
15-Marty
16-Seeiah
17-Hiro
18-Jurgen
19-luthern
20-Stretch
21-Bessy
22-Bunny
23-Churchil
24-Skel
25-Snowman
26-Yeti
27-Unkown Rider
28-Beaver
29-Abom

## Item Entries 
### Header
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Item Ammount      |                 |

### Item Entries
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Byte  | Character ID      |                 |
| Byte  | Unknown     |                 |
| Byte  | Unlock Condition      |                 |
| Byte  | Unknown     |                 |
| Int16  | Item ID      |                 |
| Int16  | Parent ID      |                 |
| Byte  | Category ID     |                 |
| Byte  | Buyable      |                 |
| Byte  | MenuPos     |                 |
| Byte  | Unknown     |                 |
| Int16  | Fillbar      |                 |
| Int16  | Cost      | Times by 10 to get correct price                 |
| Byte  | Unknown     |                 |
| Byte  | Special FX Type     |                 |
| Byte  | Special FX (?)     |                 |
| Byte  | Special FX (?)     |                 |
| Int32  | Name Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Model High ID Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Model Med ID Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Model Low ID Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Model Shadow ID Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Model Path Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Texture Path Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Small Icon Offset      | Offset is reletive to start of Text Entries                |
| Int32  | Unknown      |                 |

## Unknown Entries 1 (Effects What can be equipt with what)
### Header
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Ammount      |                 |

### Entries
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Byte  | Character ID      |                 |
| Byte  | Unknown Bool     |                 |
| Int16  | Unknown 1      |                  |
| Byte  | Unknown 2      |                 |
| Byte  | Unknown 3      |                 |
| Int16  | Unknown 4      |                  |
| Byte  | Unknown 5      |                 |
| Byte  | Unknown 6      |                 |
| Int16  | Unknown 7      |                  |

## Unknown Entries 2 
### Header
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Ammount      |                 |

### Entries
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Unknown 1      |                 |
| Int16  | Unknown 2      |                 |
| Int16  | Unknown 3      |                  |

## Unknown Entries 3 
### Header
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Ammount      |                 |

### Entries
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Unknown 1      |                 |
| Int16  | Unknown 2      |                 |
| Int16  | Unknown 3      |                  |

## Text Entries
### Header
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| Int32  | Ammount      |                 |

### Entries
| Type   | Description                          | Description             |
|--------|--------------------------------------|-----------------|
| String  | Null Terminated String      |                 |
