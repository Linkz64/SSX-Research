/*

adl/adl/adb - Unknown
aip         - (For race mode and others) start points, respawn points, ai path points, checkpoints.
ltg/ltg/btg - Bounding boxes (Collision/Rendering)
map         - Debug info
sop         - (For showoff mode) start points, respawn points, checkpoints.
pbd/nbd/xbd - Patches, Instances, Lights, etc
ssf/xsf/gsf - Collision Models
ssh/xsh/gsh - Textures

*/


struct aip_sop{ // FILE: .AIP and .SOP

	struct header{
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 unk2_Offset; // or unk1 size/end (relative to offset 0x10)
	
		UInt32 unk1_Count;
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 Unknown;
		
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 Unknown;
	};
	
	struct unk1_unk2{ // unk1 and unk2 are the same I think
	    Float32 unk;
	    UInt32  unkA_Count;
	    UInt32  unkB_Count;
	
	    Float32 unkPos1[3]; // main  point
	    Float32 unkPos2[3]; // extra point
	    Float32 unkPos3[3]; // extra point
	
	    unkA[
	        Float32 unkA_1[4];
	    ]
	
	    unkB[
	        UInt32  unkB_1[2];
	        Float32 unkB_2[2];
	    ]
	};
	
	struct unk2_Header{
		UInt32 Unknown;
		UInt32 Unknown;
		UInt32 Unk2Count;
		UInt32 Unknown;
	};
};




struct ltg{ // FILE: .LTG

    struct ltgFile{
        header     header;
        offsetList offsetList;
        bboxData   bboxData;
    };


    struct boundingBox{
        Float32 bounds[3]; * 2   // 2x Vector3's
        Float32 boundsOrigin[3]; // Middle point of box
    };


    struct header{
        UInt8   NULL; // or 0
        UInt8   ColdFusionVersion;
        UInt8   ColdFusionRevision;
        UInt8   endianBig; // or byteSwap | .ltg = little endian (False/0), .btg = big endian (True/1)

        Float32 worldBounds[3]; * 2 // 2x Vector3's | World bounding box (You respawn when you're outside it)
        Float32 worldBoundsOrigin[3]; // Middle point of box
        
        Float32 gridBoundsSize;    // @ 0x28    = 10000.0
        UInt32  pointerCount;      // @ 0x2C
        UInt32  pointerListCount;  // @ 0x30
        UInt32  Unknown;           // @ 0x34
        UInt32  mainBoundsCount;   // @ 0x38
        UInt32  Unknown;           // @ 0x3C
        Float32 gridBoxSize;       // @ 0x40    = 2500.0
        UInt32  Unknown;           // @ 0x44    = 4      | Row/Column count
        UInt32  gridBoxCount;      // @ 0x48    or gridResolution | = 16
        UInt32  pointerListOffset; // @ 0x4C    = 84
        UInt32  pointerListEnd;    // @ 0x50    offset of where list data ends (relative to offset 0x00) or list byte size or where box data begins
    };

    struct offsetList{ * pointerListCount
        UInt32 unkOffset; * pointerCount
    };

    struct bboxData{ // ALL OFFSETS INSIDE ARE RELATIVE TO THE START OF BBOXDATA
        struct mainBounds{
            boundingBox mainBbox; // 9 floats
            UInt16 Unknown;     // Total Patch count?
            UInt16 Unknown;     // Total Instance count?
            UInt16 Unknown;
            UInt16 Unknown;
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 Unknown; // index list offset (relative to self)
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 Unknown; // offset leads to list of "00000000 01000000"
            UInt32 Unknown;
        };
        struct gridBounds{
            boundingBox gridBbox;   // 9 floats
            UInt16 patchCount;      // Patch count
            UInt16 instanceCount;   // Instance count
            UInt16 Unknown;         // Instance/Model/Collision count?
            UInt16 splineCount;     // Spline count
            UInt16 lightCount;      // Light count
            UInt16 extraThingCount; // unused?        (usually 2 but sometimes higher, there's nothing extra to be seen in game)
            UInt16 particleCount;   // Particle count (a single UInt32?)
            UInt16 Unknown;         // unused?        (usually 0)
            UInt32 patchIndexListOffset; // offset leads to it's own index lists
            UInt32 instanceIndexListOffset;
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 extraThingOffset;   // offset leads to it's own extraThing list
            UInt32 Unknown;
        };

        struct indexList{
            bytes[?] Unknown; // contains indices for patch, instance, unk, spline, light, unk2, particle, unk3
        };

        struct extraThing{
            bytes[8] Unknown;*gridBoxCount // most have just [0, 1] (hex 00000000 01000000)
        };
    };
};
