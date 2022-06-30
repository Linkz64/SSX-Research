- Contents:
    - [MXF (Xbox Models)](#mxf-xbox-models)


# MXF (Xbox Models)
### Overview
An **MXF** file contains model names, bones, UV maps, normals, vertices and other model data.
Used for boards, characters and accessories.


### File Header
| Offset | Type   | Description                          | Key             | Rel         |
|--------|--------|--------------------------------------|-----------------|-------------|
| 0x00   | UInt32 | Unknown (Possibly version or magic). | `fileStart`     |             |
| 0x04   | Int16  | Model count                          | `mdlCount`      | `fileStart` |
| 0x06   | Int16  | Model list offset.                   |                 | `fileStart` |
| 0x08   | UInt32 | Model root offset.                   | `mdlRootOffset` | `fileStart` |

### Model Header

Bytes[396]
| Offset | Type       | Description                                                     | Key              | Rel         |
|--------|------------|-----------------------------------------------------------------|------------------|-------------|
| 0x00   | Bytes[16]  | Model name (An ASCII string with a maximum length of 16 bytes.) | `mdlName`        |             |
| 0x10   | UInt32     | Model offset = (This UInt32 value + `mdlRootOffset`)            | `mdlOffset`      |             |
| 0x14   | UInt32     | Model Size in bytes                                             | `mdlSizeBytes`   |             |
| 0x18   | UInt32     | Offset of bone data                                             |                  | `mdlOffset` |
| 0x1C   | UInt32     | Offset of bone data                                             |                  | `mdlOffset` |
| 0x20   | UInt32     | Unknown                                                         |                  |             |
| 0x24   | UInt32     | Offset of bone data                                             |                  | `mdlOffset` |
| 0x28   | UInt32     | Unknown data or end of bone data (Before 0xFFFFFFFF's)          |                  | `mdlOffset` |
| 0x2C   | UInt32     | Offset of model data             (After  0xFFFFFFFF's)          |                  | `mdlOffset` |
| 0x30   | UInt32     | Offset of model data             (After  0xFFFFFFFF's)          |                  | `mdlOffset` |
| 0x34   | UInt32     | Offset of face data                                             | `faceDataOffset` | `mdlOffset` |
| 0x38   | UInt32     | Unknown                                                         |                  |             |
| 0x3C   | UInt32     | Offset of mesh data                                             |                  | `mdlOffset` |
| 0x40   | UInt32     | Unknown                                                         |                  |             |
| 0x44   | UInt32     | Unknown Offset (Could be bone data or end of mesh data)         |                  |             |
| 0x48   | Bytes[324] | Unknown (TBD)                                                   |                  |             |

_Model header is part of a list, meaning there could be multiple of these. The amount of model headers is determined by `mdlCount`._


### Face data




### Mesh Data

Bytes[64]
| Offset | Type    | Description                        | Key          |
|--------|---------|------------------------------------|--------------|
| 0x00   | Float32 | Vertex X position                  | `vtxPosX`    |
| 0x04   | Float32 | Vertex Y position                  | `vtxPosY`    |
| 0x08   | Float32 | Vertex Z position                  | `vtxPosZ`    |
| 0x0C   | Float32 | Unknown (1.0)                      |              |
| 0x10   | Float32 | Normal (vertex) X direction        | `nrmVtxDirX` |
| 0x14   | Float32 | Normal (vertex) Y direction        | `nrmVtxDirY` |
| 0x18   | Float32 | Normal (vertex) Z direction        | `nrmVtXDirZ` |
| 0x1C   | UInt32  | Unknown (0 or 1, Filler/Padding)   |              |
| 0x20   | Float32 | Unknown                            |              |
| 0x24   | Float32 | Unknown                            |              |
| 0x28   | Float32 | Unknown                            |              |
| 0x2C   | Float32 | Unknown (1.0)                      |              |
| 0x30   | Float32 | UV Map U                           | `uvMapU`     |
| 0x34   | Float32 | UV Map V                           | `uvMapV`     |
| 0x38   | UInt32  | 0xFFFFFFFF                         |              |
| 0x3C   | UInt32  | Unknown                            |              |

_Vertex/Element count is face count divided by 3._

_Unknown float3 at 0x20 might be Face Normals or Tangent Normals for normal/bump maps._
