public class Solution {
    public List<String> GenerateHappyString(int n)
    {
        string[] baseCase = {"a", "b" ,"c"} ;
        if(n == 1)
            return new List<String>(baseCase);
        else
        {
            List<String> output = new List<String>();
            List<String> prev =  GenerateHappyString(n-1);
            foreach (string letter in baseCase)
            {
                for(int j = 0; j < prev.Count();j++)
                {
                    if (letter != prev[j][0].ToString())
                        output.Add(letter + prev[j]);
                }
            }
            return output;
        }
    }
    public string GetHappyString(int n, int k) {
        List<String> happyStrings = GenerateHappyString(n);
        if (k > happyStrings.Count())
            return "";
        else
            return happyStrings[k-1];
    }
}
