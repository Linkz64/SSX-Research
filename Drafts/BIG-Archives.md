# BIG Archives

## Overview

EA's archive format.

All integers are Big endian unless stated otherwise.

### Magic words

|    Hex   |   ASCII  |
|----------|----------|
| C0FB     | Àû       |
| 42494734 | BIG4     |
| 42494746 | BIGF     |

C0FB is identified as "old 24bit", and BIGF is identified as "old 32bit".

## BIGF/BIG4

### Header

| Type      | Description            |
|-----------|------------------------|
| UInt32 LE | Big File Size          |
| UInt32    | File Count             |
| UInt32    | Data Start Offset      |

<!-- Editor's note, I believe the third word is header size. This is is how you should check for lumpy debug info iirc -->

### File Entries

| Type     | Description  |
|----------|--------------|
| UInt32   | Offset       |
| UInt32   | File Size    |
| C String | Path         |

If the first word of the file data starts with 0x10FB, the file is RefPack compressed.

### Debug Info Footer

This footer contains a tiny bit of debug info about the Lumpy used to pack the archive.

| Type     | Description                                      |
|----------|--------------------------------------------------|
| char[4]  | Lumpy version/creator code (e.g: `L218`)         |
| uint32   | Lumpy flags (as a bitflag. Unknown)              | 

## C0FB

### Header

| Type   | Description            |
|--------|------------------------|
| UInt16 | Data Start Offset      |
| UInt16 | File Count             |

### File Entries

| Type     | Description |
|----------|-------------|
| UInt24   | Offset      |
| UInt24   | File Size   |
| C String | Path        |

### Footer

Same as BIGF/BIG4?
