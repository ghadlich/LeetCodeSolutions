/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    
    void addWord(string s) {
        int i = 0;
        for (char a : s) {
            freqCountByPos_[i++][a-'a']++;
        }
    }
    
    void removeWord(string s) {
        int i = 0;
        for (char a : s) {
            freqCountByPos_[i++][a-'a']--;
        }
    }
    
    int dist(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            cnt += (a[i]==b[i]);
        }
        
        return cnt;
    }
    
    int findScore(string s) {
        int score = 0;
        int i = 0;
        for (char a : s) {
            score += freqCountByPos_[i++][a-'a'];
        }
        return score;
    }
    
    string highestScoringWord(unordered_set<string>& wordlist) {
        string highest = "rstlne";
        int highscore = -1;
        
        for (string s : wordlist) {
            int score = findScore(s);
            if (score > highscore) {
                highscore = score;
                highest = s;
            }
        }
        
        return highest;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<string> wordbank(wordlist.begin(), wordlist.end());

        for (string word : wordbank) {
            addWord(word);
        }
        
        int guessesRemaining = 10;
        
        do {
            // find best word
            string best = highestScoringWord(wordbank);
            int result = master.guess(best);
            
            if (result == 6) {
                return;
            }
            // Nothing was correct, remove anything similar as those are all wrong
            else if (result == 0) {
                vector<string> v;
                
                for (string word : wordbank) {
                    if (dist(best,word) > 0) {
                        v.push_back(word);
                    }
                }
                
                for (string word : v) {
                    removeWord(word);
                    wordbank.erase(word);
                }
            }
            // There were some hits, remove anything without identical score
            else {
                vector<string> v;
                for (string word : wordbank) {
                    if (dist(best,word) != result) {
                        v.push_back(word);
                    }
                }
                    
                v.push_back(best);
                for (string word : v) {
                    removeWord(word);
                    wordbank.erase(word);
                }
            }
            
        guessesRemaining--;
            
        } while (guessesRemaining > 0);
    }
    
    int freqCountByPos_[6][26];
};