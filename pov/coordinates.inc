// `IScale` and `DScale` must be set before including


////////////////// icosahedron

#declare IFactor = 1/2 * (3 * sqrt(5) - 3) * IScale;

#declare IAbs = array[3]{
    0,
    IFactor,
    1/2 * (1 + sqrt(5)) * IFactor
}

#declare I = array[12]{ <-IAbs[2],IAbs[0],-IAbs[1]>, <-IAbs[2],IAbs[0],IAbs[1]>, <-IAbs[1],-IAbs[2],IAbs[0]>, <-IAbs[1],IAbs[2],IAbs[0]>, <IAbs[0],-IAbs[1],-IAbs[2]>, <IAbs[0],-IAbs[1],IAbs[2]>, <IAbs[0],IAbs[1],-IAbs[2]>, <IAbs[0],IAbs[1],IAbs[2]>, <IAbs[1],-IAbs[2],IAbs[0]>, <IAbs[1],IAbs[2],IAbs[0]>, <IAbs[2],IAbs[0],-IAbs[1]>, <IAbs[2],IAbs[0],IAbs[1]>, }

#declare IEdgeArrays = array[30]{array[2]{2, 4}, array[2]{4, 10}, array[2]{7, 9}, array[2]{7, 11}, array[2]{3, 7}, array[2]{1, 7}, array[2]{2, 8}, array[2]{2, 5}, array[2]{9, 10}, array[2]{4, 8}, array[2]{0, 4}, array[2]{10, 11}, array[2]{5, 7}, array[2]{3, 6}, array[2]{8, 11}, array[2]{8, 10}, array[2]{0, 2}, array[2]{9, 11}, array[2]{0, 1}, array[2]{6, 9}, array[2]{1, 3}, array[2]{5, 8}, array[2]{5, 11}, array[2]{6, 10}, array[2]{4, 6}, array[2]{1, 5}, array[2]{0, 6}, array[2]{0, 3}, array[2]{1, 2}, array[2]{3, 9}};

#declare IFaceArrays = array[20]{
    array[3]{11, 8, 10},
    array[3]{11, 10, 9},
    array[3]{11, 9, 7}
    array[3]{11, 5, 8},
    array[3]{4, 8, 2},
    array[3]{11, 7, 5},
    array[3]{4, 10, 8},
    array[3]{4, 0, 6},
    array[3]{4, 6, 10},
    array[3]{4, 2, 0},
    array[3]{9, 6, 3},
    array[3]{9, 3, 7},
    array[3]{9, 10, 6},
    array[3]{6, 0, 3},
    array[3]{8, 5, 2},
    array[3]{1, 2, 5},
    array[3]{1, 3, 0},
    array[3]{1, 0, 2},
    array[3]{1, 7, 3},
    array[3]{1, 5, 7}
}

#declare IVertexNumbers = array[12]{8, 11, 4, 0, 9, 5, 10, 2, 7, 6, 1, 3}  // in the order of faces in `DFaceArrays`


////////////////// dodecahedron

#declare DFactor = 3/2 * (sqrt(5) - 1) * DScale;

#declare DAbs = array[4]{
    0,
    1/2 * (sqrt(5) - 1) * DFactor,
    DFactor,
    1/2 * (1 + sqrt(5)) * DFactor
}

#declare D = array[20]{ <-DAbs[3],-DAbs[1],DAbs[0]>, <-DAbs[3],DAbs[1],DAbs[0]>, <-DAbs[2],-DAbs[2],-DAbs[2]>, <-DAbs[2],-DAbs[2],DAbs[2]>, <-DAbs[2],DAbs[2],-DAbs[2]>, <-DAbs[2],DAbs[2],DAbs[2]>, <-DAbs[1],DAbs[0],-DAbs[3]>, <-DAbs[1],DAbs[0],DAbs[3]>, <DAbs[0],-DAbs[3],-DAbs[1]>, <DAbs[0],-DAbs[3],DAbs[1]>, <DAbs[0],DAbs[3],-DAbs[1]>, <DAbs[0],DAbs[3],DAbs[1]>, <DAbs[1],DAbs[0],-DAbs[3]>, <DAbs[1],DAbs[0],DAbs[3]>, <DAbs[2],-DAbs[2],-DAbs[2]>, <DAbs[2],-DAbs[2],DAbs[2]>, <DAbs[2],DAbs[2],-DAbs[2]>, <DAbs[2],DAbs[2],DAbs[2]>, <DAbs[3],-DAbs[1],DAbs[0]>, <DAbs[3],DAbs[1],DAbs[0]>, }

#declare DEdgeArrays = array[30]{array[2]{4, 10}, array[2]{12, 16}, array[2]{3, 7}, array[2]{2, 8}, array[2]{7, 13}, array[2]{2, 6}, array[2]{17, 19}, array[2]{13, 17}, array[2]{8, 14}, array[2]{13, 15}, array[2]{18, 19}, array[2]{12, 14}, array[2]{9, 15}, array[2]{8, 9}, array[2]{15, 18}, array[2]{10, 11}, array[2]{10, 16}, array[2]{5, 7}, array[2]{1, 5}, array[2]{0, 2}, array[2]{11, 17}, array[2]{6, 12}, array[2]{0, 1}, array[2]{16, 19}, array[2]{5, 11}, array[2]{4, 6}, array[2]{1, 4}, array[2]{0, 3}, array[2]{14, 18}, array[2]{3, 9}};

#declare DFaceArrays = array[12]{
    array[5]{18, 15, 9, 8, 14},
    array[5]{13, 15, 18, 19, 17},
    array[5]{8, 2, 6, 12, 14},
    array[5]{1, 4, 6, 2, 0},
    array[5]{10, 11, 17, 19, 16},
    array[5]{13, 7, 3, 9, 15},
    array[5]{18, 14, 12, 16, 19},
    array[5]{2, 8, 9, 3, 0},
    array[5]{7, 13, 17, 11, 5},
    array[5]{12, 6, 4, 10, 16},
    array[5]{5, 1, 0, 3, 7},
    array[5]{1, 5, 11, 10, 4}
}