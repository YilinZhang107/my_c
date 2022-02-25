/*给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。

 

示例 1：

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 
*/


#include<bits/stdc++.h>
using namespace std;
//应该用栈解决
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names = split(path, '/');
        stack<string> simplifyPath;
        path.erase(0);//清空
        for(auto i=names.begin(); i != names.end(); i++){
            if(*i == ".")
                continue;
            else if(*i == ".."){
                if(!simplifyPath.empty())
                    simplifyPath.pop();
            }
            else{
                simplifyPath.push(*i);
            }
        }
        while(!simplifyPath.empty()){
            path.insert(0,"/");
            path.insert(1, simplifyPath.top());
            simplifyPath.pop();
        }
        if(path == "")//为空的情况
            path += "/";
        return path;
    }   
private:
    vector<string> split(string path, char c){
        int index = 0;
        vector<string> names;
        while(index < path.size() && path[index] == '/'){
            index++;
            string str;
            while(index<path.size() && path[index] != '/'){
                str += path[index];
                index++;
            }
            if(str != "")
                names.push_back(str);
        }
        return names;
    }
};

/*
class Solution {
public:
    string simplifyPath(string path) {
        int pPath = 0, pSimlify = 0;
        string simplifyPath;
        while(pPath < path.size()){
            switch (path[pPath])
            {
            case '/':  //多个斜杠用一个替换, 最后的斜杠在最后判断
                while(pPath < path.size() && path[pPath] == '/')
                    pPath++;
                simplifyPath.insert(pSimlify,1,'/');
                pSimlify++;
                break;
            case '.':
                if(pPath+1 < path.size() && path[pPath+1] == '/' || pPath+1 == path.size()){//一个点
                    pPath++;
                    simplifyPath.erase(simplifyPath.size()-1);
                    pSimlify--;
                }  
                else if((pPath+2 < path.size() && path[pPath+1] == '.' && path[pPath+2] == '/') || (pPath+2 == path.size() && path[pPath+1] == '.')){//两个点
                    if(pSimlify>1)//退到根目录不能再退
                        pSimlify-=2;
                    while(simplifyPath[pSimlify] != '/'){
                        pSimlify--;
                    }
                    simplifyPath.erase(pSimlify);
                    pPath+=2;
                }
                else{
                    while(path[pPath] != '/'){
                        simplifyPath.insert(pSimlify,1,path[pPath]);
                        pSimlify++;
                        pPath++;
                    }
                }
                break;
            default:
                while(path[pPath] != '/'){
                    simplifyPath.insert(pSimlify,1,path[pPath]);
                    pSimlify++;
                    pPath++;
                }
                break;
            }
        }
        if(simplifyPath.size()>1 && simplifyPath[simplifyPath.size()-1] == '/')
            simplifyPath.erase(simplifyPath.size()-1);
        return simplifyPath;
    }
};
*/

int main(){
    string path1 = "/home/";
    string path2 = "/../";
    string path3 = "/home//foo/";
    string path4 = "/a//b////c/d//././/..";
    Solution s;
    path1 = s.simplifyPath(path1);
    path2 = s.simplifyPath(path2);
    path3 = s.simplifyPath(path3);
    path4 = s.simplifyPath(path4);
    cout<<path1<<endl<<path2<<endl<<path3<<endl<<path4<<endl;

    return 0;

}