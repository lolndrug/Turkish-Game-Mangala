#include<stdio.h>
#include<string.h>
int prnt(int f_array[2][8]){ // This function prints the array last situation.I used nested  for loops for writing the Multidimensial array.
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<8;j++)
		{
		  
		if(!(i==0 && j== 7 || i==1 &&j==0))
		{
		
	     printf(" %d ",f_array[i][j]);
	        if(j<7)
		   {
		    printf("%c",'|');		
		   }
	    }
	    if(i==1 && j==0){
	    	printf("   |");
		}
		}
		printf("\n");	
	    	
	}
	
}



int game_for_user1(int array[2][8]){        //This function carrys the numbers to the other holes. // array[0] belongs to user 2 and array[1] belongs to user 1.
	printf("User 1 enter hole number ");
	int hole;
	scanf("%d",&hole);
	if(hole<1 ||hole>6){
		printf("Unvalid number,please enter a number between 1 and 6\n");
	}
	int n = array[1][hole];  // n variable holding the stone number existing in the hole.
	if(n!=1){
	
	 for(int i=1;i<=n-1;i++){
		array[1][hole+i]+=1; // if n is not equal 1 , this loop carry the stones to the next holes.
		
	}
    }
    
	if(array[1][hole]>1){	// if n is bigger then 1 , the hole will hold only 1 stone after carrying the other stone.
	array[1][hole]=1;
    }
	else if(array[1][hole]<=1){		
		array[1][hole]=0;   // if n is less or equal than 1 , the hole will hold 0 stone after carrying the other rocks.
		if(hole==6)         // if hole is 6'th hole than our bank will increase and user 1 will play one more time.
		{
			array[1][7]+=1;
		    prnt(array);
		    game_for_user1(array);
		}
		else {
			array[1][hole+1]=array[1][hole+1]+1;
			
		}
	} 

	

	 int z=(n-1+hole)-7;     //this expression is used to calculate where the last stone fell
	if(((n-1)+hole) == (7) ){ // if the last stone fall in bank then user1 play one more time.
		prnt(array);
	
		game_for_user1(array);	// if the last stone fall in bank then user1 play one more time.
	}
	
    else if((n-1)+hole>7)   // otherwise if (n-1) + hole number is bigger than 7, it means our stones will pass the other side.
	{
		
    	for(int i=0;i<z;i++)
	  {
		array[0][6-i]+=1;  // adding stones to other players holes.
	
      }
       if(array[0][7-z]%2==0){   // If the number of stones in the last hole we throw is even, we take all the stones in that well.
    	array[1][7] += array[0][7-z];  // we add the stones to user 1's bank.
    	array[0][7-z]=0; // there is no stone in this hole any more.
     
	}
    }
     
     prnt(array);	
		
}
int game_for_user2(int array[2][8]){      // this function works same as above function
	printf("User 2 enter hole number ");
	int hole;
	int holee;
	scanf("%d",&hole);
	if(hole<1 ||hole>6){
		printf("Unvalid number,please enter a number between 1 and 6\n");
	}
	holee = 7-hole;
	int n = array[0][holee];
	
    if(n!=1){
	
	for(int i=1;i<=n-1;i++){
		array[0][(holee)-i]+=1;
		
	}
    }
    
	if(array[0][holee]>1){	
	array[0][holee]=1;
    }
    
	else if(array[0][holee]<=1){		
		array[0][holee]=0;
		if(holee==1){
			array[0][0]+=1;
			prnt(array);
			game_for_user2(array);
		}
		else 
		{
			array[0][holee-1]=array[0][holee-1]+1;
	    }
	} 
	

	int z=(n-1+hole)-7;
	if(((n-1)+hole) == (7) ){
        prnt(array);
		game_for_user2(array);	
	
	}
    
    else if((n-1)+hole>7)
	{
		
    	for(int i=0;i<z;i++)
	  {
		array[1][1+i]+=1;
      }
      
      
      if(array[1][z-1]%2==0){
    	array[0][0] += array[1][z-1];
    	array[1][z-1]=0;
    
	}
    }
    
	
    prnt(array);

	
	
}
void game(int arr[2][8]){                     // In this function we are controling the game.
	printf("Welcome,The game has started.\n");
	printf("If you want to quit press q.\n");
	prnt(arr);
	printf("User 1 is gonna play first.\n");
    
    char quit;
  //  
	while(quit !='q'){
     game_for_user1(arr);
     game_for_user2(arr);
     scanf("%c",&quit);
	}
    
    if(arr[0][0]>arr[1][7]){       //if user 2's bank has more stones than user 1's bank, the winner is user 2.
    printf("User 2 is the winner.Congratulations!");	
	}
	else{
	printf("User 1 is the winner.Congratulations!")	; 
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
	     mangala[i][j]=4;		// Assşgning the stones in this nested loops.	
		}
		
	}
   
	
    game(mangala);              //calling "game" function and starts the game.
    
   
}
