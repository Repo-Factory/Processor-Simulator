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
    STO  ANS
    END
      
	.data

X: 3
A: 7
B: 5
C: 4
ANS: 0