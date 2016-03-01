extern int printf(string s);
extern int printd(int d);
extern int strcmp(string s, string y);

extern int put_char_at( string s, int i, int c );

extern int get_char_at( string s, int i );

string str(string s){
	return s + "\n";
}

string str2(string s, string x){
	return s + x;

}

string s;

int main(){

	string t;
	int i;

	s = "SPACE";

	
	t = "abcd";

	printf(str2(s, "\n"));
	printf(t + str(str2(s, "efg")));
	
	return 0;
}






