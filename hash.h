struct GroestlContext {

};

typedef unsigned char Data;

void init(GroestlContext*);

void update(GroestlContext*, Data*);

void doFinal(GroestlContext*, Data*);
