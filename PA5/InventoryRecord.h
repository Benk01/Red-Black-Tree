#ifndef INVENTORYRECORD_H

#define INVENTORYRECORD_H

#include <iostream>
#include <string>

using namespace std;

class InventoryRecord {
public:
	InventoryRecord();
	int getId();
	string getType();
	int getNumItems();
	void setId(int);
	void setType(string);
	void setNumItems(int);

	inline bool operator>(const InventoryRecord& data) { return id > data.id; }
	inline bool operator<(const InventoryRecord& data) { return id < data.id; }
	friend ostream& operator<<(ostream& os, const InventoryRecord& data) { os << data.id << " " << data.type << " " << data.numItems; return os; }

private:
	int id;
	string type;
	int numItems;
};

#endif