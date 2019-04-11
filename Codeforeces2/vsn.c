#include<stdio.h>
#include<math.h>
double min(double a,double b)
{
    if(a<b) return a;
    return b;
}
int main()
{
    int t;
    double r,px,py,pz,qx,qy,qz,cx,cy,dx,dy,dz,cz;
    double root1,root2,c1,c2,c3,k1,k2,k3,f,g,h,i,j,k,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&px,&py,&pz,&qx,&qy,&qz,&dx,&dy,&dz,&cx,&cy,&cz,&r);
        c1 = cx - px ; c2 = cy - py ; c3 = cz - pz;
        k1 = px - qx ; k2 = py - qy ; k3 = pz - qz;
        f = c1*dx + c2*dy + c3*dz ;
        g = c1*k1 + c2*k2 + c3*k3 ;
        h = c1*c1 + c2*c2 + c3*c3 - r*r ;
        i = k1*dx + k2*dy + k3*dz ;
        j = dx*dx + dy*dy + dz*dz ;
        k = k1*k1 + k2*k2 + k3*k3 ;
        a  = f*f - h*j ;
        b = 2*(h*i-f*g) ;
        c = g*g - k*h ;
        printf("%ld %ld %ld\n",a,b,c);
        if(a==0.0)
            printf("%lf\n",-c/b);
        else
        {
            root1 = (-b+sqrt(b*b-4*a*c))/(2*a);
            root2 = (-b-sqrt(b*b-4*a*c))/(2*a);
            if(root1 > 0 & root2 > 0)
                printf("%lf\n",min(root1,root2)) ;
            else if(root1 > 0)
                printf("%lf\n",root1) ;
            else printf("%lf\n",root2) ;
        }                 
    }
    return 0;
}