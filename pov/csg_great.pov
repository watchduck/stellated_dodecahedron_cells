#include "basics.inc"

#declare IScale = (3 - sqrt(5)) / 2;
#declare DScale = 1;
#include "coordinates.inc"

#declare Offset = -.01;
#declare Thickness = -.03;
#declare Radius = .15;
#declare Inv1 = true;
#declare Inv2 = false;

#declare OutsideColor = Color1;  #declare InsideColor = Color1Light;
#include "cell1_great.inc"
#declare OutsideColor = Color2;  #declare InsideColor = Color2Light;
#include "cell2.inc"
#declare OutsideColor = Color3;  #declare InsideColor = Color3Light;
#include "cell3.inc"
#declare OutsideColor = Color4;  #declare InsideColor = Color4Light;
#include "cell4.inc"
#declare OutsideColor = Color5;  #declare InsideColor = Color5Light;
#include "cell5.inc"

#declare Complete = union{
    object{Cell5}
    object{Cells4}
    object{Cells3}
    object{Cells2}
    object{Cell1}
}

object{Complete}


//#declare ThreeFoldCutFront = plane{ PlaneNormDistFromPoints(I[4], I[10], I[6]) }
//#declare ThreeFoldCutBack = plane{ PlaneNormDistFromPoints(I[1], I[7], I[5]) }
//#declare ThreeFoldCutCenter = intersection{
//    object{ ThreeFoldCutFront inverse }
//    object{ ThreeFoldCutBack inverse }
//}
//
//#declare FiveFoldCutFront = plane{ PlaneNormDistFromPoints(D[2], D[14], D[11]) }
//#declare FiveFoldCutBack = plane{ PlaneNormDistFromPoints(D[5], D[17], D[8]) }
//#declare FiveFoldCutCenter = intersection{
//    object{ FiveFoldCutFront inverse }
//    object{ FiveFoldCutBack inverse }
//}
//
//#declare CutVertical = plane{ PlaneNormDistFromPoints(I[2], I[3], I[9]) }
//
//intersection{
//    object{Complete}
//    object{CutVertical}
//}