// Copyright (C) 2004-2011 Christoph Kubisch
// This file is part of the "Luxinia Engine".
// For conditions of distribution and use, see copyright notice in LICENSE.txt

#ifndef __LUXTYPES_H__
#define __LUXTYPES_H__


//////////////////////////////////////////////////////////////////////////
// Types
typedef unsigned char checkint64[sizeof( long long ) == 8];

typedef unsigned char   uchar;
typedef unsigned short  ushort;
typedef unsigned int    uint;
typedef unsigned long   ulong;

typedef unsigned char byte;
typedef unsigned int  booln;

typedef char        int8;
typedef short       int16;
typedef int         int32;
typedef long long   int64;

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

typedef unsigned char   bool8;
typedef unsigned short  bool16;
typedef unsigned int    bool32;

typedef unsigned int        enum32;
typedef unsigned int        flags32;
typedef unsigned long long  flags64;

typedef unsigned short  float16;
typedef float           float32;
typedef double          float64;

typedef struct lxRectanglei_s{
  int   x;
  int   y;
  int   width;
  int   height;
}lxRectanglei_t;
typedef lxRectanglei_t* lxRectangleiPTR;

typedef struct lxRectanglef_s{
  float x;
  float y;
  float width;
  float height;
}lxRectanglef_t;
typedef struct lxRectanglef_s* lxRectanglefPTR;

typedef struct lxVec2i_s{
  int   x;
  int   y;
}lxVec2i_t;
typedef struct lxVec2i_s* lxVec2iPTR;

typedef struct lxVec3i_s{
  int   x;
  int   y;
  int   z;
}lxVec3i_t;
typedef struct lxVec3i_s* lxVec3iPTR;

typedef struct lxVec2f_s{
  float   x;
  float   y;
}lxVec2f_t;
typedef struct lxVec2f_s* lxVec2fPTR;

typedef struct lxVec3f_s{
  float   x;
  float   y;
  float   z;
}lxVec3f_t;
typedef struct lxVec3f_s* lxVec3fPTR;

typedef struct lxVec4f_s{
  float   x;
  float   y;
  float   z;
  float   w;
}lxVec4f_t;
typedef struct lxVec4f_s* lxVec4fPTR;

#define LUX_MAX(a,b)     (((a) > (b)) ? (a) : (b))
#define LUX_MIN(a,b)     (((a) < (b)) ? (a) : (b))

#ifndef LUX_TRUE
#define LUX_TRUE  1
#endif

#ifndef LUX_FALSE
#define LUX_FALSE 0
#endif

#define LUX_IS_ALIGNED(ptr,align)  (((size_t)(ptr)) % (align) == 0)

// generic type
#define LUX_ARRAY3COMPARE(a,cmp,b) (((a)[0] cmp (b)[0] && (a)[1] cmp (b)[1] && (a)[2] cmp (b)[2]))
#define LUX_ARRAY1COPY(dst,src)    ((dst)[0]=(src)[0])
#define LUX_ARRAY2COPY(dst,src)    ((dst)[0]=(src)[0],(dst)[1]=(src)[1])
#define LUX_ARRAY3COPY(dst,src)    ((dst)[0]=(src)[0],(dst)[1]=(src)[1],(dst)[2]=(src)[2])
#define LUX_ARRAY4COPY(dst,src)    ((dst)[0]=(src)[0],(dst)[1]=(src)[1],(dst)[2]=(src)[2],(dst)[3]=(src)[3])

#define LUX_ARRAY2SET(v2,x,y)      ((v2)[0]=x,(v2)[1]=y)
#define LUX_ARRAY3SET(v3,x,y,z)      ((v3)[0]=x,(v3)[1]=y,(v3)[2]=z)
#define LUX_ARRAY4SET(v4,x,y,z,w)    ((v4)[0]=x,(v4)[1]=y,(v4)[2]=z,(v4)[3]=w)
#define LUX_ARRAY5SET(v5,x,y,z,v,w)    ((v5)[0]=x,(v5)[1]=y,(v5)[2]=z,(v5)[3]=v,(v5)[4]=w)
#define LUX_ARRAY6SET(v6,x,y,z,u,v,w)  ((v6)[0]=x,(v6)[1]=y,(v6)[2]=z,(v6)[3]=u,(v6)[4]=v,(v6)[5]=w)

#define LUX_ARRAY2CLEAR(v2)  ((v2)[0]=(v2)[1]=0)
#define LUX_ARRAY3CLEAR(v3)  ((v3)[0]=(v3)[1]=(v3)[2]=0)
#define LUX_ARRAY4CLEAR(v4)  ((v4)[0]=(v4)[1]=(v4)[2]=(v4)[3]=0)
#define LUX_ARRAY5CLEAR(v5)  ((v5)[0]=(v5)[1]=(v5)[2]=(v5)[3]=(v5)[4]=0)
#define LUX_ARRAY6CLEAR(v6)  ((v6)[0]=(v6)[1]=(v6)[2]=(v6)[3]=(v6)[4]=(v6)[5]=0)

#define LUX_ARRAY2UNPACK(v)    ((v)[0]),((v)[1])
#define LUX_ARRAY3UNPACK(v)    ((v)[0]),((v)[1]),((v)[2])
#define LUX_ARRAY4UNPACK(v)      ((v)[0]),((v)[1]),((v)[2]),((v)[3])
#define LUX_ARRAYUNPACK3(v,off)    ((v)[0+off]),((v)[1+off]),((v)[2+off]),((v)[3+off])
#define LUX_ARRAY3TOVARS(v,x,y,z)  (x = ((v)[0]), y = ((v)[1]), z = ((v)[2]))

#define LUX_ARRAY16COPY(dst, src)   (\
  (dst)[0]  = (src)[0],  (dst)[1]  = (src)[1],  \
  (dst)[2]  = (src)[2],  (dst)[3]  = (src)[3],  \
  (dst)[4]  = (src)[4],  (dst)[5]  = (src)[5],  \
  (dst)[6]  = (src)[6],  (dst)[7]  = (src)[7],  \
  (dst)[8]  = (src)[8],  (dst)[9]  = (src)[9],  \
  (dst)[10] = (src)[10], (dst)[11] = (src)[11], \
  (dst)[12] = (src)[12], (dst)[13] = (src)[13], \
  (dst)[14] = (src)[14], (dst)[15] = (src)[15])

#endif