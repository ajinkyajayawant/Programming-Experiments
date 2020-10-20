class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int nv = strs.size();
        int j = 0;
        bool same = true;
        char tch;
        string prf;
        string bgn;
        
        if(nv>0)
            bgn = strs[0];
        else
            same = false;
        
        while(same && j<bgn.length()){            
            tch = bgn[j];            
            for(int i=0;i<nv && same;++i){
                string str = strs[i];
                if(str[j]!=tch){
                    same = false;
                    --j;//last correct value of j
                }                    
            }
            ++j;
        }
        prf = bgn.substr(0,j);
        return prf;
    }
};
