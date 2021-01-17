#include "InventoryRecord.h"

InventoryRecord::InventoryRecord() {
	id = 0;
	type = "";
	numItems = 0;
}


int InventoryRecord::getId() {
	return id;
}

string InventoryRecord::getType() {
	return type;
}

int InventoryRecord::getNumItems() {
	return numItems;
}

void InventoryRecord::setId(int x) {
	id = x;
}

void InventoryRecord::setType(string x) {
	type = x;
}

void InventoryRecord::setNumItems(int x) {
	numItems = x;
}