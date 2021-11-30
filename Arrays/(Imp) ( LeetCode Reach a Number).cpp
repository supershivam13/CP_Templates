// Idea to Solve :-
// "Let say in minimum 'n' steps it reaches the target(t) so , at each of his step either he had taken left(-)or right(+)
// So his final location can be represented as:- (- or +)1 + (- or +)2+............(- or +)n
// If we have taken all steps to right then final location is [n*(n+1)/2]
// but lets say to reach the target we want some steps(a,b,c,d.........) in left direction
// So we need to reduce this steps twice from the case in which we will move all steps towards right,that is:-
// [n*(n+1)/2] - 2*(a+b+c+d+e......) = target;
// Now we have,
// 2*(a+b+c+.....) = [n*(n+1)/2] - target
// which means if we get a 'n' for which [n*(n+1)/2] - target is divisble by 2 then in n steps we can reach our target

// So we will iterate all possible 'n'//

class Solution {
public:
    int reachNumber(int target) {

        target = abs(target);
        long long sum;

        for (int i = 0; i < 1000005; i++) {

            sum = ((i + 1) * i) / 2;

            if (sum >= target and (sum - target) % 2 == 0 )
                return i;
        }

        return sum;
    }
};
