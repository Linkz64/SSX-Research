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
| Offset | Type   | Description                          | Key                 |
|--------|--------|--------------------------------------|---------------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                     |
| 0x04   | Int16  | Count of **Model Files**             | `mdlCount`          |
| 0x06   | Int16  | Offset of **Model Header List**      |                     |
| 0x08   | UInt32 | Offset of **Model Data List**        | `mdlDataListOffset` |


## Model Header
Section 1 - Bytes[128]
| Offset | Type      | Description                                                | Key             | Rel                 |
|--------|-----------|------------------------------------------------------------|-----------------|---------------------|
| 0x00   | Bytes[16] | Name of model (ASCII string with a max length of 16 bytes) | `mdlName`       |                     |
| 0x10   | UInt32    | Offset of model                                            | `mdlOffset`     | `mdlDataListOffset` |
| 0x14   | UInt32    | Size of model in bytes                                     |                 | `mdlOffset`         |
| 0x18   | UInt32    | Offset of Bones                                            |                 |                     |
| 0x1C   | UInt32    | Offset of Inverse Kinematic Point                          |                 | `mdlOffset`         |
| 0x20   | UInt32    | Offset of Chunk Data                                       |                 | `mdlOffset`         |
| 0x24   | UInt32    | Offset of Mesh Data Start                                  |                 | `mdlOffset`         |
| 0x28   | UInt16    | Count of Chunk Data                                        |                 |                     |
| 0x2A   | UInt16    | Count of Bone Data                                         |                 |                     |
| 0x2C   | UInt16    | Unknown Count                                              |                 |                     |
| 0x2E   | UInt8     | Count of Material Data                                     | `matDataCount`  |                     |
| 0x2F   | UInt8     | Count of Inverse Kinematic Points                          | `ikDataCount`   |                     |
| 0x30   | Bytes[16] | Filler/Padding                                             |                 |                     |


## Material Data

| Offset | Type      | Description                                    | Key            |
|--------|-----------|------------------------------------------------|----------------|
| 0x00   | Bytes[4]  | Name of Texture map/file                       |                |
| 0x04   | Float32   | Unknown float value (Red?)                     |                |
| 0x08   | Float32   | Unknown float value (Green?)                   |                |
| 0x0C   | Float32   | Unknown float value (Blue?)                    |                |

## Bone Data

| Offset | Type      | Description                                                   | Key            |
|--------|-----------|---------------------------------------------------------------|----------------|
| 0x00   | Bytes[16] | Name of Bone (ASCII string with a maximum length of 16 bytes) | `boneName`     |
| 0x10   | UInt16    | Unknown           (First bone always has 0xFFFF)              |                |
| 0x12   | UInt16    | ID of Parent Bone (First bone always has 0xFFFF)              | `boneParentID` |
| 0x14   | Float32   | Location X                                                    |                |
| 0x18   | Float32   | Location Y                                                    |                |
| 0x1C   | Float32   | Location Z                                                    |                |



<!-- Inverse Kinematic bones/tagets/points 

This is a list which usually contains 2 points
Boards use them so the character's boots stick on

-->
## Inverse Kinematic Point
| Offset | Type      | Description                    | Key | Rel |
|--------|-----------|--------------------------------|-----|-----|
| 0x00   | Float32   | Location X                     |     |     |
| 0x04   | Float32   | Location Y                     |     |     |
| 0x08   | Float32   | Location Z                     |     |     |
| 0x0C   | UInt32    | Unknown (Filler)               |     |     |


## Chunk Data
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x00   | UInt32 | ID                         |     |     |
| 0x04   | UInt32 | Material ID                |     |     |
| 0x08   | UInt32 | Unknown                    |     |     |
| 0x0C   | UInt32 | Static Mesh Offset Start   |     |     |
| 0x10   | UInt32 | Static Mesh Offset End     |     |     |
| 0x14   | UInt32 | Flex Mesh Offset Start     |     |     |
| 0x18   | UInt32 | Flex Mesh Offset End       |     |     |


## ==Headers Need To be Revised==

# Static Mesh
## Mesh Data
| Offset | Type     | Description        | Key |
|--------|----------|--------------------|-----|
|        | UInt24   | Row Count          |     |
|        | Byte     | Column Size        |     |
|        | Byte[12] | Padding            |     |
|        | Byte[16] | Unknown            |     |
|        | Byte[10] | Unknown            |     |
|        | Byte     | Array Declaration? |     |
|        | Byte     | Array Size         |     |
|        | Byte     | Array Type         |     |
|        | Byte[16] | Unknown            |     |
|        | Row      | Model Info         |     |
|        | List     | Triangle Strip Count Row            |     |

### Model Info
| Type      | Description                                                         |
|-----------|---------------------------------------------------------------------|
| UInt32    | Strip Count                                                         |
| UInt32    | Edge Count                                                          |
| UInt32    | Normal Count (Can use used to detect if normals are in the file)    |
| UInt32    | Vertex Count                                                        |

### Triangle Strip Count Row
| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt32    | Count of vertices                       |
| Bytes[12] | Padding                                 |

## Pre Block Header
| Offset | Type     | Description        | Key |
|--------|----------|--------------------|-----|
|        | UInt24   | Row Count          |     |
|        | Byte   | Type or Size       |     |
|        | Byte[12] | Padding            |     |

## UV Block
| Offset | Type     | Description        | Key |
|--------|----------|--------------------|-----|
|        | Byte[16] | Unknown            |     |
|        | Byte[16] | Unknown            |     |
|        | Byte[10] | Unknown            |     |
|        | Byte     | Array Declaration? |     |
|        | Byte     | Array Size         |     |
|        | Byte     | Array Type         |     |
|        | List     | UV Data            |     |

### UV Data
Divide By 4096
| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt16    | UV map U    (X translation)             |
| UInt16    | UV map V    (Y translation)             |

## Normal Block
| Offset | Type     | Description        | Key |
|--------|----------|--------------------|-----|
|        | Byte[16] | Unknown            |     |
|        | Byte[16] | Unknown            |     |
|        | Byte[10] | Unknown            |     |
|        | Byte     | Array Declaration? |     |
|        | Byte     | Array Size         |     |
|        | Byte     | Array Type         |     |
|        | List     | Normal Data        |     |

### Normal Data
| Type      | Description                   |
|-----------|-------------------------------|
| UInt16    | Normal X direction            |
| UInt16    | Normal Y direction            |
| UInt16    | Normal Z direction            |


## Vertex  Block
| Offset | Type     | Description        | Key |
|--------|----------|--------------------|-----|
|        | Byte[16] | Unknown            |     |
|        | Byte[16] | Unknown            |     |
|        | Byte[10] | Unknown            |     |
|        | Byte     | Array Declaration? |     |
|        | Byte     | Array Size         |     |
|        | Byte     | Array Type         |     |
|        | List     | Vertex Data        |     |

### Vertex Data
| Type      | Description                   |
|-----------|-------------------------------|
| Float32   | Location X                    |
| Float32   | Location Y                    |
| Float32   | Location Z                    |

## Static Mesh Block Footer
| Offset | Type     | Description  | Key |
|--------|----------|--------------|-----|
|        | UInt24   | Row Count    |     |
|        | Byte[13] | Unknown      |     |

