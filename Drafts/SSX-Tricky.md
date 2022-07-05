- Contents:
    - [MPF File (PS2 Models)](#mpf-file-ps2-models)
    - [MXF File (Xbox Models)](#mxf-file-xbox-models)


<br>


***


<br>

# MPF File (PS2 Models)
## Overview
An **MPF** file contains model names, bones, UV maps, normals, vertices and other model data. <br>
Used for boards, characters and accessories.

_TODO: Contents tree_

<br>


## Structure

### File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Count of Models                      | `mdlCount`      |
| 0x06   | Int16  | Offset of model list                 |                 |
| 0x08   | UInt32 | Offset of first/root model           | `mdlRootOffset` |


<br>


### Model Header
Section 1 - Bytes[]
| Offset | Type      | Description                                                | Key         | Rel             |
|--------|-----------|------------------------------------------------------------|-------------|-----------------|
| 0x00   | Bytes[16] | Name of model (ASCII string with a max length of 16 bytes) | `mdlName`   |                 |
| 0x0C   | UInt32    | Offset of model                                            | `mdlOffset` | `mdlRootOffset` |
| 0x10   | UInt32    | Size of model in bytes                                     |             |                 |
| 0x14   | UInt32    | Offset of Model data start                                 |             | `mdlOffset`     |
| 0x18   | UInt32    | Offset of Bone weight/extra                                |             | `mdlOffset`     |
| 0x1C   | UInt32    | Offset of some unknown data                                |             | `mdlOffset`     |
| 0x20   | UInt32    | Offset of Triangle Strip data                              |             | `mdlOffset`     |
| 0x24   | UInt32    | Unknown                                                    |             |                 |
| 0x28   | UInt32    | Offset of Bone weight/extra                                |             | `mdlOffset`     |
| 0x2C   | UInt32    | Offset of Number list reference                            |             | `mdlOffset`     |
| 0x30   | UInt32    | Offset of Bone weight/extra                                |             | `mdlOffset`     |
| 0x34   | UInt32    | Unknown                                                    |             |                 |
| 0x38   | UInt32    | Unknown                                                    |             |                 |
| 0x3C   | UInt16    | Unknown (Count?)                                           |             |                 |
| 0x3E   | UInt16    | Unknown (Count?)                                           |             |                 |
| 0x40   | UInt16    | Count of the Bone weight/extra sections                    |             |                 |
| 0x42   | UInt16    | Count of Internal Meshes                                   |             |                 |
| 0x44   | UInt16    | Unknown                                                    |             |                 |
| 0x46   | UInt16    | Count of Bones                                             |             |                 |
| 0x48   | Bytes[8]  | Unknown (Filler)                                           |             |                 |





<br>


***


<br>



**End of MPF info**
<br>
<br>
<br>
<br>
<br>








<br>


***


<br>


# MXF File (Xbox Models)
## Overview
An **MXF** file contains model names, bones, UV maps, normals, vertices and other model data. <br>
Used for boards, characters and accessories.

_TODO: Contents tree for structure_

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

The amount of model headers is determined by `mdlCount`

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

_Model header is part of a list_ <br>
_Unknown Data (see 0x28) may contain inverse kinematics points/targets (point0 XYZ, unk, point1 XYZ, unk)_ <br>


<br>


### Bone Data

| Offset | Type      | Description                                                   | Key            |
|--------|-----------|---------------------------------------------------------------|----------------|
| 0x00   | Bytes[16] | Name of Bone (ASCII string with a maximum length of 16 bytes) | `boneName`     |
| 0x10   | UInt16    | Unknown           (First bone always has 0xFFFF)              |                |
| 0x12   | UInt16    | ID of Parent Bone (First bone always has 0xFFFF)              | `boneParentID` |
| 0x14   | UInt16    | Unknown                                                       |                |
| 0x16   | UInt16    | ID of Bone                                                    | `boneID`       |
| 0x18   | Float32   | Location X                                                    |                |
| 0x1C   | Float32   | Location Y                                                    |                |
| 0x20   | Float32   | Location Z                                                    |                |
| 0x24   | Float32   | Rotation Euler Radian X                                       |                |
| 0x28   | Float32   | Rotation Euler Radian Y                                       |                |
| 0x2C   | Float32   | Rotation Euler Radian Z                                       |                |
| 0x30   | Float32   | Rotation Euler Radian X                                       |                |
| 0x34   | Float32   | Rotation Euler Radian Y                                       |                |
| 0x38   | Float32   | Rotation Euler Radian Z                                       |                |
| 0x3C   | Bytes[24] | Contains 6 float values with either -1.0 or 1.0               |                |

Location and Rotation is relative to parent bone.


<br>


### Triangle Strip Data

| Offset | Type       | Description                        | Key         | Rel         |
|--------|------------|------------------------------------|-------------|-------------|
| 0x00   | UInt32     | Offset of Triangle indices         |             | `mdlOffset` |
| 0x04   | UInt32     | Triangle Count                     | `triCount`  |             |
| 0x08   | Bytes[8]   | Unknown                            |             |             |


**Triangle indices**

The amount of triangle indices is determined by `triCount` <br>
| Type    | Description                        |
|---------|------------------------------------|
| UInt16  | Triangle index                     |

_First strip usually starts off with 0x0000 0x0100 0x0200_ <br>
_If there's multiple strips, triangle indices will be separated by 0xFFFF <br>_



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
| 0x30   | Float32 | UV Map U                           | `texMapU`    |
| 0x34   | Float32 | UV Map V                           | `texMapV`    |
| 0x38   | UInt32  | 0xFFFFFFFF                         |              |
| 0x3C   | UInt32  | Unknown                            |              |

_Unknown float3 at 0x20 might be Face Normals or Tangent Normals for normal/bump maps._
