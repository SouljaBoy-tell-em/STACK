# STACK
Stack is a data-struct, that works according to the rule: First In - Last Out (FILO). This data-struct is comfortable.

1. You can use the Push-function to add a element in the stack and the Pop-function to destroy element from the stack.

2. My realisation of the stack contain the CANARY-PROTECT, that can show, where data weren't protected.
The CANARY is flags of the data or flags of the stack. Data and the stack contains between 2 CANARY. If struct of data will be violated, some (1, 2, 3, 4) CANARYES'll destroy. 

3. STACKDUMP-FILE is file, that records information about the stack. If stack don't violated, status of the stack is OK, ELSE - error. 

4. As a supplement: The HASH function can calculate the hash of the stack. 
