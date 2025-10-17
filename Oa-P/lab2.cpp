#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main() {
	string my_text;
	string space = " ";
	string a = "aA";
	string last_word = "";
	int count_a = 0;


	int min_len = 1000;
	int vr_count = 0;
	
	int lst_w = 0;

	cout << "Enter str: ";
	getline(cin, my_text);

	if (my_text[0] == a[0] || my_text[0] == a[1]) {
		count_a += 1;
	}

	for (int i = 0; i < my_text.length(); i++) {
		if (my_text[i] == space[0]) {
			if (my_text[i + 1] == a[0]) {
				count_a += 1;
			}
		}
	}


	for (int i = 0; i < my_text.length(); i++) {
		if (my_text[i] != space[0]) {
			vr_count += 1;
		}
		else {
			if (vr_count < min_len) {
				min_len = vr_count;
			}
			vr_count = 0;
		}
	}
	if (vr_count < min_len) {
		min_len = vr_count;
	}
	
	cout << "Words where first symbol it's a: " << count_a << endl;
	cout << "Shortest word: " << min_len << endl;
	
	for (int i = my_text.length() - 1; i >= 0; i--) {
		if (my_text[i] == space[0]) {
			break;
		}
		last_word = my_text[i] + last_word;
	}
	for (int i = 0; i < last_word.length(); i++) {
		if (last_word[i] == a[0] || last_word[i] == a[1]) {
			lst_w++;
		}
	}


	cout << "Count 'a' in last word: " << lst_w<< endl;


	for (int i = 0; i < my_text.length(); i++) {
		my_text[i] = tolower(my_text[i]);
	}

	cout << "Tolower registr: " << my_text<< endl;

	int wrd_count = 0;

	int vr_per = 0;


	for (int i = 0; i <= my_text.length(); i++) {
		if (i == my_text.length() || my_text[i] == space[0]) {
			if (vr_per < i) {
				string word = my_text.substr(vr_per, i - vr_per);
				if (word[0] == word[word.length() - 1]) {
					wrd_count++;
				}
			}
			vr_per = i + 1;
		}
	}

	cout << "Count where fir == last letter: " << wrd_count;
}
