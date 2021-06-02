# push_swap

## Compiling
`make` to compile.

`make check` to check if the outcome is right.

`make count` to see the number of instructions used.

`make exe` to execute with random numbers.

or

```
./push_swap 10 23 44 28

```

or

```
ARG="10 23 44 28"

./push_swap $ARG
```

Code	| Action
--------|----------------------------------------------
`sa`	| swaps the 2 top elements of stack a
`sb`	| swaps the 2 top elements of stack b
`ss`	| both `sa` and `sb`
`pa`	| moves the top element of stack b at the top of stack a
`pb`	| moves the top element of stack a at the top of stack b
`ra`	| shifts all elements of stack a from bottom to top
`rb`	| shifts all elements of stack b from bottom to top
`rr`	| both `ra` and `rb`
`rra`	| shifts all elements of stack a from top to bottom
`rrb`	| shifts all elements of stack b from top to bottom
`rrr`	| both `rra` and `rrb`

