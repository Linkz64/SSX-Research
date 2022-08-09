# MPF File (PS2 Models)

- Contents:
    - [Overview](#overview)
    - [Structure](#structure)


<br>


***


<br>


# Overview
An **MPF** file contains model names, bones, UV maps, normals, vertices and other model data. <br>
Used for boards, characters and accessories.


<br>

Here is the structure made in programming languages for easy code implementation:
<br>
- [SSX Tricky mpf GO struct by Erick](https://github.com/Erickson400/TheTrickyModels/blob/main/mpf/MpfStructure.go)<br>
- [SSX Tricky mpf C# handler by GlitcherOG](https://github.com/GlitcherOG/SSX-PS2-Collection-Modder/blob/main/FileHandlers/Models/TrickyMPFModelHandler.cs)<br>

# Structure


<br>

**File contents:**
- [File Header](#file-header)
    - Model Header List
        - [Model Header](#model-header)
    - Model Data List
        - [Model Data](#model-data)
<br>

## File Header
Section 0 - Bytes[12]

| Offset | Type   | Description                          | Key                 |
|--------|--------|--------------------------------------|---------------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic)  |                     |
| 0x04   | Int16  | Count of **Models**                  | `mdlCount`          |
| 0x06   | Int16  | Offset of **Model Header List**      |                     |
| 0x08   | UInt32 | Offset of **Model Data List**        | `mdlDataListOffset` |
|        | List   | List containing Model Headers        |                     |
|        | List   | List containing Model Data           |                     |


<br>


## Model Header
Section 1 - Bytes[80]

| Offset 	| Type      	| Description                                                	| Key              	| Rel                 	|
|--------	|-----------	|------------------------------------------------------------	|------------------	|---------------------	|
| 0x00   	| Bytes[16] 	| Name of Model (ASCII string with a max length of 16 bytes) 	| `mdlName`        	|                     	|
| 0x10   	| UInt32    	| Offset of **Model Data**                                   	| `mdlDataOffset`  	| `mdlDataListOffset` 	|
| 0x14   	| UInt32    	| Size of model in bytes or end offset                       	|                  	| `mdlDataOffset`     	|
| 0x18   	| UInt32    	| Offset of **Bone Data List**                               	| `boneListOffset` 	| `mdlDataOffset`     	|
| 0x1C   	| UInt32    	| Offset of **IK Point List**                                	|                  	| `mdlDataOffset`     	|
| 0x20   	| UInt32    	| Offset of **Mesh Group Offset** (Chunk offsets)            	|                  	| `mdlDataOffset`     	|
| 0x24   	| UInt32    	| Offset of **Mesh Data**                                    	|                  	| `mdlDataOffset`     	|
| 0x28   	| UInt32    	| Offset Of **Material Data**?                               	|                  	|                     	|
| 0x2C   	| UInt32    	| Offset of _Number list reference_                            	|                  	| `mdlDataOffset`     	|
| 0x30   	| UInt32    	| Offset of **Skinning Data**                                	|                  	| `mdlDataOffset`     	|
| 0x34   	| UInt32    	| Unknown (Unused/Filler)                                    	|                  	| `mdlDataOffset`     	|
| 0x38   	| UInt32    	| Unknown (Unused/Filler)                                    	|                  	|                     	|
| 0x3C   	| UInt16    	| Count of **Skinning Data**                                 	|                  	|                     	|
| 0x3E   	| UInt16    	| Number Ref List Count                                         |                  	|                     	|
| 0x40   	| UInt16    	| Count of **Chunk Data**                                    	|                  	|                     	|
| 0x42   	| UInt16    	| Count of **Bone Data**                                     	| `boneDataCount`  	|                     	|
| 0x44   	| UInt16    	| Count of **Material Data**                                 	| `matDataCount`   	|                     	|
| 0x46   	| UInt16    	| Count of **IK points**                                     	|                  	|                     	|
| 0x48   	| UInt16    	| Count of **Morph Data**                                    	|                  	|                     	|
| 0x4A   	| UInt16    	| Unknown ID/Count (Related to Skeleton/Animation)           	|                  	|                     	|
| 0x4C   	| UInt32    	| Filler/Padding                                             	|                  	|                     	|


<br>


## Model Data

| Name                 | Description                                              |
|----------------------|----------------------------------------------------------|
| Material Data Lists  | Contains this `matDataCount` many materials              |
| Bone Data List       | Contains this `boneDataCount` many bones                 |
| Bone Weight Headers  |                                                          |
| Number List Ref      |                                                          |
| Unknown Data         |                                                          |
| Internal Mesh Ref    |                                                          |
| Internal Mesh        |                                                          |


<br>


## Material Data

| Offset | Type      | Description                                                           | Key            |
|--------|-----------|-----------------------------------------------------------------------|----------------|
| 0x00   | Bytes[4]  | Name of main Texture map/file                                         |                |
| 0x04   | Bytes[4]  | Name/Type of Texture                                                  |                |
| 0x08   | Bytes[4]  | Name/Type of Texture                                                  |                |
| 0x0C   | Bytes[4]  | Name/Type of Texture                                                  |                |
| 0x04   | Bytes[4]  | Name/Type of Texture                                                  |                |
| 0x14   | Float32   | Unknown float value                                                   |                |
| 0x18   | Float32   | Unknown float value                                                   |                |
| 0x1C   | Float32   | Unknown float value                                                   |                |

If a slot has 0x00202020 it may be a placeholder

**Texture types:**

** = first and last letter of main texture name

- **_b   - Bump/Normal map (Xbox) <br>
- **_g   - Shadow/Light?
- �nvr  - Environment/Reflection? (Might be leftover)
- envr   - Environment/Reflection? (Xbox)


<br>


## Bone Data
Size - Bytes[84]

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


<!-- Inverse Kinematic bones/tagets/points 

This is a list which usually contains 2 points
Boards use them so the character's boots stick on

-->
## IK Point (Inverse Kinematic)
| Offset | Type      | Description                    | Key | Rel |
|--------|-----------|--------------------------------|-----|-----|
| 0x00   | Float32   | Location X                     |     |     |
| 0x04   | Float32   | Location Y                     |     |     |
| 0x08   | Float32   | Location Z                     |     |     |
| 0x0C   | UInt32    | Unknown (Filler)               |     |     |


## Group Main
### Group Main Header
| Offset 	| Type   	| Description      	| Key 	| Rel 	|
|--------	|--------	|------------------	|-----	|-----	|
| 0x00   	| UInt32 	| ID               	|     	|     	|
| 0x04   	| UInt32 	| Material ID      	|     	|     	|
| 0x08   	| UInt32 	| Unknown          	|     	|     	|
|        	| UInt32 	| Sub Group Offset 	|     	|     	|
|        	| UInt32 	| Sub Group Count  	|     	|     	|

### Group Sub Group
| Offset 	| Type   	| Description          	| Key 	| Rel 	|
|--------	|--------	|----------------------	|-----	|-----	|
| 0x00   	| UInt32 	| Mesh Group Offset 	|     	|     	|
| 0x04   	| UInt32 	| Mesh Group Count     	|     	|     	|

### Sub Sub Mesh Group
| Offset 	| Type   	| Description  	| Key 	| Rel 	|
|--------	|--------	|--------------	|-----	|-----	|
| 0x00   	| UInt32 	| Model Offset 	|     	|     	|
| 0x04   	| UInt32 	| Unknown 1    	|     	|     	|
|        	| UInt32 	| Unknown 2    	|     	|     	|

<br>


## Bone Weight
### Bone Weight Header
| Offset | Type   | Description                | Key | Rel |
|--------|--------|----------------------------|-----|-----|
| 0x00   | UInt32 | Length of array/list       |     |     |
| 0x04   | UInt32 | Offset to Bone weight list |     |     |
| 0x08   | UInt32 | Unknown                    |     |     |

<br>

### Bone Weight
| Offset | Type   | Description            | Key | Rel |
|--------|--------|------------------------|-----|-----|
| 0x00   | UInt16 | Bone weight (0 to 100) |     |     |
| 0x02   | UInt8  | Bone ID                |     |     |
| 0x03   | UInt8  | Unknown                |     |     |


## Number List Ref
### Number List Ref Header
| Offset | Type   | Description                 | Key | Rel |
|--------|--------|-----------------------------|-----|-----|
| 0x00   | UInt32 | Sub  Number List Ref Count  |     |     |
| 0x04   | UInt32 | Sub  Number List Ref Offset |     |     |

<br>


### Sub Number List Ref 
| Offset | Type   | Description            | Key | Rel |
|--------|--------|------------------------|-----|-----|
|        | UInt16 | Unknown                |     |     |
|        | UInt16 | Unknown2               |     |     |

<br>

<!-- 
    Row Count Header
    Hex examples:
    01000010 00000000 00000000 00000000
    ^ 1 row 
    06000096 00000000 00000000 00000000
    ^ 6 rows
-->

<!-- THIS IS ALSO A COMMENT

Model Data List[
    Model Data 1 [
        Material Data List[
            Material 1
            Material 2
        ]
        Bone Data List[
            Bone 1
            Bone 2
        ]
        Bone Weights List 1[

        ]
        Bone Weights List 2[

        ]
        Offsets/Count List[
            Offset/Count 1 List[
            ]
            Offset/Count 1 List[
            ]
        ]
        Mesh Data List[
            Mesh Data 1 List[
                Mesh 1
                Mesh 2
            ]
            Mesh Data 2 List[
                Mesh 1
                Mesh 2
            ]
        ]
    ]
]



There's multiple mesh groups in the mesh section

    Mesh Data List [ # the model's header leads here

      Mesh Data 1 List [ # offset/count section leads here
            Mesh 1 # mesh info, tristrips, uvs, nrm, vtx
            Mesh 2
            etc...
        ] # footer Hex: 00000000 00000010 00000000 00000014

      Mesh Data 2 List[ # offset/count section leads here
            Mesh 1
            etc...
        ]  # footer Hex: 00000000 00000010 00000000 00000014

Test
-->


## Mesh Data

| Offset | Type      | Description                                                                                                     | Key |
|--------|-----------|-----------------------------------------------------------------------------------------------------------------|-----|
| 0x00   | UInt24    | Count of total rows                                                                                             |     |
| 0x03   | Byte      | Size of individual rows (Always 16)                                                                             |     |
| 0x04   | Bytes[12] | Unknown (Filler/Padding)                                                                                        |     |
| 0x10   | Bytes[13] | Unknown (Always 0x00000000010100010000000000)                                                                   |     |
| 0x1D   | Byte      | Prefix of count (0x80)                                                                                          |     |
| 0x1E   | Byte      | Count of total mesh info rows (sum of the amount of mesh info rows and the amount of triangle strip count rows) |     |
| 0x1F   | Byte      | Suffix of count (0x6c)                                                                                          |     |
| 0x20   | Bytes[16] | Mesh Info Row 1                                                                                                 |     |
| 0x30   | Bytes[16] | Mesh Info Row 2                                                                                                 |     |
|        | List      | List of Triangle Strip Count Rows                                                                               |     |


- **Triangle Strip Count Row**

The amount of triangle strip rows can be found inside Mesh Info Row 2 <br>
_First type is assumed to be either UInt32 or Byte_

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt32    | Count of vertices                       |
| Bytes[12] | Padding/Unknown                         |

_mesh data continued:_

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt24    | Count of rows                           |
| Byte      | Unknown (Always 16)                     |
| Bytes[12] | Unknown                                 |
| List      | UV Block                                |
| List      | Normal Block                            |
| List      | Vertex Block                            |

<br>

## UV Block
| Type      | Desc                                                           | Key |
|-----------|----------------------------------------------------------------|-----|
| Bytes[16] | Header of UV Block (Hex: 00100000 00100000 00000020 50505050)  |     |
| Bytes[12] | Unknown                                                        |     |
| Byte      | Unknown                                                        |     |
| Byte      | Prefix of UV count (0x80)                                      |     |
| Byte      | Count of UVs                                                   |     |
| Byte      | Suffix of UV count (0x6D)                                      |     |
| List      | List of UV values                                              |     |

**UV value**

| Type      | Description                             |
|-----------|-----------------------------------------|
| UInt16    | UV map U    (X translation)             |
| UInt16    | UV map V    (Y translation)             |
| UInt16    | UV map U distance                       |
| UInt16    | UV map V distance                       |

<br>

## Normal Block

| Type      | Desc                                                              | Key |
|-----------|-------------------------------------------------------------------|-----|
| Bytes[16] | Header of normal Block (Hex: 00000000 00800000 00000020 40404040) |     |
| Bytes[12] | Unknown                                                           |     |
| Byte      | Unknown                                                           |     |
| Byte      | Prefix of Normal Count (0x80)                                     |     |
| Byte      | Count of Normals                                                  |     |
| Byte      | Suffix of Normal count (0x79)                                     |     |
| List      | List Normal values                                                |     |

**Normal value:**

| Type      | Description                   |
|-----------|-------------------------------|
| UInt16    | Normal X direction            |
| UInt16    | Normal Y direction            |
| UInt16    | Normal Z direction            |

<br>

## Vertex Block
| Type      | Desc                                                              | Key |
|-----------|-------------------------------------------------------------------|-----|
| Bytes[16] | Header of Vertex Block (Hex: 00000000 0000803F 00000020 40404040) |     |
| Bytes[12] | Unknown                                                           |     |
| Byte      | Unknown                                                           |     |
| Byte      | Prefix of Vertex count (0x80)                                     |     |
| Byte      | Count of Vertices                                                 |     |
| Byte      | Suffix of Vertex count (0x78)                                     |     |
| List      | List Vertex values                                                |     |

**Vertex value:**

| Type      | Description                   |
|-----------|-------------------------------|
| Float32   | Location X                    |
| Float32   | Location Y                    |
| Float32   | Location Z                    |

## Shadow Vertex Block
| Type      | Desc                                                              | Key |
|-----------|-------------------------------------------------------------------|-----|
| Bytes[16] | Header of Vertex Block (Hex: 00000000 0000803F 00000020 40404040) |     |
| Bytes[12] | Unknown                                                           |     |
| Byte      | Unknown                                                           |     |
| Byte      | Prefix of Vertex count (0x80)                                     |     |
| Byte      | Count of Vertices                                                 |     |
| Byte      | Suffix of Vertex count (0x6C)                                     |     |
| List      | List Vertex values                                                |     |

**Vertex value:**

| Type      | Description                   |
|-----------|-------------------------------|
| Float32   | Location X                    |
| Float32   | Location Y                    |
| Float32   | Location Z                    |
| UInt32    | Unknown                       |


















<br>


***


<br>



**End of MPF Structure**
<br>
