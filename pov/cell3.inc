#declare D12Norm = vnormalize(D[12]);  // needed because of bug in `RotMatFromVectorAndAngle`


// tetrahedron touching icosahedron and dodecahedron edges


#declare SolidCell = intersection{
    plane{  PlaneNormDistFromPoints(I[ 6], D[12], D[16]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[10], D[16], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[ 6], I[10], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[10], I[ 6], D[16]) -Offset  #if(Inv1) inverse #end  }
    pigment{ color OutsideColor }
}

#declare Plane1 = plane{  PlaneNormDistFromPoints(I[ 6], D[12], D[16]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane2 = plane{  PlaneNormDistFromPoints(I[10], D[16], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane3 = plane{  PlaneNormDistFromPoints(I[ 6], I[10], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane4 = plane{  PlaneNormDistFromPoints(I[10], I[ 6], D[16]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }

#declare SolidSide1 = intersection{ object{SolidCell} object{Plane1} }
#declare SolidSide2 = intersection{ object{SolidCell} object{Plane2} }
#declare SolidSide3 = intersection{ object{SolidCell} object{Plane3} }
#declare SolidSide4 = intersection{ object{SolidCell} object{Plane4} }

#declare Frame1 = union{
    cylinder{ I[ 6], D[12], Radius }
    cylinder{ I[ 6], D[16], Radius }
    cylinder{ D[12], D[16], Radius }
    pigment{ color InsideColor }
}
#declare Frame2 = union{
    cylinder{ I[10], D[16], Radius }
    cylinder{ I[10], D[12], Radius }
    cylinder{ D[16], D[12], Radius }
    pigment{ color InsideColor }
}
#declare Frame3 = union{
    cylinder{ I[ 6], I[10], Radius }
    cylinder{ I[ 6], D[12], Radius }
    cylinder{ I[10], D[12], Radius }
    pigment{ color InsideColor }
}
#declare Frame4 = union{
    cylinder{ I[10], I[ 6], Radius }
    cylinder{ I[10], D[16], Radius }
    cylinder{ I[ 6], D[16], Radius }
    pigment{ color InsideColor }
}

#declare Side1 = intersection{ object{SolidSide1} object{Frame1} }
#declare Side2 = intersection{ object{SolidSide2} object{Frame2} }
#declare Side3 = intersection{ object{SolidSide3} object{Frame3} }
#declare Side4 = intersection{ object{SolidSide4} object{Frame4} }

#declare Cell3 = union{ object{Side1} object{Side2} object{Side3} object{Side4} }


////////////////////////////////////////////////////////////////////////////////////////

#declare Cells3 = union{
    object{ Cell3 }
    object{ Cell3  scale -y }
}
#declare Cells3 = union{
    object{ Cells3 }
    object{ Cells3  scale -x }
}
#declare Cells3Z = union{
    object{ Cells3 }
    object{ Cells3  scale -z }
}
#declare Cells3X = object{ Cells3Z  rotate 90*y rotate 90*x }
#declare Cells3Y = object{ Cells3Z  rotate 90*x rotate 90*y }
#declare Cells3 = union{
    object{ Cells3X }
    object{ Cells3Y }
    object{ Cells3Z }
}

#declare Cell3a = object{
    Cell3
    RotMatFromVectorAndAngle(D12Norm, 2*pi/3)
}

#declare Cells3aZ = union{
    object{ Cell3a }
    object{ Cell3a  scale -z }
}
#declare Cells3aX = object{ Cells3aZ  rotate 90*y rotate 90*x }
#declare Cells3aY = object{ Cells3aZ  rotate 90*x rotate 90*y }
#declare Cells3a = union{
    object{ Cells3aX }
    object{ Cells3aY }
    object{ Cells3aZ }
}

#declare Cells3 = union{
    object{ Cells3 }
    object{ Cells3a }
}