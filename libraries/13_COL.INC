/*

THE FIVE ORDERS OF CLASSICAL ARCHITECTURE (version 1.0)

(C) Nathan G B O'Brien  1997

This INC file contains POVRAY 3 definitions for columns from the five orders of classical
architecture. This version of the five orders is based on a copper-plate lithograph by
Frenchman Claude Perrault, created in 1676. This file will create the following column objects ;

1. object {column_tuscan}
2. object {column_doric}
3. object {column_ionic}
4. object {column_corinthian}
5. object {column_composite}

The columns are created at a scale of 1 unit = 1 metre. At this scale the columns are the
following heights ;

{column_tuscan} 	= 2.2 metres high
{column_doric}		= 2.4 metres high
{column_ionic}		= 2.6 metres high
{column_corinthian}	= 2.8 metres high
{column_composite}	= 3.0 metres high

All columns are 0.3 metres in diametre.

The following options are available for the definition of the columns. Fluting can be turned on
and off with the use of the fluting switch.

#declare column_flute = on

Note that the tuscan column has no fluting at all. Fluting is turned on by default. In addition
to the standard fluting style the corinthian and composite columns have an alternate fluting
style available. The second style is more complex than the default. To use the alternate style
set the following switch to on.

#declare column_flute_alt = on

This switch is off by default.

All texture definitions are kept in a separate definition file called 13_COL.COL . Separate
texture definitions are created for each column element. To change the texture definitions for
any column simply edit the file 13_COL.COL . (Remember to keep an orginal copy some where.)

This file is FREEWARE. Please report all bugs and any suggestions to ;

Nathan O'Brien
email :  no13@ozemail.com.au
www	:	 http://www.ozemail.com.au/~no13

*/

#include "13_col.col"		// texture definition file

// Base object definitions

#declare N13_base1 =
union {
    box {<-0.225,0,-0.225><0.225,0.075,0.225> texture{T_Column8}}
    cylinder {<0,0.075,0><0,0.125,0>,0.2 texture{T_Column7}}
    torus {0.2,0.025 sturm translate<0,0.1,0> texture{T_Column7}}
    difference {
        cylinder {<0,0.125,0><0,0.175,0>,0.175 texture{T_Column7}}
        torus {0.175,0.025 sturm translate <0,0.175,0> texture{T_Column7}}
    }
}

#declare N13_base2 =
union {
    box {<-0.225,0,-0.225><0.225,0.05,0.225> texture{T_Column8}}
    cylinder {<0,0.05,0><0,0.09,0>,0.2 texture{T_Column7}}
    torus {0.2,0.015 sturm translate <0,0.065,0> texture{T_Column7}}
    difference {
        cylinder {<0,0.09,0><0,0.14,0>,0.18 texture{T_Column7}}
        torus {0.18,0.01 sturm translate <0,0.1,0> texture{T_Column7}}
    }
    torus {0.18,0.01 sturm translate <0,0.13,0> texture{T_Column7}}
    difference {
        cylinder {<0,0.14,0><0,0.17,0>,0.17 texture{T_Column7}}
        torus {0.17,0.02 sturm translate <0,0.17,0> texture{T_Column7}}
    }
}

#declare N13_capital1 =
union {
    cylinder {<0,0,0><0,0.025,0>,0.165 texture{T_Column4}}
    cylinder {<0,0.025,0><0,0.075,0>,0.15 texture{T_Column3}}
    cylinder {<0,0.075,0><0,0.1,0>,0.165 texture{T_Column4}}
    torus {0.15,0.025 sturm translate <0,0.125,0> texture{T_Column4}}
    box {<-0.19,0.125,-0.19><0.19,0.175,0.19> texture{T_Column5}}
}

#declare N13_horn =
union {
    difference {
        box {<0,0.045,0><0.175,0.075,-0.02> texture{T_Column4}}
        cylinder {<-1,0.06,-0.02><1,0.06,-0.02>,0.01 texture{T_Column3}}
    }
    difference {
        cylinder {<0.175,0,0><0.175,0,-0.02>,0.075 texture{T_Column4}}
        box {<0,-0.1,1><0.175,0.1,-1> texture{T_Column4}}
        torus {0.06,0.01 sturm rotate <90,0,0> translate <0.175,0,-0.02> texture{T_Column3}}
        torus {0.03,0.01 sturm rotate <90,0,0> translate <0.175,0,-0.02> texture{T_Column3}}
        sphere {<0.175,0,-0.02>,0.01 texture{T_Column3}}
    }
    difference {
        cylinder {<0.175,-0.015,0><0.175,-0.015,-0.02>,0.06 texture{T_Column4}}
        box {<0.175,-0.1,1><1,1,-1> texture{T_Column4}}
        torus {0.045,0.01 sturm rotate <90,0,0> translate <0.175,-0.015,-0.02> texture{T_Column3}}
        torus {0.015,0.01 sturm rotate <90,0,0> translate <0.175,-0.015,-0.02> texture{T_Column3}}
    }
}

#declare N13_capital2 =
union {
    cylinder {<0,0,0><0,0.01,0>,0.16 texture{T_Column4}}
    cylinder {<0,0.01,0><0,0.045,0>,0.15 texture{T_Column3}}
    box {<-0.175,0.075,-0.175><0.175,0.1,0.175> texture{T_Column5}}
	#declare Count = 0
	#while (Count < 24)
		sphere {<0,0.025,0.14>,0.015 rotate <0,(Count * 15),0> texture{T_Column4}}
		#declare Count = (Count + 1)
	#end
	object {N13_horn translate <0,0,-0.16>}
	object {N13_horn scale <-1,1,1> translate <0,0,-0.16>}
	object {N13_horn scale <1,1,-1> translate <0,0,0.16>}
	object {N13_horn scale <-1,1,-1> translate <0,0,0.16>}

	#declare N13_infill =
	union {
		difference {
			cylinder {<0.175,0,-0.16><0.175,0,0.16>,0.075 texture{T_Column4}}
			box {<0,-0.1,1><0.175,0.1,-1> texture{T_Column4}}
		}
		difference {
			cylinder {<0.175,-0.015,-0.16><0.175,-0.015,0.16>,0.06 texture{T_Column4}}
			box {<0.175,-0.1,1><1,1,-1> texture{T_Column4}}
		}
	}

	object {N13_infill}
	object {N13_infill scale <-1,1,1>}
}

#declare N13_leaf =
union {
    box {<-0.03,0,0><0.03,0.115,-0.01> texture{T_Column4}}
    difference {
        cylinder {<-0.03,0.115,-0.025><0.03,0.115,-0.025>0.025 texture{T_Column4}}
        cylinder {<-1,0.115,-0.025><1,0.115,-0.025>0.015 texture{T_Column4}}
        box {<1,0.115,1><-1,-1,-1> texture{T_Column4}}
    }
    intersection {
        box {<-0.03,0.085,-0.04><0.03,0.115,-0.05> texture{T_Column4}}
        cylinder {<0,0.115,1><0,0.115,-1>,0.03 texture{T_Column4}}
    }
}

#declare N13_capital3 =
union {
    cylinder {<0,0,0><0,0.015,0>,0.165 texture{T_Column4}}
    cylinder {<0,0.015,0><0,0.15,0>,0.15 texture{T_Column3}}
    cone {<0,0.15,0>,0.15,<0,0.35,0>,0.2 texture{T_Column3}}
	#declare Count = 0
	#while (Count < 10)
		object {N13_leaf rotate <-5,0,0> translate <0,0,-0.15> rotate <0,(Count * 36),0>}
		#declare Count = (Count + 1)
	#end
	#declare Count = 0
	#while (Count < 10)
		object {N13_leaf rotate <-15,0,0> translate <0,0.1,-0.15> rotate <0,((Count * 36) + 18),0>}
		#declare Count = (Count + 1)
	#end
	#declare Count = 0
	#while (Count < 10)
		object {N13_leaf rotate <-20,0,0> translate <0,0.22,-0.175> rotate <0,(Count * 36),0>}
		#declare Count = (Count + 1)
	#end

	#declare N13_cut1 =
	union {
    	box {<-0.15,-1,-0.15><0.15,0.36,0.15> texture{T_Column5}}
    	box {<-0.14,0.36,-0.14><0.14,0.375,0.14> texture{T_Column5}}
    	box {<-0.13,0,-0.13><0.13,0.5,0.13> texture{T_Column5}}
	}

	#declare N13_cut2 =
	union {
    	object {N13_cut1 rotate <0,45,0> translate <0.318,0,0.318> texture{T_Column5}}
    	cylinder {<0,-1,0.528><0,0.36,0.528>,0.319 texture{T_Column5}}
    	cylinder {<0,0.36,0.528><0,0.375,0.528>,0.309 texture{T_Column5}}
    	cylinder {<0,-1,0.528><0,0.5,0.528>,0.299 texture{T_Column5}}
	}

	difference {
        box {<-0.275,0.35,-0.275><0.275,0.4,0.275> texture{T_Column5}}
    	object {N13_cut2}
    	object {N13_cut2 rotate <0,90,0>}
    	object {N13_cut2 rotate <0,180,0>}
    	object {N13_cut2 rotate <0,-90,0>}
	}

	#declare N13_flower =
	union {
		sphere {<0,0,0>,.02 texture{T_Column6}}
		sphere {<0.015,0,0>,.015 texture{T_Column6}}
		sphere {<0.03,0,0>,.015 texture{T_Column6}}
		sphere {<-0.015,0,0>,.015 texture{T_Column6}}
		sphere {<-0.03,0,0>,.015 texture{T_Column6}}
	}

	object {N13_flower translate <0,0.385,-.22>}
	object {N13_flower translate <0,0.385,-.22> rotate <0,90,0>}
	object {N13_flower translate <0,0.385,-.22> rotate <0,180,0>}
	object {N13_flower translate <0,0.385,-.22> rotate <0,-90,0>}

}

#declare N13_capital4 =
union {
	object {N13_capital3}

	#declare N13_add1 =
	union {
		object {N13_horn}
		object {N13_horn scale <1,1,-1>}
	}

	object {N13_add1 translate <.08,0.28,0> rotate <0,45,0>}
	object {N13_add1 translate <.08,0.28,0> rotate <0,135,0>}
	object {N13_add1 translate <.08,0.28,0> rotate <0,-45,0>}
	object {N13_add1 translate <.08,0.28,0> rotate <0,-135,0>}

	torus {.18,.02 sturm translate <0,.3,0> texture{T_Column4}}
}

// Check fluting switches

#ifndef (column_flute)
	#declare column_flute = on
#end

#ifndef (column_flute_alt)
	#declare column_flute_alt = off
#end

// Defining columns

#declare column_tuscan =
union {
	object {N13_base1}
	cylinder {<0,0.175,0><0,2.025,0>,0.15 texture{T_Column1}}
	object {N13_capital1 translate <0,2.025,0>}
}

#declare column_doric =
union {
	object {N13_base2}
	object {N13_capital1 translate <0,2.225,0>}

	#if (column_flute = on)
		#declare N13_flute1 =
		union {
			cylinder {<0.15,0.2,0><0.15,2.15,0>,0.025 texture{T_Column2}}
			sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
			sphere {<0.15,2.15,0>,0.025 texture{T_Column2}}
		}
		difference {
			cylinder {<0,0.17,0><0,2.225,0>,0.15 texture{T_Column1}}
			#declare Count = 0
			#while (Count < 18)
				object {N13_flute1 rotate <0,(Count * (360 / 18)),0>}
				#declare Count = (Count + 1)
			#end
		}
	#else
		cylinder {<0,0.17,0><0,2.225,0>,0.15 texture{T_Column1}}
	#end
}


#declare column_ionic =
union {
	object {N13_base2}
	object {N13_capital2 translate <0,2.5,0>}

	#if (column_flute = on)
		#declare N13_flute2 =
		union {
			cylinder {<0.15,0.2,0><0.15,2.45,0>,0.025 texture{T_Column2}}
			sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
			sphere {<0.15,2.45,0>,0.025 texture{T_Column2}}
		}
		difference {
			cylinder {<0,0.17,0><0,2.5,0>,0.15 texture{T_Column1}}
			#declare Count = 0
			#while (Count < 14)
				object {N13_flute2 rotate <0,(Count * (360 / 14)),0>}
				#declare Count = (Count + 1)
			#end
		}
	#else
		cylinder {<0,0.17,0><0,2.5,0>,0.15 texture{T_Column1}}
	#end
}

#declare column_corinthian =
union {
	object {N13_base2}
	object {N13_capital3 translate <0,2.4,0>}

	#if (column_flute = on)
		#if (column_flute_alt = off)
			#declare N13_flute3 =
			union {
				cylinder {<0.15,0.2,0><0.15,2.32,0>,0.025 texture{T_Column2}}
				sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
				sphere {<0.15,2.32,0>,0.025 texture{T_Column2}}
			}
			difference {
				cylinder {<0,0.17,0><0,2.4,0>,0.15 texture{T_Column1}}
				#declare Count = 0
				#while (Count < 14)
					object {N13_flute3 rotate <0,(Count * (360 / 14)),0>}
					#declare Count = (Count + 1)
				#end
			}
		#else
			#declare N13_flute3 =
			union {
				cylinder {<0.15,0.2,0><0.15,1,0>,0.025 texture{T_Column2}}
				sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
				sphere {<0.15,1,0>,0.025 texture{T_Column2}}
			}
			#declare N13_flute4 =
			union {
				cylinder {<0.15,1.07,0><0.15,2.32,0>,0.025 texture{T_Column2}}
				sphere {<0.15,1.07,0>,0.025 texture{T_Column2}}
				sphere {<0.15,2.32,0>,0.025 texture{T_Column2}}
			}
			#declare N13_flute5 =
			union {
				cylinder {<0.13,0.2,0><0.13,1,0>,0.02 texture{T_Column2}}
				sphere {<0.13,0.2,0>,0.02 texture{T_Column2}}
				sphere {<0.13,1,0>,0.02 texture{T_Column2}}
			}
			difference {
				cylinder {<0,0.17,0><0,2.4,0>,0.15 texture{T_Column1}}
				#declare Count = 0
				#while (Count < 18)
					object {N13_flute3 rotate <0,(Count * (360 / 18)),0>}
					#declare Count = (Count + 1)
				#end
				#declare Count = 0
				#while (Count < 14)
					object {N13_flute4 rotate <0,(Count * (360 / 14)),0>}
					#declare Count = (Count + 1)
				#end
			}
			#declare Count = 0
			#while (Count < 18)
				object {N13_flute5 rotate <0,(Count * (360 / 18)),0>}
				#declare Count = (Count + 1)
			#end
		#end
	#else
		cylinder {<0,0.17,0><0,2.4,0>,0.15 texture{T_Column1}}
	#end
}


#declare column_composite =
union {
	object {N13_base2}
	object {N13_capital4 translate <0,2.6,0>}

	#if (column_flute = on)
		#if (column_flute_alt = off)
			#declare N13_flute3 =
			union {
				cylinder {<0.15,0.2,0><0.15,2.52,0>,0.025 texture{T_Column2}}
				sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
				sphere {<0.15,2.52,0>,0.025 texture{T_Column2}}
			}
			difference {
				cylinder {<0,0.17,0><0,2.6,0>,0.15 texture{T_Column1}}
				#declare Count = 0
				#while (Count < 14)
					object {N13_flute3 rotate <0,(Count * (360 / 14)),0>}
					#declare Count = (Count + 1)
				#end
			}
		#else
			#declare N13_flute3 =
			union {
				cylinder {<0.15,0.2,0><0.15,1,0>,0.025 texture{T_Column2}}
				sphere {<0.15,0.2,0>,0.025 texture{T_Column2}}
				sphere {<0.15,1,0>,0.025 texture{T_Column2}}
			}
			#declare N13_flute4 =
			union {
				cylinder {<0.15,1.07,0><0.15,2.52,0>,0.025 texture{T_Column2}}
				sphere {<0.15,1.07,0>,0.025 texture{T_Column2}}
				sphere {<0.15,2.52,0>,0.025 texture{T_Column2}}
			}
			#declare N13_flute5 =
			union {
				cylinder {<0.13,0.2,0><0.13,1,0>,0.02 texture{T_Column2}}
				sphere {<0.13,0.2,0>,0.02 texture{T_Column2}}
				sphere {<0.13,1,0>,0.02 texture{T_Column2}}
			}
			difference {
				cylinder {<0,0.17,0><0,2.6,0>,0.15 texture{T_Column1}}
				#declare Count = 0
				#while (Count < 18)
					object {N13_flute3 rotate <0,(Count * (360 / 18)),0>}
					#declare Count = (Count + 1)
				#end
				#declare Count = 0
				#while (Count < 14)
					object {N13_flute4 rotate <0,(Count * (360 / 14)),0>}
					#declare Count = (Count + 1)
				#end
			}
			#declare Count = 0
			#while (Count < 18)
				object {N13_flute5 rotate <0,(Count * (360 / 18)),0>}
				#declare Count = (Count + 1)
			#end
		#end
	#else
		cylinder {<0,0.17,0><0,2.6,0>,0.15 texture{T_Column1}}
	#end
}

