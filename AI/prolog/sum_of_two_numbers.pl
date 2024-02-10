% Documentation : sum of two numbers
% Predicate: calculate_sum/3
% Paramenters : _num1, _num2, _sum
% - _num1 : first number (will take as input)
% - _num2 : second number (will take as input)
% - _sum : we'll store the sum in this variable

% main program :
calculate_sum(_num1, _num2, _sum) :-
    _sum is _num1 + _num2.

% dry run :
% calculate_sum(4, 5, _sum)
% output : _sum = 9