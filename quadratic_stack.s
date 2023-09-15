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
    POP  X
    END

	.data

X:	.word 3
A:	.word 7
B:	.word 5
C:	.word 4
