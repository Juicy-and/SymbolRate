#include <iostream>
#include <string>
#include <map>

template<typename K, typename V>
std::multimap<V, K> invertMap(std::map<K, V> const& map)
{
	std::multimap<V, K> mup;
	for (auto const& pair : map) {
		mup.insert(std::make_pair(pair.second, pair.first));
	}
	return mup;
}

int main() {
	std::map<char, int> mp;
	std::string str = "Hello world!!";
	std::cout << "[IN]: "<< str<< std::endl;
	for (auto& i : str)
		++mp[i];
	std::multimap<int, char> mup = invertMap(mp);
	std::cout << "\n[OUT]: " << std::endl;
	for (auto it = mup.rbegin(); it != mup.rend(); ++it)
		std::cout << (*it).second << ": " << (*it).first << std::endl;

	return 0;
}