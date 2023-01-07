class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()), head({beginWord}), tail({endWord});
        if(wordSet.end() == wordSet.find(endWord)) return 0;
        
        int result = 2;
        while(false == head.empty() && false == tail.empty()){
            if(head.size() > tail.size()) head.swap(tail);  

            unordered_set<string> temp;
            for (auto it = head.begin(); it != head.end(); it++){
                string word = *it;         
                for(int i = 0; i < word.size(); i++){
                    char t = word[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        word[i] = c;
                        if(tail.end() != tail.find(word)) return result;

                        if(wordSet.end() != wordSet.find(word)){
                            wordSet.erase(word);
                            temp.insert(word);
                        }
                    }
                    word[i] = t;
                }
            }
            head.swap(temp);
            result++;
        }		
        return 0;
    }
};



class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// NOTE: This check is necessary for multi source BFS method!
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;	
		unordered_map<string, vector<string>> wildcardToWordList = createWildcardToWordMap(wordList);
            
        queue<string> queueBegin({beginWord});
        unordered_set<string> visitedBegin({beginWord});
        queue<string> queueEnd({endWord});
        unordered_set<string> visitedEnd({endWord});
            
        int beginPathLength = 1;
        int endPathLength = 1;
        while(false == queueBegin.empty() && false == queueEnd.empty()){
			bool isFound = searchLevel(queueBegin, visitedBegin, queueEnd, visitedEnd, wildcardToWordList);
			if(isFound)  return beginPathLength + endPathLength - 1;
			++beginPathLength;
			isFound = searchLevel(queueEnd, visitedEnd, queueBegin, visitedBegin, wildcardToWordList);
			if(isFound)  return beginPathLength + endPathLength - 1;
			++endPathLength;									
        }
		return 0;
    }
    
	// Time complexity of creating adjacency list wildcardToWordList : 
	// Number of wildcard is: wordList.length * wordList[i].length  *  Inserting wordList[i] to related adjaceny list: wordList[i].length
	// Time complexity of BFS is:
	// Maximum number of edges: O(wordList.length^2)  *  Const of String comparison: wordList[i].length
	// TC: O(wordList[i].length^2 * wordList.length) + O(wordList.length^2 * wordList[i].length)
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;	// Maybe removed!
        unordered_map<string, vector<string>> wildcardToWordList = createWildcardToWordMap(wordList);
        queue<string> queue({beginWord});
        unordered_set<string> visited({beginWord});
        
		int result = 0;
        while(false == queue.empty()){
            int qSize = queue.size();
            ++result;
            while(qSize--){
                const string front = queue.front(); queue.pop();
                if(front == endWord) return result;
                vector<string> neighbours =  getValidLinkedWords(front, wildcardToWordList);
                for(const auto & neighbour : neighbours){
                    if(visited.end() == visited.find(neighbour)){
                        queue.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }           
        }            
        return 0;
    }
    
private:
    // X*X -> XXX, XYX, XWX etc.
    unordered_map<string, vector<string>> createWildcardToWordMap(const vector<string>& wordList){
        unordered_map<string, vector<string>> result;   
        for(const auto & word : wordList){
            vector<string> linked = getWildcardRoots(word);  
            for(const auto & linkedWord : linked){
                result[linkedWord].push_back(word);
            }
        }
        return result;
    }
    
    vector<string> getWildcardRoots(const string & word){
        vector<string> result;
        for(size_t i = 0; i < word.size(); i++){
            string temp = word;
            temp[i] = '*';
            result.push_back(temp);
        }
        return result;
    }
    
    vector<string> getValidLinkedWords(const string & word, unordered_map<string,  vector<string>> & wildcardToWordList){
        vector<string> result;
        vector<string> wildcards = getWildcardRoots(word);
        
        for(const string & wildcard : wildcards){
            const vector<string> & linkedWords = wildcardToWordList[wildcard];
            for(const string & linkedWord : linkedWords){
                if(linkedWord != word) result.push_back(linkedWord);
            }
        }
        
        return result;
    }
	
	int searchLevel(queue<string> & queueBegin, unordered_set<string> & visitedBegin, const queue<string> & queueEnd, const unordered_set<string> & visitedEnd, unordered_map<string, vector<string>> & wildcardToWordList){
	    int qSize = queueBegin.size();
        while(qSize--){
            const string front = queueBegin.front(); queueBegin.pop();
            if(visitedEnd.end() != visitedEnd.find(front)) return true;
            else{
				vector<string> neighbours =  getValidLinkedWords(front, wildcardToWordList);
				for(const auto & neighbour : neighbours){
					if(visitedBegin.end() == visitedBegin.find(neighbour)){
						queueBegin.push(neighbour);
						visitedBegin.insert(neighbour);
					}
				}  
            }
        }
		return false;
	}
};