SSX Content

# MPF File (PS2 Models)
## Overview
An **MPF** file contains model names, bones, UV maps, normals, vertices and other model data. <br>
Used for boards, characters and accessories.

Please note hex offsets are currently wrong
## Structure

**File contents:**
- [File Header](#file-header)
    - Model Header List
        - [Model Header](#model-header)
    - Model Data List
        - [Model Data](#model-data)

### File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Count of **Model Files**                  | `mdlCount`      |
| 0x06   | Int16  | Offset of **Model Header List**      |                 |
| 0x08   | UInt32 | Offset of **Model Data List**        | `mdlRootOffset` |


### Model Header
Section 1 - Bytes[128]
| Offset | Type      | Description                                                | Key         | Rel             |
|--------|-----------|------------------------------------------------------------|-------------|-----------------|
| 0x00   | Bytes[16] | Name of model (ASCII string with a max length of 16 bytes) | `mdlName`   |                 |
| 0x10   | UInt32    | Offset of model                                            | `mdlOffset` | `mdlRootOffset` |
| 0x18   | UInt32    | Offset of Model data start                                 |             | `mdlOffset`     |
| 0x14   | UInt32    | Size of model in bytes                                     |             |                 |
| 0x1C   | UInt32    | Offset of Bones                                |             | `mdlOffset`     |
| 0x20   | UInt32    | Offset of some unknown data (Possible Rotation Data)                                |             | `mdlOffset`     |
| 0x24   | UInt32    | Offset of Chunk Data                                        |             | `mdlOffset`     |
| 0x28   | UInt32    | Data Start                                                    |             |                 |
| 0x3C   | UInt16    | Chunk Count                                                    |             |                 |
| 0x3E   | UInt16    | Bone Count                                          |             |                 |
| 0x40   | UInt16    | Unknown Count                                      |             |                 |
| 0x42   | UInt16    | Body Objects Count                                 |             | `boneDataCount` |
| 0x44   | UInt16    | Unknown Data Count (Possible Rotation Stuff)                                  |             |   |
| 0x4C   | UInt32    | Filler/Padding                                             |             |                 |


### Body Objects(?)

| Offset | Type      | Description                                    | Key            |
|--------|-----------|------------------------------------------------|----------------|
| 0x00   | Bytes[4]  | Name                                           |                |
| 0x14   | Float32   | Unknown float value (x?)                            |                |
| 0x14   | Float32   | Unknown float value (y?)                         |                |
| 0x14   | Float32   | Unknown float value (z?)                           |                |

### Bone Data

| Offset | Type      | Description                                                   | Key            |
|--------|-----------|---------------------------------------------------------------|----------------|
| 0x00   | Bytes[16] | Name of Bone (ASCII string with a maximum length of 16 bytes) | `boneName`     |
| 0x10   | UInt16    | Unknown           (First bone always has 0xFFFF)              |                |
| 0x12   | UInt16    | ID of Parent Bone (First bone always has 0xFFFF)              | `boneParentID` |
| 0x18   | Float32   | Location X                                                    |                |
| 0x1C   | Float32   | Location Y                                                    |                |
| 0x20   | Float32   | Location Z                                                    |                |


### Rotation data? Header
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x14   | Float32   | Unknown float value (x?)                            |                |
| 0x14   | Float32   | Unknown float value (y?)                         |                |
| 0x14   | Float32   | Unknown float value (z?)                           |                |
| 0x08   | UInt32 | Unknown (Filler)           |     |     |


### Chunk Data
| Offset | Type   | Description            | Key | Rel |
|--------|--------|------------------------|-----|-----|
| 0x00   | UInt32 | ID |     |     |
| 0x02   | UInt32 | Chunk ID                |     |     |
| 0x03   | UInt32 | Unknown                |     |     |
| 0x03   | UInt32 | Static Mesh Offset Start                |     |     |
| 0x03   | UInt32 | Static Mesh Offset End                |     |     |
| 0x03   | UInt32 | Flex Mesh Offset Start                |     |     |
| 0x03   | UInt32 | Flex Mesh Offset End                |     |     |


### ==Everything below here def needs to be revised at a later date as i didnt update it all==

## Static Mesh
### Mesh Data

| Offset | Type      | Description                                                                                                     | Key |
|--------|-----------|-----------------------------------------------------------------------------------------------------------------|-----|
| 0x00   | UInt24    | Count of total rows                                                                                             |     |
| 0x03   | Byte      | Size of individual rows (Always 16)                                                                             |     |
| 0x04   | Bytes[12] | Unknown (Filler/Padding)                                                                                        |     |
| 0x10   | Bytes[13] | Unknown (Always 0x00000000010100010000000000)                                                                   |     |
| 0x1D   | Byte      | Prefix of count (0x80)                                                                                          |     |
| 0x1E   | Byte      | Count of total mesh info rows (sum of the amount of mesh info rows and the amount of triangle strip count rows) |     |
| 0x1F   | Byte      | Suffix of count (0x6c)                                                                                          |     |
| 0x20   | Bytes[16] | Mesh info row                                                                                                   |     |
| 0x30   | Bytes[16] | Mesh info row                                                                                                   |     |

- **Triangle Strip Count Row**

The amount of triangle strip rows can be calculated by subtracting 2 from total mesh info count (see 0x1E) <br>
_First type is assumed to be either UInt32 or Byte_
| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt32    | Count of vertices                       |
| Bytes[12] | Padding                                 |

_mesh data continued:_

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt24    | Count of vertices (?)                   |
| Byte      | Unknown (Always 16)                     |
| Bytes[12] | Unknown                                 |


### UV Block
| Type      | Desc                                                    | Key |
|-----------|---------------------------------------------------------|-----|
| Bytes[16] | Header of UV Block (0x00100000001000000000002050505050) |     |
| Bytes[12] | Unknown                                                 |     |
| Byte      | Unknown                                                 |     |
| Byte      | Prefix of UV count (0x80)                               |     |
| Byte      | Count of UVs                                            |     |
| Byte      | Suffix of UV count (0x6D)                               |     |

**UV**

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt16    | UV map U    (X translation)             |
| UInt16    | UV map V    (Y translation)             |

- **Filler - Byte**

## Normal Block

| Type      | Desc                                                        | Key |
|-----------|-------------------------------------------------------------|-----|
| Bytes[16] | Header of normal Block (0x00000000008000000000002040404040) |     |
| Bytes[12] | Unknown                                                     |     |
| Byte      | Unknown                                                     |     |
| Byte      | Prefix of Normal Count (0x80)                               |     |
| Byte      | Count of Normals                                            |     |
| Byte      | Suffix of Normal count (0x79)                               |     |

**Normal:**

| Type      | Description                   |
|-----------|-------------------------------|
| UInt16    | Normal X direction            |
| UInt16    | Normal Y direction            |
| UInt16    | Normal Z direction            |

- **Filler - Byte**

### Vertex Block
| Type      | Desc                                                        | Key |
|-----------|-------------------------------------------------------------|-----|
| Bytes[16] | Header of Vertex Block (0x000000000000803F0000002040404040) |     |
| Bytes[12] | Unknown                                                     |     |
| Byte      | Unknown                                                     |     |
| Byte      | Prefix of Vertex count (0x80)                               |     |
| Byte      | Count of Vertices                                           |     |
| Byte      | Suffix of Vertex count (0x78)                               |     |

**Vertex:**

| Type      | Description                   |
|-----------|-------------------------------|
| Float32   | Location X                    |
| Float32   | Location Y                    |
| Float32   | Location Z                    |
