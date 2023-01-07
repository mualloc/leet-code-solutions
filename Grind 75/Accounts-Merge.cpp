class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, string> emailToName;
        
        for(size_t i = 0; i < accounts.size(); i++){
            const string & account = accounts[i][0];
            for(size_t j = 1; j < accounts[i].size(); j++){
                const string & email = accounts[i][j];
                emailToName[email] = account;
                if(graph.end() == graph.find(email)) { graph.insert(make_pair(email,unordered_set<string>())); }
                if(j != 1){
                    const string & leftEmail = accounts[i][j - 1];
                    graph[email].insert(leftEmail);
                    graph[leftEmail].insert(email);
                }
            }
        }
                
        unordered_set<string> visited;
        for(const auto & it : graph){
            if(visited.end() == visited.find(it.first)){
                vector<string> output;
                dfs(it.first, graph, visited, output);
                sort(output.begin(), output.end());
                output.insert(output.begin(), emailToName[it.first]);
                result.push_back(output);
            }
        }    
        return result;
    }
    
private:
    void dfs(const string & start, unordered_map<string, unordered_set<string>> & graph, unordered_set<string> & visited, vector<string> & output){
        if(visited.end() != visited.find(start)) return;
        visited.insert(start);
        output.push_back(start);
        
        for(const string & neighbour : graph[start]){
            dfs(neighbour, graph, visited, output);            
        }
    }

    /*vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        unordered_map<string, int> emailAccountsIndex;    // email to union-find id
        vector<int> parents(accounts.size());
        for(size_t i = 0; i < accounts.size(); i++) parents[i] = i; 
        
        for(size_t i = 0; i < accounts.size(); i++){
            for(size_t j = 1; j < accounts[i].size(); j++){
                string & email = accounts[i][j];
                if(emailAccountsIndex.end() != emailAccountsIndex.find(email)){
                    unify(i, emailAccountsIndex[email], parents);
                }else{
                    emailAccountsIndex[email] = find(i, parents);  
                }
            }
        }
        
        unordered_map<int, vector<string>> accountIdEmails;
        for(const auto & it : emailAccountsIndex){      
            accountIdEmails[find(it.second, parents)].push_back(it.first);
        }  

        for(const auto & it : accountIdEmails){
            vector<string> emails = it.second;
            emails.push_back("");      // For account name
            sort(emails.begin(), emails.end());
            emails[0] = accounts[it.first][0];      // Place account name
            result.push_back(emails);
        }
        
        return result;
    }
    
    inline void unify(int child, int parent, vector<int> &parents){
        parents[find(child, parents)] = find(parent, parents);
    }
    
    inline int find(int x, vector<int> &parents){
        while(x != parents[x]) { x = parents[x]; }
        return x;
        //if(x != parents[x]) { parents[x] = find(parents[x], parents); }       
        //return parents[x];
    }*/
    
    /*vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        map<string, vector<int>> emailAccountMap;   // email to account indexes
        for(size_t i = 0; i < accounts.size(); i++){
            for(size_t j = 1; j < accounts[i].size(); j++){
                emailAccountMap[accounts[i][j]].push_back(i);
            }
        }  
        
        queue<int> queue;
        vector<bool> visited(accounts.size(), false);
        for(int i = 0; i < accounts.size(); i++){
            if(false == visited[i]){
                queue.push(i);
                visited[i] = true;
                set<string> accountEmails;
                while(false == queue.empty()){
                    int front = queue.front(); queue.pop();
                    const vector<string> & account = accounts[front];
                    for(int j = 1; j < account.size(); j++){
                        accountEmails.insert(account[j]);
                        const string & email = account[j];
                        const vector<int> & accountIndexes = emailAccountMap[email];
                        for(int index : accountIndexes){
                            if(false == visited[index]){
                                visited[index] = true;
                                queue.push(index);
                            }
                        }
                    }  
                }
                std::vector<string> output(accountEmails.size() + 1);
                output[0] = accounts[i][0];
                std::copy(accountEmails.begin(), accountEmails.end(), next(output.begin()));
                result.push_back(output); 
            }
        }
        return result;
    }*/

    /*vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {      
        map<string, vector<int>> emailAccountMap;   // email to account indexes
        for(size_t i = 0; i < accounts.size(); i++){
            for(size_t j = 1; j < accounts[i].size(); j++){
                emailAccountMap[accounts[i][j]].push_back(i);
            }
        }
        
        vector<vector<string>> result;
        vector<bool> visited(accounts.size(), false);
        for(size_t i = 0; i < accounts.size(); i++){
            if(false == visited[i]){
                set<string> accountEmails;
                dfs(i, accounts, visited, emailAccountMap, accountEmails);
                              
                std::vector<string> output(accountEmails.size() + 1);
                output[0] = accounts[i][0];
                std::copy(accountEmails.begin(), accountEmails.end(), next(output.begin()));
                result.push_back(output);
            }          
        } 
        return result;
    }
    
    void dfs(int accountIndex, vector<vector<string>>& accounts, vector<bool> & visited, map<string, vector<int>> &  emailAccountMap, set<string> & result){
        visited[accountIndex] = true;
        
        const vector<string> & account = accounts[accountIndex];
        for(int i = 1; i < account.size(); i++){
            const string & email = account[i];
            result.insert(email);
            for(int commonAccountIndex : emailAccountMap[email]){
                if(false == visited[commonAccountIndex]){
                    dfs(commonAccountIndex, accounts, visited, emailAccountMap, result);
                }
            }
        }
    }*/
};