# MPF File (Models)

- Contents:
    - [Overview](#overview)
    - [Structure](#structure)


<br>


***


<br>

# Overview
An **MPF** file contains model names, bones, UV maps, normals, vertices and other model data. <br>
Used for boards, characters and accessories.<br>
<br>
[SSX OG mpf C# handler by GlitcherOG](https://github.com/GlitcherOG/SSX-PS2-Collection-Modder/blob/main/FileHandlers/Models/SSXMPFModelHandler.cs)<br>

Please note hex offsets are currently wrong
# Structure

**File contents:**
- [File Header](#file-header)
    - Model Header List
        - [Model Header](#model-header)
    - Model Data List
        - [Model Data](#model-data)

## File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Count of **Model Files**             | `mdlCount`      |
| 0x06   | Int16  | Offset of **Model Header List**      |                 |
| 0x08   | UInt32 | Offset of **Model Data List**        | `mdlRootOffset` |


## Model Header
Section 1 - Bytes[128]
| Offset | Type      | Description                                                | Key         | Rel             |
|--------|-----------|------------------------------------------------------------|-------------|-----------------|
| 0x00   | Bytes[16] | Name of model (ASCII string with a max length of 16 bytes) | `mdlName`   |                 |
| 0x10   | UInt32    | Offset of model                                            | `mdlOffset` | `mdlRootOffset` |
| 0x18   | UInt32    | Offset of Model data start                                 |             | `mdlOffset`     |
| 0x14   | UInt32    | Size of model in bytes                                     |             |                 |
| 0x1C   | UInt32    | Offset of Bones                                            |             | `mdlOffset`     |
| 0x20   | UInt32    | Offset of some unknown data (Possible Rotation Data)       |             | `mdlOffset`     |
| 0x24   | UInt32    | Offset of Chunk Data                                       |             | `mdlOffset`     |
| 0x28   | UInt32    | Data Start                                                 |             |                 |
| 0x3C   | UInt16    | Chunk Count                                                |             |                 |
| 0x3E   | UInt16    | Bone Count                                                 |             |                 |
| 0x40   | UInt16    | Unknown Count                                              |             |                 |
| 0x42   | UInt16    | Body Objects Count                                         |             | `boneDataCount` |
| 0x44   | UInt16    | Unknown Data Count (Possible Rotation Stuff)               |             |                 |
| 0x4C   | UInt32    | Filler/Padding                                             |             |                 |


## Body Objects(?)

| Offset | Type      | Description                                    | Key            |
|--------|-----------|------------------------------------------------|----------------|
| 0x00   | Bytes[4]  | Name                                           |                |
| 0x14   | Float32   | Unknown float value (x?)                       |                |
| 0x14   | Float32   | Unknown float value (y?)                       |                |
| 0x14   | Float32   | Unknown float value (z?)                       |                |

## Bone Data

| Offset | Type      | Description                                                   | Key            |
|--------|-----------|---------------------------------------------------------------|----------------|
| 0x00   | Bytes[16] | Name of Bone (ASCII string with a maximum length of 16 bytes) | `boneName`     |
| 0x10   | UInt16    | Unknown           (First bone always has 0xFFFF)              |                |
| 0x12   | UInt16    | ID of Parent Bone (First bone always has 0xFFFF)              | `boneParentID` |
| 0x18   | Float32   | Location X                                                    |                |
| 0x1C   | Float32   | Location Y                                                    |                |
| 0x20   | Float32   | Location Z                                                    |                |


## Rotation data? Header
| Offset | Type   | Description                    | Key | Rel |
|--------|--------|--------------------------------|-----|-----|
| 0x14   | Float32   | Unknown float value (x?)    |     |     |
| 0x14   | Float32   | Unknown float value (y?)    |     |     |
| 0x14   | Float32   | Unknown float value (z?)    |     |     |
| 0x08   | UInt32 | Unknown (Filler)               |     |     |


## Chunk Data
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x00   | UInt32 | ID                         |     |     |
| 0x02   | UInt32 | Chunk ID                   |     |     |
| 0x03   | UInt32 | Unknown                    |     |     |
| 0x03   | UInt32 | Static Mesh Offset Start   |     |     |
| 0x03   | UInt32 | Static Mesh Offset End     |     |     |
| 0x03   | UInt32 | Flex Mesh Offset Start     |     |     |
| 0x03   | UInt32 | Flex Mesh Offset End       |     |     |


## ==Headers Need To be Revised==

# Static Mesh
## Mesh Data
+48 Offset
| Type      | Description                                                         |
|-----------|---------------------------------------------------------------------|
| UInt32    | Strip Count                                                         |
| UInt32    | Edge Count                                                          |
| UInt32    | Normal Count (Can use used to detect if normals are in the file)    |
| UInt32    | Vertex Count                                                        |

#### Triangle Strip Count Row
| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt32    | Count of vertices                       |
| Bytes[12] | Padding                                 |
+16 Offset

## UV Block
+48 Offset

#### UV
Divide By 4096
| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt16    | UV map U    (X translation)             |
| UInt16    | UV map V    (Y translation)             |

## Normal Block
+48 Offset

#### Normal
| Type      | Description                   |
|-----------|-------------------------------|
| UInt16    | Normal X direction            |
| UInt16    | Normal Y direction            |
| UInt16    | Normal Z direction            |


## Vertex  Block
+48 Offset

#### Vertex
| Type      | Description                   |
|-----------|-------------------------------|
| Float32   | Location X                    |
| Float32   | Location Y                    |
| Float32   | Location Z                    |

