/*
 * 
 *  File: observer.h
 * 
 */
#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "state.h"

void observer_init(void);

void observer_write(const state_t *s);

void observer_finalize(void);

#endif
