#ifndef PRIMITIVES_H

#define PRIMITIVES_H

#include "memory.h"
#include "vm.h"

#define PRIMITIVE_ID_NOPE 0
#define PRIMITIVE_ID_FAIL 1
#define PRIMITIVE_ID_PUT_CHAR 2

#define PRIMITIVE_OK_RESULT_CODE 0
#define PRIMITIVE_FAILED_RESULT_CODE 1

#define PRIMITIVE_NOT_READY 0
#define PRIMITIVE_READY 1

/**
 * A primitive that always fails.
 * Writes the PRIMITIVE_FAILED_RESULT_CODE at PRIMITIVE_RESULT_CODE_ADDRESS.
 */
void primitive_fail(struct virtual_machine *vm);

/**
 * A primitive that does nothing.
 */
void primitive_nop(struct virtual_machine *vm);

void primitive_get_char(struct virtual_machine *vm);

void primitive_put_char(struct virtual_machine *vm);

void primitive_save_snapshot(struct virtual_machine *vm);

/**
 * Stops virtual machine execution.
 */
void primitive_stop(struct virtual_machine *vm);

#endif