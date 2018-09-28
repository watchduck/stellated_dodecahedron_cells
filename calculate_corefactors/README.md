The radii come from [dmccooey.com/polyhedra](http://dmccooey.com/polyhedra):<br>
[SmallStellatedDodecahedron](http://dmccooey.com/polyhedra/SmallStellatedDodecahedron.html) (sD),
[GreatStellatedDodecahedron](http://dmccooey.com/polyhedra/GreatStellatedDodecahedron.html) (gsD),
[Dodecahedron](http://dmccooey.com/polyhedra/Dodecahedron.html) (D),
[Icosahedron](http://dmccooey.com/polyhedra/Icosahedron.html) (I)

| hull | star | core |
| ---- | ---- | ---- |
| I    | sD   | D    |
| D    | gsD  | I    |

The aim is to calculate how much smaller the core is than the hull.
The desired value is core midradius to hull midradius.


### Calculation for the small stellated dodecahedron

The hull of an sD is an I.<br>
The circradius of an sD is that of its hull. There is no variable `circ_hull_sD`, because that is `circ_sD`.<br>
`mid_hull_sD / circ_sD == mid_I / circ_I` implies<br>
`mid_hull_sD = circ_sD * mid_I / circ_I`

The core of an sD is a D.<br>
The midradius of an sD is that of its core. There is no variable `mid_core_sD`, because that is `mid_sD`.

The quotient of core midradius and hull midradius is `mid_sD / mid_hull_sD`.<br>
This is **`1/2 * (sqrt(5) - 1)`** = 0.61803...
(see [golden ratio](https://en.wikipedia.org/wiki/Golden_ratio))


### Result for the great stellated dodecahedron

`mid_gsD / mid_hull_gsD` = **`1/2 * (3 - sqrt(5))`** = 0.38196...

The sum of both results is 1.


### SymPy vs WolframAlpha

The readable results are calculated with WolframAlpha. The results SymPy returned were:<br>
`(-1/4 + sqrt(5)/4)*sqrt(2*sqrt(5) + 10)/((1/4 + sqrt(5)/4)*sqrt(-2*sqrt(5) + 10))` and<br>
`(sqrt(3)/4 + sqrt(15)/4)*(-sqrt(5)/4 + 3/4)/((-sqrt(3)/4 + sqrt(15)/4)*(sqrt(5)/4 + 3/4))`
