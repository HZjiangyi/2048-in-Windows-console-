#include <iostream>
#include <conio.h>
#include<string>
#include <iomanip>
#include<cstdlib>
#include<time.h> 
#include<vector>
using namespace std;
class Session{
	private:
		int value[4][4];
		int score;
		int result;
		int zero;
	public:
		Session();
		~Session();
		void print();
		void init();
		void up();
		void down();
		void left();
		void right();
		void gen();
		void gen1();
		int judge();
		int _size();
		
				
};

int main(int argc, char** argv) {
	
	Session s;
	int ch;
    while (1){
        if (_kbhit())
		{
            ch = _getch();
            if(ch<128){
            	switch(ch){
            		case 72:
            			s.up();
            			if(s.judge()) return 0;
						break;
					case 80:
            			s.down();
            			if(s.judge()) return 0;
						break;	
					case 75:
            			s.left();
            			if(s.judge()) return 0;
						break;	
					case 77:
            			s.right();
            			if(s.judge()) return 0;
						break;
					case 110:
            			s.init();
						break;				
				}
			}
            	
            
	            
        }
    }
    
    
	out:return 0;
}
Session::Session(){
	init();
}
void Session::init(){
	score=0;
	result=0;
	zero=16;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			value[i][j]=0;
		}
	}
	gen();
	
	
	
	
}		
void Session::print(){
	system("cls");
	cout<<"Welcome to 2048! (author:JY)"<<endl;
	cout<<string(20,'#')<<endl;
	cout<<"score:"<<score<<endl;
	cout<<string(20,'-')<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<setw(4)<<value[i][j];
			
			if(j<3){
				cout<<" ";
			}
		
		}
		
				cout<<endl;
			
		
	}
	cout<<string(20,'#')<<endl;
	//cout<<"zero:"<<zero<<endl;
	
}
int Session::_size(){
	int cnt;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!value[i][j]) cnt++;
		}
	}
	return cnt;
}

		
void Session::up(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
		{
			int k=j+1;
			
			while(k<4)
			{
				if(value[j][i]&&value[j][i]==value[k][i])
				{
					score+=value[j][i];
					value[j][i]*=2;
					value[k][i]=0; 
					zero++;
				
				}
				else if(value[k][i])
				{
					break;
				}
				k++;
			}	
		}
		vector<int> v;
		for(int j=0;j<4;j++){
			if(value[j][i]){
				v.push_back(value[j][i]);
				value[j][i]=0;
			}
			
		}
		vector<int>::iterator it =v.begin();
		for(int j=0;j<v.size();j++){
			
				value[j][i]=*it;
				it++;
			
		}
		
		
	}
	
	gen();
	
	
}
void Session::down(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
		{
			int k=j+1;
			
			while(k<4)
			{
				if(value[3-j][i]&&value[3-j][i]==value[3-k][i])
				{
					score+=value[3-j][i];
					value[3-j][i]*=2;
					value[3-k][i]=0; 
					zero++;
				
				}
				else if(value[3-k][i])
				{
					break;
				}
				k++;
			}	
		}
		vector<int> v;
		for(int j=0;j<4;j++){
			if(value[3-j][i]){
				v.push_back(value[3-j][i]);
				value[3-j][i]=0;
			}
			
		}
		vector<int>::iterator it =v.begin();
		for(int j=0;j<v.size();j++){
			
				value[3-j][i]=*it;
				it++;
			
		}
		
		
	}
	
	gen();
	
}
void Session::left(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
		{
			int k=j+1;
			
			while(k<4)
			{
				if(value[i][j]&&value[i][j]==value[i][k])
				{
					score+=value[i][j];
					value[i][j]*=2;
					value[i][k]=0; 
					zero++;
				
				}
				else if(value[i][k])
				{
					break;
				}
				k++;
			}	
		}
		vector<int> v;
		for(int j=0;j<4;j++){
			if(value[i][j]){
				v.push_back(value[i][j]);
				value[i][j]=0;
			}
			
		}
		vector<int>::iterator it =v.begin();
		for(int j=0;j<v.size();j++){
			
				value[i][j]=*it;
				it++;
			
		}
		
		
	}
	
	gen();
	
}
void Session::right(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++)
		{
			int k=j+1;
			
			while(k<4)
			{
				if(value[i][3-j]&&value[i][3-j]==value[i][3-k])
				{
					score+=value[i][3-j];
					value[i][3-j]*=2;
					value[i][3-k]=0; 
					zero++;
				
				}
				else if(value[i][3-k])
				{
					break;
				}
				k++;
			}	
		}
		vector<int> v;
		for(int j=0;j<4;j++){
			if(value[i][3-j]){
				v.push_back(value[i][3-j]);
				value[i][3-j]=0;
			}
			
		}
		vector<int>::iterator it =v.begin();
		for(int j=0;j<v.size();j++){
			
				value[i][3-j]=*it;
				it++;
			
		}
		
		
	}
	
	gen();
	
}
void Session::gen1(){
	if(zero)
	{
		
		int n,cnt=-1;
		srand(time(NULL));
    	
	    n=rand()%(zero);
	for(int i=0;i<4;i++){
		
		for(int j=0;j<4;j++){
			if(!value[i][j])
			{
				cnt++;
				if(cnt==n)
				{
				
					value[i][j]=rand()%2?4:2;
					zero--;
					print();
					return;
				}
			} 
			
		}
	}
		
	}
	
	
}
void Session::gen(){
	srand(time(NULL));
	if(zero<3){
		gen1();
	}
	else{
		gen1();
		if(rand()%2) gen1();
		
	}
	
}
int Session::judge(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(value[i][j]==2048){
				cout<<"You win!"<<endl;
				return 1;
			}
		}
	}
	return 0;
	
}
Session::~Session(){
	
}
