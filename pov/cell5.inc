#include "LongCylinder.inc"


// icosahedron


#declare OuterCell = intersection{
    #for( Index, 0, 19 )
        #declare F = IFaceArrays[Index];
        plane{ PlaneNormDistFromPoints(I[F[0]], I[F[1]], I[F[2]]) +Offset }
    #end
    #if(Inv2) inverse #end
    pigment{ color OutsideColor }
}

#declare InnerCell = intersection{
    #for( Index, 0, 19 )
        #declare F = IFaceArrays[Index];
        plane{ PlaneNormDistFromPoints(I[F[0]], I[F[1]], I[F[2]]) +Offset+Thickness }
    #end
    #if(Inv2) inverse #end
    pigment{ color InsideColor }
}

#declare HollowCell = difference{
    object{ OuterCell }
    object{ InnerCell }
}

#declare IcosahedronEdges = union{
    #for( Index, 0, 29 )
        #local EdgeArray = IEdgeArrays[Index];
        LongCylinder(I[EdgeArray[0]], I[EdgeArray[1]], Radius)
    #end
    pigment{color InsideColor}
}

#declare Cell5 = intersection{
    object{ HollowCell }
    object{ IcosahedronEdges }
}