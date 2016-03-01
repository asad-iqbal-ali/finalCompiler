extern int printf(string s);
extern int printd(int d);
extern int strcmp(string s, string y);

int main(){

	string s;
	string t,b;

	s = "aaa";
	b = "aaa";
	t = "bbb";

	if(t > s){
		if(strcmp(t,s) > 0)
			printf("correct\n");
		else printf("wrong\n");
	}
	

	return 0;
	
}






