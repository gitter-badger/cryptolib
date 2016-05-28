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
