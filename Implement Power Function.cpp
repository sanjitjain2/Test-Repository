int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (n==0) return 1 % d;
    long long result=1,temp=x;
    while(n>0){
        if(n%2 == 1){
            result = (result*temp)%d;
            n--;
        }
        else{
            temp = (temp*temp)%d;
            n = n/2;
        }
    }
    if(result<0) result = (result+d)%d;
        
    return result;
}
