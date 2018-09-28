// pentagonal pyramid


#declare SolidCell = intersection{
    plane{  PlaneNormDistFromPoints(D[4], D[ 6], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[6], D[ 6], D[ 4]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[6], D[12], D[ 6]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[6], D[16], D[12]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[6], D[10], D[16]) -Offset  #if(Inv1) inverse #end  }
    plane{  PlaneNormDistFromPoints(I[6], D[ 4], D[10]) -Offset  #if(Inv1) inverse #end  }
    pigment{ color OutsideColor }
}

#declare Plane1 = plane{  PlaneNormDistFromPoints(D[4], D[ 6], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane2 = plane{  PlaneNormDistFromPoints(I[6], D[ 6], D[ 4]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane3 = plane{  PlaneNormDistFromPoints(I[6], D[12], D[ 6]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane4 = plane{  PlaneNormDistFromPoints(I[6], D[16], D[12]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane5 = plane{  PlaneNormDistFromPoints(I[6], D[10], D[16]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }
#declare Plane6 = plane{  PlaneNormDistFromPoints(I[6], D[ 4], D[10]) -Offset-Thickness  #if(Inv2) inverse #end  pigment{ color InsideColor }  }

#declare SolidSide1 = intersection{ object{SolidCell} object{Plane1} }
#declare SolidSide2 = intersection{ object{SolidCell} object{Plane2} }
#declare SolidSide3 = intersection{ object{SolidCell} object{Plane3} }
#declare SolidSide4 = intersection{ object{SolidCell} object{Plane4} }
#declare SolidSide5 = intersection{ object{SolidCell} object{Plane5} }
#declare SolidSide6 = intersection{ object{SolidCell} object{Plane6} }

#declare Frame1 = union{
    cylinder{ D[ 4], D[ 6], Radius }
    cylinder{ D[ 6], D[12], Radius }
    cylinder{ D[12], D[16], Radius }
    cylinder{ D[16], D[10], Radius }
    cylinder{ D[10], D[ 4], Radius }
    pigment{ color InsideColor }
}
#declare Frame2 = union{
    cylinder{ I[6], D[ 6], Radius }
    cylinder{ I[6], D[ 4], Radius }
    cylinder{ D[ 6], D[ 4], Radius }
    pigment{ color InsideColor }
}
#declare Frame3 = union{
    cylinder{ I[6], D[12], Radius }
    cylinder{ I[6], D[ 6], Radius }
    cylinder{ D[12], D[ 6], Radius }
    pigment{ color InsideColor }
}
#declare Frame4 = union{
    cylinder{ I[6], D[16], Radius }
    cylinder{ I[6], D[12], Radius }
    cylinder{ D[16], D[12], Radius }
    pigment{ color InsideColor }
}
#declare Frame5 = union{
    cylinder{ I[6], D[10], Radius }
    cylinder{ I[6], D[16], Radius }
    cylinder{ D[10], D[16], Radius }
    pigment{ color InsideColor }
}
#declare Frame6 = union{
    cylinder{ I[6], D[ 4], Radius }
    cylinder{ I[6], D[10], Radius }
    cylinder{ D[ 4], D[10], Radius }
    pigment{ color InsideColor }
}

#declare Side1 = intersection{ object{SolidSide1} object{Frame1} }
#declare Side2 = intersection{ object{SolidSide2} object{Frame2} }
#declare Side3 = intersection{ object{SolidSide3} object{Frame3} }
#declare Side4 = intersection{ object{SolidSide4} object{Frame4} }
#declare Side5 = intersection{ object{SolidSide5} object{Frame5} }
#declare Side6 = intersection{ object{SolidSide6} object{Frame6} }

#declare Cell2 = union{ object{Side1} object{Side2} object{Side3} object{Side4} object{Side5} object{Side6} }


////////////////////////////////////////////////////////////////////////////////////////

#declare Cells2 = union{
    object{ Cell2 }
    object{ Cell2  scale -y }
}
#declare Cells2Z = union{
    object{ Cells2 }
    object{ Cells2  scale -z }
}
#declare Cells2X = object{ Cells2Z  rotate 90*y rotate 90*x }
#declare Cells2Y = object{ Cells2Z  rotate 90*x rotate 90*y }
#declare Cells2 = union{
    object{ Cells2X }
    object{ Cells2Y }
    object{ Cells2Z }
}