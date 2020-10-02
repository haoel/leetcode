class Solution {
public:
    static bool comp(string a,string b){
        return a.size() < b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int ans = 0;
        int count = 0;
        unordered_map<string,int> M;
        for(int i = 0 ; i < words.size() ; i++){
            string temp = "";
            for(int k = words[i].size() - 1 ; k >= 0 ; k--){
                temp = words[i][k] + temp;
                M[temp]++;
            }
        }
        for(int i = 0 ; i < words.size() ; i++){
            ans = ans + words[i].size();
            count++;
            if(M[words[i]] > 1){
                ans = ans - words[i].size();
                count--;
                M[words[i]]--;
            }
        }
        return ans + count;
    }
};
