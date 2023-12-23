#ifndef BITMATH_H
#define BITMATH_H

#define SET_BIT(x, n) x = x | (1<<n)
#define GET_BIT(x, n) ((x & (1 << n)) >> n) 
#define CLEAR_BIT(x, n) x = x & (~(1<<n))
#define TOGGLE_BIT(x, n) x = x ^ (1<<n)

#endif




