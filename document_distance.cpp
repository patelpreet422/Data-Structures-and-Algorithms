#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cctype>

using namespace std;
using namespace chrono;

const string readFile(const string &name)
{
    ifstream fin(name);
    string temp;
    fin.seekg(0, ios::end);
    size_t fileSize = fin.tellg();
    temp.resize(fileSize);
    fin.seekg(0, ios::beg);
    fin.read(&temp[0], fileSize);
    fin.close();
    return temp;
}

const unordered_map<string, int> wordFrequency(const string &str)
{
    unordered_map<string, int> wordMap;
    string temp;
    for(int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        if(isalnum(c))
        {
            if(isupper(c))
            {
                temp += string(1, static_cast<char>(tolower(c)));
            } else {
                temp += string(1, c);
            }
        } else {
            if(wordMap.find(temp) == wordMap.end())
            {
                wordMap[temp] = 1;
            } else {
                ++wordMap[temp];
            }
            temp = "";
        }

        if(i == str.size()-1)
        {
            if(wordMap.find(temp) == wordMap.end())
            {
                wordMap[temp] = 1;
            } else {
                ++wordMap[temp];
            }
        }
    }
    return wordMap;
}

double magnitude(const unordered_map<string, int> &m)
{
    int sum_of_square_of_terms = 0;
    for(const auto &e: m)
    {
        sum_of_square_of_terms += pow(e.second, 2);
    }
    return sqrt(sum_of_square_of_terms);
}

double computeAngle(const unordered_map<string, int> &f1, const unordered_map<string, int> &f2)
{
    double res = 0;
    for(auto it1 = f1.begin(); it1 != f1.end(); ++it1)
    {
        string word_from_file1 = it1->first;
        if(f2.find(word_from_file1) != f2.end())
        {
            res += it1->second * f2.find(word_from_file1)->second;
        }
    }

    return acos(res/(magnitude(f1)*magnitude(f2)));
}

float compareFile(const string &name1, const string &name2)
{
    const string file1Content = readFile(name1);
    const string file2Content = readFile(name2);
    unordered_map<string, int> wordMap_file1 = wordFrequency(file1Content);
    unordered_map<string, int> wordMap_file2 = wordFrequency(file2Content);
    return computeAngle(wordMap_file1, wordMap_file2);
}

int main() {
    auto begin = system_clock::now();
    cout << compareFile("file1.txt", "file2.txt") << '\n';
    auto end = system_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << "Time elapsed in (ms): " << elapsed.count() << '\n';
    return 0;
}
