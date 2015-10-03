#include"leetcode.h"
#include<cstdlib>
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//A 00 C 01 G 10 T 11
		vector<string> result;
		map<int,string> table;
		for (int i = 0; i<s.size(); i++){

			if (i + 10<s.size()){
				string key = s.substr(i, 10);
				int key2 = 0;
				for (int i = 0; i<10; i++){
					switch (key[i]){
					case 'A':break;
					case 'C':key2 |= (1 << (i << 1)); break;
					case 'G':key2 |= (2 << (i << 1)); break;
					case 'T':key2 |= (3 << (i << 1)); break;
					}
				}
				if (table.find(key2) != table.end()){
					cout <<"First:"<< key <<"--->"<<key2<< endl;
					//if (table[key2] == false) {
						cout <<"Seconde:"<< key << "----" << key2 << endl;
						result.push_back(key);
					//	table[key2] = true;
					//}
				}
				else{
					table[key2] = key;
				}
			}
		}
		cout << "";
		return result;
	}
};
//int main(){
//	Solution s;
////	s.findRepeatedDnaSequences("CGACGCAATTTAGAACGGGCCGCACTGCAACCATTGCTCAGACAACGCATGAGTTAAATTTCACAAGTGATAGTGGCTTGCGAGACGTGGGTTGGTGGTAGCGTACGCCCGCTATTCGCCCCTAACGTGACGGGATTATAAGGTCGCTTCCCGGAATGCGCAGACGAGTCTCCGGTTTAGCCTAGACGTCTCACGCGCGCAAGGCGTCAGTTCTCACTATCTCGCACAGGTGTATTCTATTAGTTATGGGTTCTCACTACAGTCGGTTACTTCCTCATCCATTTCTGCATACGGGTCAACTAACAGTGTCATGGGGTATTGGGAAGGATGCGTTTTTAAACCCTCTCAGTAGCGCGAGGATGCCCACAAATACGACGGCGGCCACGGATCTAATGCGAAGCTAGCGACGCTTTCCAGCAACGAGCGCCCCACTTATGACTGCGTGGGGCGCTCCGCTTTCCTAGAGAACATAGATGGTGTTTTCGAATCGTAACCACTTA");
//	char bu[100];
//	for (int i = 0; i < 10000;i++){
//		sprintf_s(bu, "%x", i);
//		cout << bu << endl;
//	}
//	return 0;
//}