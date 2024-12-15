# C-multitype-functions

Allow function returns a few variables:

    multitype(double, char, int) f(void){
      return (1.1,'$', 4);
    }

    void test(void){
      double a=0;
      char b;
      int c;
      
      let(,b,c)=f();
      let(a,b,c)=f();
    }

Look for usage examples in main.c



