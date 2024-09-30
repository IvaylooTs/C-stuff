#include <stdio.h>

int main()
{
    float a,b,h,r, area;
    int numOfProduct;
    printf("Press 1 for - area of a triangle\n");
    printf("Press 2 for - area of a SqTriangle\n");
    printf("Press 3 for - area of a rectangle\n");
    printf("Press 4 for - area of a circle\n");
    printf("Press 5 for - volume of a cylinder\n");
    printf("Press 6 for - volume of a cube\n");
    scanf("%i", &numOfProduct);
    switch(numOfProduct){
    case 1:
        printf("A = ");
        scanf("%f", &a);
        printf("H = ");
        scanf("%f", &h);
        area = (a*h)/2;
        printf("Area of a triangle is A*H/2 => %f", area);
        break;
    case 2:
        printf("A = ");
        scanf("%f", &a);
        printf("B = ");
        scanf("%f", &b);
        area = (a*b)/2;
        printf("Area of a SqTriangle is A*B/2 => %f", area);
        break;
    case 3:
        printf("A = ");
        scanf("%f", &a);
        printf("B = ");
        scanf("%f", &b);
        area = a*b;
        printf("Area of a rectangle is A*B => %f", area);
        break;
    case 4:
        scanf("%f", &r);
        area = 3.14*(r*r);
        printf("Area of a circle is Pi*R^2 => %f", area);
        break;
    case 5:
        printf("R = ");
        scanf("%f", &r);
        printf("H = ");
        scanf("%f", &h);
        area = 3.14*(r*r)*h;
        printf("Volume of a cylinder is Pi*R^2*H => %f", area);
        break;
    case 6:
        scanf("%f", &a);
        area = a*a*a;
        printf("Volume of a cube is A*A*A => %f", area);
    }
    return 0;
}
