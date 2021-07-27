// POV-Ray 3.7 Scene File " ... .pov"
// author:  ...
// date:    ...
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
#declare Camera_Number = 0 ;
//---------------------------------------------------------------------------------
// camera -------------------------------------------------------------------------
#switch ( Camera_Number )
#case (0)
  #declare Camera_Location = < 0.00, 0.00, -20.00> ;  // front view
  #declare Camera_Look_At  = < 0.00, 0.00,  0.00> ;
  #declare Camera_Angle    =  15 ;
#break
#case (1)
  #declare Camera_Location =  < 6.0 , 6.0 ,-6.0> ;  // diagonal view
  #declare Camera_Look_At  =  < 0.0 , 0.9 , 0.0> ;
  #declare Camera_Angle    =  45 ;
#break
#case (2)
  #declare Camera_Location = < 3.0, 1.0 , 0.0> ;  // right side view
  #declare Camera_Look_At  = < 0.0, 1.0,  0.0> ;
  #declare Camera_Angle    =  90 ;
#break
#case (3)
  #declare Camera_Location = < 0.00, 5.00,  0+0.000> ;  // top view
  #declare Camera_Look_At  = < 0.00, 0.00,  0+0.001> ;
  #declare Camera_Angle    = 90 ;
#break
#else
  #declare Camera_Location = < 0.00, 1.00, -3.50> ;  // front view
  #declare Camera_Look_At  = < 0.00, 1.00,  0.00> ;
  #declare Camera_Angle    =  75 ;
#break
#break
#end // of "#switch ( Camera_Number )"  
//--------------------------------------------------------------------------
camera{ // ultra_wide_angle // orthographic 
        location Camera_Location
        right    x*image_width/image_height
        angle    Camera_Angle
        look_at  Camera_Look_At
      }
// sun -------------------------------------------------------------------
light_source{< 3000,3000,-3000> color rgb<1,1,1>*0.9}                // sun 
light_source{ Camera_Location   color rgb<0.9,0.9,1>*0.1 shadowless}// flash
// sky ---------------------------------------------------------------------

#include "stars.inc"

    sky_sphere {
            pigment {
                bozo
                color_map {
                    [0.0 color rgb <.5,.5,.5>]
                    [0.2 color rgb <0,0,0>]
                    [1.0 color rgb <0,0,0>]
                }
                scale .003
            }
        }

// ground ------------------------------------------------------------------
/*
plane{ <0,1,0>, 0 
       texture{ pigment{ color rgb <0.7,0.5,0.3>}
              //normal { bumps 0.75 scale 0.025}
                finish { phong 0.1}
              } // end of texture
     } // end of plane
*/
//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------
  
  
  
  #declare LandArea = texture {
      pigment {
        agate
        turbulence 1
        lambda 1.5
        omega .8
        octaves 8
        scale 5
        color_map {
          [0.00 color rgb <.5, .25, .15>]
          [0.33 color rgb <.1, .5, .4>]
          [0.86 color rgb <.6, .3, .1>]
          [1.00 color rgb <.5, .25, .15>]
        }
      }
    }

  #declare OceanArea = texture {
      pigment {
        bozo
        turbulence .5
        lambda 2
        color_map {
          [0.00, 0.33 color rgb <0, 0, 1>
                      color rgb <0, 0, 1>]
          [0.33, 0.66 color rgbf <1, 1, 1, 1>
                      color rgbf <1, 1, 1, 1>]
          [0.66, 1.00 color rgb <0, 0, 1>
                      color rgb <0, 0, 1>]
        }
      }
    }

  #declare CloudArea = texture {
    pigment {
      bozo
      turbulence 1
      lambda 2
      frequency 2
      color_map {
        [0.0 color rgbf <1, 1, 1, 1>]
        [0.5 color rgbf <1, 1, 1, .35>]
        [1.0 color rgbf <1, 1, 1, 1>]
      }
    }
  }

  sphere {
    <0,0,0>, 1
    texture { LandArea }
    texture { OceanArea }
    texture { CloudArea }
  }