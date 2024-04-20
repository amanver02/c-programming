 #include<stdio.h>

 int main(){
    float base, height, area;

    printf("Enter the base and height of triangle :");
    scanf("%f %f", &base, &height);

    area = 0.5 * base * height;

    printf("Area of triangle : %.2f", area);
    return 0;
}
