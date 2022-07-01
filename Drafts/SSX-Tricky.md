- Contents:
    - [MXF File (Xbox Models)](#mxf-file-xbox-models)


<br>


***


<br>


# MXF File (Xbox Models)
## Overview
An **MXF** file contains model names, bones, UV maps, normals, vertices and other model data.
Used for boards, characters and accessories.


<br>


## Structure

### File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Model count                          | `mdlCount`      |
| 0x06   | Int16  | Model list offset.                   |                 |
| 0x08   | UInt32 | Models root offset.                  | `mdlRootOffset` |


<br>


### Model Header
Section 1 - Bytes[396]
| Offset | Type       | Description                                                     | Key              | Rel             |
|--------|------------|-----------------------------------------------------------------|------------------|-----------------|
| 0x00   | Bytes[16]  | Model Name (An ASCII string with a maximum length of 16 bytes)  | `mdlName`        |                 |
| 0x10   | UInt32     | Offset of Model                                                 | `mdlOffset`      | `mdlRootOffset` | 
| 0x14   | UInt32     | Size of Model in bytes                                          | `mdlSizeBytes`   |                 |
| 0x18   | UInt32     | Offset of Bone Data                                             |                  | `mdlOffset`     |
| 0x1C   | UInt32     | Offset of Bone Data                                             |                  | `mdlOffset`     |
| 0x20   | UInt32     | Unknown                                                         |                  |                 |
| 0x24   | UInt32     | Offset of Bone Data                                             |                  | `mdlOffset`     |
| 0x28   | UInt32     | Offset of Unknown Data or end of bone data (Before 0xFFFFFFFF's)|                  | `mdlOffset`     |
| 0x2C   | UInt32     | Offset of Model Data             (After  0xFFFFFFFF's)          |                  | `mdlOffset`     |
| 0x30   | UInt32     | Offset of Model Data             (After  0xFFFFFFFF's)          |                  | `mdlOffset`     |
| 0x34   | UInt32     | Offset of Triangle Strip Data                                   | `triDataOffset`  | `mdlOffset`     |
| 0x38   | UInt32     | Unknown                                                         |                  |                 |
| 0x3C   | UInt32     | Offset of Vertex Data                                           |                  | `mdlOffset`     |
| 0x40   | UInt32     | Unknown                                                         |                  |                 |
| 0x44   | UInt32     | Unknown Offset (Could be bone data or end of vertex data)       |                  |                 |
| 0x48   | Bytes[324] | Unknown (TBD)                                                   |                  |                 |

_Model header is part of a list, meaning there could be multiple of these. The amount of model headers is determined by `mdlCount`._
_Unknown Data (read 0x28) may contain inverse kinematics points/targets (point0 XYZ, unk, point1 XYZ, unk)_


<br>


### Bone Data

| Offset | Type    | Description                        | Key         |
|--------|---------|------------------------------------|-------------|
| 0x00   | (TBD)   | (TBD)                              |             |


<br>


### Triangle Strip Data

| Offset | Type       | Description                        | Key         | Rel         |
|--------|------------|------------------------------------|-------------|-------------|
| 0x00   | UInt32     | Offset of Triangle indices         |             | `mdlOffset` |
| 0x04   | UInt32     | Triangle Count                     | `triCount`  |             |
| 0x08   | Bytes[8]   | Unknown                            |             |             |


**Triangle indices**

First strip usually starts off with 0x0000 0x0100 0x0200
If there's multiple strips, face indices will be separated by 0xFFFF
Bytes[6]
| Offset | Type    | Description                        |
|--------|---------|------------------------------------|
| 0x00   | UInt16  | Face index                         |
| 0x02   | UInt16  | Face index                         |
| 0x04   | UInt16  | Face index                         |

_For total byte size of triangle indices do 6 × `faceCount`_


<br>


### Vertex Data

Bytes[64]
| Offset | Type    | Description                        | Key          |
|--------|---------|------------------------------------|--------------|
| 0x00   | Float32 | Vertex X position                  | `vtxPosX`    |
| 0x04   | Float32 | Vertex Y position                  | `vtxPosY`    |
| 0x08   | Float32 | Vertex Z position                  | `vtxPosZ`    |
| 0x0C   | Float32 | Unknown (1.0)                      |              |
| 0x10   | Float32 | Normal (vertex) X direction        | `nrmDirX`    |
| 0x14   | Float32 | Normal (vertex) Y direction        | `nrmDirY`    |
| 0x18   | Float32 | Normal (vertex) Z direction        | `nrmDirZ`    |
| 0x1C   | UInt32  | Unknown (0 or 1, Filler/Padding)   |              |
| 0x20   | Float32 | Unknown                            |              |
| 0x24   | Float32 | Unknown                            |              |
| 0x28   | Float32 | Unknown                            |              |
| 0x2C   | Float32 | Unknown (1.0)                      |              |
| 0x30   | Float32 | UV Map U                           | `uvMapU`     |
| 0x34   | Float32 | UV Map V                           | `uvMapV`     |
| 0x38   | UInt32  | 0xFFFFFFFF                         |              |
| 0x3C   | UInt32  | Unknown                            |              |

_Unknown float3 at 0x20 might be Face Normals or Tangent Normals for normal/bump maps._
