# SSH Image File

## Overview

EA's SSH Texture Files

### Magic words

| Hex      | ASCII                               |
|----------|-------------------------------------|
| ????     | SHPS (SSX, SSX Tricky, SSX 3)       |
| ????     | ShpS (SSX On Tour)                  |

<!-- Editor's note: ShpS is the "new" format. Tools as early as 2004 call SHPS "old". -->

## SHPS

### Header

| Type   |   Description                    |
|--------|----------------------------------|
| UInt32 | SSH File Size                    |
| UInt32 | Texture Count                    |
| Char[4]| Gimex Version/Creator Code       |

### Texture Entries

| Type    |   Description  |
|---------|----------------|
| Char[4] | Short Name     |
| UInt32  | Offset         |

### Header End

<!-- Editor's note: I believe this is padding, and they chose to make it funny cause.. it's padding. -->

| Type   | Description |
|--------|------------|
| Char[4]| Group      |
| Char[4]| String?    |

<!-- rewrite this section from #file-formats info -->

## Texture Entry

## Entry Texture Types

All shape entries start with a header that looks like this:

```cpp
struct ShapeChunkHeader {
	uint8_t chunkType;

	uint24_t nextChunk; 
	// Note that the above isn't a standard type. 
	// You can probably represent it as a bitfield if you want.

	// In layman's terms, if the next chunk offset is 0, then
	// it's the end of this shape.

	bool IsEndOfShape() {
		return nextChunk == 0x0;
	}
};
```


| Chunk Type           | Description                  |
|----------------------|-------------------------------|
| 0x1                  | 4-Bit (16 Colours) Data       |
| 0x2                  | 8-bit (256 Colours) Data      |
| 0x5                  | 32-bit True Color Image       |
| 0x20                 | Palette/CLUT                  |
| 105                  | Metal Bin                     |
| 0x70                 | Long/Full Name                |
| 0x85 (`0x5 | 0x80`)  | 8-bit Data, RefPack Compressed|


If `(type & 0x80) == 1` the data will be compressed with RefPack.

### Texture Header

| Type   | Description |
|--------|-------------|
| Byte   | Entry Type  |
| UInt24 | Size        |
| UInt16 | Width       |
| UInt16 | Height      |
| UInt16 | XAxis       |
| UInt16 | YAxis       |
| UInt16 | Swizzled    |
| UInt16 | Unknown     |

The data following this header can be:

| Image Type | Data Type                       |
|------------|---------------------------------|
| 4-bit      | 4-bit indexes into Palette/CLUT |
| 8-bit      | 8-bit indexes into Palette/CLUT |
| 32-bit     | BGRA8888 Direct Colors          |

### Colour Pallet Header

| Type   | Description |
|--------|-------------|
| Byte   | Entry Type  |
| UInt24 | Size        |
| UInt16 | Width       |
| UInt16 | Height      |
| UInt16 | Total       |
| UInt16 | Unknown     |
| UInt16 | Swizzled    |
| UInt16 | Unknown     |

After the header is *Width* count BGRA8888 colors.

### Long Name Header

| Type     | Description  |
|----------|--------------|
| Byte     | Entry Type   |
| UInt24   | Size         |
| C String | Long Name    |
