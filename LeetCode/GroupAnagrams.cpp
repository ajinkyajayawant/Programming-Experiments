class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n_wrds = strs.size();
        vector<vector<string> > ana_grps;
        vector<string> ord_strs;
        
        // Iterate over the words
        // Check if a word is an anagram of any of the first words in the vector
        for(int i=0;i<strs.size();++i){
            bool found_mtch = false;
            string s1(strs[i]);
            sort(s1.begin(),s1.end());            
            
            for(int j=0;j<ana_grps.size() && !found_mtch;++j){
                // Anagram compare ana_grps[j][0] and strs[i]
                // If an anagram and if not already present in ana_grps[j] vector then insert it                
                // Insert characters into the sets                
                // string s2(ana_grps[j][0]);                
                // sort(s2.begin(),s2.end());
                if( s1 == ord_strs[j] ){
                    found_mtch = true;
                    //if(find(ana_grps[j].begin(),ana_grps[j].end(),strs[i])==ana_grps[j].end())
                    ana_grps[j].push_back(strs[i]);                
                }
            }
            if(found_mtch==false){
                vector<string> vs = {strs[i]};
                ana_grps.push_back(vs);
                ord_strs.push_back(s1);
            }
        }
        return ana_grps;        
    }     
};
