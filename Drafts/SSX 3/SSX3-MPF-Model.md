# MPF File (PS2 Models)

- Contents:
    - [Overview](#overview)
    - [Structure](#structure)

<br>


***


<br>

# Overview
An **MPF** file contains model names, bones, UV maps, normals, vertices and other model information.


# Structure

The file structure was reversed by [kris2ffer](https://github.com/kris2ffer). You can find a C# struct [here](https://github.com/Kris2ffer/SSX-3D/blob/ps2-model/ssx3-ps2-model.cs).

_[ref n] = reference in wiki_

## File Header
| Offset | Type      | Description                                        |
|--------|-----------|----------------------------------------------------|
| 0x00   | UInt32    | Unknown (Possibly version or magic).               |
| 0x04   | Int16     | Number of Models.                                  |
| 0x06   | Int16     | Model list offset.                                 |
| 0x08   | UInt32    | Model root offset. _[ref 1]_                       |


## Model Header Section
| Offset | Type      | Description                                        |
|--------|-----------|----------------------------------------------------|
| 0x00   | Bytes[16] | An ASCII string with a maximum length of 16 bytes. |
| 0x0C   | UInt32    | Model offset = This value + _[ref 1]_              |
| 0x10   | UInt32    | Size                                               |
| 0x14   | UInt32    | Offset of Model data start offset.                 |
| 0x18   | UInt32    | Offset of Bone percentage offset.                  |
| 0x1C   | UInt32    | Offset of some unknown data.                       |
| 0x20   | UInt32    | First internal model offset.                       |
| 0x24   | UInt32    | Unknown                                            |
| 0x28   | UInt32    | Offset of Bone percentage offset 2.                |
| 0x2C   | UInt32    | Number list reference offset.                      |
| 0x30   | UInt32    | Offset of Bone percentage offset 3.                |
| 0x34   | UInt32    | Unknown                                            |
| 0x38   | UInt32    | Unknown                                            |
| 0x3C   | UInt32    | Unknown                                            |
| 0x40   | UInt16    | Count of the bone percentage offset offset.        |
| 0x42   | UInt16    | Internal model count.                              |
| 0x44   | UInt16    | Unknown                                            |
| 0x46   | UInt16    | Bone count.                                        |
| 0x48   | Bytes[8]  | Unknown (Bone count filler)                        |
