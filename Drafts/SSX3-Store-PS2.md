# SSX 3 Store PS2 (BoltPS2.Dat)
## Overview
This file governs details about the ssx 3 store


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
