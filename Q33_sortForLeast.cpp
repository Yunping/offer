int compare(int l, int r) {
	char str_l[512];
	char str_r[512];
	sprintf(str_l, "%d", l);
	sprintf(str_r, "%d", r);
	
	char str_lr[1024];
	strcpy(str_lr, str_l);
	strcat(str_lr, str_r);
	
	char str_rl[1024];
	strcpy(str_rl, str_r);
	strcat(str_rl, str_l);
	
	return strcmp(str_lr, str_rl);
}

void sortForLeast(int a[], int length) {
}