#include <stdio.h>

int main(){
    typedef struct{
        float x;
        float y;
    }Point;

    typedef struct{
        Point point;
        float slope;
    }Line;

    Point point_1;
    Line line_1;

    scanf("%f%f%f",&line_1.point.x,&line_1.point.y,&line_1.slope);
    scanf("%f%f",&point_1.x,&point_1.y);

    if(point_1.y-line_1.point.y == line_1.slope*(point_1.x-line_1.point.x)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    
    return 0;
}