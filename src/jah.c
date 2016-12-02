
int main (void){
	int j, k=20162497;
	char password[20];
	j = Sign_down(k);
	printf("%d\n",j);
	Sign_up();
	Revise(k);
	Sign_down(k);
	printf("%d\n",j);
	scanf("%s",password);
	Log_in(k,password);

	return 0;
	}
