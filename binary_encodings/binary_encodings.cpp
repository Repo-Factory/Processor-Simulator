/* 
 * 
 *
 * It should be noted that having ASCII-encoded instructions in memory is not realistic. Even in case when very large semiconductor memories are
available, one of the key problems is that memory cycle times are much slower than CPU cycle times - and getting slower (in relative terms). One
way to solve this problem is to encode instructions and data as densely as possible - so that means we need dense, binary encodings for the instruction
sets of both simulated machines.
We've only been using five instructions, so you could potentially use a 3-bit opcode. In order to have an apples-to-apples comparison with the code
density of the MIPS ISA, I'll add one "extraneous" condition: your instruction set encoding must be able to accommodate 140 instructions. Other than
that, the conditions your encodings must satisfy are:
1. Addresses in main memory are 32-bit quantities. That means any address fields in your instructions must be 32 bits long, unless you can find
some other way to specify a reasonable range of addresses (at minimum, you must be able to get to the base addresses of all five regions in the
MIPS memory model: user text, kernel text, user data, kernel data and the stack).
2. You must invent one new instruction for each architecture that manages an immediate value, either pushing it onto the top of the stack in the
stack-based machine, or loading it into the accumulator of the accumulator-based machine.
There is no programming in this part of the lab assignment. Your task is to invent separate binary encodings for the stack-based and accumulator-
based machines. Then you have to write your quadratic evaluators in binary (please use hexadecimal notation though!). Finally, record the number of
bytes required for your programs (both code and data) and compare that to the size of the MIPS program (not including the trap handler, of course)
 */

/* To accomodate 140 instructions we need 8 bits */

/* 8 bit opcode, 24 bit immediate value */
