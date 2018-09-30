#macro LongCylinder(A, B, Rad)

    cylinder{  
        A - 100*(A-B),
        B + 100*(A-B),
        Rad
    }

#end
