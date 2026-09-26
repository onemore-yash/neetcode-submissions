class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int temp=x;
        int i=0;
        while(temp){
            int cur=temp%10;
            if(ans<INT_MIN/10 || ans>INT_MAX/10){
                return 0;
            }else if((ans==INT_MAX/10 && cur>INT_MAX%10)||(ans==INT_MIN/10 && cur<INT_MIN%10)){
                return 0;
            }
            else{
                ans=ans*10+cur;
            }
            temp=temp/10;
            i++;
        }
        return ans;
    }
};
