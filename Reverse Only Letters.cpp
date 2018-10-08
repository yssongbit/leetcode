#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.empty())
        	return S;
        string letters = "";
        for(int i = 0; i < S.size(); i++)
        {
        	if((S[i] <= 'Z' && S[i] >= 'A') || (S[i] <= 'z' && S[i] >= 'a'))
        		letters += S[i];
        }
        reverse(letters.begin(), letters.end());
        string res = "";
        int letter_idx = 0;
        for(int i = 0; i < S.size(); i++)
        {
        	if((S[i] <= 'Z' && S[i] >= 'A') || (S[i] <= 'z' && S[i] >= 'a'))
        		res += letters[letter_idx++];
			else
				res += S[i]; 
        }
        return res;
    }
};

class Solution1 {
public:
    string reverseOnlyLetters(string S) {
    	for(int i = 0, j = S.size()-1; i < j; i++, j--)
    	{
    		while(i < j && !isalpha(S[i])) i++;
    		while(i < j && !isalpha(S[j])) j--;
    		swap(S[i], S[j]);
    	}
    	return S;
    }
};

int main()
{
	Solution1 s;
	string res = s.reverseOnlyLetters("a-bC-dEf-ghIj");
	cout << "res == " << res << endl;
}
