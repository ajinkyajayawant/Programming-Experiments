class Solution {
public:
    int strStr(string haystack, string needle) {
        bool isempt = false;
        bool got = false;
        int pos = -1;
        int nl = needle.length();
        
        string::const_iterator ph = haystack.begin(), pn = needle.begin();
        
        if(nl==0){
            pos = 0;
            isempt = true;
        }
        
        int k=0;
        string::const_iterator ph1 = ph;
        while(ph1!=haystack.end() && !isempt && !got){
            bool streq = true;
            if(*ph1 == *pn){                
                string::const_iterator pn1 = needle.begin();
                for(string::const_iterator ph2 = ph1;ph2!=haystack.end() && pn1!=needle.end() && streq;++ph2){
                    if(*ph2 != *pn1)
                        streq = false;
                    ++pn1;
                }           
                    
                if(streq == true && pn1==needle.end()){
                    got = true;
                    pos = k;
                }                    
            }
            ++ph1; ++k;
        }
        return pos;
    }
};
