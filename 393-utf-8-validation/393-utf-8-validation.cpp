class Solution {
    string intToBinary(int num) {
        string res;
        
        for(int i = 0; i < 8; i++) {
            if(num & (1 << i))
                res += '1';
            else
                res += '0';
        }
        
        reverse(begin(res), end(res));
        return res;
    }
public:
    bool validUtf8(vector<int>& data) {
        vector<string> binaryNums;
        
        for(auto &ai: data)
            binaryNums.push_back(intToBinary(ai));
        
        int cntOne = 0;
        bool isFirstByte = true;
        
        for(int i = 0; i < data.size(); i++) {
            string byte = binaryNums[i];
            
            
            if(isFirstByte) {
                if(byte[0] == '0') continue;
                
                while(cntOne < 8 and byte[cntOne] != '0')
                    cntOne++;
    
                isFirstByte = false;
                
                if(cntOne > 4)
                    return false;
            }
            else {
                cntOne--;
                if(cntOne == 1) {
                    isFirstByte = true;
                    cntOne = 0;
                }
                
                if(!(byte[0] == '1' and byte[1] == '0'))
                    return false;
            }
            
        }
        
        
        
        return isFirstByte ? true : false;
    }
};