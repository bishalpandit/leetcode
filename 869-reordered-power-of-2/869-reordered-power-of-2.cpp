class Solution {
    bool isAnagram(string s, string t) {
        int m = s.length(), n = t.length();
        if(m != n)
            return false;
        
        int freq[10]{0};
        
        for(auto &c: s)
            freq[(int)(c - '0')]++;
        
        for(auto &c: t)
            freq[(int)(c - '0')]--;
        
        cout << s << " : " << t << endl;
        
        for(auto &val: freq)
            cout << val << " ";
        cout << endl;
        
        for(int i = 0; i < 10; i++)
            if(freq[i] != 0)
                return false;
        
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        long long temp = 1;
        
        set<string> powerof2s;
        
        while(temp < 1000000000) {
            string p_str = to_string(temp);
            powerof2s.insert(p_str);
            temp *= 2;
        }
        
        string n_str = to_string(n);
        
        for(auto &val: powerof2s) {
            if(isAnagram(val, n_str))
                return true;
        }
        
        return false;
    }
};