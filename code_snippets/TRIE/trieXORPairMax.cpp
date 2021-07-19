// https://binarysearch.com/problems/Max-XOR-of-Two-Integers/
// https://www.youtube.com/watch?v=MyiHeqtwOWQ&t=3244s

class TrieNode{
    public : 
        TrieNode* zero;
        TrieNode* one;
        int eof;
        TrieNode(){
            zero = one = nullptr;
            eof = 0;
        }
};
TrieNode* head;

void insert(string s){
    TrieNode* root = head;
    for(int i = 0 ; i < s.size(); ++i){
        if(s[i]=='0' && root->zero==NULL)root->zero = new TrieNode();
        if(s[i]=='1' && root->one==NULL)root->one = new TrieNode();
        if(s[i]=='0')root = root->zero;
        if(s[i]=='1')root = root->one;
    }
    root->eof++;
}

string getBinary(int n){
    string ans = "";
    while(n>0){
        ans.push_back(n%2 + '0');
        n/=2;
    }
    while(ans.size()<31)ans.push_back('0');
    reverse(ans.begin(),ans.end());
    return ans;
}

int solve(vector<int>& nums) {
    head = new TrieNode();
    int n = nums.size();
    int ans = 0;
    for(auto & x : nums)insert(getBinary(x));
    for(auto & x : nums){
        int y = 0;
        TrieNode* root = head;
        for(int j = 30 ; j>=0 ; --j){
            if(x&(1<<j)){
                // we need zero
                if(root->zero!=NULL){
                    root = root->zero;
                    y = (y<<1);
                }
                else{
                    root = root->one;
                    y = (y<<1) + 1;
                }
            }
            else{
                // we need one 
                if(root->one!=NULL){
                    root = root->one;
                    y = (y<<1) + 1;
                }
                else{
                    root = root->zero;
                    y = (y<<1);
                }
            }
        }
        ans = max(ans,x^y);
    }
    return ans;
}