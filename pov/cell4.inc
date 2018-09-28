#declare I6Norm = vnormalize(I[6]);  // needed because of bug in `RotMatFromVectorAndAngle`


// tetrahedron touching icosahedron face


#declare SolidCell = intersection{
    plane{  PlaneNormDistFromPoints(I[ 4], I[ 6], I[10]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[ 6], I[ 4], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[10], I[ 6], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[ 4], I[10], D[12]) -Offset  #if(Inv1) inverse #end  }
    pigment{color OutsideColor}
}

#declare Plane1 = plane{  PlaneNormDistFromPoints(I[ 4], I[ 6], I[10]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{color InsideColor}  }
#declare Plane2 = plane{  PlaneNormDistFromPoints(I[ 6], I[ 4], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{color InsideColor}  }
#declare Plane3 = plane{  PlaneNormDistFromPoints(I[10], I[ 6], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{color InsideColor}  }
#declare Plane4 = plane{  PlaneNormDistFromPoints(I[ 4], I[10], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{color InsideColor}  }

#declare SolidSide1 = intersection{ object{SolidCell} object{Plane1} }
#declare SolidSide2 = intersection{ object{SolidCell} object{Plane2} }
#declare SolidSide3 = intersection{ object{SolidCell} object{Plane3} }
#declare SolidSide4 = intersection{ object{SolidCell} object{Plane4} }

#declare Frame1 = union{
    cylinder{ I[ 4], I[ 6], Radius }
    cylinder{ I[ 4], I[10], Radius }
    cylinder{ I[ 6], I[10], Radius }
    pigment{ color InsideColor }
}
#declare Frame2 = union{
    cylinder{ I[ 6], I[ 4], Radius }
    cylinder{ I[ 6], D[12], Radius }
    cylinder{ I[ 4], D[12], Radius }
    pigment{ color InsideColor }
}
#declare Frame3 = union{
    cylinder{ I[10], I[ 6], Radius }
    cylinder{ I[10], D[12], Radius }
    cylinder{ I[ 6], D[12], Radius }
    pigment{ color InsideColor }
}
#declare Frame4 = union{
    cylinder{ I[ 4], I[10], Radius }
    cylinder{ I[ 4], D[12], Radius }
    cylinder{ I[10], D[12], Radius }
    pigment{ color InsideColor }
}

#declare Side1 = intersection{ object{SolidSide1} object{Frame1} }
#declare Side2 = intersection{ object{SolidSide2} object{Frame2} }
#declare Side3 = intersection{ object{SolidSide3} object{Frame3} }
#declare Side4 = intersection{ object{SolidSide4} object{Frame4} }

#declare Cell4 = union{ object{Side1} object{Side2} object{Side3} object{Side4} }


////////////////////////////////////////////////////////////////////////////////////////

#declare Cells4 = union{
    object{ Cell4 }
    object{ Cell4  scale -x }
}
#declare Cells4Z = union{
    object{ Cells4 }
    object{ Cells4  scale -z }
}
#declare Cells4X = object{ Cells4Z  rotate 90*y rotate 90*x }
#declare Cells4Y = object{ Cells4Z  rotate 90*x rotate 90*y }
#declare Cells4 = union{
    object{ Cells4X }
    object{ Cells4Y }
    object{ Cells4Z }
}

#declare Cell4a = object{
    Cell4
    RotMatFromVectorAndAngle(I6Norm, 2*pi/5)
}

#declare Cells4a = union{
    object{ Cell4a }
    object{ Cell4a  scale -x }
}
#declare Cells4a = union{
    object{ Cells4a }
    object{ Cells4a  scale -y }
}
#declare Cells4a = union{
    object{ Cells4a }
    object{ Cells4a  scale -z }
}

#declare Cells4 = union{
    object{ Cells4 }
    object{ Cells4a }
}
