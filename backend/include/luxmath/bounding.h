// Copyright (C) 2004-2011 Christoph Kubisch
// This file is part of the "Luxinia Engine".
// For conditions of distribution and use, see copyright notice in LICENSE.txt



#ifndef __LUXMATH_BOUNDING_H__
#define __LUXMATH_BOUNDING_H__

#include <luxmath/basetypes.h>
#include <luxmath/vector3.h>

#ifdef __cplusplus
extern "C"{
#endif


//////////////////////////////////////////////////////////////////////////
// Generic

LUX_API booln lxMinMax_intersectsV(const float selfminmax[6], const float otherminmax[6]);


///////////////////////////////////////////////////////////////////////////////
// BOUNDING VOLUMES

LUX_API void lxBoundingBox_init(lxBoundingBoxPTR bbox);
LUX_API void lxBoundingBox_toCenter(const lxBoundingBoxPTR bbox, lxVector3 center, lxVector3 size);

// copy a bounding volume to another
LUX_API lxBoundingBoxPTR    lxBoundingBox_copy(lxBoundingBoxPTR dst, const lxBoundingBoxPTR src);
LUX_API lxBoundingSpherePTR lxBoundingSphere_copy(lxBoundingSpherePTR dst, const lxBoundingSpherePTR src);


// use min/max
// ------------
// merge two bounding volumes
LUX_API lxBoundingBoxPTR  lxBoundingBox_merge(lxBoundingBoxPTR out, const lxBoundingBoxPTR a, const lxBoundingBoxPTR b);
// returns TRUE if result differs from a
LUX_API booln lxBoundingBox_mergeChange(lxBoundingBoxPTR out, const lxBoundingBoxPTR a, const lxBoundingBoxPTR b);
LUX_API booln lxBoundingSphere_mergeChange(lxBoundingSpherePTR out, const lxBoundingSpherePTR a, const lxBoundingSpherePTR b);

// converts a bounding box to a bounding sphere
LUX_API lxBoundingSpherePTR lxBoundingBox_toSphere(const lxBoundingBoxPTR bbox, lxBoundingSpherePTR sphere);
LUX_API void lxBoundingBox_toSphereV(const lxVector3 min,const lxVector3 max, lxVector3 center, float *radius);

// convert bounding box to capsule
// a capsule along major axis of boundingbox is generated with radius
// of the greater half dimension of the other 2 axis
LUX_API lxBoundingCapsulePTR lxBoundingBox_toCapsule(const lxBoundingBoxPTR bbox,lxBoundingCapsulePTR capsule);

// transforms a bounding box to an axis aligned bounding box
LUX_API lxBoundingBoxPTR lxBoundingBox_transform(lxBoundingBoxPTR out, const lxBoundingBoxPTR in, const lxMatrix44PTR trans);
LUX_API void lxBoundingBox_transformBoxCorners(const lxBoundingBoxPTR in, const lxMatrix44PTR trans, lxVector3 box[8]);
LUX_API void lxBoundingBox_transformV(lxVector3 outmins, lxVector3 outmaxs, const lxVector3 mins, const lxVector3 maxs, const lxMatrix44PTR trans);

LUX_API void lxBoundingBox_fromCorners(lxBoundingBoxPTR bbox,const lxVector3 vecs[8]);
LUX_API void lxBoundingVectors_fromCamera(lxVector3 vecs[8],const lxMatrix44PTR mat,const float fov, const float frontplane, const float backplane, const float aspect);

LUX_API booln lxBoundingBox_intersect(const lxBoundingBoxPTR a,const lxBoundingBoxPTR b);
LUX_API booln lxBoundingBox_checkPoint(const lxBoundingBoxPTR out,const lxVector3 point);
LUX_API booln lxBoundingCone_checkSphereV(const lxBoundingConePTR cone,const lxVector3 center, float radius, float radiusSqr);

// approximates frustum via Sphere & Cone, dir must be normalized
LUX_API void lxBoundingSphereCone_fromCamera(lxBoundingSpherePTR sphere, lxBoundingConePTR cone,float frontplane, float backplane, const lxVector3 pos, const lxVector3 dir, float fov);
LUX_API void lxBoundingCone_fromFrustumCorners(lxBoundingConePTR cone, const lxVector3 box[LUX_FRUSTUM_CORNERS]);
LUX_API void lxBoundingSphere_fromFrustumCorners(lxBoundingSpherePTR sphere,const lxVector3 box[LUX_FRUSTUM_CORNERS]);

//////////////////////////////////////////////////////////////////////////
LUX_INLINE void lxBoundingBox_init(lxBoundingBoxPTR box)
{
  box->min[0] = FLT_MAX;
  box->min[1] = FLT_MAX;
  box->min[2] = FLT_MAX;

  box->max[0] = -FLT_MAX;
  box->max[1] = -FLT_MAX;
  box->max[2] = -FLT_MAX;
}

LUX_INLINE booln lxMinMax_intersectsV(const float selfminmax[6], const float otherminmax[6]){
  return (  
    selfminmax[0] <= otherminmax[3] && 
    selfminmax[1] <= otherminmax[4] &&
    selfminmax[2] <= otherminmax[5] &&
    selfminmax[3] >= otherminmax[0] &&
    selfminmax[4] >= otherminmax[1] &&
    selfminmax[5] >= otherminmax[2] );
}

LUX_INLINE void lxBoundingBox_toCenter(const lxBoundingBoxPTR bbox, lxVector3 center, lxVector3 size)
{
  lxVector3Sub(size,bbox->max, bbox->min);
  center[0] /= 2;
  center[1] /= 2;
  center[2] /= 2;
  lxVector3ScaledAdd(center, bbox->min, 0.5f, size);
}

LUX_INLINE lxBoundingBoxPTR lxBoundingBox_copy(lxBoundingBoxPTR out, const lxBoundingBoxPTR in)
{
  lxVector3Copy(out->max, in->max);
  lxVector3Copy(out->min, in->min);

  return out;
}

LUX_INLINE lxBoundingSpherePTR lxBoundingSphere_copy(lxBoundingSpherePTR out, const lxBoundingSpherePTR in)
{
  lxVector3Copy(out->center, in->center);
  out->radius = in->radius;

  return out;
}

LUX_INLINE lxBoundingBoxPTR  lxBoundingBox_merge(lxBoundingBoxPTR out, const lxBoundingBoxPTR a, const lxBoundingBoxPTR b)
{
  out->min[0] = LUX_MIN(a->min[0], b->min[0]);
  out->min[1] = LUX_MIN(a->min[1], b->min[1]);
  out->min[2] = LUX_MIN(a->min[2], b->min[2]);

  out->max[0] = LUX_MAX(a->max[0], b->max[0]);
  out->max[1] = LUX_MAX(a->max[1], b->max[1]);
  out->max[2] = LUX_MAX(a->max[2], b->max[2]);

  return out;
}

LUX_INLINE booln lxBoundingBox_intersect(const lxBoundingBoxPTR a,const lxBoundingBoxPTR b)
{
  return !( (a)->min[0]>(b)->max[0] || (a)->min[1]>(b)->max[1] ||
    (a)->min[2]>(b)->max[2] || (a)->max[0]<(b)->min[0] ||
    (a)->max[1]<(b)->min[1] || (a)->max[2]<(b)->min[2]  );
}

LUX_INLINE booln lxBoundingBox_checkPoint(const lxBoundingBoxPTR out, const lxVector3 pt){
  if (pt[0] < out->min[0] || pt[0] > out->max[0] ||
    pt[1] < out->min[1] || pt[1] > out->max[1] ||
    pt[2] < out->min[2] || pt[2] > out->max[2])
    return LUX_FALSE;
  return LUX_TRUE;
}

#ifdef __cplusplus
}
#endif

#endif

