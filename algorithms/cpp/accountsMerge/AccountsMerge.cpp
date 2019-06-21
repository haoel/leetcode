// Source : https://leetcode.com/problems/accounts-merge/
// Author : Hao Chen
// Date   : 2019-03-29

/***************************************************************************************************** 
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where the first element 
 * accounts[i][0] is a name, and the rest of the elements are emails representing emails of the 
 * account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong to the same person if 
 * there is some email that is common to both accounts.  Note that even if two accounts have the same 
 * name, they may belong to different people as people could have the same name.  A person can have 
 * any number of accounts initially, but all of their accounts definitely have the same name.
 * 
 * After merging the accounts, return the accounts in the following format: the first element of each 
 * account is the name, and the rest of the elements are emails in sorted order.  The accounts 
 * themselves can be returned in any order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], 
 * ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", 
 * "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
 * 
 * Explanation: 
 * The first and third John's are the same person as they have the common email "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email addresses are used by other 
 * accounts.
 *
 * We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], 
 * ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 ******************************************************************************************************/


//Bad Performance Solution
class Solution_Time_Limit_Exceeded {
public:
    // We can orginze all relevant emails to a chain,
    // then we can use Union Find algorithm
    // Besides, we also need to map the relationship between name and email.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emails_chains; // email chains
        unordered_map<string, string> names; // names to email chains' head

        //initialization
        for(int i = 0 ; i<accounts.size();i++) {
            auto& account = accounts[i];
            auto& name = account[0];
            for (int j=1; j<account.size(); j++) {
                auto& email = account[j];
                if ( names.find(email) == names.end() ) {
                    emails_chains[email] = email;
                    names[email] = name;
                }
                join(emails_chains, account[1], email);
            }
        }

        //reform the emails
        unordered_map<string, set<string>> res;
        for( auto& acc : accounts ) {
            string e = find(emails_chains, acc[1]);
            res[e].insert(acc.begin()+1, acc.end());
        }

        //output the result
        vector<vector<string>> result;
        for (auto pair : res) {
            vector<string> emails(pair.second.begin(), pair.second.end());
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }
        return result;
    }

    string find(unordered_map<string, string>& emails_chains,
                string email) {
        while( email != emails_chains[email] ){
            email = emails_chains[email];
        }
        return email;
    }

    bool join(unordered_map<string, string>& emails_chains,
              string& email1, string& email2) {
        string e1 = find(emails_chains, email1);
        string e2 = find(emails_chains, email2);
        if ( e1 != e2 )  emails_chains[e1] = email2;
        return e1 == e2;
    }
};

//
// Performance Tunning
// -----------------
//
// The above algorithm need to do string comparison, it causes lots of efforts
// So, we allocated the ID for each email, and compare the ID would save the time.
//
// Furthermore, we can use the Group-Email-ID instead of email ID,
// this would save more time.
//
class Solution {
public:
    // We can orginze all relevant emails to a chain,
    // then we can use Union Find algorithm
    // Besides, we also need to map the relationship between name and email.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emails_id; //using email ID for union find
        unordered_map<int, int> emails_chains; // email chains
        unordered_map<int, string> names; // email id & name

        //initialization & join
        for(int i = 0 ; i<accounts.size();i++) {

            // using the account index as the emails group ID,
            // this could simplify the emails chain.
            emails_chains[i] = i;

            auto& account = accounts[i];
            auto& name = account[0];
            for (int j=1; j<account.size(); j++) {
                auto& email = account[j];
                if ( emails_id.find(email) == emails_id.end() ) {
                    emails_id[email] = i;
                    names[i] = name;
                }else {
                    join( emails_chains, i, emails_id[email] );
                }

            }
        }

        //reform the emails
        unordered_map<int, set<string>> res;
        for(int i=0; i<accounts.size(); i++) {
            int idx = find(emails_chains, i);
            res[idx].insert(accounts[i].begin()+1, accounts[i].end());
        }


        //output the result
        vector<vector<string>> result;
        for (auto pair : res) {
            vector<string> emails( pair.second.begin(), pair.second.end() );
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }
        return result;
    }

    int find(unordered_map<int, int>& emails_chains, int id) {
        while( id != emails_chains[id] ){
            id = emails_chains[id];
        }
        return id;
    }

    bool join(unordered_map<int, int>& emails_chains, int id1, int id2) {
        int e1 = find(emails_chains, id1);
        int e2 = find(emails_chains, id2);
        if ( e1 != e2 )  emails_chains[e1] = e2;
        return e1 == e2;
    }
};
