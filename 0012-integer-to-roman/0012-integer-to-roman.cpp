class Solution {
public:
    
    string convert(int num,vector<int>&arr,map<int,string>&m)
    {
        if(num==0)
            return "";
        int n=arr.size();
        int i=0;
        while(i<n and arr[i]<=num)
        {
            i++;
        }
        i--;
        string x="";
        x+=m[arr[i]];
        x+=convert(num-arr[i],arr,m);
        return x;
    }
    
    string intToRoman(int num) {
        vector<int>arr;
        arr.push_back(1);
        arr.push_back(4);
        arr.push_back(5);
        arr.push_back(9);
        arr.push_back(10);
        arr.push_back(40);
        arr.push_back(50);
        arr.push_back(90);
        arr.push_back(100);
        arr.push_back(400);
        arr.push_back(500);
        arr.push_back(900);
        arr.push_back(1000);
        
        map<int,string>m;
        m[1]="I";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        
        return convert(num,arr,m);
    }
};