class Solution {
public:
    string connect(string a,string b){
        if(a.find(b)!=std::string::npos)return a;
        else{

            for(int i=b.length();i>0;--i){
                int k=a.length()-1;
                int p=i;
                while(k>=0 && p>0 && a[k]==b[p-1]){
                    k--;
                    p--;
                }
                if(p==0){
                    string temp=b.substr(i);
                    return a+temp;
                }
            }
            return  a+b;
        }
    }

    string minimumString(string a, string b, string c) {
        //a+b+c v
        //a+c+b v
        //b+a+c v
        //b+c+a 
        //c+a+b v
        //c+b+a
        int minLen=INT_MAX;
        string res="";

        //a+b+c
        string s1=connect(a,b);
        string s2=connect(s1,c);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }
        //c+a+b
        s2=connect(c,s1);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }
        //a+c+b
        s1=connect(a,c);
        s2=connect(s1,b);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }
        //b+a+c
        s2=connect(b,s1);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }

        //c+b+a
        s1=connect(c,b);
        s2=connect(s1,a);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }

        //b+c+a
        s1=connect(b,c);
        s2=connect(s1,a);
        if(s2.length()<minLen){
            minLen=s2.length();
            res=s2;
        }
        else if(s2.length()==minLen){
            res=min(res,s2);
        }


        return res;
    }
};
