#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

// bool compare( int a, int b ) {
// 	return (a < b);
// }

// int main ( void ) {
// 	std::vector<int> one(7);
// 	std::vector<int> two(5);
// 	std::srand(std::time(NULL));

// 	std::vector<int>::iterator itOne = one.begin();
// 	std::cout << "[ ONE ]" << std::endl;
// 	for(itOne; itOne != one.end(); itOne++) {
// 		*itOne = std::rand() % 100;
// 		std::cout << "[ " << *itOne << " ]" << std::endl;
// 	}
// 	std::cout << std::endl << "[ TWO ]" << std::endl;
// 	std::vector<int>::iterator itTwo = two.begin();
// 	for(itTwo; itTwo != two.end(); itTwo++) {
// 		*itTwo = std::rand() % 100;
// 		std::cout << "[ " << *itTwo << " ]" << std::endl;
// 	};

// 	std::sort(one.begin(), one.end());
// 	std::sort(two.begin(), two.end());

// 	std::cout << std::endl << "[ THREE ]" << std::endl;
// 	std::vector<int> three(one.size() + two.size());
// 	std::vector<int>::iterator itThree = three.begin();
// 	std::merge(one.begin(), one.end(), two.begin(), two.end(), three.begin(), compare);
// 	for(itThree; itThree != three.end(); itThree++) {
// 		std::cout << "[ " << *itThree << " ]" << std::endl;
// 	};
// 	return (0);
// }

// int main ( void ) {
// 	std::vector<std::pair<int, int> > first(5);
// 	std::vector<std::pair<int, int> > second(5);
// 	std::vector<std::pair<int, int> > third(10);
// 	std::srand(std::time(NULL));

// 	std::cout << "{ FIRST }" << std::endl;
// 	for (int i = 0; i < first.size() ; i++ ) {
// 		first[i].first = i+7;
// 		first[i].second = std::rand() % 10;
// 		std::cout << "[" << first[i].first << "," << first[i].second << "]" << std::endl;
// 	}
// 	std::cout << "{ SECOND }" << std::endl;
// 	for (int i = 0; i < second.size() ; i++ ) {
// 		second[i].first = i;
// 		second[i].second = std::rand() % 10;
// 		std::cout << "[" << second[i].first << "," << second[i].second  << "]" << std::endl;
// 	}
// 	std::cout << "{ THIRD }" << std::endl;
// 	for (int i = 0; i < third.size() ; i++ ) {
// 		third[i].first = -1;
// 		third[i].second = -1;
// 		std::cout << "[" << -1 << "," << -1 << "]" << std::endl;
// 	}
// 	std::merge(first.begin(), first.end(), second.begin(), second.end(), third.begin());
// 	std::cout << std::endl << "{ MERGED }" << std::endl;
// 	for (int i = 0; i < third.size() ; i++ ) {
// 		std::cout << "[" << third[i].first << "," << third[i].second << "]" << std::endl;
// 	}
// 	return (0);
// }


int main ( void ) {
	std::vector<std::pair<int,int> > a(1); // ----> [50, 0]-[10, 0]
	std::vector<std::pair<int,int> > b(1);

	a[0].first = 50;
	b[0].first = 10;
	std::vector<std::pair<int,int> > temp(a.size() + b.size());

	std::merge(a.begin(), a.end(), b.begin(), b.end(), temp.begin()); // probably NEED TO MOVE THIS FUCKING BEGIN BECAUSE PORCODIO RETURNS ALWAYS FROM THE BEGINNING !?!?!?!?!?!?!?
	std::cout << "SIZE> " << temp.size() << std::endl;
	std::cout << temp[0].first << std::endl;
	std::cout << temp[1].first << std::endl;


	std::vector<std::pair<int,int> > c(1);
	c[0].first = 99;
	std::vector<std::pair<int,int> > temp2(temp.size() + 1);
	std::merge(temp.begin(), temp.end(), c.begin(), c.end(), temp2.begin()); // probably NEED TO MOVE THIS FUCKING BEGIN BECAUSE PORCODIO RETURNS ALWAYS FROM THE BEGINNING !?!?!?!?!?!?!?
	std::cout << "SIZE> " << temp2.size() << std::endl;
	std::cout << temp2[0].first << std::endl;
	std::cout << temp2[1].first << std::endl;
	std::cout << temp2[2].first << std::endl;

	return (0);
}