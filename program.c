#include <stdio.h>

struct qNum{
	int nume ;
	int deno ;
	int sign ;
};

int min(int a,int b) ;
int lcm(int a,int b) ;
int gcd(int a,int b) ;

struct qNum qAdd(struct qNum a,struct qNum b) ;
struct qNum qOpp(struct qNum a) ;
struct qNum qSub(struct qNum a,struct qNum b) ;
struct qNum qMul(struct qNum a,struct qNum b) ;
struct qNum qRec(struct qNum a) ;
struct qNum qDiv(struct qNum a,struct qNum b) ;

struct qNum qScan() ; 
void qPrint(struct qNum a) ;

int main(){
	
}

struct qNum qAdd(struct qNum a,struct qNum b){
	if ( a.sign == 0 ){
		return b ;
	}
	if ( b.sign == 0 ){
		return a ;
	}
	struct qNum res ;
	if ( a.sign == 1 && b.sign == 1 ){
		int ndeno = lcm(a.deno,b.deno) ;
		int nnume = a.nume*ndeno/a.deno + b.nume*ndeno/b.deno ;
		int red = gcd(ndeno,nnume) ;
		ndeno = ndeno / red ;
		nnume = nnume / red ;
		res.deno = ndeno ;
		res.nume = nnume ;
		res.sign = 1 ;
		return res ;
	}
	if ( a.sign == -1 && b.sign == -1 ){
		int ndeno = lcm(a.deno,b.deno) ;
		int nnume = a.nume*ndeno/a.deno + b.nume*ndeno/b.deno ;
		int red = gcd(ndeno,nnume) ;
		ndeno = ndeno / red ;
		nnume = nnume / red ;
		res.deno = ndeno ;
		res.nume = nnume ;
		res.sign = -1 ;
		return res ;
	}
	if ( a.sign == -1 && b.sign == 1 ){
		int ndeno = lcm(a.deno,b.deno) ;
		int nnume = - a.nume*ndeno/a.deno + b.nume*ndeno/b.deno ;
		int nsign ;
		if ( nnume == 0 ){
			res.deno = 1 ;
			res.nume = 0 ;
			res.sign = 0 ;
			return res ;
		}
		if ( nnume < 0 ){
			nnume = - nnume ;
			nsign = -1 ;
		}
		else{
			nsign = 1 ;
		}
		int red = gcd(ndeno,nnume) ;
		ndeno = ndeno / red ;
		nnume = nnume / red ;
		res.deno = ndeno ;
		res.nume = nnume ;
		res.sign = nsign ;
		return res ;
	}
	if ( a.sign == 1 && b.sign == -1 ){
		int ndeno = lcm(a.deno,b.deno) ;
		int nnume = a.nume*ndeno/a.deno - b.nume*ndeno/b.deno ;
		int nsign ;
		if ( nnume == 0 ){
			res.deno = 1 ;
			res.nume = 0 ;
			res.sign = 0 ;
			return res ;
		}
		if ( nnume < 0 ){
			nnume = - nnume ;
			nsign = -1 ;
		}
		else{
			nsign = 1 ;
		}
		int red = gcd(ndeno,nnume) ;
		ndeno = ndeno / red ;
		nnume = nnume / red ;
		res.deno = ndeno ;
		res.nume = nnume ;
		res.sign = nsign ;
		return res ;
	}
}

struct qNum qOpp(struct qNum a){
	a.sign = - a.sign ;
	return a ;
}

struct qNum qSub(struct qNum a,struct qNum b){
	return qAdd(a,qOpp(b)) ;
}

struct qNum qMul(struct qNum a,struct qNum b){
	struct qNum res ;
	if ( a.sign == 0 || b.sign == 0 ){
		res.nume = 0 ;
		res.deno = 1 ;
		res.sign = 0 ;
		return res ;
	}
	int ndeno = a.deno * b.deno ;
	int nnume = a.nume * b.nume ;
	int nsign = a.sign * b.sign ;
	int red = gcd(ndeno,nnume) ;
	ndeno = ndeno / red ;
	nnume = nnume / red ;
	res.deno = ndeno ;
	res.nume = nnume ;
	res.sign = nsign ;
	return res ;
}

struct qNum qRec(struct qNum a){
	if ( a.sign == 0 ){
		printf("Error!\n") ;
		return a ;
	}
	int changer ;
	changer = a.deno ;
	a.deno = a.nume ;
	a.nume = changer ;
	return a ;
}

struct qNum qDiv(struct qNum a,struct qNum b){
	return qMul(a,qRec(b)) ;
}

struct qNum qScan(){
	char str[30] ;
	struct qNum res ;
	scanf("%s",&str) ;
	int frac = 0 ;
	for ( int k = 0 ; k >= 0 ; k++ ){
		if ( str[k] == '\0' ){
			break ;
		}
		if ( str[k] == '/' ){
			frac = 1 ;
			break ;
		}
	}
	int nega = 0 ;
	if ( str[0] == '-' ){
		nega = 1 ;
	}
	if ( !frac && !nega ){
		sscanf(str,"%d",&res.nume) ;
		res.deno = 1 ;
		if ( res.nume == 0 ){
			res.sign = 0 ;
		}
		else{
			res.sign = 1 ;
		}
	}
	if ( frac && !nega ){
		sscanf(str,"%d/%d",&res.nume,&res.deno) ;
		res.sign = 1 ;
	}
	if ( !frac && nega ){
		sscanf(str,"-%d",&res.nume) ;
		res.deno = 1 ;
		res.sign = -1 ;
	}
	if ( frac && nega ){
		sscanf(str,"-%d/%d",&res.nume,&res.deno) ;
		res.sign = -1 ;
	}
	int red = gcd(res.deno,res.nume) ;
	res.deno = res.deno / red ;
	res.nume = res.nume / red ;
	return res ;
}

void qPrint(struct qNum a){
	if ( a.sign == -1 ){
		putchar('-') ;
	}
	printf("%d",a.nume) ;
	if ( a.deno != 1 ){
		printf("/%d",a.deno) ;
	}
	return ;
}

int min(int a,int b){
	if ( a < b ){
		return a ;
	}
	else{
		return b ;
	}
}

int lcm(int a,int b){
	int res = 1 ;
	while(1){
		int status = 0 ;
		for ( int i = 2 ; i <= min(a,b) ; i++ ){
			if ( a % i == 0 && b % i == 0 ){
				res = res * i ;
				a = a / i ;
				b = b / i ;
				status = 1 ;
				break ;
			}
		}
		if ( !status ){
			break ;
		}
	}
	return res * a * b ;
}

int gcd(int a,int b){
	int res = 1 ;
	while(1){
		int status = 0 ;
		for ( int i = 2 ; i <= min(a,b) ; i++ ){
			if ( a % i == 0 && b % i == 0 ){
				res = res * i ;
				a = a / i ;
				b = b / i ;
				status = 1 ;
				break ;
			}
		}
		if ( !status ){
			break ;
		}
	}
	return res ;
}
