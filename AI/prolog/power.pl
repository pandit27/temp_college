% Documentation : Num to the power Pow
% Predicate: power/3
% Paramenters : Num, Pow, Ans
% - Num : number
% - Pow : power
% - Ans : Num to the power Pow

% main program :
power(Num, Pow, Ans) :-
    Ans is Num ^ Pow.

% dry run :
% power(2, 3, Ans)
% output : Ans = 8