#ifndef MULTITYPE_H
#define MULTITYPE_H

#include <stdio.h>
#include <string.h>

#include "macro.h"


typedef void* multitype;

void multitypeInit();

#define let(...)       M_IF(M_COUNT(M_REMAINED(__VA_ARGS__)))(_LET,M_EXTRACT)(__VA_ARGS__)
#define return(...)    M_IF(M_COUNT(M_REMAINED(__VA_ARGS__)))(_RETURN,return)(__VA_ARGS__)
#define multitype(...) M_IF(M_COUNT(__VA_ARGS__))( M_IF(M_COUNT(M_REMAINED(__VA_ARGS__)))(multitype,__VA_ARGS__),multitype)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _TYPEOF(...) __typeof__(__VA_ARGS__)
#define _LET_UNPACK(_0_,_1_,...) M_WHEN(M_IS_ARG(__VA_ARGS__))( __VA_ARGS__=*(_TYPEOF(__VA_ARGS__)*)(*_1_); ) ++_1_;
#define _LET_PACK(_1_,...) M_FOREACH(__LET_PACK,_1_,__VA_ARGS__)
#define __LET_PACK(_index_,_1_,...) M_WHEN(M_IS_ARG(__VA_ARGS__))( _1_->M_JOIN(_,_index_)=(__VA_ARGS__); *_1_->i++=&_1_->M_JOIN(_,_index_); )
#define _LET_STRUCT(...) struct{void *p[_RETURN_COUNT(__VA_ARGS__)]; M_FOREACH(__LET_STRUCT,-,__VA_ARGS__) void **i;}
#define __LET_STRUCT(_index_,_0_,...) M_WHEN(M_IS_ARG(__VA_ARGS__))( _TYPEOF(__VA_ARGS__) M_JOIN(_,_index_); )
#define _LET(...) for(;;({void **_1_=(&_1_)[_letGlob==99]; _LETHOLD(_1_); M_FOREACH(_LET_UNPACK,_1_,__VA_ARGS__) goto M_JOIN(_mark,M_LINE());}))if(!8){M_JOIN(_mark,M_LINE()): break;} else ({void *_1_; (&_1_);})[_letGlob]
#define _RETURN(...) { _LET_STRUCT(__VA_ARGS__) _1_[1]={{.i=(void*)_1_}}; _LET_PACK(_1_,__VA_ARGS__) _LETHOLD(_1_); return _letAddr(_1_);} return NULL
#define _RETURN_COUNT(...) (M_FOREACH(__RETURN_COUNT,-,__VA_ARGS__) 0)
#define __RETURN_COUNT(_1_,_2_,...) M_WHEN(M_IS_ARG(__VA_ARGS__))( 1+ )
#define _LETHOLD(...) if(_letGlob==99)printf("ret %p\n",__VA_ARGS__)
extern signed char _letGlob;
void *_letAddr(void *p);


#ifdef MULTITYPE_IMPL

signed char _letGlob=100;

void multitypeInit(){
    if(_letGlob==100){
        void *p1, *p2;
        for(;;({void **p; p1=&p; _letGlob=(void**)p1-(void**)p2; return;}))
            *({void *p; p2=&p; &p;})=NULL;
    }
}

void *_letAddr(void *p){
    void *x=&_letGlob;
    memcpy(&x,&p,sizeof(p));
    return x;
}

#endif

#endif // MULTITYPE_H
