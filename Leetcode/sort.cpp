#include<vector>
#include<stack>
#include<queue>
#include<iostream>
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v){ val = v; next = NULL; }
};

namespace bing{
	void swap(int &a, int &b){
		int c = a;
		a = b;
		b = c;
	}
	void insertSort(std::vector<int> &num){
		//insert sort
		for (int i = 1; i < num.size(); i++){
			int v = num[i];
			int j = 0;
			for (j = i-1; j >=0&&num[j]>v; j--){
					num[j +1] = num[j];
			}
			j++;
			num[j] = v;
		}
	}
	void selectSort(std::vector<int> &num){
		//select sort
		for (int i = 0; i < num.size(); i++){
			int min = i;
			for (int j = i + 1; j < num.size(); j++){
				if (num[j] < num[min])
					min = j;
			}
			swap(num[i], num[min]);
		}
	}
	void bulleSort(std::vector<int> &num){
		//bulle sort
		for (int i = 0; i < num.size(); i++){
			for (int j = 0; j < num.size() - i - 1; j++){
				if (num[j] > num[j + 1])
					swap(num[j], num[j + 1]);
			}
		}
	}
	void shellSort(std::vector<int> &num){
		//shell sort
		int i, j, h;
		for (h = 1; h < (num.size() - 1) / 9; h = h * 3 + 1);
		for (; h > 0; h /= 3){
			for (int i = h; i < num.size(); i++){
				j = i; int v = num[j];
				while (j - h >=0 && num[j - h]>v){
					swap(num[j - h], num[j]);
					j -= h;
				}
				num[j] = v;
			}
		}
	}
	void quickSort(std::vector<int> &num, int l, int h){
		//recursive quick sort
		if (l>=h)
			return;
		int i = l; int m = l;
		for (int i = l+1; i <= h; i++){
			if (num[i] < num[l]){
				swap(num[++m], num[i]);
			}
		}
		swap(num[m], num[l]);
		quickSort(num, l, m-1);
		quickSort(num, m + 1, h);
	}
	void quickSort2(std::vector<int> &num){
		//non-recursive quick sort
		int l, h, m;
		std::stack<int> sk;
		sk.push(num.size() - 1);
		sk.push(0);
		while (!sk.empty()){
			l = sk.top();
			sk.pop();
			h = sk.top();
			sk.pop();
			
			if (l >= h)
				continue;
			m = l;
			for (int i = l + 1; i <= h; i++){
				if (num[i] < num[l]){
					swap(num[++m], num[i]);
				}
			}
			swap(num[m], num[l]);

			sk.push(h);
			sk.push(m + 1);
			sk.push(m - 1);
			sk.push(l);
		}
	}
	void merge(std::vector<int> &auxiliary, std::vector<int> &num, int l, int h, int ll, int hh){
		int i, j, k;
		i = l; j = ll;
		for (k = l; k <=hh; k++){
			if (i > h) {
				auxiliary[k] = num[j++];
				continue;
			}
			if (j > hh) {
				auxiliary[k] = num[i++];
				continue;
			}

			if (num[i] < num[j])
				auxiliary[k] = num[i++];
			else
				auxiliary[k] = num[j++];
		}
	}
	void msort( std::vector<int> &num,std::vector<int> &auxiliary, int l, int h){
		if (l >= h)
			return;
		int m = (l + h) / 2;
		msort(auxiliary, num, l, m);
		msort(auxiliary, num, m + 1, h);
		merge(num,auxiliary, l, m, m + 1, h);
	}	
	void mergeSort(std::vector<int> &num){
		//merge sort
		std::vector<int> auxiliary(num);
		msort(num, auxiliary, 0, num.size() - 1);
	}
	ListNode* listMerge(ListNode* a, ListNode* b){
		//List merger

		ListNode* head=new ListNode(0);
		ListNode* h = head;
		while ((a != NULL) && (b != NULL)){
			ListNode* temp = NULL;
			if (a->val < b->val){
				temp = a;
				a = a->next;
				temp->next = NULL;
				head->next = temp;
				head = head->next;
			}
			else{
				temp = b;
				b = b->next;
				temp->next = NULL;
				head->next = temp;
				head = head->next;
			}
		}
		if (a == NULL){
			head->next = b;
		}
		else{
			head->next = a;
		}

		return h->next;
	}
	void listMergeSort(ListNode* &head){
		//list merge sort
		std::queue<ListNode*> Q;
		ListNode* temp;
		while (head != NULL){
			temp = head;
			head = head->next;
			temp->next = NULL;
			Q.push(temp);
		}
		temp = Q.front();
		Q.pop();
		while (!Q.empty()){
			Q.push(listMerge(temp, Q.front()));
			Q.pop();
			temp = Q.front();
			Q.pop();
		}
		head = temp;
	}
}
//using namespace bing;
//int main(){
//		std::vector<int> a = { 50,3,2,3,1,21,3,23123,123,12,234,433,56,676,575,75,6,3345 };
//		ListNode* lista=NULL;
//		for (int i = 0; i < a.size(); i++){
//			ListNode* temp = new ListNode(a[i]);
//			temp->next = lista;
//			lista = temp;
//		}
//
//		listMergeSort(lista);
//		while (lista != NULL){
//			std::cout << lista->val << "  ";
//			lista = lista->next;
//		}
//		//mergeSort(a);
//		//insertSort(a);
//		//selectSort(a);
//		//bulleSort(a);
//		//shellSort(a);
//		//quickSort2(a);
//		return 0;
//	}