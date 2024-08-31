# C-multitype-functions

Allow function returns a few variables:

multitype(double, char, int) f(){
    return (1.1,'$', 4);
}

void test(){
    double a=0;
    char b;
    int c;

    let(,b,c)=f();

    let(a,b,c)=f();
}

Important: don't #include multitype.c, it must be compilled as transaltion unit!




