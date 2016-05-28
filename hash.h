#define L 512
#define N 256

struct GroestlContext {
    Data[L] ctx_h;
};

typedef unsigned char Data;

void init(GroestlContext*);

void update(GroestlContext*, Data*);

void doFinal(GroestlContext*, Data*);
