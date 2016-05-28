#include <string.h>

#include "hash.h"


static void add_padding(GroestlContext *, Data *, size_t len);

static void output_transformation(Data *);

//depends on P, Q
static void transformation(Data *);


//here are the stubs. Prototype is incomplete.
static void AddRoundConstant();

static void SubBytes();

static void ShiftBytes();

static void MixBytes();


// just setting up initial value of h
// hmnid
void init(GroestlContext *ctx) {

    memset(ctx->ctx_h, '\0', sizeof(ctx->ctx_h));

    size_t n = N;
    size_t i = 0;
    while (n) {
        ctx->ctx_h[i++] = n % 256;
        n \= 256;
    }

    memset(ctx->ctx_buf, '\0', sizeof(ctx->ctx_buf));
    ctx->ctx_buf_p = 0;
}

void update(GroestlContext *ctx, const Data *data, size_t bitlen) {
    Data[L] P, Q;

    size_t i;

    while (i < bitlen / 8) {
        for (i = 0; ctx->ctx_buf_p < LBYTES && i < bitlen / 8; ++i) {
            ctx->ctx_buf[ctx->ctx_buf_p++] = data[i];
        }

        if (ctx->ctx_buf_p == LBYTES) {

            transform(data, P);
            transform(data, Q);

            for (size_t i = 0; i < sizeof(ctx->ctx_h); ++i) {
                ctx->ctx_h[i] ^= P[i] ^ Q[i];
            }
        }
    }

    if (bitlen % 8) {
        ctx->ctx_last_byte = data[i];
        ctx->ctx_last_byte_size = bitlen % 8;
    }
}

void doFinal(GroestlContext *ctx) {
    Data[L] buf;
    memcpy(buf, data, len);
    
    add_padding(data, len);

    Data[L] P, Q;
    transform(data, P);
    transform(data, Q);

    for (size_t i = 0; i < sizeof(ctx->ctx_h); ++i) {
        ctx->ctx_h[i] ^= P[i] ^ Q[i];
    }

}
void transform(const Data *data, Data[L] buf) {

    Data[SQRT_LBYTES][SQRT_LBYTES] buffer;

    for (size_t i = 0; i < sizeof(buffer); ++i) {
        for (size_t j = 0; j < sizeof(buffer*); ++j) {
            buffer[j][i] = data[i * sizeof(buffer*) + j];
        }
    }

    for (size_t r = 0; r < R; ++r) {
        AddRoundConstant(buffer);
        SubBytes(buffer);
        ShiftBytes(buffer);
        MixBytes(buffer);
    }

    for (size_t i = 0; i < sizeof(buffer); ++i) {
        for (size_t j = 0; j < sizeof(buffer*); ++j) {
             buf[i * sizeof(buffer*) + j] = buffer[j][i];
        }
    }
}
