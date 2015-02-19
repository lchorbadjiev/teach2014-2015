Tasks
--------


1. Add binary operations MinusOp(-), MulOp(*), DivOp(/).

2. Add unary operation abstract class.

3. Add unary operation NegOp(neg) that negates the top element of the stack.

3 1/2. Add unary operation SqOp(sq) that squares the top element of the stack.

4. Add unary operation natural logarithm LogOp(log) and reverse operation ExpOp(exp).

5. Add operation DupOp(dup) that duplicates the top element of the stack.

6. Add operation SwapOp(swap) that exchanges the top 2 elements of the stack.

7. Add error handling: add throw exception inside operations where neccessary and add exception handling inside Postfix::run()

8. Experiment with adding composite operation (operation of operations). see http://en.wikipedia.org/wiki/Composite_pattern, http://sourcemaking.com/design_patterns/composite
	
9. Add composite operation that calculates (x^2+y^2). The operation should contain list of following operations:
	- sq
	- swap
	- sq
	- +








