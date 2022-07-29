# SSX 3 File Structure

- Contents:
    - [PS2](#PS2)

# PS2
Note: Currently based on the pal version
## Root
| Name        	| Type            	| Description 	|
|-------------	|-----------------	|-------------	|
| CNF         	| Folder          	|             	|
| [Data](#Data)     	| Folder          	|             	|
| NETGUI      	| Folder          	|             	|
| SLES_516.97 	| Boot File       	|             	|
| SYSTEM.CNF  	| PS2 Config File 	|             	|

## Data/
| Name     	| Type   	| Description 	|
|----------	|--------	|-------------	|
| [AUDIO](#DataAudio)    	| Folder 	|             	|
| [BE](#DataBe)       	| Folder 	|             	|
| [CHAR](#DataChar)     	| Folder 	|             	|
| [CONFIG](#DataConfig)   	| Folder 	|             	|
| [FONTS](#DataFonts)    	| Folder 	|             	|
| [ICON](#DataIcon)     	| Folder 	|             	|
| [LOCALE](#DataLocale)   	| Folder 	|             	|
| [MISSIONS](#DataMissions) 	| Folder 	|             	|
| [MODULES](#DataModules)  	| Folder 	|             	|
| [MOVIES](#DataMovies)   	| Folder 	|             	|
| [SCRIPTS](#DataScripts)  	| Folder 	|             	|
| [TEXTURES](#DataTextures) 	| Folder 	|             	|
| [UI](#DataUI)       	| Folder 	|             	|
| [WORLDS](#DataWorlds)   	| Folder 	|             	|

## Data/Audio

| Name         	| Type        	| Version 	| Description 	|
|--------------	|-------------	|---------	|-------------	|
| AUDIO.BIG    	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| ENGLISH.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| FRENCH.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| GERMAN.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| GRNT_AI.BNK  	| BNK         	|         	|             	|
| GRNT_ARI.BNK 	| BNK         	|         	|             	|
| GRNT_ARI.BNK 	| BNK         	|         	|             	|
| GRNT_GRF.BNK 	| BNK         	|         	|             	|
| GRNT_KAO.BNK 	| BNK         	|         	|             	|
| GRNT_MAC.BNK 	| BNK         	|         	|             	|
| GRNT_MOB.BNK 	| BNK         	|         	|             	|
| GRNT_NAT.BNK 	| BNK         	|         	|             	|
| GRNT_PSY.BNK 	| BNK         	|         	|             	|
| GRNT_VIG.BNK 	| BNK         	|         	|             	|
| GRNT_ZOE.BNK 	| BNK         	|         	|             	|
| MUSIC.BIG    	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| MUSIC2.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| SPANISH.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| SPEECH.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|

## Data/Be
| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| BEHILOC.DBL  	| DBL  	|         	|             	|
| CHARDB.DBL   	| DBL  	|         	|             	|
| GLOBAL.DBL   	| DBL  	|         	|             	|
| MODECHAL.DBL 	| DBL  	|         	|             	|
| RWRDPS2.DAT  	| DAT  	|         	|             	|
| STATDB.DBL   	| DBL  	|         	|             	|

## Data/Char
| Name         	| Type                                                                                                 	| Version 	| Description 	|
|--------------	|------------------------------------------------------------------------------------------------------	|---------	|-------------	|
| ALLEGTXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| ANM.BIG      	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| BOLTPS2.DAT  	| DAT                                                                                                  	|         	|             	|
| ELISETXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| GRIFFTXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| KAORITXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| MACTXP.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| MDLPS2.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| MOBYTXP.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| NATETXP.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| OTHERTXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| PSYMOTXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| RWRDPS2.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| VIGGOTXP.BIG 	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| ZOETXP.BIG   	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|

## Data/Config 
| Name         	| Type        	| Version 	| Description 	|
|--------------	|-------------	|---------	|-------------	|
| BANKS.INF    	| INF         	|         	|             	|
| CROWD.INF    	| INF         	|         	|             	|
| INPUT.MAP    	| MAP         	|         	|             	|
| INPUT2.MAP   	| MAP         	|         	|             	|
| MIX.INF      	| INF         	|         	|             	|
| MUSIC.INF    	| INF         	|         	|             	|
| PLAYLIST.INF 	| INF         	|         	|             	|
| SLESOVF.BIG  	| [BIG Archive](https://github.com/Linkz64/SSX-Research/blob/main/Drafts/File%20Types/BIG-Archives.md) 	|         	|             	|
| SNOW.INF     	| INF         	|         	|             	|
| SPEECH.INF   	| INF         	|         	|             	|
| WATRIG.ADB   	| ADB         	|         	|             	|
| WATRIG.ADL   	| ADL         	|         	|             	|

## Data/Fonts

| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| DEBUGFNT.SFN 	| SFN  	|         	|             	|
| FEFONT.SFN   	| SFN  	|         	|             	|
| FLOAD.SSH    	| SSH  	|         	|             	|
| FONT.SFN     	| SFN  	|         	|             	|
| GLOAD.SSH    	| SSH  	|         	|             	|
| HUDFONT.SFN  	| SFN  	|         	|             	|
| MENU.SSH     	| SSH  	|         	|             	|
| SPLASH.SSH   	| SSH  	|         	|             	|

## Data/Icon
| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| SSX1.ICO  	| ICO  	|         	|             	|

## Data/Locale
| Name        	| Type 	| Version 	| Description 	|
|-------------	|------	|---------	|-------------	|
| CMNAMER.LOC 	| LOC  	|         	|             	|
| CMNFREN.LOC 	| LOC  	|         	|             	|
| CMNGRMN.LOC 	| LOC  	|         	|             	|
| CMNSPAN.LOC 	| LOC  	|         	|             	|
| CRAMER.LOC  	| LOC  	|         	|             	|
| CRFREN.LOC  	| LOC  	|         	|             	|
| CRGRMN.LOC  	| LOC  	|         	|             	|
| CRGRMN.LOC  	| LOC  	|         	|             	|
| FEAMER.LOC  	| LOC  	|         	|             	|
| FEFREN.LOC  	| LOC  	|         	|             	|
| FEGRMN.LOC  	| LOC  	|         	|             	|
| FESPAN.LOC  	| LOC  	|         	|             	|
| OVAMER.LOC  	| LOC  	|         	|             	|
| OVFREN.LOC  	| LOC  	|         	|             	|
| OVGRMN.LOC  	| LOC  	|         	|             	|
| OVSPAN.LOC  	| LOC  	|         	|             	|
| TOSFREN.LOC 	| LOC  	|         	|             	|
| TOSGRMN.LOC 	| LOC  	|         	|             	|
| TOSSPAN.LOC 	| LOC  	|         	|             	|

## Data/Missions
| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| PLAYBACK.BIG  | BIG Archive  	|         	|             	|

## Data/Modules

## Data/Movie
| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| ABC1.MPC     	| MPC  	|         	|             	|
| ABC1WS.MPC   	| MPC  	|         	|             	|
| DBC2.MPC     	| MPC  	|         	|             	|
| DBC2WS.MPC   	| MPC  	|         	|             	|
| EABIG.MPC    	| MPC  	|         	|             	|
| EBC3.MPC     	| MPC  	|         	|             	|
| EBC3WS.MPC   	| MPC  	|         	|             	|
| INTRO.MPC    	| MPC  	|         	|             	|
| INTRO_DJ.MPC 	| MPC  	|         	|             	|
| MTNALIVE.MPC 	| MPC  	|         	|             	|
| NFLXSELL.MPC 	| MPC  	|         	|             	|
| NFSXSELL.MPC 	| MPC  	|         	|             	|
| ST3XSELL.MPC 	| MPC  	|         	|             	|
| THX.MPC      	| MPC  	|         	|             	|

## Data/Scripts
| Name         	| Type        	| Version 	| Description 	|
|--------------	|-------------	|---------	|-------------	|
| ANIMDBG.BIG  	| BIG Archive 	|         	|             	|
| SCDAT.BIG    	| BIG Archive 	|         	|             	|
| SOUNDDBG.BIG 	| BIG Archive 	|         	|             	|

## Data/Textures
| Name         	| Type 	| Version 	| Description 	|
|--------------	|------	|---------	|-------------	|
| BACKS.SSH    	| SSH  	|         	|             	|
| DBGIRAD.SSH  	| SSH  	|         	|             	|
| CRWD.SSH     	| SSH  	|         	|             	|
| DOT.SSH      	| SSH  	|         	|             	|
| EFFECTS.SSH  	| SSH  	|         	|             	|
| FE_1.SSH     	| SSH  	|         	|             	|
| PARTICLE.SSH 	| SSH  	|         	|             	|

## Data/UI
| Name         	| Type        	| Version 	| Description 	|
|--------------	|-------------	|---------	|-------------	|
| CHARPIC.BIG  	| BIG Archive 	|         	|             	|
| COURSPIC.BIG 	| BIG Archive 	|         	|             	|
| FE.LUI       	| LUI         	|         	|             	|
| FE_1.SSH     	| SSH         	|         	|             	|
| FL.LUI       	| LUI         	|         	|             	|
| FL_1.SSH     	| SSH         	|         	|             	|
| GL.LUI       	| LUI         	|         	|             	|
| GL_1.SSH     	| SSH         	|         	|             	|
| MAPGFX.BIG   	| BIG Archive 	|         	|             	|
| OV.LUI       	| LUI         	|         	|             	|
| OV_1.SSH     	| SSH         	|         	|             	|
| SU.LUI       	| LUI         	|         	|             	|
| SU_1.SSH     	| SSH         	|         	|             	|

## Data/Worlds
| Name    	| Type        	| Version 	| Description 	|
|---------	|-------------	|---------	|-------------	|
| BAM.BIG 	| BIG Archive 	|         	|             	|
| IRR.DAT 	| DAT         	|         	|             	|
