#include <string.h>

#include "hash.h"


static void add_padding(Data *);

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
}

void update(GroestlContext *ctx, Data *data) {
    Data[L] P, Q;
    transform(data, P);
    transform(data, Q);

    for (size_t i = 0; i < sizeof(ctx->ctx_h); ++i) {
        ctx->ctx_h[i] ^= P[i] ^ Q[i];
    }
}

void transform(Data *data, Data[L] buf) {

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
             data[i * sizeof(buffer*) + j] = buffer[j][i];
        }
    }
}
