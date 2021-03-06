/*
 *  ccrng.h
 *  corecrypto
 *
 *  Created on 12/13/2010
 *
 *  Copyright (c) 2010,2011,2013,2014,2015 Apple Inc. All rights reserved.
 *
 */

#ifndef _CORECRYPTO_CCRNG_H_
#define _CORECRYPTO_CCRNG_H_

#include <stdint.h>

#define CC_ERR_DEVICE           -100
#define CC_ERR_INTERUPTS        -101
#define CC_ERR_CRYPTO_CONFIG    -102
#define CC_ERR_PERMS            -103
#define CC_ERR_PARAMETER        -104
#define CC_ERR_MEMORY           -105
#define CC_ERR_FILEDESC         -106
#define CC_ERR_OUT_OF_ENTROPY   -107

#define CCRNG_STATE_COMMON                                                          \
    int (*generate)(struct ccrng_state *rng, unsigned long outlen, void *out);

/* default state structure - do not instantiate, instead use the specific one you need */
struct ccrng_state {
    CCRNG_STATE_COMMON
};

#define ccrng_generate(ctx, outlen, out) ((ctx)->generate((ctx), (outlen), (out)))

#endif /* _CORECRYPTO_CCRNG_H_ */
