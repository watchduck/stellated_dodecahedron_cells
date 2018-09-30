This is the POV-Ray code for a series of images about two topologically equivalent geometric objects related to the
[small](https://en.wikipedia.org/wiki/Small_stellated_dodecahedron) and the
[great](https://en.wikipedia.org/wiki/Great_stellated_dodecahedron) stellated dodecahedron.

<table>
  <tr>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Stell12s_ball-and-stick.png">
        <img width="300" src='https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Stell12s_ball-and-stick.png/516px-Stell12s_ball-and-stick.png'/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Stell12g_ball-and-stick.png">
        <img width="300" src='https://upload.wikimedia.org/wikipedia/commons/thumb/3/33/Stell12g_ball-and-stick.png/516px-Stell12g_ball-and-stick.png'/>
      </a>
    </td>
  </tr>
  <tr>
    <td>
      <a href='https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/simple_small.pov'>
        <code>simple_small.pov</code>
      </a>
    </td>
    <td>
      <a href='https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/simple_great.pov'>
        <code>simple_great.pov</code>
      </a>
    </td>
  </tr>
</table>

As the objects are topologically the same, the two ball-and-stick models shown above have essentially the same code.
The coordinates come from
[`coordinates.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/coordinates.inc),
and the scene is then described in
[`simple.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/simple.inc).
What makes the difference between the two images are only the variables 
`IScale` and `DScale`, determining the size of the icosahedron and dodecahedron.
(The factors to scale the cores,
closely related to the [golden ratio](https://en.wikipedia.org/wiki/Golden_ratio),
have been calculated in
[`calculate_corefactors`](https://github.com/watchduck/stellated_dodecahedron_cells/tree/master/calculate_corefactors).)

The vertex numbers used in this project are those of
[this icosahedron](https://commons.wikimedia.org/wiki/File:Polyhedron_20,_numbers.png) and 
[this dodecahedron](https://commons.wikimedia.org/wiki/File:Polyhedron_12,_numbers.png).

<table>
  <tr>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Stell12s_cells_12345.png">
        <img width="300" src='https://upload.wikimedia.org/wikipedia/commons/thumb/0/00/Stell12s_cells_12345.png/516px-Stell12s_cells_12345.png'/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Stell12g_cells_54321.png">
        <img width="300" src='https://upload.wikimedia.org/wikipedia/commons/thumb/1/16/Stell12g_cells_54321.png/516px-Stell12g_cells_54321.png'/>
      </a>
    </td>
  </tr>
  <tr>
    <td>
      <a href='https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/csg_small.pov'>
        <code>csg_small.pov</code>
      </a>
    </td>
    <td>
      <a href='https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/csg_great.pov'>
        <code>csg_great.pov</code>
      </a>
    </td>
  </tr>
</table>

Also the code for the
[CSG](https://en.wikipedia.org/wiki/Constructive_solid_geometry)
images has been written only once.
Only a small detail required different versions of the red dodecahedron as core of the small figure
([`cell1_small.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell1_small.inc))
and as hull of the great figure
([`cell1_great.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell1_great.inc)).
The 12 magenta pentagonal pyramids
([`cell2.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell2.inc)),
the 30 blue tetrahedra
([`cell3.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell3.inc)),
the 20 green tetrahedra
([`cell4.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell4.inc))
and the yellow icosahedron
([`cell5.inc`](https://github.com/watchduck/stellated_dodecahedron_cells/blob/master/pov/cell5.inc))
are used for both figures, and are adapted with opposite values for `Offset`, `Thickness`, `Inv1` and `Inv2`.
`Offset` is half the distance between two cells, and `Thickness` is the thickness of the cell walls.
The other two values are used to determine on which side the
[half-spaces](https://en.wikipedia.org/wiki/Half-space_(geometry)) ("planes") have their volume,
using the [`inverse`](http://www.povray.org/documentation/view/3.6.1/325/) keyword.

The openings in the faces are achieved using intersections with edge cylinders.
To give the impression of solid cells their `Radius` has simply been increased to 100.
To cut through solid cells it was necessary to modify the cell files, leaving only the `SolidCell`.

The three macros used are found in
[`pov_macros`](https://github.com/watchduck/stellated_dodecahedron_cells/tree/master/pov_macros).
`RotMatFromVectorAndAngle` is described
[in a different project](https://github.com/watchduck/convex_polyhedra/tree/master/povray_includes).



