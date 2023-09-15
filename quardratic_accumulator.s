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

X: 3
A: 7
B: 5
C: 4
