#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<string, string> map1;
	map1.insert({ "moaz", "mariem" });
	map1.insert({ "ahmed", "menna" });
	map1.insert({ "khaled", "hager" });
	unordered_map<string, string> map2;
	setmap(map1, map2);
	for (auto& it : map2)
		cout << it.first << " : " << it.second << endl;

}

void setmap(const unordered_map<string, string>& map1, unordered_map<string, string>& map2) {
	map2 = map1;
}