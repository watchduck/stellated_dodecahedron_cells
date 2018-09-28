#include "LongCylinder.inc"


// big outer dodecahedron, volume meant to be on the outside

#declare SmallerCell = intersection{
    plane{  PlaneNormDistFromPoints(D[14], D[ 9], D[ 8]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[13], D[15], D[18]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 8], D[ 2], D[ 6]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 1], D[ 4], D[ 6]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[16], D[17], D[19]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[13], D[ 7], D[ 3]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[18], D[14], D[12]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 2], D[ 8], D[ 9]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 7], D[13], D[17]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[16], D[ 4], D[10]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 7], D[ 0], D[ 3]) -Offset  }
    plane{  PlaneNormDistFromPoints(D[ 1], D[ 5], D[11]) -Offset  }
    pigment{ color OutsideColor }
}

#declare BiggerCell = intersection{
    plane{  PlaneNormDistFromPoints(D[14], D[ 9], D[ 8]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[13], D[15], D[18]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 8], D[ 2], D[ 6]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 1], D[ 4], D[ 6]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[16], D[17], D[19]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[13], D[ 7], D[ 3]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[18], D[14], D[12]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 2], D[ 8], D[ 9]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 7], D[13], D[17]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[16], D[ 4], D[10]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 7], D[ 0], D[ 3]) -Offset-Thickness  }
    plane{  PlaneNormDistFromPoints(D[ 1], D[ 5], D[11]) -Offset-Thickness  }
    pigment{ color InsideColor }
}

#declare HollowCell = difference{ object{BiggerCell} object{SmallerCell} }


#declare Cell1 = union{
    #for( Index, 0, 11 )
        #local F = DFaceArrays[Index];
        #local Frame = union{
            LongCylinder(D[F[0]], D[F[1]], Radius)
            LongCylinder(D[F[1]], D[F[2]], Radius)
            LongCylinder(D[F[2]], D[F[3]], Radius)
            LongCylinder(D[F[3]], D[F[4]], Radius)
            LongCylinder(D[F[4]], D[F[0]], Radius)
            pigment{color InsideColor}
        }
        #local Plane = plane{  PlaneNormDistFromPoints(D[F[0]], D[F[1]], D[F[2]]) -Offset  inverse  pigment{ color OutsideColor }  }
        #local SolidSide = intersection{ object{HollowCell} object{Plane} }
        intersection{ object{SolidSide} object{Frame} }

    #end
}



