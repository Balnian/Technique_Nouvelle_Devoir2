#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <locale>
using namespace std;
//template<class T>
//T trouver_consecutifs(T debut, T fin, int n)
//{
//   T curCheck = debut;
//   int count = 1;
//   
//   while (debut != fin)
//   {
//      ++debut;
//      if (count == n)
//         return curCheck;
//
//      if (*curCheck != *debut)
//      {
//         curCheck = debut;
//         count = 1;
//      }
//      else
//         count++;
//      
//         
//   }
//   return fin;
//   
//}
template<class T>
T trouver_consecutifs(T debut, T fin, unsigned int n)
{
	auto currelem = debut;
	if (n <= 0 || distance(debut, fin) < n)
		return fin;
	while (debut != fin) {
		if (distance(debut, currelem = find_if(debut, fin, [&](auto elem) {return elem != *currelem; })) >= n)
			return debut;
		else
			debut = currelem;
	}
	return fin;
}


//template<class T>
//pair<T,T> plus_longue_sequence(T debut, T fin)
//{
//   if (debut == fin)
//      return make_pair(fin, fin);
//
//   T curCheck = debut;
//   int curCount = 1;
//
//   T LongestITbegin = curCheck;
//   
//   T LongestITend = next(curCheck);
//   int LonguestITcount = curCount;
//
//   while (debut != fin)
//   {
//      ++debut;      
//      if (curCount > LonguestITcount)
//      {
//         LongestITbegin = curCheck;
//         LongestITend = debut;
//         LonguestITcount = curCount;
//      }
//      if (*curCheck != *debut)
//      {
//         curCheck = debut;
//         curCount = 1;
//      }
//      else
//         curCount++;
//   }
//
//   return make_pair(LongestITbegin, LongestITend);
//
//}

template<class T>
pair<T, T> plus_longue_sequence(T debut, T fin)
{
	T currdeb = debut;
	T currfin = debut;
	auto currelem = debut;
	while (debut != fin) {
		if (distance(debut, currelem = find_if(debut, fin, [&](auto elem) {return elem != *currelem; })) > distance(currdeb, currfin))
		{
			currdeb = debut;
			currfin = currelem;

		}
		debut = currelem;
	}
	return make_pair(currdeb, currfin);
}

template<class T, class U>
pair<T, T> plus_longue_sequence(T debut, T fin, U pred)
{
	T currdeb = fin;
	T currfin = fin;
	auto currelem = debut;
	while (debut != fin) {
		if (distance(debut, currelem = find_if(debut, fin, [&](auto p) {return !pred(p); })) > distance(currdeb, currfin))
		{
			currdeb = debut;
			currfin = currelem;

		}
		if (currelem == debut)
			debut = next(currelem);
		else
			debut = currelem;
	}

	return make_pair(currdeb, currfin);
}

//template<class T, class U>
//pair<T, T> plus_longue_sequence(T debut, T fin,U pred)
//{
//   if (debut == fin)
//      return make_pair(fin, fin);
//
//   auto curCount;
//
//   T LongestITbegin = curCheck;
//
//   T LongestITend = next(curCheck);
//   auto LonguestITcount = curCount;
//
//   T curCheck = debut;
//
//   T start ;
//   T end ;
//   while (curCheck != fin)
//   {
//      start = find_if(curCheck, fin, pred);
//      end = find_if_not(find_if(curCheck, fin, pred), fin, pred);
//
//      curCount = distance(find_if(curCheck, fin, pred), find_if_not(find_if(curCheck, fin, pred),fin,pred));
//      
//      if (curCount > LonguestITcount)
//      {
//         LongestITbegin = start;
//         LongestITend = end;
//      }
//      curCheck = find_if_not(find_if(curCheck, fin, pred);
//   }
//
//   return make_pair(LongestITbegin, LongestITend);
//}


string inverser_mots(string s)
{
	vector<string> str, space;

	auto debut = begin(s), fin = end(s);
	//Sépare les string et les espaces
	while (debut != fin)
	{
		auto t = find_if(debut, fin, [](char c) {return !isspace(c, locale{ "" }); });
		//if(debut!=t)
		space.emplace_back(string(debut, t));

		auto t2 = find_if(t, fin, [](char c) {return isspace(c, locale{ "" }); });

		str.emplace_back(string(t, t2));
		debut = t2;
	}
	//reverse les mots
	str.erase(std::remove_if(begin(str), end(str), [](string s) { return s.empty(); }), end(str));
	std::reverse(begin(str), end(str));

	string out = "";
	for (size_t i = 0; i < str.size(); i++) { out += space.at(i) + str.at(i); }
	for (size_t i = 0; i < space.size() - str.size(); i++) { out += space.at(str.size() + i); }

	return out;
}


int main()
{
	int x[] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7 };// { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,5,5,5 };

	//int x[11] = { 1, 4 , 1};
	vector<int> x2;
	vector<int> x3 = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,5,5,5 };
	list<int> x4 = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,5,5,5 };
	//auto retur = trouver_consecutifs(begin(x), end(x),15);
	//if (retur != end(x))
	//   cout << *retur << endl;
	//else
	//   cout << "rien trouver" << endl;

	//auto retur = plus_longue_sequence(begin(x4), end(x4));
	//if (retur != make_pair(end(x4), end(x4)))
	//	cout << *retur.first << " , " << *retur.second << endl;
	//else
	//	cout << "rien trouver" << endl;

	auto retur = plus_longue_sequence(begin(x), end(x), [](int p) { return p == 4; });
	if (retur != make_pair(end(x), end(x)))
		cout << *retur.first << " , " << *retur.second << endl;
	else
		cout << "rien trouver" << endl;

	//string out = inverser_mots("d 4 s ");
	//transform(begin(out), end(out), begin(out), [](auto c) {
	//	if (isspace(c, locale{ "" }))
	//		return '/';
	//	else
	//		return c;
	//});
	//cout << out << endl;

}