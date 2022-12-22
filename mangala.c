#include<stdio.h>
#include<string.h>
int prnt(int f_array[2][8]){
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<8;j++)
		{
	     printf("%d",f_array[i][j]);
	     if(j<7)
		 {
		 printf("%c",'|');		
		 }
		}
		printf("\n");		
	}
	
}
int game_for_user1(int array[2][8]){
	printf("User 1 enter hole number ");
	int hole;
	scanf("%d",&hole);
	int n = array[1][hole];
	if(n!=1){
	
	 for(int i=1;i<=n-1;i++){
		array[1][hole+i]+=1;
		
	}
    }
    
	if(array[1][hole]>1){	
	array[1][hole]=1;
    }
	else if(array[1][hole]<=1){		
		array[1][hole]=0;
		if(hole==6)
		{
			printf("lucky\n");
			array[1][7]+=1;
		    game_for_user1(array);
		}
		else {
			array[1][hole+1]=array[1][hole+1]+1;
			
		}
	} 

	prnt(array);

	if(((n-1)+hole) == (7) ){
	printf("lucky\n");
		game_for_user1(array);	
		
	}
	
   
}
int game_for_user2(int array[2][8]){
	printf("User 2 enter hole number ");
	int hole;
	scanf("%d",&hole);
	hole = 7-hole;
	int n = array[0][hole];
	
	if((n-1)+(hole) == (array[0][0]+6)){
	printf("lucky\n");
		game_for_user2(array);
		
	}
	for(int i=1;i<=n-1;i++){
		array[0][(hole)-i]+=1;
		
	}
	if(array[0][hole]>1){	
	array[0][hole]=1;
    }
	else{		
		array[0][hole]=0;
		if(hole=1){
			array[0][0]+=1;
		}
	} 
	
}
int main(){
	int mangala[2][8];
	mangala[0][0] = 0;
	mangala[0][7] = 0;
	mangala[1][0] = 0;
	mangala[1][7] = 0;
	int i,j;
	
	for( i=0;i<2;i++)
	{
		for( j=1;j<7;j++)
		{
	     mangala[i][j]=4;			
		}
		
	}
   	//mangala[1][6]=1;
	
	game_for_user1(mangala);
    game_for_user1(mangala);
	//game_for_user1(mangala);	
    //game_for_user1(mangala);
    //game_for_user1(mangala);
  //  prnt(mangala);

    
   
}
