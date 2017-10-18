#include <iostream>
#include "queue.h"
#include "deque.h"
#include <algorithm>

using namespace std;

struct City {
	string name;
	int id;
	int path = -1;
};

struct Road {
	int begin;
	int end;
};

City* fillCities(int &size);
Road* fillRoads(City* cities, int &size, int citySize);
int findCity(City* cities, string name, int size);
void bfs(City* cities, Road* roads, int start, int roadSize);
void printPath(City* cities, Road* roads, int end, int roadSize);

int main() {
	int citySize, roadSize;
	City* cities = fillCities(citySize);
	Road* roads = fillRoads(cities, roadSize, citySize);
	cout << "Enter start and end city: \n";
	string startStr, endStr;
	cin >> startStr >> endStr;
	int start = findCity(cities, startStr, citySize);
	int end = findCity(cities, endStr, citySize);
	bfs(cities, roads, start, roadSize);
	printPath(cities, roads, end, roadSize);
	return 0;
}

void printPath(City* cities, Road* roads, int end, int roadSize) {
	Deque deque;
	City current = cities[end];
	do {
		deque.pushBack(current.id);
		int prev = -1;
		for (int i = 0; i < roadSize; i++) {
			if (roads[i].begin == current.id) {
				if (cities[roads[i].end].path == current.path - 1) {
					prev = roads[i].end;
					break;
				}
			} else if (roads[i].end == current.id) {
				if (cities[roads[i].begin].path == current.path - 1) {
					prev = roads[i].begin;
					break;
				}
			}
		}
		if (prev == -1) {
			break;
		}
		current = cities[prev];
	} while (true);
	while (!deque.isEmpty()) {
		cout << cities[deque.getBack()].name << " ";
		deque.popBack();
	}
}

void bfs(City* cities, Road* roads, int start, int roadSize) {
	Queue queue;
	cities[start].path = 0;
	queue.push(start);
	while (!queue.isEmpty()) {
		City* current = &cities[queue.get()];
		queue.pop();
		Queue tmp;
		for (int i = 0; i < roadSize; i++) {
			if (roads[i].begin == current->id) {
				if (cities[roads[i].end].path == -1) {
					tmp.push(roads[i].end);
				}
			} else if (roads[i].end == current->id) {
				if (cities[roads[i].begin].path == -1) {
				tmp.push(roads[i].begin);
				}
			}
		}
		while (!tmp.isEmpty()) {
			City* next = &cities[tmp.get()];
			tmp.pop();
			next->path = current->path + 1;
			queue.push(next->id);
		}
	}
}

int findCity(City* cities, string name, int size) {
	for (int i = 0; i < size; i++) {
		if (cities[i].name == name) {
			return cities[i].id;
		}
	}
	return -1;
}

Road* fillRoads(City* cities, int &size, int citySize) {
	cout << "Enter number of Roads: ";
	int n;
	cin >> n;
	cout << "Enter list of Roads: \n";
	Road* roads = new Road[n];
	for (int i = 0; i < n; i++) {
		string begin, end;
		cin >> begin >> end;
		roads[i].begin = findCity(cities, begin, citySize);
		roads[i].end = findCity(cities, end, citySize);
	}
	size = n;
	return roads;
}

City* fillCities(int &size) {
	cout << "Enter number of Cities: ";
	int n;
	cin >> n;
	cout << "Enter list of Cities: \n";
	City* cities = new City[n];
	for (int i = 0; i < n; i++) {
		cin >> cities[i].name;
		cities[i].id = i;
	}
	size = n;
	return cities;
}
