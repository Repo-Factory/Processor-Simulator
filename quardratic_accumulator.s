#
# Code to evaluate a quadratic
#

	.text
	
main:
 	LOAD A
    MUL  X
    MUL  X
    STO  A 
    LOAD B
    MUL  X
    STO  B
    LOAD C 
    ADD  A 
    ADD  B 
    STO  X
      
	.data

X:	.word 3
A:	.word 7
B:	.word 5
C:	.word 4
