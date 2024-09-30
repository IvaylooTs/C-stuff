#include <stdio.h>
#include <math.h>
#include "maxPeakZAD8.h"


typedef struct{
    double x, y;
} Point;

double MathLine_Dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n; // number of peaks
    scanf("%d", &n);

    Point peaks[MAX_PEAKS]; // array of peaks
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &peaks[i].x, &peaks[i].y);
    }
    peaks[n] = peaks[0];

    double perimeter = 0;
    for (int i = 0; i < n; i++) {
        perimeter += MathLine_Dist(peaks[i], peaks[i+1]);
    }

    printf("%lf\n", perimeter);
    return 0;
}
