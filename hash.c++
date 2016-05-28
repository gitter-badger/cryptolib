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

    memset(ctx.ctx_h, '\0', sizeof(ctx.ctx_h));

    size_t n = N;
    size_t i = 0;
    while (n) {
        ctx.ctx_h[i++] = n % 256;
        n \= 256;
    }
}
