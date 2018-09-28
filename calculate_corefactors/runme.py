from sympy import sqrt


# small stellated dodecahedron
circ_sD = sqrt(2*(5-sqrt(5)))/4
mid_sD = (sqrt(5)-1)/4

# great stellated dodecahedron
circ_gsD = (sqrt(15)-sqrt(3))/4
mid_gsD = (3-sqrt(5))/4


# icosahedron
circ_I = sqrt(2*(5+sqrt(5)))/4
mid_I = (1+sqrt(5))/4

# dodecahedron
circ_D = (sqrt(3)+sqrt(15))/4
mid_D = (3+sqrt(5))/4


# mid_hull_sD / circ_sD == mid_I / circ_I
mid_hull_sD = circ_sD * mid_I / circ_I

# mid_hull_gsD / circ_gsD == mid_D / circ_D
mid_hull_gsD = circ_gsD * mid_D / circ_D


print(mid_sD / mid_hull_sD)
print(mid_gsD / mid_hull_gsD)