// ***************************************************************************
// Objects provided by this file are:
//	KEYBOARD
//	SMALL_KEYBOARD
//	key, key0, ..., key8
//
// Textures provided by this file are:
//	computerwhite_plastic
//	computergray_plastic
//	brightgreen_LED
//	dark_LED
// ***************************************************************************
// Scale: 1 millimeter per POV unit.
// ***************************************************************************
// *               Manfred.Agne@munich.netsurf.de  (1998)                    *
// *                     Feel free to use this file.                         *
// ***************************************************************************


#declare computerwhite_plastic = texture {
  pigment {color rgb <0.9647,0.9098,0.7529>} 
  normal  { bumps 0.5 scale 0.1 }
  finish  { phong 0.1 }
}
#declare computergray_plastic = texture {
  pigment {color rgb <0.7773,0.7517,0.5664>} 
  normal  { bumps 0.5 scale 0.1 }
  finish  { phong 0.1 }
}
#declare brightgreen_LED = texture{
  pigment {color rgb<0,1,0>} 
  finish  {ambient 0.8}
}
#declare dark_LED = texture {
  pigment { color rgbf<0.5, 0.6, 0.5, 1.0> }
  finish {
    ambient 0
    diffuse 0.1
    reflection 0.1
    refraction 1
    ior 1.5
    phong 0.1
    phong_size 20
  }
}
//############################################################################
// Any standard size key. I'm not really happy with the shape, but I couldn't
// find a better one. Suggestions are welcome!
//----------------------------------------------------------------------------
#declare keyx=19;
#declare keyz=19;
#declare key = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-19>}
  texture{computerwhite_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-19>}}
}
//############################################################################
// Standard size key, but with different color.
//----------------------------------------------------------------------------
#declare key0 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-19>}
  texture{computergray_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-19>}}
}
//############################################################################
// slightly bigger key for CTRL, ALT, etc.
//----------------------------------------------------------------------------
#declare key1z=23;
#declare key1 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-22>}
  texture{computergray_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-key1z>}}
}
//############################################################################
// right SHIFT key.
//----------------------------------------------------------------------------
#declare key2z=53;
#declare key2 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-52>}
  texture{computergray_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-53>}}
}
//############################################################################
// SPACE bar.
//----------------------------------------------------------------------------
#declare key3z=193;
#declare key3 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,   0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,   0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-192>}
  texture{computerwhite_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-key3z>}}
}
//############################################################################
// CAPS LOCK key.
//----------------------------------------------------------------------------
#declare key4z=32;
#declare key4 = union{
  intersection{
    plane{< 0, 1, 0>, 10}
    plane{< 0,-1, 0>,  0}
    plane{< 1, 0, 0>,  0}
    plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
    plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
    plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-22>}
  }
  intersection{
    plane{< 0, 1, 0>,  5}
    plane{< 0,-1, 0>,  0}
    plane{< 1, 0, 0>,  0}
    plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
    plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
    plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-31>}
  }
  texture{computergray_plastic}
  bounded_by{box{<keyx,0,0>,<-keyx,10,-32>}}
}
//############################################################################
// TAB key.
//----------------------------------------------------------------------------
#declare key5z=28;
#declare key5 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-27>}
  texture{computergray_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-key5z>}}
}
//############################################################################
// BACKSPACE and NUMPAD-INS
//----------------------------------------------------------------------------
#declare key6z=38;
#declare key6 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>,  0}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-37>}
  texture{computergray_plastic}
  bounded_by{box{<0,0,0>,<-keyx,10,-key6z>}}
}
//############################################################################
// RETURN key.
//----------------------------------------------------------------------------
#declare key7 = union{
  intersection{
    plane{< 0, 1, 0>,10}
    plane{< 0,-1, 0>, 0}
    plane{< 1, 0, 0>, keyx}
    plane{<-1, 0, 0>, 0 rotate<  0,0,-30> translate<(-18+keyx),0,  0>}
    plane{< 0, 0, 1>, 0 rotate<-15,0,  0> translate<  0,0,  6>}
    plane{< 0, 0,-1>, 0 rotate< 15,0,  0> translate<  0,0,-23>}
  }
  intersection{
    plane{< 0, 1, 0>,10}
    plane{< 0,-1, 0>, 0}
    plane{< 1, 0, 0>, keyx}
    plane{<-1, 0, 0>, 0 rotate<  0,0,-30> translate<-18,0,  0>}
    plane{< 0, 0, 1>, 0 rotate<-15,0,  0> translate<  0,0,  0>}
    plane{< 0, 0,-1>, 0 rotate< 15,0,  0> translate<  0,0,-23>}
  }
  texture{computergray_plastic}
}
//############################################################################
// NUMPAD-ENTER and NUMPAD-PLUS
//----------------------------------------------------------------------------
#declare key8 = intersection{
  plane{< 0, 1, 0>, 10}
  plane{< 0,-1, 0>,  0}
  plane{< 1, 0, 0>, 18}
  plane{<-1, 0, 0>,  0 rotate<  0,0,-30> translate<-18,0,  0>}
  plane{< 0, 0, 1>,  0 rotate<-15,0,  0> translate<  0,0,  0>}
  plane{< 0, 0,-1>,  0 rotate< 15,0,  0> translate<  0,0,-19>}
  texture{computergray_plastic}
}
//############################################################################
#declare kbd =
union {
  object{key1 translate<  0,10,   0>}		// left CTRL
  object{key1 translate<  0,10, -23>}		// ALT
  object{key3 translate<  0,10, -46>}		// SPACE
  object{key1 translate<  0,10,-239>}		// ALT GR
  object{key1 translate<  0,10,-262>}		// right CTRL
  object{key1 translate< 19,10,   0>}		// left SHIFT
  object{key  translate< 19,10, -23>}		// <>
  object{key  translate< 19,10, -42>}		// Y
  object{key  translate< 19,10, -61>}		// X
  object{key  translate< 19,10, -80>}		// C
  object{key  translate< 19,10, -99>}		// V
  object{key  translate< 19,10,-118>}		// B
  object{key  translate< 19,10,-137>}		// N
  object{key  translate< 19,10,-156>}		// M
  object{key  translate< 19,10,-175>}		// ;,
  object{key  translate< 19,10,-194>}		// :.
  object{key  translate< 19,10,-213>}		// _-
  object{key2 translate< 19,10,-232>}		// right SHIFT
  object{key4 translate< 38,10,   0>}		// CAPS LOCK
  object{key  translate< 38,10, -32>}		// A
  object{key  translate< 38,10, -51>}		// S
  object{key  translate< 38,10, -70>}		// D
  object{key  translate< 38,10, -89>}		// F
  object{key  translate< 38,10,-108>}		// G
  object{key  translate< 38,10,-127>}		// H
  object{key  translate< 38,10,-146>}		// J
  object{key  translate< 38,10,-165>}		// K
  object{key  translate< 38,10,-184>}		// L
  object{key  translate< 38,10,-203>}		// ™
  object{key  translate< 38,10,-222>}		// Ž
  object{key  translate< 38,10,-241>}		// '#
  object{key7 translate< 38,10,-260>}		// RETURN
  object{key5 translate< 57,10,   0>}		// TAB
  object{key  translate< 57,10, -28>}		// Q
  object{key  translate< 57,10, -47>}		// W
  object{key  translate< 57,10, -66>}		// E
  object{key  translate< 57,10, -85>}		// R
  object{key  translate< 57,10,-104>}		// T
  object{key  translate< 57,10,-123>}		// Z
  object{key  translate< 57,10,-142>}		// U
  object{key  translate< 57,10,-161>}		// I
  object{key  translate< 57,10,-180>}		// O
  object{key  translate< 57,10,-199>}		// P
  object{key  translate< 57,10,-218>}		// š
  object{key  translate< 57,10,-237>}		// *
  object{key  translate< 76,10,   0>} 		// ø^
  object{key  translate< 76,10, -19>} 		// 1
  object{key  translate< 76,10, -38>} 		// 2
  object{key  translate< 76,10, -57>} 		// 3
  object{key  translate< 76,10, -76>} 		// 4
  object{key  translate< 76,10, -95>} 		// 5
  object{key  translate< 76,10,-114>} 		// 6
  object{key  translate< 76,10,-133>} 		// 7
  object{key  translate< 76,10,-152>} 		// 8
  object{key  translate< 76,10,-171>} 		// 9
  object{key  translate< 76,10,-190>} 		// 0
  object{key  translate< 76,10,-209>} 		// á?\
  object{key  translate< 76,10,-228>} 		// `ï
  object{key6 translate< 76,10,-247>} 		// BACKSPACE
  object{key0 translate<114,10,   0>} 		// ESC
  object{key  translate<114,10, -38>} 		// F1
  object{key  translate<114,10, -57>} 		// F2
  object{key  translate<114,10, -76>} 		// F3
  object{key  translate<114,10, -95>} 		// F4
  object{key0 translate<114,10,-124>} 		// F5
  object{key0 translate<114,10,-143>} 		// F6
  object{key0 translate<114,10,-162>} 		// F7
  object{key0 translate<114,10,-181>} 		// F8
  object{key  translate<114,10,-209>} 		// F9
  object{key  translate<114,10,-228>} 		// F10
  object{key  translate<114,10,-247>} 		// F11
  object{key  translate<114,10,-266>} 		// F12
  object{key0 translate<  0,10,-295>}		// CUR LEFT
  object{key0 translate<  0,10,-314>}		// CUR DOWN
  object{key0 translate<  0,10,-333>}		// CUR RIGHT
  object{key0 translate< 19,10,-314>}		// CUR UP
  object{key0 translate< 57,10,-295>}		// DEL
  object{key0 translate< 57,10,-314>}		// HOME
  object{key0 translate< 57,10,-333>}		// PG DOWN
  object{key0 translate< 76,10,-295>}		// INS
  object{key0 translate< 76,10,-314>}		// POS1
  object{key0 translate< 76,10,-333>}		// PG UP
  object{key0 translate<114,10,-295>}		// PRINT
  object{key0 translate<114,10,-314>}		// SCROLL LOCK
  object{key0 translate<114,10,-333>}		// PAUSE
  object{key6 translate<  0,10,-361>}		// 0/INS
  object{key  translate<  0,10,-399>}		// ,/DEL
  object{key8 translate<  0,10,-418>}		// ENTER
  object{key  translate< 19,10,-361>}		// 1
  object{key  translate< 19,10,-380>}		// 2
  object{key  translate< 19,10,-399>}		// 3
  object{key  translate< 38,10,-361>}		// 4
  object{key  translate< 38,10,-380>}		// 5
  object{key  translate< 38,10,-399>}		// 6
  object{key8 translate< 38,10,-418>}		// PLUS
  object{key  translate< 57,10,-361>}		// 7
  object{key  translate< 57,10,-380>}		// 8
  object{key  translate< 57,10,-399>}		// 9
  object{key0 translate< 76,10,-361>}		// NUM LOCK
  object{key0 translate< 76,10,-380>}		// DIV
  object{key0 translate< 76,10,-399>}		// MULT
  object{key0 translate< 76,10,-418>}		// MINUS
  union{
    box{<-29,0,  15>,<129, 9,-452>}
    box{<-29,9,  15>,<-20,12,-452>}
    box{< 76,9,  15>,< 95,12,-452>}
    box{< 76,9,  15>,<129,12,-452>}
    box{<-29,9,  15>,<129,12,   0>}
    box{<-29,9,-105>,<129,12,-295>}
    box{<-29,9,-352>,<129,12,-361>}
    box{<-29,9,-437>,<129,12,-452>}
    box{< 95,9  -19>,<114,12, -38>}
    box{< 95,9,-114>,<114,12,-124>}
    box{< 95,9,-200>,<114,12,-209>}
    box{< 95,9,-285>,<114,12,-295>}
    box{< 95,9,-352>,<114,12,-437>}
    box{<  0,9,-295>,< 38,12,-314>}
    box{<  0,9,-333>,< 38,12,-352>}
    box{< 19,9,-314>,< 38,12,-333>}
    texture{computerwhite_plastic}
  }
}
//############################################################################
// A standard keyboard WITHOUT the infamous Windoze keys. If you need those
// winkeys, you'll have to do them by yourself.
//----------------------------------------------------------------------------
#declare KEYBOARD =
union {
  object{kbd translate<-60,10,220> rotate<0,0,4>}
  box{<-67,0,233>,<65,10,-230> texture{computerwhite_plastic}}
}
//############################################################################
// A keyboard without the NUMPAD keys.
//----------------------------------------------------------------------------
#declare SMALL_KEYBOARD =
union {
  object{key1 translate<  0,10,   0>}		// left CTRL
  object{key1 translate<  0,10, -23>}		// ALT
  object{key3 translate<  0,10, -46>}		// SPACE
  object{key1 translate<  0,10,-239>}		// ALT GR
  object{key1 translate<  0,10,-262>}		// right CTRL
  object{key1 translate< 19,10,   0>}		// left SHIFT
  object{key  translate< 19,10, -23>}		// <>
  object{key  translate< 19,10, -42>}		// Y
  object{key  translate< 19,10, -61>}		// X
  object{key  translate< 19,10, -80>}		// C
  object{key  translate< 19,10, -99>}		// V
  object{key  translate< 19,10,-118>}		// B
  object{key  translate< 19,10,-137>}		// N
  object{key  translate< 19,10,-156>}		// M
  object{key  translate< 19,10,-175>}		// ;,
  object{key  translate< 19,10,-194>}		// :.
  object{key  translate< 19,10,-213>}		// _-
  object{key2 translate< 19,10,-232>}		// right SHIFT
  object{key4 translate< 38,10,   0>}		// CAPS LOCK
  object{key  translate< 38,10, -32>}		// A
  object{key  translate< 38,10, -51>}		// S
  object{key  translate< 38,10, -70>}		// D
  object{key  translate< 38,10, -89>}		// F
  object{key  translate< 38,10,-108>}		// G
  object{key  translate< 38,10,-127>}		// H
  object{key  translate< 38,10,-146>}		// J
  object{key  translate< 38,10,-165>}		// K
  object{key  translate< 38,10,-184>}		// L
  object{key  translate< 38,10,-203>}		// ™
  object{key  translate< 38,10,-222>}		// Ž
  object{key  translate< 38,10,-241>}		// '#
  object{key7 translate< 38,10,-260>}		// RETURN
  object{key5 translate< 57,10,   0>}		// TAB
  object{key  translate< 57,10, -28>}		// Q
  object{key  translate< 57,10, -47>}		// W
  object{key  translate< 57,10, -66>}		// E
  object{key  translate< 57,10, -85>}		// R
  object{key  translate< 57,10,-104>}		// T
  object{key  translate< 57,10,-123>}		// Z
  object{key  translate< 57,10,-142>}		// U
  object{key  translate< 57,10,-161>}		// I
  object{key  translate< 57,10,-180>}		// O
  object{key  translate< 57,10,-199>}		// P
  object{key  translate< 57,10,-218>}		// š
  object{key  translate< 57,10,-237>}		// *
  object{key  translate< 76,10,   0>} 		// ø^
  object{key  translate< 76,10, -19>} 		// 1
  object{key  translate< 76,10, -38>} 		// 2
  object{key  translate< 76,10, -57>} 		// 3
  object{key  translate< 76,10, -76>} 		// 4
  object{key  translate< 76,10, -95>} 		// 5
  object{key  translate< 76,10,-114>} 		// 6
  object{key  translate< 76,10,-133>} 		// 7
  object{key  translate< 76,10,-152>} 		// 8
  object{key  translate< 76,10,-171>} 		// 9
  object{key  translate< 76,10,-190>} 		// 0
  object{key  translate< 76,10,-209>} 		// á?\
  object{key  translate< 76,10,-228>} 		// `ï
  object{key6 translate< 76,10,-247>} 		// BACKSPACE
  object{key0 translate<114,10,   0>} 		// ESC
  object{key  translate<114,10, -38>} 		// F1
  object{key  translate<114,10, -57>} 		// F2
  object{key  translate<114,10, -76>} 		// F3
  object{key  translate<114,10, -95>} 		// F4
  object{key0 translate<114,10,-114>} 		// F5
  object{key0 translate<114,10,-143>} 		// F6
  object{key0 translate<114,10,-162>} 		// F7
  object{key0 translate<114,10,-181>} 		// F8
  object{key  translate<114,10,-209>} 		// F9
  object{key  translate<114,10,-228>} 		// F10
  object{key  translate<114,10,-247>} 		// F11
  object{key  translate<114,10,-266>} 		// F12
  object{key0 translate<  0,10,-295>}		// CUR LEFT
  object{key0 translate<  0,10,-314>}		// CUR DOWN
  object{key0 translate<  0,10,-333>}		// CUR RIGHT
  object{key0 translate< 19,10,-314>}		// CUR UP
  object{key0 translate< 57,10,-295>}		// DEL
  object{key0 translate< 57,10,-314>}		// HOME
  object{key0 translate< 57,10,-333>}		// PG DOWN
  object{key0 translate< 76,10,-295>}		// INS
  object{key0 translate< 76,10,-314>}		// POS1
  object{key0 translate< 76,10,-333>}		// PG UP
  object{key0 translate<114,10,-295>}		// PRINT
  object{key0 translate<114,10,-314>}		// SCROLL LOCK
  object{key0 translate<114,10,-333>}		// PAUSE
  union{
    box{<-29,0,  15>,<114, 9,-367>}
    box{<-29,9,  15>,<-20,12,-367>}
    box{< 76,9,  15>,< 95,12,-367>}
    box{< 76,9,  15>,<129,12,-367>}
    box{<-29,9,  15>,<129,12,   0>}
    box{<-29,9,-105>,<129,12,-295>}
    box{<-29,9,-352>,<129,12,-361>}
    box{< 95,9  -19>,<114,12, -38>}
    box{< 95,9,-114>,<114,12,-124>}
    box{< 95,9,-200>,<114,12,-209>}
    box{< 95,9,-285>,<114,12,-295>}
    box{< 95,9,-352>,<114,12,-367>}
    box{<  0,9,-295>,< 38,12,-314>}
    box{<  0,9,-333>,< 38,12,-352>}
    box{< 19,9,-314>,< 38,12,-333>}
    texture{computerwhite_plastic}
  }
}
//**************************************************************************
//*** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF **
//**************************************************************************
