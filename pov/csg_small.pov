#include "basics.inc"

#declare IScale = 1;
#declare DScale = (sqrt(5) - 1) / 2;
#include "coordinates.inc"

#declare Offset = .01;
#declare Thickness = .03;
#declare Radius = .15;
#declare Inv1 = false;
#declare Inv2 = true;

#declare OutsideColor = Color1;  #declare InsideColor = Color1Light;
#include "cell1_small.inc"
#declare OutsideColor = Color2;  #declare InsideColor = Color2Light;
#include "cell2.inc"
#declare OutsideColor = Color3;  #declare InsideColor = Color3Light;
#include "cell3.inc"
#declare OutsideColor = Color4;  #declare InsideColor = Color4Light;
#include "cell4.inc"
#declare OutsideColor = Color5;  #declare InsideColor = Color5Light;
#include "cell5.inc"

#declare Complete = union{
    object{Cell1}
    object{Cells2}
    object{Cells3}
    object{Cells4}
    object{Cell5}
}

object{Complete}


//#declare CutFront = plane{ PlaneNormDistFromPoints(D[ 6], D[12], D[16]) }
//#declare CutBack = plane{ PlaneNormDistFromPoints(D[ 3], D[ 7], D[13]) }
//#declare CutCenter = intersection{
//    object{ CutFront inverse }
//    object{ CutBack inverse }
//}
//
//intersection{
//    object{Complete}
//    object{CutCenter}
//}