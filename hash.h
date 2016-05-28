#define L 512
#define LBYTES 64
#define SQRT_LBYTES 8

#define N 256
// Amount of rounds.
#define R 10

struct GroestlContext {
    Data[L] ctx_h;
};

typedef unsigned char Data;

void init(GroestlContext*);

void update(GroestlContext*, Data*);

void doFinal(GroestlContext*, Data*);
