// ***************************************************************************
// Modelled after my Samsung Syncmaster 17 GL. For the sake of rendering speed
// I made the screen flat instead of slightly curved as it is in reality.
// A curved screen would have required a relatively complicated CSG, namely
// the difference of a huge sphere and several planes and a box, and 
// differences seem to render rather slowly.
// The screen image map is used with a non-zero "ambient" value, therefore
// it will glow in the dark just like the real thing. For those who are
// interested, the image map is a screenshot of my OS/2 desktop and the 
// background image is a photograph that I took in Scotland in 1994.
// ***************************************************************************
// Objects provided by this file are:
//	SYNCMASTER17
//
// Textures provided by this file are:
//	computerwhite_plastic
// ***************************************************************************
// Scale: 1 millimeter per POV unit.
// ***************************************************************************
// *               Manfred.Agne@munich.netsurf.de  (1998)                    *
// *                     Feel free to use this file.                         *
// ***************************************************************************


#declare computerwhite_plastic = texture {
  pigment {color rgb <0.9647,0.9098,0.7529>} 
  normal { bumps 0.5 scale 0.1 }
  finish { phong 0.1 }
}
//############################################################################
// Monitor: Syncmaster 17GL nachempfunden. Steht auf (0,0,0) symmetrisch in 
// +-y, Bildschirmfl„che ist von -x aus zu betrachten.
// Maáe in mm.
//----------------------------------------------------------------------------
#declare SYNCMASTER17 =
union {
  union {
    cylinder{<0, 0,0>,<0,15,0>,125}
    box{<0,0,-125>,<150,15,125>}
    cylinder{<0,15,0>,<0,30,0>,105}
    cylinder{<0,30,0>,<0,45,0>, 85}
    sphere{<0,100,0>,90}
    box{<-120, 60,-150>,<-80,100,150>}
    box{<-135, 70,-150>,<-80,100,150>}
    box{<-150,100,-210>,<-50,430,-170>}
    box{<-150,100, 210>,<-50,430, 170>}
    box{<-150, 95,-205>,<-50,140, 205>} 
    box{<-150,435,-205>,<-50,395, 205>}
    cylinder{<-150,100,-205>,<-50,100,-205> 5} 
    cylinder{<-150,100, 205>,<-50,100, 205> 5} 
    cylinder{<-150,430,-205>,<-50,430,-205> 5} 
    cylinder{<-150,430, 205>,<-50,430, 205> 5} 
    difference {
      cylinder{<-300,95,0>,<-300,420,0>,320}
      plane{<1,0,0>,-45}
    }
    difference{
      box{<-80,60,-165>,<240,390,165>}
      plane{<0,-1,0>,0 rotate <0,0,-10> translate<0,385,0>}
      plane{<0, 1,0>,0 rotate <0,0, 10> translate<0, 60,0>}
      box{<-80,55,-170>,<250,170,-145>}
      box{<-80,55, 170>,<250,170, 145>}
      box{<250,55,-170>,<220,170, 170>}
    }
    texture{computerwhite_plastic}
  }  
  box {<-140,140,-170>,<-130,395,170>}
  texture {
    pigment {
      image_map {tga "SCREEN.TGA"} 
      rotate <0,90,0>
      scale <1,255,340>
      translate <0,140,-170>
    }}
  }

//**************************************************************************
//*** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF **
//**************************************************************************
