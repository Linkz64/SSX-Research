- Contents:
    - [MXF (Xbox Models)](#mxf-xbox-models)


# MXF (Xbox Models)
### Overview
An **MXF** file contains model names, bones, UV maps, normals, vertices and other model data.
Used for boards, characters and accessories.


### File Header
| Offset | Type   | Description                          | Key           | Rel       |
|--------|--------|--------------------------------------|---------------|-----------|
| 0x00   | UInt32 | Unknown (Possibly version or magic). | fileStart     |           |
| 0x04   | Int16  | Model count                          | mdlCount      | fileStart |
| 0x06   | Int16  | Model list offset.                   |               | fileStart |
| 0x08   | UInt32 | Model root offset.                   | mdlRootOffset | fileStart |

### Model Header [List]
_Model header is part of a list, meaning there could be multiple of these. The amount of model headers is determined by mdlCount._
| Offset | Type       | Description                                                     | Key       | Rel       |
|--------|------------|-----------------------------------------------------------------|-----------|-----------|
| 0x00   | Bytes[16]  | Model name (An ASCII string with a maximum length of 16 bytes.) | mdlName   |           |
| 0x10   | UInt32     | Model offset = (This UInt32 value + mdlRootOffset)              | mdlOffset |           |
| 0x14   | UInt32     | Size in bytes                                                   | mdlSize   |           |
| 0x18   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x1C   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x20   | UInt32     | Unknown                                                         |           |           |
| 0x24   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x28   | UInt32     | End of model data header (Before 0xFFFFFFFF)                    |           | mdlOffset |
| 0x2C   | UInt32     | Offset of first internal model (After 0xFFFFFFFF)               |           | mdlOffset |
| 0x30   | UInt32     | Offset of first internal model (After 0xFFFFFFFF)               |           | mdlOffset |
| 0x34   | UInt32     | Offset of model data                                            |           | mdlOffset |
| 0x38   | UInt32     | Unknown                                                         |           |           |
| 0x3C   | UInt32     | Offset of mesh data                                             |           | mdlOffset |
| 0x40   | UInt32     | Unknown                                                         |           |           |
| 0x44   | UInt32     | Unknown Offset (Could be bone data or end of mesh data)         |           |           |
| 0x48   | Bytes[324] | Unknown (TBD)                                                   |           |           |

### Mesh Data [List]
_Vertex normal data may be incorrect._
| Offset | Type    | Description                   | Key     |
|--------|---------|-------------------------------|---------|
| 0x00   | Float32 | Vertex X position             | vtxPosX |
| 0x04   | Float32 | Vertex Y position             | vtxPosY |
| 0x08   | Float32 | Vertex Z position             | vtxPosZ |
| 0x0C   | Float32 | Unknown (1.0)                 |         |
| 0x10   | Float32 | Normal X direction            | nrmDirX |
| 0x14   | Float32 | Normal Y direction            | nrmDirY |
| 0x18   | Float32 | Normal Z direction            | nrmDirZ |
| 0x1C   | UInt32  | Unknown (0, Filler/Padding)   |         |
| 0x20   | Float32 | Unknown                       |         |
| 0x24   | Float32 | Unknown                       |         |
| 0x28   | Float32 | Unknown                       |         |
| 0x2C   | Float32 | Unknown (1.0)                 |         |
| 0x30   | Float32 | UV Map U                      | uvMapU  |
| 0x34   | Float32 | UV Map V                      | uvMapV  |
| 0x38   | UInt32  | 0xFFFFFFFF                    |         |
