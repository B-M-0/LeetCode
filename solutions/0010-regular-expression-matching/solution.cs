using System.Text.RegularExpressions;
public class Solution {
    public bool IsMatch(string s, string p) {
        Regex r = new Regex($"^{p}$");
        return r.IsMatch(s);
    }
}
