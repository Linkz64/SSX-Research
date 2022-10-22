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
        bboxData   bboxData; * pointerCount
    };


    struct boundingBox{
        Float32 bounds[3]; * 2   // 2x Vector3's
        Float32 boundsOrigin[3]; // Middle point of box
    };


    struct header{
        UInt8   NULL; // or 0
        UInt8   ColdFusionVersion;
        UInt8   ColdFusionRevision;
        UInt8   endianess; // endianBig or byteOrder or byteSwap | .ltg = little endian (False/0), .btg = big endian (True/1)

        boundingBox worldBounds // 2x Vector3's | World bounding box (Also acts as out of bounds box; makes you respawn when you're outside of it)
        
        Float32 mainBboxSize;        // @ 0x28    = 10000.0
        UInt32  pointerCount;        // @ 0x2C    number of mainBbox placed along X axis (horizontally)
        UInt32  pointerListCount;    // @ 0x30    number of mainBbox placed along Y axis
        UInt32  totalGridCount;      // @ 0x34    pointerCount * pointerListCount
        UInt32  mainBboxCount;       // @ 0x38    number of grids/mainBbox used
        UInt32  mainBboxEmptyCount;  // @ 0x3C    number of empty grids where none were spawned/processed

        Float32 nodeBoxSize;         // @ 0x40    = 2500.0
        UInt32  nodeBoxWidth;        // @ 0x44    = 4       row or column count
        UInt32  nodeBoxCount;        // @ 0x48    = 16

        UInt32  pointerListOffset;   // @ 0x4C    = 84
        UInt32  bboxDataListOffset;  // @ 0x50    offset of where box data begins
    };

    struct offsetList{ * pointerListCount
        UInt32 unkOffset; * pointerCount
    };

    struct bboxData{ // All offsets inside are relative to start of individual bboxData
        struct mainBbox{
            boundingBox mainBbox;      // 3 Vector3's (9 floats)
            
            UInt16 totalPatchCount;            // Total Patch count
            UInt16 totalInstanceCount;         // Total Instance count
            UInt16 unknown;
            UInt16 totalLightCount;            // Total Light count
            UInt16 totallightsCrossingCount;   // Total Lights crossing count. Whatever that means
            UInt16 totalParticleInstanceCount;
            UInt32 Unknown; // number of elements?
            UInt32 Unknown; // offset to first nodeBbox? or mainBbox byte size
            UInt32 Unknown; // index list offset
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 Unknown;
            UInt32 Unknown; // offset leads to list of extraThing lists
            UInt32 Unknown;
        };
        struct nodeBbox{
            boundingBox nodeBbox;       // 3 Vector3's (9 floats)

            UInt16 patchCount;          // Patch count
            UInt16 instanceCount;       // Instance count
            UInt16 instAndGemCount;     // Models/Instances & Gems apparently
            UInt16 splineCount;         // Spline count
            UInt16 lightCount;          // Light count
            UInt16 lightsCrossingCount; // Lights crossing count
            UInt32 particleCount;       // Particle model count

            UInt32 patchesOffset;        // offset leads to it's own index list
            UInt32 instancesOffset;      // or models
            UInt32 splinesOffset;
            UInt32 lightsOffset;
            UInt32 lightsCrossingOffset; // offset of it's own extraThing list, usually hex 00000000 01000000
            UInt32 particleModelsOffset;
        };

        struct indexList{
            UInt32 Index;*_whatever object type_ Count // contains indices for patch, instance, unk, spline, light, unk2, particle, unk3
        };
    };
};
