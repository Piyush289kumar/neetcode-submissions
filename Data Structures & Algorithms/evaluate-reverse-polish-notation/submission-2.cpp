class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        set<string> hash = {"+","/","-","*"};

        stack <int> st;

        int ans = 0;

        for(auto ch : tokens){

            if(hash.find(ch) != hash.end()){

                int operantA = st.top();
                st.pop();
                
                int operantB = st.top();
                st.pop();                
                
                if(ch == "+"){                    
                    st.push(operantA + operantB);
                }else if(ch == "-"){
                    st.push(operantB - operantA);
                }else if(ch == "*"){
                    st.push(operantA * operantB);
                }else if(ch == "/"){
                    st.push(operantB / operantA);
                }

            }else{
                int en = stoi(ch);
                st.push(en);
            }

        }

        
        return st.top();

    }
};
