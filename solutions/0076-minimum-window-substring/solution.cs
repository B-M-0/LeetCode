public class Solution {
    

    public bool isWindowSubstring(Dictionary<char,int> s_dict, Dictionary<char,int> t_dict)
    {
        foreach(var pair in t_dict)
        {
            char letter = pair.Key;
            int count = pair.Value;
            if(!s_dict.ContainsKey(letter) || s_dict[letter] ==0 || s_dict[letter]<count)
                return false;
        }
        
        return true;
    }
    
    public string MinWindow(string s, string t) {
        int l = 0;
        int r = 1;
        Dictionary<char,int> t_dict = new Dictionary<char,int>(); 
        Dictionary<char,int> sub_dict = new Dictionary<char,int>(); 
        sub_dict[s[0]] =1;
        foreach(char letter in t)
        {
            if(t_dict.ContainsKey(letter))
                t_dict[letter] ++;
            else t_dict[letter] = 1;
        }
        int minL = -1;
        int minR =-1;

        string minseq = "";
        int min = int.MaxValue;
        while(r  <= s.Length)
        {
            if (isWindowSubstring(sub_dict,t_dict)&& r > l){
                if(r-l < min)
                {
                    min = r-l;
                    minL = l;
                    minR = r;
                }
                sub_dict[s[l]]--;
                l++;
            }
            else{
            
            if((r<s.Length))
                if(sub_dict.ContainsKey(s[r]))
                    sub_dict[s[r]]++;
                else
                    sub_dict[s[r]] =1;
            r++;
            }
        }
        if (minL ==-1)
        return "";
        else return s.Substring(minL,minR-minL);

    }
}
