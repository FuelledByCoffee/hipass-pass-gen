#ifndef GENERATOR_H
#define GENERATOR_H

// Generator definition to generate random sequence of characters
// A-Z, a-z, symbols and numbers included.
#include <stdbool.h>
int  generate_random_CLI(bool CH_TYPE[], char *sufix, char *prefix);
void generate_passphrase(char separator);
#endif // GENERATOR_H
