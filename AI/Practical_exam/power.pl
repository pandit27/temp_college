%- base case: X^0 = 1
power(N, 0, A) :-
    A is 1.

% recursive case
power(N, P, A) :-
    P > 0,
    P1 is P - 1,
    power(N, P1, A1),
    A is N * A1.
