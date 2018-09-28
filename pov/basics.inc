#version 3.6;
global_settings { assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}

#include "colors.inc"
#include "math.inc"
#include "textures.inc"

#include "PlaneNormDistFromPoints.inc"
#include "RotMatFromVectorAndAngle.inc"


///////////////////////////// camera and light

#declare Camera_Position = vnormalize(<13.2, 13.7, -45>) * 38;

camera{
    location Camera_Position
    right    x*image_width/image_height
    angle    10.8
    look_at  <-.05, -.02, 0>
}

light_source{ <-400, 600, -900> color White*.65 shadowless }
light_source{ <-200, 500, -50>  color White*.5 shadowless }
light_source{ Camera_Position   color White*.25 shadowless }

sky_sphere{ pigment{ White } }


///////////////////////////// colors

#declare Color1 = srgb <237, 44, 45> / 255;
#declare Color2 = srgb <195, 73, 255> / 255;
#declare Color3 = srgb <40, 144, 219> / 255;
#declare Color4 = srgb <122, 173, 0> / 255;
#declare Color5 = srgb <255, 207, 0> / 255;

#declare Color1Light = srgb <249, 191, 192> / 255;
#declare Color2Light = srgb <237, 200, 255> / 255;
#declare Color3Light = srgb <190, 221, 244> / 255;
#declare Color4Light = srgb <215, 230, 178> / 255;
#declare Color5Light = srgb <255, 240, 178> / 255;


///////////////////////////// run command example

/*
povray csg_small.pov +ua +fn Height=3720 Width=4000
*/