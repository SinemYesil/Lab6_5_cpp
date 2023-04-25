#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>list3(vector<int> list1,vector<int> list2){//q1
    vector<int>result;
    for(int element: list1){
        if(find(list2.begin(),list2.end(),element)!=list2.end()){
            result.push_back(element);
        }
    }
    return result;
}
//q2
vector<string> palindromes (vector <string> list){
    vector<string> palindromes;
    for (string word : list){
        if(word==string(word.rbegin(),word.rend())){
            palindromes.push_back(word);
        }
    }return palindromes;
}
//q3
vector<int> prime_func(vector<int>int_list){
    int max_number=*max_element(int_list.begin(),int_list.end());
    vector<bool> sieve(max_number+1,true);
    sieve[0]=sieve[1]= false;
    vector<int> primes_list;
    for(int number:int_list){
        if(sieve[number]){
            primes_list.push_back(number);
            for(int mult=number*2;mult<=max_number;mult+=number){
                sieve[mult]=false;
            }
        }
    }
    return primes_list;
}
//q4
vector<string > anagrams(string word1, vector<string>word_list1){
    vector<string > output;
    string sorted_word=word1;
    transform(sorted_word.begin(),sorted_word.end(), sorted_word.begin(),::tolower);
    sort(sorted_word.begin(),sorted_word.end());
    for(string str1:word_list1){
        string sorted_str=str1;
        transform(sorted_str.begin(),sorted_str.end(),sorted_word.begin(),::tolower);
        sort(sorted_str.begin(),sorted_str.end());
        if (sorted_str==sorted_word)
            output.push_back(str1);
    }
    return output;
}



int main() {
    vector<int>list1 {1,2,3,4,5};
    vector<int> list2{3,4,5,6,7};
    vector<int> list4=list3(list1,list2);
    for(int element:list4)
        cout<<element<<"";
    cout<<endl;
    cout<<"****q2****"<<endl;
    vector<string>list{"sinem", "yesil", "software", "engineering", "sinnis", "yessey"};
    vector<string>result= palindromes(list);
    for(string word: result){
        cout<<word<<"";
    }
    cout<<endl;
    cout<<"***q3***"<<endl;
    vector<int>int_list={1,2,3,4,5,6,7,8,9};
    vector<int> primes_list= prime_func(int_list);
    for(int prime:primes_list){
        cout<<prime<<"";

    }cout<<endl;
    cout<<"***q4***"<<endl;
    string word1="cinema";
    vector<string>word_list1={"iceman","sinem","yesil", "iiceman"};
    vector<string>output= anagrams(word1, word_list1);
    for(string str:output) {
        cout << str << "";
    }
    cout<<endl;

    return 0;
}
