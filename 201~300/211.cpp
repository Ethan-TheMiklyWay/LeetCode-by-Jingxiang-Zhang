Design Add and Search Words Data Structure - Medium

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

struct word_tree{
    vector<char> word;  // word character
    vector<word_tree*> child;  // node to link the child tree
    vector<bool> finish;  // whether a word tree finished here
};



class WordDictionary {
public:
    word_tree* tree_root;
    
    WordDictionary() {
        tree_root = new word_tree();
    }
    
    void addWord(string word) {
        word_tree* temp = tree_root;
        for(int i=0;i<word.length();i++){  // walk throuth the word
            char c = word[i];
            int j=0;
            
            while(j<temp->word.size()){  // trying to find tree node
                if(c==temp->word[j])
                    break;
                j++;
            }
            
            if(j>=temp->word.size()){  // no tree node, then add a new one
                word_tree *tree = new word_tree();
                temp->word.push_back(c); 
                temp->child.push_back(tree);
                if(i==word.length()-1){  // the word is finished here, put a signal
                    temp->finish.push_back(true);
                }
                else{
                    temp->finish.push_back(false);
                }
                temp = tree;
            }
            else{
                if(i==word.length()-1){ // the word is finished here, put a signal
                    temp->finish[j] = true;
                }
                temp = temp->child[j];
            }
        }
    }
    
    int location;
    string word;
    bool search_from_node(word_tree* temp_root){
        char c = word[location];
        if(c!='.'){  // not wildcard character
            int j=0;
            while(j<temp_root->word.size()){  // trying to match word
                if(c==temp_root->word[j])
                    break;
                j++;
            }
            
            if(j>=temp_root->word.size()){  // fail to match word, return false
                return false;
            }
            else{  // match currently
                if(location==word.length()-1){  // word match finished
                    if(temp_root->finish[j])  // word match successfully
                        return true;
                    else
                        return false;
                }
                location++;
                temp_root = temp_root->child[j];
                bool result = search_from_node(temp_root);
                location--;
                return result;
            }
        }
        else{
            int j=0;
            if(location==word.length()-1){ // if it is the last one
                while(j<temp_root->word.size()){  // trying to match end flag
                    if(temp_root->finish[j])
                        return true;
                    j++;
                }
                return false;
            }
            j=0;
            while(j<temp_root->word.size()){  // trying to match word
                word_tree* temp = temp_root->child[j];
                location++;
                if(search_from_node(temp))  // if one way is true, then return true
                    return true;
                location--;
                j++;
            }
            return false;
        }
        return false;
    }
    
    bool search(string word) {
        word_tree* temp = tree_root;
        this->word = word;
        this->location = 0;
        return search_from_node(temp);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */