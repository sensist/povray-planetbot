// POV-Ray 3.6/3.7 include file "Seven_Segment_Board_Sample.inc"
// A circuit board with 2 rows of 5 pins for seven-segment displays 
// author: Friedrich A, Lohmueller, Aug-2009
// homepage: http://www.f-lohmueller.de/
// email: Friedrich.Lohmueller_aT_t-online.de
//------------------------------------------------------------------------
#ifndef( Seven_Segment_Board_Sample_Inc_Temp)
#declare Seven_Segment_Board_Sample_Inc_Temp = version;
#version 3.6;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#ifndef(  Colors_Inc_Temp)
#include "colors.inc"                                             
#end
#ifndef(  Textures_Inc_Temp)
#include "textures.inc"                                             
#end
//------------------------------------------------------------------------------ /////////  
//--------------------------------------------------------------------------------------- 
//---------------------------------------------------------------------------------------
#macro Seven_Segment_Board_Sample ( 

                  Board_Start_X, //   in mm
                  Board_End_X,
                  Board_Start_Z, //   in mm
                  Board_End_Z,
                  Contacts_Active, 
                  Contact_Center_X, 
                  Contact_Center_Z, 
                  
                  Contact_Raster_Distance, // in 2.54 mm raster (0.1 inch)  
                  Contact_Raster_Direction, // 0 = in z;  1 = in x 
               ) // ------------------------------------  
//---------------------------------------------------------
#ifndef ( Board_Texture )
#declare  Board_Texture = 
         texture { pigment{ color rgb< 0.05, 0.3, 0.05> }// dark olive green  
                // normal { bumps 0.5 scale 0.05 }
                   finish { phong 1 reflection 0.1}
                 } // end of texture 
#end  
#ifndef ( Contact_Texture )
#declare  Contact_Texture = 
         texture { Chrome_Metal
                // normal { bumps 0.5 scale 0.05 }
                   finish { phong 1 }
                 } // end of texture 
#end  
#ifndef ( Solder_Texture )
#declare  Solder_Texture = 
         texture { Polished_Chrome
                   normal { bumps 0.5 scale 0.2 }
                   finish { phong 1 }
                 } // end of texture 
#end  
//------------------------------------------------------------------------ 
#local Contact_Center = <Contact_Center_X,0,Contact_Center_Z>; 
#local D = 0.00001;
#local B_Raster = 2.54; // mm = 0.1 inch
//-----------------------------
#local Board_D = 0.50; // mm 
#local Hole_R = 0.30;
#local Bolt_D = 0.20;// border D
#local Bolt_R = 0.70;// 
//------------------------------------------------------------------------ 
#local Hole = 
   cylinder{ < 0,-Board_D-Bolt_D-D,0>, <0,Bolt_D+D,0>, Hole_R} 
#local Holes_5_X = 
union{ 
   object{ Hole translate< 2*B_Raster,0,0>} 
   object{ Hole translate< 1*B_Raster,0,0>} 
   object{ Hole translate< 0*B_Raster,0,0>} 
   object{ Hole translate<-1*B_Raster,0,0>} 
   object{ Hole translate<-2*B_Raster,0,0>} 
}// end union 
//--------------------------------------------------------
#local Bolt = 
 difference{  
   cylinder{ <0,-Board_D-Bolt_D  ,0>, <0,Bolt_D+D  ,0>, Bolt_R} 
   cylinder{ <0,-Board_D-Bolt_D-D,0>, <0,Bolt_D+2*D,0>, Hole_R} 
   box{<-1,-1,-1>,<1,0,1> scale <Bolt_R+D,-Board_D,Bolt_R+D>}  
 texture{ Contact_Texture } 
  translate<0,Bolt_D/2,0>
 } // end of difference 
//--------------------------------------------------------
#macro Contact_Point ( Active ) 


union{ 
  object{ Bolt }
  #if ( Active = 1 ) // solder !!! 
   #local Strength = 1.0; //(+ or -) strength of component's radiating density
   #local Radius1  = 0.24*2.0; //(0 < Radius) outer sphere of influence on other components
   blob{
     threshold 0.6 // threshold (0.0 < threshold <= Strength) surface falloff threshold #
     sphere  { <0,0,0>, Radius1*2, Strength scale<1,0.5,1> translate<0,        Bolt_D+0.1,0>}
     sphere  { <0,0,0>, Radius1*2, Strength scale<1,0.5,1> translate<0,-Board_D-Bolt_D-0.1,0>}
     cylinder{ <0,-Board_D-0.75,0>,<0,+0.75,0>, Radius1*1.25, Strength}
  // sturm 
  scale 1
  texture{ Solder_Texture }
  } //----------------------  end of blob object             

  #end // of "#if ( Active = 1 )"
 /*
  // test
  cylinder{ <0,-Board_D-2.5,0>,<0,+2.5,0>, 0.25
            texture{ Contact_Texture } 
           } 
 */          
           
} #end //-------------------------------------------------
//------------------------------------------------------------------------
#macro Contact_Point_Row_5_x (  Active_ ) 
union{ 
   object{ Contact_Point ( Active_ ) translate< 2*B_Raster,0,0>} 
   object{ Contact_Point ( Active_ ) translate< 1*B_Raster,0,0>} 
   object{ Contact_Point ( Active_ ) translate< 0*B_Raster,0,0>} 
   object{ Contact_Point ( Active_ ) translate<-1*B_Raster,0,0>} 
   object{ Contact_Point ( Active_ ) translate<-2*B_Raster,0,0>} 
}// end union 
#end //
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
union{ 
 difference{
     box{ <Board_Start_X,-Board_D,Board_Start_Z>,<Board_End_X,0,Board_End_Z> }  
     object{ Holes_5_X  translate Contact_Center+ <0,0, -B_Raster*Contact_Raster_Distance/2> }      
     object{ Holes_5_X  translate Contact_Center+ <0,0,  B_Raster*Contact_Raster_Distance/2> }      
     texture{ Board_Texture } 
  } // end of difference
 union{ 
  object{  Contact_Point_Row_5_x(Contacts_Active) translate Contact_Center+ <0,0, -B_Raster*Contact_Raster_Distance/2> }    
  object{  Contact_Point_Row_5_x(Contacts_Active) translate Contact_Center+ <0,0,  B_Raster*Contact_Raster_Distance/2> }    
   #if (Contact_Raster_Direction = 0 ) rotate<0,90,0> #end   
  } // end union Contact_Point_Rows
  
} // end of union
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------
#end// of macro ------------------------------------------------------// end of macro




//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
// sample: 
/*
//-----------------------------------------------------------------------------  
//--------------------------------------------------------------------------
//-------------------------------------------------------- optional textures
#declare  Board_Texture = 
         texture { pigment{ color rgb< 0.05, 0.3, 0.05> }// dark olive green  
                // normal { bumps 0.5 scale 0.05 }
                   finish { phong 1 reflection 0.1}
                 } // end of texture 
#declare  Contact_Texture = 
         texture { Chrome_Metal
                // normal { bumps 0.5 scale 0.05 }
                   finish { phong 1 }
                 } // end of texture 
#declare  Solder_Texture = 
         texture { Polished_Chrome
                   normal { bumps 0.5 scale 0.2 }
                   finish { phong 1 }
                 } // end of texture 
//--------------------------------------------------------------------------
#include "Board_000.inc"
//--------------------------------------------------------------------------
object{ Board_000( -10, // Board_Start_X, //   in mm
                    8, // Board_End_X,
                  -12, // Board_Start_Z, //   in mm
                   12, // Board_End_Z,
                  
                  1, // Contacts_Active,  0/1
                  0, // Contact_Center_X, 
                  0, //  Contact_Center_Z, 
                  
                  6, // Contact_Raster_Distance,// in 2.54 mm raster (0.1 inch)  
                  0, // Contact_Raster_Direction, // 0 = in z;  1 = in x
                   
               ) // ------------------------------------  
        // scale<1,1,1>  
        rotate<0,0,0> 
       
     // rotate<16,0,30> 
        
        translate<0,10,0>  
      } // end of object --------------------------------------------------- 
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
*/


#version Seven_Segment_Board_Sample_Inc_Temp;
#end
//------------------------------------- end of include file

