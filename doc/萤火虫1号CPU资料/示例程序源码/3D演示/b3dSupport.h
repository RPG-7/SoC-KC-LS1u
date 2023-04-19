#ifndef __B3L_SUPPORT_H__
#define __B3L_SUPPORT_H__
#include <stdint.h>
#include "b3dlib.h"




typedef enum {
      STOPPED, 
      RUNNING, 
      PAUSED,
      FINISHED
    }B3L_timeState_e;

typedef struct b3L_TIMER{
    struct b3L_TIMER *next; 
    struct b3L_TIMER *prev; 
    B3L_timeState_e  state;   
    void (*TimerCallback)(struct b3L_TIMER *timer); 
    u32              duration;                  // how many milliseconds between callbacks
    u32              started;                   // system time when timer started in milliseconds
    s32              loop_count;
    s32              loops;                     // number of times to repeat timer (-1 == forever)
                     
}B3L_timer_t;  //28byte in ARM32  40byte in WIN64
typedef void (*B3L_TimerCallback)(B3L_timer_t *timer);

typedef struct b3L_TWEEN{
    struct b3L_TWEEN *next; 
    struct b3L_TWEEN *prev;   
    B3L_timeState_e  state; 
    f32 (*TweenCallback)(u32 t, float b, float c, u32 d);
    u32              duration;                  // how many milliseconds between callbacks
    s32              loop_count;
    u32              started;                   // system time when timer started in milliseconds
    s32              loops;                     // number of times to repeat timer (-1 == forever)    
    f32              from;
    f32              to;
    f32              value;                
}B3L_tween_t;  //40byte in ARM32  52byte in WIN64

typedef f32 (*B3L_TweenCallback)(u32 t, float b, float c, u32 d);

typedef struct{
    u16  timerNum;
    u16  tweenNum;
    B3L_timer_t *pFirstTimer;
    B3L_tween_t *pFirstTween;
}B3L_timeTweenCtl_t;
//call by update function
extern void B3L_TimerTweenUpdate(B3L_timeTweenCtl_t *pCtl,u32 time);
extern void B3L_TimerTweenCtlInit(B3L_timeTweenCtl_t *pCtl);

extern void B3L_TimerInit(B3L_timeTweenCtl_t *pCtl,B3L_timer_t *pTimer,B3L_TimerCallback callback, u32 duration, s32 loops);
extern void B3L_TimerStart(B3L_timer_t *pTimer,u32 time);
extern void B3L_TimerStop(B3L_timer_t *pTimer);
extern bool B3L_TimerIsRunning(B3L_timer_t *pTimer);   
extern bool B3L_TimerIsPaused(B3L_timer_t *pTimer);   
extern bool B3L_TimerIsStopped(B3L_timer_t *pTimer);   
extern bool B3L_TimerIsFinished(B3L_timer_t *pTimer); 

extern void B3L_TweenInit(B3L_timeTweenCtl_t *pCtl,B3L_tween_t *pTween,B3L_TweenCallback callback, f32 start, f32 end, u32 duration, s32 loops);
extern void B3L_TweenStart(B3L_tween_t *pTween,u32 time);
extern void B3L_TweenStop(B3L_tween_t *pTween);
extern bool B3L_TweenIsRunning(B3L_tween_t *pTween);   
extern bool B3L_TweenIsPaused(B3L_tween_t *pTween);   
extern bool B3L_TweenIsStopped(B3L_tween_t *pTween);   
extern bool B3L_TweenIsFinished(B3L_tween_t *pTween); 
extern f32 B3L_tween_sine(uint32_t t, float b, float c, uint32_t d);//->
extern f32 B3L_tween_linear(uint32_t t, float b, float c, uint32_t d);//->
extern f32 B3L_tween_ease_in_quad(uint32_t t, float b, float c, uint32_t d);//->
extern f32 B3L_tween_ease_out_quad(uint32_t t, float b, float c, uint32_t d);//->
extern f32 B3L_tween_ease_in_out_quad(uint32_t t, float b, float c, uint32_t d);//<->
extern f32 B3L_tween_linear_return(uint32_t t, float b, float c, uint32_t d);//<->
extern f32 B3L_tween_sine_return(uint32_t t, float b, float c, uint32_t d);//<->
#endif