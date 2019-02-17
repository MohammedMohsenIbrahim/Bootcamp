/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in May 2016
 *
 */
#ifndef AES_SCHEDULE_128_H
#define AES_SCHEDULE_128_H
#include <stdint.h>

#define AES_BLOCK_SIZE      16
#define AES_ROUNDS          10  // 12, 14
// AES-128 has 10 rounds, and there is a AddRoundKey before first round. (10+1)x16=176.
/**
 * @purpose:            Key schedule for AES-128
 * @par[in]key:         16 bytes of master keys
 * @par[out]roundkeys:  176 bytes of round keys
 */
void aes_key_schedule_128( uint8_t *keys,uint8_t *roundkeys);
#endif
