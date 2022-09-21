struct aip{ // FILE: .AIP    | Contents: Start points, Respawn locations and/or Bot path location.

    struct aip_Header{
    
        UInt32 unk1 Count;
        UInt32 unk2 Count;
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
        UInt32 unk[4];
    }
    // start of unk1
    
    // followed by unk2
    
    struct unk1_unk2{ // unk1 and unk2 are the same I think
    
        Float32       unk;
        UInt32        unkA_Count;
        UInt32        unkB_Count;
    
        Float32 3     pos1; // main  point
        Float32 3     pos2; // extra point
        Float32 3     pos3; // extra point
    
        unkA[
            Float32 4 unkA_1;
        ]
        unkB[
            UInt32  2 unkB_1;
            Float32 2 unkB_2;
        ]
    };
};












struct wdf{ // FILE: .WDF    | CONTENTS: Instances, Patches
    
    struct wdf_Header{ // for every instance and patches
    
        Float32 9   unks;
        UInt16      instCount;
        UInt16      patchCount;
        UInt16      unk2Count; // or UInt32
        UInt16      unkxCount;
        UInt16      unk3Count;
        //FFFF
    };
    
    // followed by pchRando, some random patch points (they form a flat patch in a random spot)
    
    struct pchRando{ // 16 of these
        bytes[8]    unk;
        UInt32      unkCount;
        UInt16 4    unk;
        Float32 3   pchRandoPoint1;
        Float32 3   pchRandoPoint2;
    };
    
    struct unk3{ // there's unk3Count of these
        bytes[4]    unk
        // followed by either buffer padding/filler or instances
    
        // calculating buffer size:    -((unk3Count * 4) % -16)
    };
    
    struct instances{ // [size 0x110]
    
        Float32 16    matrix; // 4x4 3D transformation matrix (location, rotation, scale)
        Float32 16    unkMtx; // unknown matrix
        bytes[32]     unk;    // 2 blank rows?
        Float32 3     unk;
        bytes[4]      unk;
        Float32 2     unk;
        Float32 2     unk; // both powers of 2 (32.0, 128.0, etc)
        UInt32        unk;
        //FFFFFFFF x2
        UInt32        unk;
        Float32 3     unk; // bounds point 1?
        Float32 3     unk; // bounds point 2?
        bytes[2]      unk;
        UInt16        unk;
        Float32       unk; // or bytes[4] or 2 UInt16's
        UInt16 2      unk;
        FFFF
        UInt16        unk;
        Float32       unk;
        //FFFFFFFF
        bytes[4]      unk;
        //FFFFFFFF x3
    };
    
    struct patches{
    
        Float32 2   lightmapUvOffset/uvCoords;
        Float32 2   lightmapUvScale;
        Float32 12  uvStuff;
        Float32 64  patchPoints; // 16 points, 1 point = 4 floats (x, y, z, w)
        bytes[112]  unk; // bounds, corners, properties, etc
    };
    
    // followed by unk2
    
    struct unk2{
    
        UInt32    unk;
        Float32   unk;
        bytes[4]  unk;
        Float32 3 unk;
        Float32 3 unk;
        Float32 3 unk;
        Float32 3 unk;
        Float32   unk;
        UInt32    unk;
        Float32   unk;
        bytes[4]  unk; // filler?
    };
};













struct wds{ // FILE: .WDS


    struct header{
    
        unk[4]
        Float32 unk;
        Float32 unk;
        Float32 unk; 
        Float32 unk;
        unk[4]
        UInt32  unk1_Count;
        unk[4]
    };
    
    
    
    struct unk1{
    
        Float32 3        unk;
        Float32 3        unk;
        Float32 3        unk;
        Float32          unk;
        Float32          unk;
        UInt32           unk;
        UInt32           unk;
        UInt32           unk;
        UInt16           unk;
        UInt16           unk;
        //FFFFFFFF
        bytes[16]        blank;
        Float32          unk;
        bytes[4]         unk;
        Float32/2*UInt16 unk;
        bytes[4]         unk;
        //FFFFFFFF
        Float32/bytes[4] unk;
        bytes[16]        blank;
        Float32          unk;
    };
};
