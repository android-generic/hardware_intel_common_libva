#ifndef _VA_ANDROID_H_
#define _VA_ANDROID_H_

#include <va/va.h>
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Returns a suitable VADisplay for VA API
 */
VADisplay vaGetDisplay (
    void *android_dpy
);

#if ANDROID    
#include <ui/Surface.h>
class Surface;
    
/*
 * Output rendering
 * Following is the rendering interface for X windows, 
 * to get the decode output surface to a X drawable
 * It basically performs a de-interlacing (if needed), 
 * color space conversion and scaling to the destination
 * rectangle
 */
VAStatus vaPutSurface (
    VADisplay dpy,
    VASurfaceID surface,	
    Surface *draw, /* Android Window/Surface */
    short srcx,
    short srcy,
    unsigned short srcw,
    unsigned short srch,
    short destx,
    short desty,
    unsigned short destw,
    unsigned short desth,
    VARectangle *cliprects, /* client supplied destination clip list */
    unsigned int number_cliprects, /* number of clip rects in the clip list */
    unsigned int flags /* PutSurface flags */
);
#endif
    
#ifdef __cplusplus
}
#endif

#endif /* _VA_ANDROID_H_ */
