#
# Code to evaluate a quadratic
#

	.text
	
main:
 	PUSH C
    PUSH B
    PUSH X
    MUL 
    PUSH X
    PUSH X
    MUL 
    PUSH A
    MUL
    ADD 
    ADD  
    POP ANS
    END

	.data

X: 3
A: 7
B: 5
C: 4
ANS: 0