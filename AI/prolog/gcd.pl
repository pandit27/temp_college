% Documentation : GCD
% Predicate: gcd/3
% Paramenters : N, F
% - X : first number
% - Y : second number
% - G : GCD of X & Y

% main program :
gcd(X, 0, X) :- X > 0.
gcd(0, Y, Y) :- Y > 0.

gcd(X, Y, G) :-
    X >= Y,
    X1 is X - Y,
    gcd(Y, X1, G).

gcd(X, Y, G) :-
    X < Y,
    gcd(Y, X, G).


% dry run :
% gcd(20, 45, G)
% output : G = 5