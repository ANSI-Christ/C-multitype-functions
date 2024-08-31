#include "multitype.h"

multitype(double,char,float) f1(int x){
    char symb='0'+x;
    return(x+4.,symb,x*2.0f);
}

multitype(double) f2(int x){
    char symb='0'+x;
    return (x+14.);
}
  
int main()
{
    char a;
    float b;
    double c=0.;
    
    let(,a,b)=f1(1);
    printf("%f %c %f\n",c,a,b);

    let(c,a,b)=f1(2);
    printf("%f %c %f\n",c,a,b);

    c=f2(3);
    printf("%f\n",c);

    return 0;
}
