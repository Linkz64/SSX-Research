/*

adl/adl/adb - Unknown
aip         - (For race mode and others) start points, respawn points, ai path points, checkpoints.
ltg/ltg/btg - Bounding boxes (Collision/Rendering)
map         - Debug info
sop         - (For showoff mode) start points, respawn points, checkpoints.
pbd/nbd/xbd - Patches, Instances, Lights, etc
ssf/xsf/gsf - Collision Models
ssh/xbd/gsh - Textures

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
	    Float32       unk;
	    UInt32        unkA_Count;
	    UInt32        unkB_Count;
	
	    Float32 3     unkPos1; // main  point
	    Float32 3     unkPos2; // extra point
	    Float32 3     unkPos3; // extra point
	
	    unkA[
	        Float32 4 unkA_1;
	    ]
	
	    unkB[
	        UInt32  2 unkB_1;
	        Float32 2 unkB_2;
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

	struct header{
		bytes[4] Unknown;
		Float32 worldBounds; * 2 // World bounding box (You respawn when you're outside it)
		Float32 worldBoundsOrigin; // Middle point of box
		Float32 Unknown; // 10000.0
		UInt32	offsetCount;
		UInt32	offsetListCount;
		UInt32	Unknown;
		UInt32	Unknown;
		UInt32	Unknown;
		Float32 Unknown; // 2500.0
		UInt32	Unknown;
		UInt32	Unknown;
		UInt32	offsetListOffset;
		UInt32	offsetListEnd; // offset of where it ends (relative to offset 0x00)
	};

	struct offsetList{ * offsetListCount
		UInt32 unkOffset; * offsetCount
	}
	
};
