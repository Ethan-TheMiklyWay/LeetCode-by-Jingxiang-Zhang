Word Ladder - Hard

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        bool isPresent = false;
        for(string word: wordList){
            if(endWord.compare(word) == 0){ 
                // if end word is present in wordList
                isPresent = true;
            }
            wordSet.insert(word); 
            // Inserting each word in wordSet
        }
        if(isPresent == false){
            // if end word is not present in worrd List
            return 0;
        }
        
        queue<string> q; // declare an queue, for BFS traversal
        q.push(beginWord); // push begin word into our queue
        int depth = 0; 
        // for telling depth of the queue we are exploring
        
        while(q.empty() == false){
           
            depth = depth + 1; 
            // if one level is over increment depth
            int levelSize = q.size(); 
            // number of words present at a level
            while(levelSize--){
                string curr = q.front();
                q.pop();
                // checking for all possible depth word
                for(int i = 0; i < curr.length(); i++) {
                    // for each index
                    string temp = curr; 
                    
                    for(char c = 'a'; c <= 'z'; c++){
                        temp[i] = c;
                        if(curr.compare(temp) == 0) 
                            // skipping the same word
                            continue;
                        if(temp.compare(endWord) == 0) 
                             // if matches with end word
                            return depth + 1;
                        // if present in word set
                        if(wordSet.find(temp) != wordSet.end()) {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
                
            }
            
        }
        
        return 0;
    }
};