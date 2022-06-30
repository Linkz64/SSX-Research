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
| 0x04   | Int16  | Number of Models.                    | mdlNum        | fileStart |
| 0x06   | Int16  | Model list offset.                   |               | fileStart |
| 0x08   | UInt32 | Model root offset.                   | mdlRootOffset | fileStart |

### Model Header Section
| Offset | Type       | Description                                                     | Key       | Rel       |
|--------|------------|-----------------------------------------------------------------|-----------|-----------|
| 0x00   | Bytes[16]  | Model name (An ASCII string with a maximum length of 16 bytes.) | mdlName   |           |
| 0x10   | UInt32     | Model offset = (This UInt32 value + mdlRootOffset)              | mdlOffset |           |
| 0x14   | UInt32     | Size in bytes                                                   | mdlSize   |           |
| 0x18   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x1C   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x20   | UInt32     | Unknown                                                         |           |           |
| 0x24   | UInt32     | Offset of model data header                                     |           | mdlOffset |
| 0x28   | UInt32     | End of model data header (Before "FFFFFFFF")                    |           | mdlOffset |
| 0x2C   | UInt32     | Offset of first internal model (After "FFFFFFFF")               |           | mdlOffset |
| 0x30   | UInt32     | Offset of first internal model (After "FFFFFFFF")               |           | mdlOffset |
| 0x34   | UInt32     | Offset of model data                                            |           | mdlOffset |
| 0x38   | UInt32     | Unknown                                                         |           |           |
| 0x3C   | UInt32     | Offset of mesh data                                             |           | mdlOffset |
| 0x40   | UInt32     | Unknown                                                         |           |           |
| 0x44   | UInt32     | Unknown Offset (Could be bone data or end of mesh data)         |           |           |
| 0x48   | Bytes[324] | Unknown (TBD)                                                   |           |           |
