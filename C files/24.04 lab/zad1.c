#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
        float x;
        float y;
    } Point;

typedef struct {
    Point A;
    Point B;
    Point C;
 } Triangle;

int main() {

    int TriCount;
    printf("Number of triangles: ");
    scanf("%d", &TriCount);

    Point *points = (Point *)malloc(TriCount * 3 * sizeof(Point));

    for (int i=0; i<TriCount*3; i+=3) {
        printf("X: ");
        scanf("%f", &points[i].x);
        printf("Y: ");
        scanf("%f", &points[i].y);

        printf("X2: ");
        scanf("%f", &points[i+1].x);
        printf("Y2: ");
        scanf("%f", &points[i+1].y);

        printf("X3: ");
        scanf("%f", &points[i+2].x);
        printf("Y3: ");
        scanf("%f", &points[i+2].y);

    }
/*
for (int i=0; i<TriCount*3; i++){
    printf("X: %f ", points[i].x);
    printf("Y: %f\n", points[i].y);
}
*/

    for (int i=0; i<TriCount*3; i+=3) {
    }



    free(points);



    return 0;
}
