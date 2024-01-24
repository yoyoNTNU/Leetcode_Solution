class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int curWidth=0;
        int wordCount=0;
        int finish=-1;
        for(int i=0;i<words.size()-1;++i){
            curWidth+=words[i].length();
            wordCount++;
            if(curWidth+words[i+1].length()+1>maxWidth){
                string cur="";
                if(wordCount==1){
                    cur+=words[i];
                    for(int k=0;k<maxWidth-curWidth;++k){
                        cur+=" ";
                    }
                }
                else{
                    int more1=(maxWidth-curWidth)%(wordCount-1);
                    int c=(maxWidth-curWidth)/(wordCount-1)+1;
                    
                    for(int j=i-wordCount+1;j<i;++j){
                        cur+=words[j];
                        for(int k=0;k<c+(more1>0);++k){
                            cur+=" ";
                        }
                        more1--;
                    }
                    cur+=words[i];
                }
                finish=i;
                res.emplace_back(cur);
                curWidth=0;
                wordCount=0;
            }
            else{
                curWidth++;
            }
        }   
        string cur="";
        for(int i=finish+1;i<words.size();++i){
            cur+=words[i];
            if(cur.length()<maxWidth)cur+=" ";
        }
        int space=maxWidth-cur.length();
        for(int i=0;i<space;++i){
            cur+=" ";
        }
        res.emplace_back(cur);
        return res;
    }
};
