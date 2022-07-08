# SSH Image File
## Overview
EA's SSH Texture Files

### Magic words
|    Hex   |   ASCII  |
|----------|----------|
| ????     | SHPS (SSX, SSX Tricky, SSX 3)       |
| ???? | ShpS (SSX On Tour)     |

## SHPS
### Header
|    Type   |   Description  |
|----------|----------|
| UInt32 | SSH File Size       |
| UInt32 | Texture Count      |
| Char[4] | Format     |

### Texture Entries
|    Type   |   Description  |
|----------|----------|
| Char[4] | Short Name       |
| UInt32 | Offset      |

### Header End
|    Type   |   Description  |
|----------|----------|
| Char[4] | Group       |
| Char[4] | String?      |

## Texture Entry
## Entry Texture Types
|    Type (Int8)   |   Description  |
|----------|----------|
| 1 | 4-Bit 16 Colour Palette        |
| 2 | 8-bit 256 Colours swapped palette      |
| 5 | 8-bit Full Colour Image      |
| 33 | Colour Pallet      |
| 105 | Metal Bin      |
| 112 | Long Name      |
| 130 | 8-bit 256 colors swapped palette RefPack Compressed     |

### Texture Header
|    Type   |   Description  |
|----------|----------|
| Byte | Entry Type       |
| UInt24 | Size       |
| UInt16 | Width       |
| UInt16 | Height       |
| UInt16 | XAxis       |
| UInt16 | YAxis       |
| UInt16 | Swizzled       |
| UInt16 | Unknown      |
... Texture data goes below

### Colour Pallet Header
|    Type   |   Description  |
|----------|----------|
| Byte | Entry Type       |
| UInt24 | Size       |
| UInt16 | Width       |
| UInt16 | Height       |
| UInt16 | Total       |
| UInt16 | Unknown       |
| UInt16 | Swizzled       |
| UInt16 | Unknown      |
... Entry Listed as RGBA Each int8s

### Long Name Header
|    Type   |   Description  |
|----------|----------|
| Byte | Entry Type       |
| UInt24 | Size       |
| String | Long Name (Null Terminated String)       |
