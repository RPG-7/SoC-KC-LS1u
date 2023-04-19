//A C version of 32blit tween timer engine
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "b3dSupport.h"


void B3L_TimerTweenUpdate(B3L_timeTweenCtl_t *pCtl,u32 time){
    s32 timerNum = pCtl->timerNum ;
    s32 tweenNum = pCtl->tweenNum ;
    B3L_tween_t *pCurtTween = pCtl->pFirstTween;
    B3L_timer_t *pCurtTimer = pCtl->pFirstTimer;
    while(tweenNum --){
        //process all the tween
        if (pCurtTween->state == RUNNING){
            u32 elapsed = time - pCurtTween->started;
            pCurtTween->value = pCurtTween->TweenCallback(elapsed, pCurtTween->from, pCurtTween->to, pCurtTween->duration);
            if (elapsed >= pCurtTween->duration) {
                if(pCurtTween->loops != -1){
                    pCurtTween->loop_count++;               
                    if (pCurtTween->loop_count == pCurtTween->loops){
                        pCurtTween->state = FINISHED;
                    }
                }
                pCurtTween->started = time;
            }
        }
        pCurtTween = pCurtTween->next;
    }
    while(timerNum --){
        //process all the time callback
        if (pCurtTimer->state == RUNNING){
            u32 elapsed = time - pCurtTimer->started;
            if (elapsed>=pCurtTimer->duration){
                pCurtTimer->TimerCallback(pCurtTimer);
                if(pCurtTimer->loops != -1){
                    pCurtTimer->loop_count++;  
                    if (pCurtTimer->loop_count == pCurtTimer->loops){
                        pCurtTimer->state = FINISHED;
                    }
                }
                pCurtTimer->started = time;
            }
        }
        pCurtTimer = pCurtTimer ->next;
    }
}

void B3L_TimerTweenCtlInit(B3L_timeTweenCtl_t *pCtl){
    pCtl->timerNum =0;
    pCtl->tweenNum =0;
    pCtl->pFirstTween = (B3L_tween_t *)NULL;
    pCtl->pFirstTimer = (B3L_timer_t *)NULL;
}

void B3L_TimerInit(B3L_timeTweenCtl_t *pCtl,B3L_timer_t *pTimer,
                   B3L_TimerCallback callback, u32 duration, s32 loops){
    pTimer->TimerCallback = callback;
    pTimer->duration = duration;
    pTimer->loops = loops;
    pTimer->state = STOPPED;

    pTimer->prev = pTimer; 
    if (pCtl->timerNum++){ //if it is zero        
        pTimer->next = pCtl->pFirstTimer;  
        pCtl->pFirstTimer->prev = pTimer;       
        pCtl->pFirstTimer = pTimer;               
    }else{ 
        pCtl->pFirstTimer =pTimer;
        pTimer->next = (B3L_timer_t *)NULL;  
    }

}

void B3L_TimerStart(B3L_timer_t *pTimer,u32 time){
    pTimer->state = RUNNING;
    pTimer->started = time;
}
void B3L_TimerStop(B3L_timer_t *pTimer){
     pTimer->state = STOPPED;
}
bool B3L_TimerIsRunning(B3L_timer_t *pTimer){
    return pTimer->state == RUNNING;
}   
bool B3L_TimerIsPaused(B3L_timer_t *pTimer){
    return pTimer->state == PAUSED;
}  
bool B3L_TimerIsStopped(B3L_timer_t *pTimer){
    return pTimer->state == STOPPED;
} 
bool B3L_TimerIsFinished(B3L_timer_t *pTimer){
    return pTimer->state == FINISHED;
} 

void B3L_TweenInit(B3L_timeTweenCtl_t *pCtl,B3L_tween_t *pTween,
                   B3L_TweenCallback callback, f32 start, f32 end, u32 duration, s32 loops){
    pTween->loops = loops;
    pTween->TweenCallback = callback;
    pTween->from = start;
    pTween->to = end;
    pTween->duration = duration;
    pTween->loop_count = -1;
    pTween->TweenCallback = callback;
    pTween->state = STOPPED;
    
    if (pCtl->tweenNum++){ //if it is zero
        pTween->prev = pTween;  
        pTween->next = pCtl->pFirstTween;  
        pCtl->pFirstTween->prev = pTween;       
        pCtl->pFirstTween = pTween;               
    }else{ 
        pCtl->pFirstTween = pTween;
        pTween->prev = pTween;
        pTween->next = (B3L_tween_t *)NULL;              
    }
     
}
void B3L_TweenStart(B3L_tween_t *pTween,u32 time){
    pTween->started = time;
    pTween->loop_count = 0;
    pTween->state = RUNNING;
}
void B3L_TweenStop(B3L_tween_t *pTween){
    pTween->state = STOPPED;
}
bool B3L_TweenIsRunning(B3L_tween_t *pTween){
    return (pTween->state == RUNNING);
}   
bool B3L_TweenIsPaused(B3L_tween_t *pTween){
    return (pTween->state == PAUSED);
}  
bool B3L_TweenIsStopped(B3L_tween_t *pTween){
    return (pTween->state == STOPPED);
}  
bool B3L_TweenIsFinished(B3L_tween_t *pTween){
    return (pTween->state == FINISHED);
}
f32 B3L_tween_sine(uint32_t t, float b, float c, uint32_t d){
    f32 ft = ((f32)t) / ((f32)d);
    return b + (B3L_sin(ft*0.5f - 0.25f) + 1.0f) *0.5f * (c - b);  
}
f32 B3L_tween_linear(uint32_t t, float b, float c, uint32_t d){
    f32 ft = ((f32)t) / ((f32)d);
    return (c-b) * ft + b;
}
f32 B3L_tween_ease_in_quad(uint32_t t, float b, float c, uint32_t d){
    f32 ft = ((f32)t) / ((f32)d);
    return (c-b) * ft * (2.0f - ft) + b;
}
f32 B3L_tween_ease_out_quad(uint32_t t, float b, float c, uint32_t d){
    f32 ft = ((f32)t) / ((f32)d);
    return (c-b) * ft * ft + b;
}
f32 B3L_tween_ease_in_out_quad(uint32_t t, float b, float c, uint32_t d){
    f32 ft = (((f32)t) / ((f32)d)) *2.0f;
    if (ft < 1.0f) return (c-b)* (2.0f - ft) * ft + b;
    ft -=1.0f;
    return (c-b)*(1.0f-ft) *(1.0f-ft) + b;
}

extern f32 B3L_tween_linear_return(uint32_t t, float b, float c, uint32_t d){
    f32 ft = (((f32)t) / ((f32)d)) *2.0f;
    if (ft<1.0f) return (c-b)*ft+b;
    ft -= 1.0f;
    return (c-b)*(1.0f-ft)+b;
}

extern f32 B3L_tween_sine_return(uint32_t t, float b, float c, uint32_t d){
    f32 ft = ((f32)t) / ((f32)d);
    return b + (B3L_sin(ft - 0.25f) + 1.0f) *0.5f * (c - b);  
}