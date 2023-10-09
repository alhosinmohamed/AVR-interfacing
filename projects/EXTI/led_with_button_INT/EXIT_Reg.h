/*****************************************************/
/* Author      : alhosin                             */
/* date        : 15/09/2023                          */
/*****************************************************/
#ifndef EXIT_REG_H
#define EXIT_REG_H

#define MCUCR  (*((volatile u8 *) 0x55))
#define MCUCSR (*((volatile u8 *) 0x54))
#define GICR   (*((volatile u8 *) 0x5B))
#define GIFR   (*((volatile u8 *) 0x5A))
#define SREG   (*((volatile u8 *) 0x5F))

#endif
