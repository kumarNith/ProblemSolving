/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sublist_helper(vector<string> &lst, vector<string> &sub_lst){
    if(lst.size() == 0){
        for (string s : sub_lst)
            cout<<s<<" ";
        cout<<endl;
    }
    else{
        
        string first = lst.at(0);
        //cout<<lst.begin()
        lst.erase(l st.begin());
        
        //Choose
        sub_lst.push_back(first);
        sublist_helper(lst,sub_lst);
        
        //Unchoose
        //cout<<"first---> "<<first<<endl;
        sub_lst.erase(sub_lst.begin()+(sub_lst.size()-1));
        sublist_helper(lst,sub_lst);
        lst.push_back(first);
        /*cout<<"Test starts<--";
        for (string s : lst)
            cout<<s<<" ";
        cout<<"---->Test ends";
        cout<<endl; */
    }
    
}

void sublist(vector<string> lst){
    vector<string> sub_lst = {""};
    //for (int i =0; i < lst.size();i++)
    sublist_helper(lst, sub_lst);
}

int main()
{
    vector<string> lst = {"father","mother","son","daughter"};
    sublist(lst);
    
    //cout<<"Hello World";

    //return 0;
}

