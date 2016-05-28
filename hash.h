#define L 512
#define LBYTES 64
#define SQRT_LBYTES 8

#define N 256
// Amount of rounds.
#define R 10

struct GroestlContext {
    Data[L] ctx_h;
    Data[L] ctx_buf;
    size_t ctx_buf_p;
    size_t ctx_last_byte_size;
    size_t ctx_block_count;
};

typedef unsigned char Data;

typedef Data[SQRT_LBYTES][SQRT_LBYTES] Matrix;

void init(GroestlContext*);

void update(GroestlContext*, const Data*);

void doFinal(GroestlContext*, const Data*, size_t len);
