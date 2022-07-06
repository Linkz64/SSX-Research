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


<br>


## Structure


The file structure was reversed by [kris2ffer](https://github.com/kris2ffer). You can find their C# struct [here](https://github.com/Kris2ffer/SSX-3D/blob/ps2-model/ssx3-ps2-model.cs).


### File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Count of Models                      | `mdlCount`      |
| 0x06   | Int16  | Offset of Model Header list          |                 |
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
| 0x20   | UInt32    | Offset of Mesh Data                                        |             | `mdlOffset`     |
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


### Model

- Bone weight headers
- Bone weights
- Number list references
- Unknown list
- Unknown data
- Internal mesh references
- Internal meshes
- bytes[32] (footer)


<br>


### Bone/Skeleton


<br>


### Bone Weight Header
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x00   | UInt32 | Length of array/list       |     |     |
| 0x04   | UInt32 | Offset to Bone weight list |     | `?` |
| 0x08   | UInt32 | Unknown (Filler)           |     |     |


<br>


### Bone Weight
| Offset | Type   | Description            | Key | Rel |
|--------|--------|------------------------|-----|-----|
| 0x00   | UInt32 | Bone weight (0 to 100) |     |     |
| 0x02   | UInt32 | Bone ID                |     |     |
| 0x03   | UInt32 | Unknown                |     |     |


<br>


### Number List Ref
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x00   | UInt32 | Count                      |     |     |
| 0x04   | UInt32 | Offset of Number list      |     | `?` |


<br>


### Unknown Data
| Offset | Type   | Description                                                  | Key | Rel |
|--------|--------|--------------------------------------------------------------|-----|-----|
| 0x00   | UInt32 | Unknown (Always 1)                                           |     |     |
| 0x04   | UInt32 | Unknown (3 with one internal mesh, 4 with 2 internal meshes) |     | `?` |
| 0x08   | UInt32 | Unknown (Always -1)                                          |     |     |


<br>


### Internal Mesh refs
| Offset | Type   | Description                                                  | Key | Rel |
|--------|--------|--------------------------------------------------------------|-----|-----|
| 0x00   | UInt32 | Count                                                        |     |     |
| 0x04   | UInt32 | Offset of internal mesh offset table                         |     | `?` |


<br>


### Internal Mesh

- model/mesh data
- bytes[32] (footer)


<br>


### Offset of internal mesh offset OR Internal mesh header

### Offset of internal mesh


<br>


### Mesh Data

| Offset | Type      | Description                                                                                                     | Key |
|--------|-----------|-----------------------------------------------------------------------------------------------------------------|-----|
| 0x00   | UInt24    | Count of total rows                                                                                             |     |
| 0x03   | Byte      | Unknown (Always 10)                                                                                             |     |
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
| UInt32    | Count of vertices within triangle strip |
| Bytes[12] | Padding                                 |

_mesh data continued:_

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt24    | Count of vertices (?)                   |
| Byte      | Unknown (Always 0x10                    |
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
| UInt16    | UV map U                                |
| UInt16    | UV map V                                |
| UInt16    | UV map U distance                       |
| UInt16    | UV map V distance                       |

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

- **Filler - Byte**

- **Footer - Bytes[32] 0x......**















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

<br>

<br>

<br>

<br>

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


<br>


## Structure

### File Header
Section 0 - Bytes[12]
| Offset | Type   | Description                          | Key             |
|--------|--------|--------------------------------------|-----------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                 |
| 0x04   | Int16  | Count of Models                      | `mdlCount`      |
| 0x06   | Int16  | Offset of Model Header list          |                 |
| 0x08   | UInt32 | Offset of first/root model           | `mdlRootOffset` |


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
