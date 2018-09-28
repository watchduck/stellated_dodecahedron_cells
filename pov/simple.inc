#declare VertexRadius = .08;
#declare EdgeRadius = .035;


////////////////////////////////////////////////////////////////////////////////////////////////////


#declare Vertices = union{
    union{
        #for( Index, 0, 11 )
            sphere{ I[Index], VertexRadius }
        #end
    }
    union{
        #for( Index, 0, 19 )
            sphere{ D[Index], VertexRadius }
        #end
    }
}

#declare IcosahedronEdges = union{
    #for( Index, 0, 29 )
        #local EdgeArray = IEdgeArrays[Index];
        cylinder{ I[EdgeArray[0]], I[EdgeArray[1]], EdgeRadius }
    #end
}

#declare DodecahedronEdges = union{
    #for( Index, 0, 29 )
        #local EdgeArray = DEdgeArrays[Index];
        cylinder{ D[EdgeArray[0]], D[EdgeArray[1]], EdgeRadius }
    #end
}

#declare ConnectionEdges = union{
    #for( A, 0, 11 )
        #declare IVertexNumber = IVertexNumbers[A];
        #declare DFaceArray = DFaceArrays[A];
        #for( B, 0, 4 )
            #declare DVertexNumber = DFaceArray[B];
            cylinder{ I[IVertexNumber], D[DVertexNumber], EdgeRadius }
        #end
    #end
}

#declare DodecahedronFaces = union{
    #for( Index, 0, 11 )
        #local FaceArray = DFaceArrays[Index];
        polygon{ 5,
            #for(VertexIndexInFace, 0, 4)
                D[FaceArray[VertexIndexInFace]]
            #end
        }
    #end
}

#declare IcosahedronFaces = union{
    #for( Index, 0, 19 )
        #local FaceArray = IFaceArrays[Index];
        polygon{ 3,
            #for(VertexIndexInFace, 0, 2)
                I[FaceArray[VertexIndexInFace]]
            #end
        }
    #end
}


////////////////////////////////////////////////////////////////////////////////////////////////////


# declare Transparent = rgbt<1, 1, 1, .7>;

union{
    object{ IcosahedronEdges   pigment{color Color5} }
    object{ IcosahedronFaces   pigment{color Transparent} }

    object{ DodecahedronEdges  pigment{color Color1} }
    object{ DodecahedronFaces  pigment{color Transparent} }

    object{ ConnectionEdges    pigment{color White} }
    object{ Vertices           pigment{color Black} }
}