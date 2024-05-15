multiply(_, 0, 0).   % Multiplying any number by 0 results in 0
multiply(X, Y, Result) :-
    Y > 0,
    Y1 is Y - 1,
    multiply(X, Y1, Temp),
    Result is Temp + X.
