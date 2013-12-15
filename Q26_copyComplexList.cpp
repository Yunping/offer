struct ComplexList {
	int value;
	ComplexList *next;
	ComplexList *sibling;
};

ComplexList *copyComplexList(ComplexList *list) {
	ComplexList *source = list;
	ComplexList *dest = 0;
	ComplexList *preDest = 0;
	std::map<ComplexList*, ComplexList*> aMap;
	
	while (source) {
		dest = new ComplexList();
		dest->value = source->value;
		dest->next = 0;
		dest->sibling = source->sibling;
		aMap[source] = dest;
		source = source->next;
		
		if (preDest)
			preDest->next = dest;
		preDest = dest;
	}
	
	dest = list ? aMap[list] : 0;
	while (dest) {
		if (dest->sibling) {
			dest->sibling = aMap[dest->sibling];
		}
		dest = dest->next;
	}
	
	return list ? aMap[list] : 0;
}