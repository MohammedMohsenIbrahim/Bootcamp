/*
 * common_macros.h
 *
 * Created: 2/13/2019 10:55:20 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef BitwiseOperations_H_
#define BitwiseOperations_H_

#define Set_Bit(REG,BIT)	(REG |= (1<<BIT))
#define Clear_Bit(REG,BIT)	(REG &= (~(1<<BIT)))
#define Toggle_Bit(REG,BIT) (REG ^= (1<<BIT))
#define Get_Bit(REG,BIT)    ((REG & (1<<BIT)) >> (BIT))


#endif /* BitwiseOperations_H_ */