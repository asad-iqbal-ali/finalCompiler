extern int printd(int s);



int main(){

	int s;
	int t;

	s = 3;
	t = 2;

	if(s < t){
		printd(s);
		printd(5);
	}
	else { printd(t); printd(2);}

	
	return 1;
}






