class Trie {
public:
    // declaration of TrieNode;
    struct TrieNode{
        bool isendofWord=false;
        TrieNode* children[26];
    };
    // hmlog initilization es waale step me kr rhe hai.
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->isendofWord=false;
        for(int i=0;i<26;i++){
            // starting me ye khi point ni kr rha hai
            // eslie hmlog isko NULL se point krwa rhe hai.
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    TrieNode* root;
    // constructor function me ek node bn ke aa jaega.
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            // check kro aisa bol ke koi hai ky agr ni hai toh phir 
            // nya node banao.
            if(crawler->children[index]==NULL){
                crawler->children[index]=getNode();
            }
            crawler=crawler->children[index];
        }
        crawler->isendofWord=true;
    }
    
    bool search(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(crawler->children[index]==NULL){
                // crawler->children[i]=getNode();
                // bs line ko replace krna hoga.
                return false;
            }
            crawler=crawler->children[index];
        }
        // ab hmlog ye baaat jaante hai ki agr wo pura search kr liya hoga.
        // toh definetely wo last wala TrieNode pe pahuch gy hoga 
        // or uska isendofWord=true hoga.
        return (crawler!=NULL && crawler->isendofWord==true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler=root;
        int i;
        for(i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int index=ch-'a';
            if(crawler->children[index]==NULL){
                // crawler->children[i]=getNode();
                // bs es line ko replace kr do. ki agr word ka 
                // wo character ni mila toh.
                break;
            }
            crawler=crawler->children[index];
        }
        // ab dekho ek baat toh hai. agr wo pura search kiya hoga toh definetely 
        // wo last index ke bahar chala gy hoga prefix/word ke toh eslie bs whi 
        // check kr lete hai.
        return i==prefix.length();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */