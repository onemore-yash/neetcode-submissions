class Solution {

public:
    bool checkValidString(string s) {
         int n=s.size();
        int minOpen=0;
        int maxOpen=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                minOpen++;
                maxOpen++;
            }else if(s[i]==')'){
                minOpen--;
                maxOpen--;
            }else{
                minOpen--;
                maxOpen++;
            }

            if(maxOpen<0){
                return false;
            }
            minOpen=max(minOpen,0);
        }

        if(minOpen==0){
            return true;
        }
        return false;
        
    }
};
