# PBD Track File

# Overview

# Structure

## Patch 


| Offset 	| Type    	| Description    	|
|--------	|---------	|----------------	|
|        	| Vertex4 	| Shading Point  	|
|        	| Vertex4 	| UV Point 1     	|
|        	| Vertex4 	| UV Point 2     	|
|        	| Vertex4 	| UV Point 3     	|
|        	| Vertex4 	| UV Point 4     	|
|        	| Vertex4 	| Row 4 Colum 4  	|
|        	| Vertex4 	| Row 4 Colum 3  	|
|        	| Vertex4 	| Row 4 Colum 2  	|
|        	| Vertex4 	| Row 4 Colum 1  	|
|        	| Vertex4 	| Row 3 Colum 4  	|
|        	| Vertex4 	| Row 3 Colum 3  	|
|        	| Vertex4 	| Row 3 Colum 2  	|
|        	| Vertex4 	| Row 3 Colum 1  	|
|        	| Vertex4 	| Row 2 Colum 4  	|
|        	| Vertex4 	| Row 2 Colum 3  	|
|        	| Vertex4 	| Row 2 Colum 2  	|
|        	| Vertex4 	| Row 2 Colum 1  	|
|        	| Vertex4 	| Row 1 Colum 4  	|
|        	| Vertex4 	| Row 1 Colum 3  	|
|        	| Vertex4 	| Row 1 Colum 2  	|
|        	| Vertex4 	| Row 1 Colum 1  	|
|        	| Vertex3 	| Lowest XYZ     	|
|        	| Vertex3 	| Highest XYZ    	|
|        	| Vertex4 	| Corner Point 1 	|
|        	| Vertex4 	| Corner Point 2 	|
|        	| Vertex4 	| Corner Point 3 	|
|        	| Vertex4 	| Corner Point 4 	|
|        	| Int32   	| Patch Style    	|
|        	| Int32   	| Unknown        	|
|        	| Int16   	| Texture ID     	|
|        	| Int16   	| Unknown        	|
|        	| Int32   	| Unknown        	|
|        	| Int32   	| Unknown        	|
|        	| Int32   	| Unknown        	|

### Equations

__Speical Thanks For Solving the Equations__ <br>
-Archy/GlitcherOG and his Garbage Program <br>
-Linkz <br>
-Kris <br>

| Input                     	| Equations            	|
|---------------------------	|----------------------	|
| EQ1 (A,B) = Raw B         	| A + B/3              	|
| EQ2 (RawA,B,C) = Raw C    	| RawA+(B+C)/3         	|
| EQ3 (A, B, C, D) = Raw D  	| A+(B+C+D/3)/3        	|
| EQ4 (A,B,C,D) = Raw D     	| A+B+C+D              	|
| EQ5 (RawA,A,B,C,D)= Raw D 	| RawA+(A+B+(C+D)/3)/3 	|
| EQ6 (RawA,B,C,D,E)= Raw E 	| RawA+(B+C+D+E)/3     	|

### Encoding
| Row\Column 	| Column 1                    	| Column 2                    	| Column 3                  	| Column 4                    	|
|------------	|-----------------------------	|-----------------------------	|---------------------------	|-----------------------------	|
| Row 1      	| No Equation Needed          	| EQ1(R1C1,R1C2)              	| EQ2(Raw R1C2, R1C2, R1C3) 	| EQ4(R1C1, R1C2, R1C3, R1C4) 	|
| Row 2      	| EQ1(R1C1,R2C1)              	| EQ3(R1C1, R2C1, R1C2, R2C2) 	|                           	|                             	|
| Row 3      	| EQ2(Raw R2C1, R2C1, R3C1)   	|                             	|                           	|                             	|
| Row 4      	| EQ4(R1C1, R2C1, R3C1, R4C1) 	|                             	|                           	|                             	|