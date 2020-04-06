#ifndef VM_H

#define VM_H

#include "memory.h"

// Offsets to read an instruction.
#define FROM_ADDRESS_HIGH_OFFSET 0
#define FROM_ADDRESS_MIDDLE_OFFSET 1
#define FROM_ADDRESS_LOW_OFFSET 2

#define TO_ADDRESS_HIGH_OFFSET 3
#define TO_ADDRESS_MIDDLE_OFFSET 4
#define TO_ADDRESS_LOW_OFFSET 5

#define JUMP_ADDRESS_HIGH_OFFSET 6
#define JUMP_ADDRESS_MIDDLE_OFFSET 7
#define JUMP_ADDRESS_LOW_OFFSET 8

#define NULL_VM (struct virtual_machine *) NULL

enum vm_status { VIRTUAL_MACHINE_RUN, VIRTUAL_MACHINE_STOP };

struct virtual_machine{
    WORD *memory;
    WORD *pc;
    enum vm_status status;
};

/**
 * Loads the program counter stored in vm's memory into pc field of the vm
 * structure.
 */
int load_pc(struct virtual_machine *vm);

/**
 * Creates a new virtual machine structure with uninitialized memory.
 */
struct virtual_machine* new_vm();

/**
 * Creates a new virtual machine structure with the memory provided as argument.
 */
struct virtual_machine* new_vm_with_memory(WORD *memory);

/**
 * Frees the virtual machine provided as argument.
 */
void free_vm(struct virtual_machine *vm);

/**
 * Lookup the primitive corresponding to the id stored at address
 * PRIMITIVE_CALL_ID_ADDRESS in memory and executes it.
 * 
 * After execution, overwrite value at PRIMITIVE_CALL_ID_ADDRESS in memory and
 * write PRIMITIVE_ID_NOPE instead.
 */
int execute_primitive(struct virtual_machine *vm);

int execute_instruction(struct virtual_machine *vm);

void print_pc_address(WORD *memory, WORD *pc);

void print_value_at_address(WORD *memory, unsigned int address);

#endif